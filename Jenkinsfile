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
success=`./test_asm.sh | grep "DIFF" | head -1 | cut -d":" -f2 | cut -d " " -f2`
if [ $success == 0 ]
then
        echo "No test failed"
        exit 0 
else
        echo `./test_asm.sh | grep "DIFF" | head -1 | cut -d":" -f2 | cut -d " " -f2`" tests failed"
        exit 84
fi'''
      }
    }
  }
}