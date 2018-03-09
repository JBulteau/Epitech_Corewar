pipeline {
  agent any
  stages {
    stage('Building project') {
      steps {
        sh 'make'
      }
    }
    stage('Runnign test_all_asm') {
      steps {
        sh './test_asm.sh'
      }
    }
  }
}