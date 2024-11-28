pipeline {
    agent any
    options {
        ansiColor('xterm')
    }
    stages {
        stage('Checkout subrepos') {
            steps {
                echo 'Jenkins environment variable..'
                sh 'printenv | sort'
                echo 'Subrepos..'
                sh 'git submodule update --init --recursive'
            }
        }
        stage('Cmake') {
            steps {
                echo 'Running Cmake..'
                sh 'rm -fr build; mkdir build; cd build; cmake ..; cd ..'
            }
        }
        stage('Static Analysis') {
            environment {
                BUILD_FILES = sh(script: "cat build/compile_commands.json | jq -r \'.[] .file\' | grep -v unity/src/unity", returnStdout: true).trim()
            }
            steps {
                echo 'Static Analysis..'
                sh '/Applications/Clion.app/Contents/bin/clang/mac/clang-tidy -p build/compile_commands.json ${BUILD_FILES}'
            }
        }
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'cd build; make clean; make; cd ..'
            }
        }
        stage('Unit Test') {
            steps {
                echo 'Unit testing (libraries) ...'
                sh "cd build; ./unittest"
                echo 'Unit testing (application) ...'
                sh "cd build; ./application"
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
                sh 'cd build; make package; cd ..'
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: """
                build/application,
                build/output.map,
                build/unittest,
                build/application-*.sh,
                build/application-*.tar.gz
            """, fingerprint: true
        }
    }
}