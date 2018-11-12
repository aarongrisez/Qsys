#!/bin/bash

ENGINE_RELEASE=3.0.6
GODOT_HEADLESS=Godot_v$ENGINE_RELEASE-stable_linux_headless.64

echo
echo "Downloading godot headless"
echo

wget https://downloads.tuxfamily.org/godotengine/$ENGINE_RELEASE/$GODOT_HEADLESS.zip
unzip $GODOT_HEADLESS.zip

mv $GODOT_HEADLESS godot