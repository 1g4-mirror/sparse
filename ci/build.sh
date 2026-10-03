#!/bin/bash

set -eu

scriptdir="$(dirname "$0")"

echo "compiler path: $(type -p "${CC:-gcc}")"
nproc=$(nproc)
case "$MODE" in
    asan)
	ASAN_FLAGS="-fsanitize=address,pointer-compare,pointer-subtract,undefined"
	CFLAGS="-O1 -g ${ASAN_FLAGS} -fno-omit-frame-pointer"
	LDFLAGS="${ASAN_FLAGS}"
	make -s -j"${nproc}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
	;;
    regular)
	make -s -j"${nproc}"
	;;
    *)
	exit 1
	;;
esac
