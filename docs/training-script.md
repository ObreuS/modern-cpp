# Training Script

## Demo 1: Happy Path
- Show C++ source code
- Run local build:
  - cmake --preset release
  - cmake --build --preset release
  - ctest --preset release
- Show Docker build
- Show Helm deployment

## Demo 2: Unit Test Failure
Change expected mid price in `tests/unit/QuoteProcessorTest.cpp`.
Pipeline fails at test stage.

## Demo 3: Static Analysis
Introduce a suspicious pattern or formatting issue.
Pipeline catches it during analysis stage.

## Demo 4: Security Scan
Use an older base image in Dockerfile.
Trivy flags vulnerabilities.

## Demo 5: GitOps
Explain how Jenkins/GitLab produces image, while ArgoCD reconciles Kubernetes state.
