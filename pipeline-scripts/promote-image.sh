#!/usr/bin/env bash
set -euo pipefail
SOURCE_TAG="$1"
TARGET_TAG="$2"
echo "Promoting image from $SOURCE_TAG to $TARGET_TAG"
