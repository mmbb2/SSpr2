#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#pragma once
class Camera {
public:
    Camera();

    Camera(string model, string brand, string matrixSize, string country,
        int pixels, string videoFormat, int price, int requests, int orders);

    string model;
    string brand;
    string matrixSize;
    string country;
    int pixels;
    string videoFormat;
    int price;
    int requests;
    int orders;

    void print();

    void write(ostream& f);
    void read(istream& f);
    void nullify();

private:
    static void writeStr(const string& s, ostream& f);

    static void writeInt(const int& i, ostream& f);

    static void readStr(string& s, istream& f);

    static void readInt(const int& i, istream& f);
};