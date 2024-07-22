#ifndef CTHREAD_H
#define CTHREAD_H

#include <thread>
#include <mutex>
#include <condition_variable>

class CThread
{
private:
    std::mutex mutex;
    std::condition_variable cv;

    int data;
    bool ready;

public:
    CThread();

    void increment();

    void waitUntilReady();

    int getData();

};

#endif // CTHREAD_H
