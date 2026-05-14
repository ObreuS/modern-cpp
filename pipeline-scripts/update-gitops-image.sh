#!/usr/bin/env bash
set -euo pipefail
ENV="$1"
IMAGE_TAG="$2"
echo "Updating GitOps repo for environment=$ENV imageTag=$IMAGE_TAG"
