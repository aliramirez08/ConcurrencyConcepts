#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex outputMutex;

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Counting Up: " << i << std::endl;
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Counting Down: " << i << std::endl;
    }
}

int main() {
    std::cout << "Starting Concurrency Example..." << std::endl;

    std::thread thread1(countUp);
    thread1.join();  // Wait for countUp to complete

    std::thread thread2(countDown);
    thread2.join();  // Wait for countDown to complete

    std::cout << "Both threads have finished." << std::endl;
    return 0;
}
// main.cpp 