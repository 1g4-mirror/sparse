#!/bin/bash

set -eu

packages=(
    bc
    bison
    build-essential
    dwarves
    flex
    libelf-dev
    libgtk-3-dev
    libsqlite3-dev
    libssl-dev
    llvm-dev
    make
    pahole
    perl
    pkg-config
)
apt-get update
for p in "${packages[@]}"; do
    apt-get install -qq -o=Dpkg::Use-Pty=0 -y "$p"
done
