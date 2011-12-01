#ifndef TESTCOMPUTATIONTHREAD_H
#define TESTCOMPUTATIONTHREAD_H

#include <QThread>

#include "ComputationThread.h"

// This class is named 'TestComputationThreadClass' instead of just 'TestComputationThread'
// because we often want to name a member variable 'ComputationThread'
template<typename TObject>
class TestComputationThreadClass : public ComputationThreadClass<TObject>
{
Q_OBJECT

public:
  TestComputationThreadClass();

  void AllSteps();
  void SingleStep();

};

#endif