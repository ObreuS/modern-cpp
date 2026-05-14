# Modern Enterprise C++ CI/CD Training Pack

Demo service: `market-data-service`

This pack demonstrates a modern enterprise C++ delivery model:

- C++17 service codebase
- CMake + CMakePresets
- Unit tests via CTest
- Docker multi-stage build
- Jenkins Declarative Pipeline
- GitLab CI example
- Static analysis hooks
- Sanitizer build profile
- Trivy security scan
- Helm chart
- Kubernetes manifests
- ArgoCD GitOps application

Recommended training story:

1. Developer pushes to app repo
2. Pipeline builds with CMake preset
3. Unit tests run via CTest
4. Static analysis and sanitizer profiles run
5. Docker image is built
6. Image is scanned
7. Image is pushed to registry
8. Helm chart deploys to DEV
9. ArgoCD promotes environment through GitOps
10. PROD requires manual approval
