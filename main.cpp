#include <QtGui>
#include <iostream>

#include "main.h"

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
  setupUi(this);
  this->Object = new MyObject;
}

void MainWindow::on_btnStop_clicked()
{
  this->TestComputationThread.StopComputation();
}

void MainWindow::on_btnCompute_clicked()
{
  this->TestComputationThread.Operation = ComputationThreadClass<MyObject>::ALLSTEPS;
  this->TestComputationThread.start();
}

void MainWindow::on_btnStep_clicked()
{
  this->TestComputationThread.Operation = ComputationThreadClass<MyObject>::SINGLESTEP;
  this->TestComputationThread.start();
}
