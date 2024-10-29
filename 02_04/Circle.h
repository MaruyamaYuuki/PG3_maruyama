#pragma once
#include "IShape.h"
#include <iostream>
#include <stdio.h>

class Circle : public IShape {
public:
    Circle(float radius) : radius(radius), area(0.0) {}

    void Size() override {
        area = 3.14159f * radius * radius; // 円の面積を計算
    }

    void Draw() override {
        std::cout << "Circle Area : " << area << std::endl;
    }

private:
    float radius;
    float area;
};
