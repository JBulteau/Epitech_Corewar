pipeline {
  agent any
  stages {
    stage('Building project') {
      steps {
        sh 'make'
      }
    }
    stage('Running ASM compiling tests') {
      steps {
        sh '''#/bin/bash
success=`./test_asm.sh | grep "DIFF : " | head -1 | cut -d\':\' -f2 | cut -d " " -f2`
if [ $success == 0 ]; then
        echo "OK."
        exit 0
else
        echo "PAS OK."
        exit 84
fi'''
      }
    }
  }
}