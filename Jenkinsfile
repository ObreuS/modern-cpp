pipeline {
    agent any

    environment {
        REGISTRY = 'localhost:5000'
        APP_NAME = 'market-data-service'
        IMAGE_TAG = "${BUILD_NUMBER}"
        FULL_IMAGE = "${REGISTRY}/${APP_NAME}:${IMAGE_TAG}"
    }

    options {
        timestamps()
    }

    stages {

        stage('Checkout Application Repo') {
            steps {
                checkout scm
            }
        }

        stage('Checkout Pipeline Scripts Repo') {
            steps {
                dir('pipeline-scripts') {
                    script {
                        if (fileExists('README.md')) {
                            echo 'Using local pipeline-scripts'
                        } else {
                            echo 'Pipeline scripts repo could be checked out here'
                        }
                    }
                }
            }
        }

        stage('Configure Release') {
            steps {
                dir('market-data-service') {
                    sh 'cmake --preset release'
                }
            }
        }

        stage('Build Release') {
            steps {
                dir('market-data-service') {
                    sh 'cmake --build --preset release'
                }
            }
        }

        stage('Run Unit Tests') {
            steps {
                dir('market-data-service') {
                    sh 'ctest --preset release'
                }
            }
        }

        stage('Static Analysis') {
            steps {
                dir('market-data-service') {
                    sh '''
                    cppcheck src include --enable=warning,performance,portability || true
                    '''
                }
            }
        }

        stage('Sanitizer Build') {
            steps {
                dir('market-data-service') {
                    sh '''
                    cmake --preset asan
                    cmake --build --preset asan
                    ctest --preset asan
                    '''
                }
            }
        }

        stage('Docker Build') {
            steps {
                dir('market-data-service') {
                    sh '''
                    docker build -t $FULL_IMAGE .
                    '''
                }
            }
        }

        stage('Security Scan') {
            steps {
                sh '''
                trivy image \
                  --severity HIGH,CRITICAL \
                  --exit-code 0 \
                  $FULL_IMAGE
                '''
            }
        }

        stage('Push Image') {
            steps {
                sh '''
                docker push $FULL_IMAGE
                '''
            }
        }

        stage('Deploy DEV') {
            steps {
                sh '''
                docker rm -f market-data-dev || true

                docker run -d \
                  --name market-data-dev \
                  -p 8080:8080 \
                  $FULL_IMAGE
                '''
            }
        }

        stage('Smoke Test DEV') {
            steps {
                sh '''
                sleep 5
                docker ps
                '''
            }
        }

        stage('Approval Gate') {
            steps {
                input 'Promote to PROD?'
            }
        }

        stage('Deploy PROD') {
            steps {
                sh '''
                docker rm -f market-data-prod || true

                docker run -d \
                  --name market-data-prod \
                  -p 9090:8080 \
                  $FULL_IMAGE
                '''
            }
        }
    }

    post {
        success {
            echo 'Enterprise pipeline success'
        }

        failure {
            echo 'Enterprise pipeline failed'
        }
    }
}
