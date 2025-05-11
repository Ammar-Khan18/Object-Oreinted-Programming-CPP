#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

enum class ProcessState { Ready, Running, Blocked, Terminated };

class Process {
public:
    int pid;
    std::string name;
    int priority;
    ProcessState state;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    std::list<int> resources;

    Process(int id, const std::string& nm, int prio, int burst, int arrival)
        : pid(id), name(nm), priority(prio), state(ProcessState::Ready),
          burstTime(burst), arrivalTime(arrival), remainingTime(burst) {}

    // Display details
    void display() const {
        std::cout << "PID: " << pid << ", Name: " << name
                  << ", Priority: " << priority
                  << ", State: " << stateToString()
                  << ", Burst: " << burstTime
                  << ", Arrival: " << arrivalTime
                  << ", Remaining: " << remainingTime
                  << ", Resources: [";
        for (auto r : resources) std::cout << r << ' ';
        std::cout << "]\n";
    }

private:
    std::string stateToString() const {
        switch (state) {
            case ProcessState::Ready: return "Ready";
            case ProcessState::Running: return "Running";
            case ProcessState::Blocked: return "Blocked";
            case ProcessState::Terminated: return "Terminated";
        }
        return "Unknown";
    }
};

// Comparator functor for priority scheduling
struct ProcessComparator {
    bool operator()(const Process& a, const Process& b) const {
        if (a.priority != b.priority)
            return a.priority < b.priority;
        if (a.remainingTime != b.remainingTime)
            return a.remainingTime < b.remainingTime;
        return a.arrivalTime < b.arrivalTime;
    }
};

class Scheduler {
    std::list<Process> processes;

public:
    void addProcess(const Process& p) {
        processes.push_back(p);
    }

    void removeProcess(int pid) {
        processes.remove_if([pid](const Process& p) { return p.pid == pid; });
    }

    void updateProcessState(int pid, ProcessState newState) {
        auto& p = getProcessByPid(pid);
        p.state = newState;
    }

    void allocateResource(int pid, int resourceId) {
        auto& p = getProcessByPid(pid);
        p.resources.push_back(resourceId);
    }

    void releaseResource(int pid, int resourceId) {
        auto& p = getProcessByPid(pid);
        p.resources.remove(resourceId);
    }

    void displayProcessDetails(int pid) const {
        const auto& p = const_cast<Scheduler*>(this)->getProcessByPid(pid);
        p.display();
    }

    void displayAllProcesses() const {
        for (const auto& p : processes) p.display();
    }

    Process& getProcessByPid(int pid) {
        for (auto& p : processes) {
            if (p.pid == pid) return p;
        }
        throw std::runtime_error("Process with PID " + std::to_string(pid) + " not found");
    }

    std::vector<std::reference_wrapper<Process>> getProcessesByState(ProcessState state) {
        std::vector<std::reference_wrapper<Process>> result;
        for (auto& p : processes) {
            if (p.state == state) result.push_back(p);
        }
        return result;
    }

    // Scheduling algorithms
    void scheduleByPriority() {
        processes.sort(ProcessComparator());
    }

    void scheduleByShortestJobFirst() {
        processes.sort([](const Process& a, const Process& b) {
            return a.burstTime < b.burstTime;
        });
    }

    void scheduleByRoundRobin(int quantum) {
        std::list<Process*> readyQueue;
        for (auto& p : processes) {
            if (p.state == ProcessState::Ready) readyQueue.push_back(&p);
        }
        while (!readyQueue.empty()) {
            Process* p = readyQueue.front();
            readyQueue.pop_front();
            p->state = ProcessState::Running;
            int slice = std::min(p->remainingTime, quantum);
            p->remainingTime -= slice;
            if (p->remainingTime <= 0) {
                p->state = ProcessState::Terminated;
            } else {
                p->state = ProcessState::Ready;
                readyQueue.push_back(p);
            }
        }
    }
};

int main() {
    Scheduler sched;
    // Create 10 processes
    sched.addProcess({1, "P1", 2, 10, 0});
    sched.addProcess({2, "P2", 1, 5, 1});
    sched.addProcess({3, "P3", 3, 8, 2});
    sched.addProcess({4, "P4", 2, 6, 3});
    sched.addProcess({5, "P5", 1, 4, 4});
    sched.addProcess({6, "P6", 4, 7, 5});
    sched.addProcess({7, "P7", 2, 9, 6});
    sched.addProcess({8, "P8", 3, 3, 7});
    sched.addProcess({9, "P9", 1, 12, 8});
    sched.addProcess({10, "P10", 2, 11, 9});

    std::cout << "Initial Processes:\n";
    sched.displayAllProcesses();

    // Priority scheduling
    std::cout << "\nPriority Scheduling:\n";
    sched.scheduleByPriority();
    sched.displayAllProcesses();

    // Reset states for next demo
    for (int pid = 1; pid <= 10; ++pid) sched.updateProcessState(pid, ProcessState::Ready);

    // SJF scheduling
    std::cout << "\nShortest Job First Scheduling:\n";
    sched.scheduleByShortestJobFirst();
    sched.displayAllProcesses();

    // Reset states and remaining times for RR
    std::cout << "\nRound Robin Scheduling (quantum = 3):\n";
    // Reset remainingTime
    for (int pid = 1; pid <= 10; ++pid) {
        auto& p = sched.getProcessByPid(pid);
        p.remainingTime = p.burstTime;
        p.state = ProcessState::Ready;
    }
    sched.scheduleByRoundRobin(3);
    sched.displayAllProcesses();

    return 0;
}
