#pragma once
#include "IShape.h"
#include <iostream>
#include <stdio.h>

class Rectangle : public IShape {
public:
    Rectangle(float width, float height) : width(width), height(height), area(0.0) {}

    void Size() override {
        area = width * height; // 長方形の面積を計算
    }

    void Draw() override {
        std::cout << "Rectangle Area : " << area << std::endl;
    }

private:
    float width;
    float height;
    float area;
};
