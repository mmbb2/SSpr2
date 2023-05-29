#include <vector>
#include "Camera.h"
#include <fstream>
#include <iostream>

using namespace std;

#pragma once

vector<Camera> findPrice(vector<Camera> db, int price);

vector<Camera> findCountry(vector<Camera> db, string country);

vector<Camera> sort(vector<Camera> db);

vector<Camera> getTop(vector<Camera> db);

vector<Camera> editDb(vector<Camera>& db, ostream& f);

bool validateNumber(string str);