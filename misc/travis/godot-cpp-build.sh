#!/bin/sh
cd $TRAVIS_BUILD_DIR/godot-cpp
scons -j2 generate_bindings=yes
scons -j2 platform=$PLATFORM