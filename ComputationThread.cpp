#include "ComputationThread.h"

template <typename TObject>
ComputationThreadClass<TObject>::ComputationThreadClass() : Operation(ALLSTEPS), Stop(false)
{

}

template <typename TObject>
void ComputationThreadClass<TObject>::StopComputation()
{
  this->Stop = true;
}

template <typename TObject>
void ComputationThreadClass<TObject>::run()
{
  if(this->Operation == ALLSTEPS)
    {
    AllSteps();
    }
  else if(this->Operation == SINGLESTEP)
    {
    SingleStep();
    }
}

template <typename TObject>
void ComputationThreadClass<TObject>::exit()
{
  // When the thread is stopped, emit the signal to stop the marquee progress bar
  emit StopProgressBarSignal();
}

template <typename TObject>
void ComputationThreadClass<TObject>::SetObject(TObject* object)
{
  this->Object = object;
}
