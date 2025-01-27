#ifndef INSTANCECOUNTER_H
#define INSTANCECOUNTER_H

class InstanceCounter {
private:
    static int count;  // Static member variable to track instances

public:
    InstanceCounter();
    static int getCount();  // Static method to get the current count
};

#endif // INSTANCECOUNTER_H