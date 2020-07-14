#include "Looper.h"

#include "Arduino.h"

Task Looper::tasks[16] = {};
volatile int Looper::numTasks = 0;

void Looper::add(const Task& task) {
  tasks[numTasks] = task;
  numTasks++;
}

void Looper::loop() {
  unsigned long currentMillis = millis();

  Task* nextTask = nullptr;
  Task* task = nullptr;

  for (int i = 0; i < numTasks; i++)
  {
    task = &tasks[i];

    if(task->nextRunMillis < currentMillis) {
      if(nextTask == nullptr
      || task->nextRunMillis < nextTask->nextRunMillis) {
        nextTask = task;
      }
    }
  }

  // TODO Handle task starvation
  if(nextTask != nullptr) {
    nextTask->run();
  }
}

Task::Task() {

}

Task::Task(unsigned long everyMillis, TaskFunction func) {
  nextRunMillis = 0;
  this->runEveryMillis = everyMillis;
  this->function = func;
}

void Task::run() {
  nextRunMillis = millis() + runEveryMillis;
  function();
}