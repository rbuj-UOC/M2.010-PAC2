#!/bin/sh
aclocal
autoheader
autopoint -f
automake -ac
autoreconf --install
