/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is encdet.
 *
 * The Initial Developer of the Original Code is
 * Jiro Nishiguchi <jiro@cpan.org>
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "encdet.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int
print_encoding(FILE *fp)
{
    char buf[BUFSIZ];
    const char *encoding;
    encdet_t det;
    int rc = 0;

    det = encdet_new(ENCDET_ALL);
    if (!det) {
        fprintf(stderr, "failed to encdet_create().\n");
        return rc;
    }
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        rc = encdet_handle_data(det, buf, strlen(buf));
        if (rc) {
            fprintf(stderr, "failed to encdet_handle_data().\n");
            encdet_destroy(det);
            return rc;
        }
    }
    encdet_data_end(det);
    encoding = encdet_get_result(det);
    if (encoding) {
        puts(encoding);
    } else {
        puts("ASCII");
    }
    encdet_destroy(det);
    return 0;
}

int
main(int argc, char **argv)
{
    FILE *fp;
    int rc;
    if (argc == 1) {
        fp = stdin;
    } else if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror(NULL);
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr, "usage: encdet [FILE]\n");
        return EXIT_FAILURE;
    }
    rc = print_encoding(fp);
    if (argc == 2) fclose(fp);
    return rc ? EXIT_FAILURE : EXIT_SUCCESS;
}

