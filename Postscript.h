#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
using namespace std;

class Postscript {
private:
    std::ofstream s;
    char strokeColor[64];
    char fillColor[64];

public:
    Postscript(const char *str) {
        s.open(str);

        strcpy(strokeColor, "1 1 1 setrgbcolor\n");
        strcpy(fillColor, "1 1 1 setrgbcolor\n");
    }

    ~Postscript() {
        s.close();
    }

    void line(int a, int b, int c, int d){
        char temp[256];
        int size = sprintf(temp, "%d %d moveto %d %d lineto stroke\n", a, b, c, d);
        s.write(temp, size);
    }

    void setStrokeColor(int r, int g, int b){
        double red, green, blue;
        char buffer[256];

        red = r / 255.0;
        green = g / 255.0;
        blue= b / 255.0;

        sprintf(buffer, "%f %f %f setrgbcolor\n", red, green, blue);
        strcpy(strokeColor, buffer);
    }

    void setFillColor(int r, int g, int b){
        double red, green, blue;
        char buffer[256];

        red = r / 255.0;
        green = g / 255.0;
        blue= b / 255.0;

        sprintf(buffer, "%f %f %f setrgbcolor\n", red, green, blue);
        strcpy(fillColor, buffer);
    }

    void drawRect(double x, double y, double w, double h){
        char buffer[256];
        int size = sprintf(buffer, "%f %f moveto %f %f lineto %f %f lineto %f %f lineto closepath\n%sstroke\n", x, y, x+w, y, x+w, y+h, x, y+h, strokeColor);
        s.write(buffer, size);
    }

    void fillRect(double x, double y, double w, double h){
        char buffer[256];
        int size = sprintf(buffer, "%f %f moveto %f %f lineto %f %f lineto %f %f lineto closepath\n%sfill\n", x, y, x+w, y, x+w, y+h, x, y+h, fillColor);
        s.write(buffer, size);
    }

    void drawTriangle(double x1, double y1, double x2, double y2, double x3,double y3){
        char buffer[256];
        int size = sprintf(buffer, "%f %f moveto %f %f lineto %f %f lineto closepath\n%sstroke\n", x1, y1, x2, y2, x3, y3, strokeColor);
        s.write(buffer, size);
    }

    void fillTriangle(double x1, double y1, double x2, double y2, double x3,double y3){
        char buffer[256];
        int size = sprintf(buffer, "%f %f moveto %f %f lineto %f %f lineto closepath\n%sfill\n", x1, y1, x2, y2, x3, y3, fillColor);
        s.write(buffer, size);
    }

  
};