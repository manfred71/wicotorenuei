#!/bin/sh -e
# /usr/lib/emacsen-common/packages/remove/wicotorenuei

FLAVOR=$1
PACKAGE=wicotorenuei

if [ ${FLAVOR} != emacs ]; then
    if test -x /usr/sbin/install-info-altdir; then
        echo remove/${PACKAGE}: removing Info links for ${FLAVOR}
        install-info-altdir --quiet --remove --dirname=${FLAVOR} /usr/info/wicotorenuei.info.gz
    fi

    echo remove/${PACKAGE}: purging byte-compiled files for ${FLAVOR}
    rm -rf /usr/share/${FLAVOR}/site-lisp/${PACKAGE}
fi