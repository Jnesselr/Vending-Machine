#include "Looper.h"

#include "Arduino.h"
#include "utils.h"

// See utils.h for more info
unsigned long current_loop_millis = 0;

Task Looper::tasks[16] = {};
volatile int Looper::numTasks = 0;

void Looper::add(const Task& task) {
  tasks[numTasks] = task;
  numTasks++;
}

void Looper::loop() {
  // Assign it to a global volatile variable so everything
  // can use it and be on the same time.
  current_loop_millis = millis();

  Task* nextTask = nullptr;
  Task* task = nullptr;

  for (int i = 0; i < numTasks; i++)
  {
    task = &tasks[i];

    if(task->nextRunMillis < current_loop_millis) {
      if(nextTask == nullptr) {
        nextTask = task;
      } else if(task->nextRunMillis < nextTask->nextRunMillis) {
        nextTask = task;
      }
    }
  }

  // TODO Handle task starvation
  if(nextTask != nullptr) {
    nextTask->run();
    nextTask->nextRunMillis = current_loop_millis + nextTask->runEveryMillis;
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
  function();
}