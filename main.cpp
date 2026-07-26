#include <iostream>
#include <mutex>
#include <thread>

std::mutex outputMutex;

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Counting Up: " << i << '\n';
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "Counting Down: " << i << '\n';
    }
}

int main() {
    std::cout << "Starting Concurrency Example...\n";

    std::thread upThread(countUp);
    std::thread downThread(countDown);

    upThread.join();
    downThread.join();

    std::cout << "Both threads have finished.\n";

    return 0;
}
