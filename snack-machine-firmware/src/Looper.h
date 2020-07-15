#pragma once

typedef void (*TaskFunction)();

class Task {
  public:
    Task();
    Task(unsigned long everyMillis, TaskFunction func);
    void run();
    unsigned long nextRunMillis = 0;
    unsigned long runEveryMillis;
  private:
    TaskFunction function;
};

class Looper {
  public:
    static void add(const Task& task);
    static void loop();
  private:
    static Task tasks[16];
    static volatile int numTasks;
};