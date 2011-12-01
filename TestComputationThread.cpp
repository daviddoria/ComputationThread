#include "TestComputationThread.h"

template<typename TObject>
TestComputationThreadClass<TObject>::TestComputationThreadClass() : ComputationThreadClass<TObject>()
{

}

template<typename TObject>
void ComputationThreadClass<TObject>::AllSteps()
{
  emit StartProgressBarSignal();

  // Start the procedure
  this->Stop = false;

  while(!this->Stop)
    {
    this->Object->Step();
    emit IterationCompleteSignal();
    }

  // When the function is finished, end the thread
  exit();
}

template<typename TObject>
void ComputationThreadClass<TObject>::SingleStep()
{
  //std::cout << "ProgressThread::run()" << std::endl;
  // When the thread is started, emit the signal to start the marquee progress bar
  emit StartProgressBarSignal();

  this->Object->Step();
  
  emit IterationCompleteSignal();
  emit StepCompleteSignal();

  // When the function is finished, end the thread
  exit();
}
