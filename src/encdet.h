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

#ifndef ENCDET_H
#define ENCDET_H

#ifdef __cplusplus
extern "C" {
#if 0
} /* satisfy cc-mode */
#endif
#endif

#define ENCDET_CHINESE_SIMPLIFIED  0x01
#define ENCDET_CHINESE_TRADITIONAL 0x02
#define ENCDET_JAPANESE            0x04
#define ENCDET_KOREAN              0x08
#define ENCDET_NON_CJK             0x10
#define ENCDET_ALL                 0x1F
#define ENCDET_CHINESE (ENCDET_CHINESE_SIMPLIFIED | \
                        ENCDET_CHINESE_TRADITIONAL)
#define ENCDET_CJK (ENCDET_CHINESE_SIMPLIFIED | \
                    ENCDET_CHINESE_TRADITIONAL | \
                    ENCDET_JAPANESE | \
                    ENCDET_KOREAN)

typedef void* encdet_t;

encdet_t encdet_new(unsigned int langflags);

int encdet_handle_data(encdet_t det, const char *data, unsigned int len);

void encdet_data_end(encdet_t det);

void encdet_reset(encdet_t det);

const char *encdet_get_result(encdet_t det);

void encdet_destroy(encdet_t det);

const char *encdet_version(void);

#ifdef __cplusplus
#if 0
{ /* satisfy cc-mode */
#endif
} /* extern "C" { */
#endif

#endif /* ENCDET_H */
