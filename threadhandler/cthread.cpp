#include "cthread.h"
#include <iostream>


CThread::CThread(): data(0), ready(false)
{

}

void CThread::increment()
{
    std::lock_guard<std::mutex> lock(mutex);
    ++data;
    ready = true;
    std::cout << "Data incremented to: " << data << std::endl;
    cv.notify_one();
}

void CThread::waitUntilReady()
{
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [this] {  return ready; });
    std::cout << "Condition met, data is: " << data << std::endl;
    ready = false;
}

int CThread::getData()
{
    std::lock_guard<std::mutex> lock(mutex);
    return data;
}
