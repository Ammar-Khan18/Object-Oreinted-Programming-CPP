#include "../headers/InstanceCounter.h"

int InstanceCounter::count = 0;

InstanceCounter::InstanceCounter() {
    count++;  // Increment count whenever a new object is created
}

// Static method to get the current count
int InstanceCounter::getCount() {
    return count;
}