pipeline {
    agent any

    options {
        timestamps()
    }

    stages {

        stage('Checkout Application Repo') {
            steps {
                echo 'Checking out source code...'
                checkout scm
            }
        }

        stage('Show Workspace') {
            steps {
                sh '''
                    pwd
                    ls -la
                    ls -la market-data-service
                '''
            }
        }

        stage('Configure Release') {
            steps {
                dir('market-data-service') {
                    sh '''
                        cmake --preset release
                    '''
                }
            }
        }

        stage('Build Release') {
            steps {
                dir('market-data-service') {
                    sh '''
                        cmake --build --preset release
                    '''
                }
            }
        }

        stage('Run Unit Tests') {
            steps {
                dir('market-data-service') {
                    sh '''
                        ctest --preset release
                    '''
                }
            }
        }

        stage('Static Analysis') {
            steps {
                dir('market-data-service') {
                    sh '''
                        cppcheck src include \
                          --enable=warning,performance,portability \
                          || true
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
    }

    post {
        success {
            echo 'Modern C++ CI pipeline completed successfully.'
        }

        failure {
            echo 'Pipeline failed.'
        }
    }
}
