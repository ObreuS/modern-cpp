#!/usr/bin/env bash
set -euo pipefail
IMAGE="$1"
trivy image --severity HIGH,CRITICAL "$IMAGE"
