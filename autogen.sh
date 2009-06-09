#!/bin/sh

run()
{
    echo "running $@"
    $@
    if test $? -ne 0; then
        echo "failed $@"
        exit 1
    fi
}

run aclocal
run libtoolize --copy --force
run autoheader
run automake --add-missing --copy
run autoconf
