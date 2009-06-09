#!/bin/sh
# -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is encdet.
#
# The Initial Developer of the Original Code is
# Jiro Nishiguchi <jiro@cpan.org>
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

warn() {
    echo $@ 1>&2
}

cd `dirname $0`
index=1
files=`find . -type f -name "*.txt" | sort`
tests=`echo "$files" | wc -l`
tests=`expr $tests + 0`
fail=0
echo "$index..$tests" # plan
for file in $files
do
    result=`./encdet $file`
    fileenc=`echo "$file" | sed -e 's/^\.\///' | sed -e 's/\.txt$//'`
    if [ "$result" != "$fileenc" ]; then
        echo "not ok $index - $fileenc"
        warn "#   Failed test '$fileenc'"
        warn "#   at $0 line $LINENO."
        warn "#          got: '$result'"
        warn "#     expected: '$fileenc'"
        fail=`expr $fail + 1`
    else
        echo "ok $index - $fileenc"
    fi
    index=`expr $index + 1`
done
if [ $fail != 0 ]; then
    warn "# Looks like you failed $fail tests of $tests."
    exit 1
fi
exit 0
