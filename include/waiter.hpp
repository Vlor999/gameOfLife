#pragma once
#include <chrono>
#include <thread>

// Function to wait/sleep for a specified number of seconds
inline void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
}