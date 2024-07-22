#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

std::mutex mutex;
std::condition_variable cv;
int ready = 0;


void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulating some work
    {
        std::lock_guard<std::mutex> lock(mutex);
        ready ++;
        std::cout << "producer " << ready << std::endl;
    }
    cv.notify_all(); // Notify one waiting thread
}

void consumer() {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [] { return ready; }); // Wait until ready becomes true
    ready --;
    std::cout << "consumer " << ready << std::endl;
//    std::cout << "Consumer thread notified" << std::endl;
}


int main(int argc, char *argv[])
{
    std::thread t_p1(producer);
    std::thread t_c1(consumer);
    std::thread t_p2(producer);
    std::thread t_c2(consumer);
    std::thread t_p3(producer);
    std::thread t_c3(consumer);
    t_p1.join();
    t_c1.join();
    t_p2.join();
    t_c2.join();
    t_p3.join();
    t_c3.join();

    return 0;
}
