#include <vector>
#include "Camera.h"
#include "ExtraFuncs.h"
#include <string> 
#include <fstream>
#include <iostream>

using namespace std;

vector<Camera> findPrice(vector<Camera> db, int price)
{
	vector<Camera> finded;

	if (price <= 0) {
		return db;
	}

	for (int i = 0; i < db.size(); i++) {
		if (db[i].price <= price) {
			finded.push_back(db[i]);
		}
	}

	return finded;
}

vector<Camera> findCountry(vector<Camera> db, string country)
{
	vector<Camera> finded;


	for (int i = 0; i < db.size(); i++) {
		if (db[i].country.compare(country) == 0) {
			finded.push_back(db[i]);
		}
	}

	return finded;
}

vector<Camera> sortPrice(vector<Camera> db)
{
	for (int i = 0; i < db.size() - 1; i++) {
		for (int j = 0; j < db.size() - i - 1; j++) {
			if (db[j].price > db[j + 1].price) {
				auto temp = db[j];
				db[j] = db[j + 1];
				db[j + 1] = temp;
			}
		}
	}

	return db;
}

vector<Camera> sortName(vector<Camera> db)
{
	for (int i = 0; i < db.size() - 1; i++) {
		for (int j = 0; j < db.size() - i - 1; j++) {
			if (db[j].model.compare(db[j + 1].model) > 0) {
				auto temp = db[j];
				db[j] = db[j + 1];
				db[j + 1] = temp;
			}
		}
	}

	return db;
}

vector<Camera> sort(vector<Camera> db)
{
	int field = 0;
	cout << "������� �� ����� �������� �����" << endl
		<< "1 - ��������� �� �������" << endl
		<< "2 - ��������� �� ������" << endl;

	while ((field < 1) || (field > 2))
	{
		cin >> field;
	}

	if (field == 1) {
		return sortPrice(db);
	}
	else if (field == 2) {
		return sortName(db);
	}

	return vector<Camera>();
}

vector<Camera> topRequests(vector<Camera> db, int quantity)
{

	for (int i = 0; i < db.size() - 1; i++) {
		for (int j = 0; j < db.size() - i - 1; j++) {
			if (db[j].requests < db[j + 1].requests) {
				auto temp = db[j];
				db[j] = db[j + 1];
				db[j + 1] = temp;
			}
		}
	}

	vector<Camera> finded;

	for (int i = 0; i < quantity; i++) {
		finded.push_back(db[i]);
	}


	return finded;
}

vector<Camera> topOrders(vector<Camera> db, int quantity)
{
	for (int i = 0; i < db.size() - 1; i++) {
		for (int j = 0; j < db.size() - i - 1; j++) {
			if (db[j].orders < db[j + 1].orders) {
				auto temp = db[j];
				db[j] = db[j + 1];
				db[j + 1] = temp;
			}
		}
	}

	vector<Camera> finded;

	for (int i = 0; i < quantity; i++) {
		finded.push_back(db[i]);
	}


	return finded;
}

vector<Camera> getTop(vector<Camera> db)
{
	int field = 0;
	cout << "������� �� ����� �������� �����" << endl
		<< "1 - ������� ������������� ����� �� ��������"<< endl
		<< "2 - ������� ������������� ����� �� ������������" << endl;

	while ((field < 1) || (field > 2))
	{
		cin >> field;
	}


	string quantity = "a";
	cout << "������ ������� �������, �� ���������� �� �����" << endl;

	while (!validateNumber(quantity))
	{
		cin >> quantity;
	}

	if (field == 1) {
		return topRequests(db, stoi(quantity));
	}
	else if (field == 2) {
		return topOrders(db, stoi(quantity));
	}

	return vector<Camera>();
}


bool validateNumber(string str) {
	for (int i = 0; i < str.length(); i++) {

		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

int InputNumber() {
	string input = "a";

	cout << "������ ��������" << endl;


	cin >> input;

	while (!validateNumber(input))
	{
		cin >> input;
	}

	return stoi(input);

}

string InputString() {
	string input = "";

	cout << "������ ��������" << endl;

	cin >> input;
	return input;
}

string InputModel (vector<Camera> db, int index) {
	string input = "";
	bool validate = false;

	while (!validate)
	{
	cout << "������ ��������" << endl;

	cin >> input;

	validate = true;
	for (int i = 0; i < db.size(); i++) {
		if ((db[i].model.compare(input) == 0) && (index != i)) {
			validate = false;
		}
	}
	}

	return input;
}

vector<Camera> editDb(vector<Camera>& db, ostream& f)
{
	string model= "";
	int findedIndex = -1;

	while (findedIndex < 0) {

	cout << "������ ������ ��� �����������" << endl;
	cin.ignore();
	getline(cin,model);

	for (int i = 0; i < db.size(); i++) {
		if (db[i].model.compare(model) == 0) {
			findedIndex = i;
			break;
		}
	}
	}


	db[findedIndex].print();


	int field = 0;

	cout << "��� ���� ��������� ���� ������ �������� �����" << endl
		<< "1 - ������" << endl
		<< "2 - ��������" << endl
		<< "3 - ����� �������" << endl
		<< "4 - ����� �����������" << endl
		<< "5 - ʳ������ ������" << endl
		<< "6 - ������ ����" << endl
		<< "7 - �������" << endl
		<< "8 - ʳ������ ������" << endl
		<< "9 - ʳ������ ���������" << endl;


	while ((field < 1) || (field > 10))
	{
		cin >> field;
	}


	switch (field) {
	case 1:
		db[findedIndex].model = InputModel(db, findedIndex);
		break;
	case 2:
		db[findedIndex].brand = InputString();
		break;
	case 3:
		db[findedIndex].matrixSize = InputString();
		break;
	case 4:
		db[findedIndex].country = InputString();
		break;
	case 5:
		db[findedIndex].pixels = InputNumber();
		break;
	case 6:
		db[findedIndex].videoFormat = InputString();
		break;
	case 7:
		db[findedIndex].price = InputNumber();
		break;
	case 8:
		db[findedIndex].requests = InputNumber();
		break;
	case 9:
		db[findedIndex].orders = InputNumber();
		break;

	default:
		break;
	}

	cout << "³������������ �������: " << endl;

	db[findedIndex].print();

	for (int i = 0; i < db.size(); i++) {
		db[i].write(f);
	}

	return db;
}




