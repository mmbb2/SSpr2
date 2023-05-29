#include <fstream>
#include <iostream>
#include <vector>
#include "Camera.h"

using namespace std;

Camera::Camera(){
    model = "";
    brand = "";
    matrixSize = "";
    country = "";
    pixels = 0;
    videoFormat = "";
    price = 0;
    requests = 0;
    orders = 0;
}

Camera::Camera(string model, string brand, string matrixSize, string country, int pixels, string videoFormat, int price, int requests, int orders)
{
    this->model = model;
    this->matrixSize = matrixSize;
    this->country = country;
    this->pixels = pixels;
    this->videoFormat = videoFormat;
    this->price = price;
    this->requests = requests;
    this->orders = orders;
}

void Camera::print()
{
    cout << "Модель " << model << " Бренд " << brand << " Розмір матриці "
        << matrixSize << " Країна виробника " << country
        << " Кількість пікселів " << pixels << " Формат відео " << videoFormat
        << " Ціна " << price << " Запити " << requests << " Замовлення "
        << orders << endl;
}

void Camera::write(ostream& f)
{
    writeStr(model, f);
    writeStr(brand, f);
    writeStr(matrixSize, f);
    writeStr(country, f);
    writeInt(pixels, f);
    writeStr(videoFormat, f);
    writeInt(price, f);
    writeInt(requests, f);
    writeInt(orders, f);
}

void Camera::read(istream& f)
{
    readStr(model, f);
    readStr(brand, f);
    readStr(matrixSize, f);
    readStr(country, f);
    readInt(pixels, f);
    readStr(videoFormat, f);
    readInt(price, f);
    readInt(requests, f);
    readInt(orders, f);
}

void Camera::nullify()
{
    model = "";
    brand = "";
    matrixSize = "";
    country = "";
    pixels = 0;
    videoFormat = "";
    price = 0;
    requests = 0;
    orders = 0;
}

void Camera::writeStr(const string& s, ostream& f)
{
    int l = s.length();
    f.write((char*)&l, sizeof(int));
    for (int i = 0; i < s.length(); i++) {
        f.write((char*)&s[i], sizeof(s[i]));
    }
}

void Camera::writeInt(const int& i, ostream& f)
{
    f.write((char*)&i, sizeof(int));
}

void Camera::readStr(string& s, istream& f)
{
    int l;
    f.read((char*)&l, sizeof(int));

    char c;
    for (int i = 0; i < l; i++) {
        f.read((char*)&c, sizeof(c));
        s += c;
    }
}

void Camera::readInt(const int& i, istream& f)
{
    f.read((char*)&i, sizeof(int));
}


//Camera c1("gt-75", "Canon", "1/4", "Japan", 48000000, "raw", 930, 240, 100);
//Camera c2("M50", "Canon", "1/3", "Japan", 24000000, "raw", 1150, 457, 23);
//Camera c3("Ol5", "Nikon", "1/2.8", "Japan", 54000000, "raw", 950, 783, 343);
//Camera c4("Kw8", "Panasonic", "1/4", "Japan", 18000000, "raw", 750, 873, 243);
//Camera c5("LiY4", "Fujifilm ", "1/2", "Japan", 32000000, "raw", 800, 387,
//    120);
//Camera c6("Alpha5", "Sony", "1/2.2", "Japan", 20000000, "raw", 1200, 783,
//    235);
//Camera c7("Alpha7", "Sony", "1/2.4", "Japan", 94000000, "raw", 1000, 277,
//    354);
//Camera c8("Alpha2", "Sony", "1/3", "Japan", 41000000, "raw", 950, 725, 634);
//Camera c9("Alpha5", "Sony", "1/2.6", "Japan", 64000000, "raw", 800, 275, 150);

 //c1.write(fs);
 //c2.write(fs);
 //c3.write(fs);
 //c4.write(fs);
 //c5.write(fs);
 //c6.write(fs);
 //c7.write(fs);
 //c8.write(fs);
 //c9.write(fs);