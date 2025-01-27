#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    float radius;

public:
    void setRadius(float r);
    float getRadius() const;
    float circumference() const;
};

#endif // CIRCLE_H