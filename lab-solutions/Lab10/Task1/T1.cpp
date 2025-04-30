#include <iostream>
#include <chrono>

class Stopwatch {
private:
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point end_time;
    bool running;

public:
    Stopwatch() : running(false) {}

    void start() {
        start_time = std::chrono::steady_clock::now();
        running = true;
    }

    void stop() {
        if (running) {
            end_time = std::chrono::steady_clock::now();
            running = false;
        }
    }

    void reset() {
        running = false;
        start_time = std::chrono::steady_clock::time_point{};
        end_time = std::chrono::steady_clock::time_point{};
    }

    double get_elapsed_time_seconds() const {
        if (running) {
            auto now = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed = now - start_time;
            return elapsed.count();
        } else {
            std::chrono::duration<double> elapsed = end_time - start_time;
            return elapsed.count();
        }
    }

    double get_elapsed_time_milliseconds() const {
        if (running) {
            auto now = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> elapsed = now - start_time;
            return elapsed.count();
        } else {
            std::chrono::duration<double, std::milli> elapsed = end_time - start_time;
            return elapsed.count();
        }
    }
};

int main() {
    Stopwatch sw;
    sw.start();

    // Simulate some workload
    for (volatile int i = 0; i < 100000000; ++i);

    sw.stop();

    std::cout << "Elapsed time in seconds: " << sw.get_elapsed_time_seconds() << " s\n";
    std::cout << "Elapsed time in milliseconds: " << sw.get_elapsed_time_milliseconds() << " ms\n";

    return 0;
}
