#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include "cthread.h"


void producer(CThread &obj) {
    for (int i = 0; i < 10; ++i)
    {
        obj.increment();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(CThread &obj) {
    for (int i = 0; i < 10; ++i)
    {
        obj.waitUntilReady();
    }
}


int main(int argc, char *argv[])
{
    CThread obj;
    std::thread producerThread(producer, std::ref(obj));
    std::thread consumerThread(consumer, std::ref(obj));
    producerThread.join();
    consumerThread.join();
    return 0;
}
