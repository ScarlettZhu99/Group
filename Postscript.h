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

    void drawCircle(double x, double y, double r){
        char buffer[256];
        int size = sprintf(buffer, "%f %f %f 0 360 arc\n%sstroke\n", x, y, r, strokeColor);
        s.write(buffer, size);
    }

    void fillCircle(double x, double y, double r){
        char buffer[256];
        int size = sprintf(buffer, "%f %f %f 0 360 arc\n%sfill\n", x, y, r, fillColor);
        s.write(buffer, size);
    }

    void text(double x, double y, const char* str){
        unsigned int len = strlen(str);
        char buffer[256 + len];
        int size = sprintf(buffer, "/Times-Roman findfont 18 scalefont setfont newpath %f %f moveto (%s) %sshow\n", x, y, str, strokeColor);
        s.write(buffer, size);
    }

    void grid(double x1, double interval_x, double x2, double y1, double interval_y, double y2){
        char buffer1[256];
        char buffer2[256];
        char buffer3[256];
        char buffer4[256];

        int bins_x = int((x2 - x1) / interval_x);
        int bins_y =int((y2 - y1) / interval_y);

        int size1 = sprintf(buffer1, "/vline {%f %f moveto %f %f lineto stroke} def\n", x1, y1, x1, y2);
        s.write(buffer1, size1);
        int size2 = sprintf(buffer2, "gsave\nvline\n%d {%f 0 translate vline} repeat\ngrestore\n", bins_x, interval_x);
        s.write(buffer2, size2);

        int size3 = sprintf(buffer3, "/hline {%f %f moveto %f %f lineto stroke} def\n", x1, y1, x2, y1);
        s.write(buffer3, size3);
        int size4 = sprintf(buffer4, "gsave\nhline\n%d {0 %f translate hline} repeat\ngrestore\n", bins_y, interval_y);
        s.write(buffer4, size4);
    }
};