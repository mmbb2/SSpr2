#include <fstream>
#include <iostream>
#include <vector>
#include "Camera.h"
#include "ExtraFuncs.h"
#include <string> 
#include <Windows.h>

using namespace std;

void printDb(vector<Camera> db) {
    cout << endl << "Результат:" << endl << endl;
    for (int i = 0; i < db.size(); i++) {
        db[i].print();
    }
    cout << endl;
}

//Новий коментар
//Новий коментар 2

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string path = "text.txt";

    fstream fs;

    cout << "Введіть ім'я файла" << endl;

    cin >> path;

    fs.open(path, fstream::in | fstream::out);
    if (!fs.is_open()) {
        cout << "Помилка відкриття файлу" << endl;
        return 0;
    }

    fs.close();

    fs.open(path, fstream::in | fstream::out | fstream::app | fstream::binary);



    fs.close();

    fs.open(path, fstream::in | fstream::out | fstream::app | fstream::binary);

    fs.seekg(0, fs.end);
    int eof = fs.tellg();
    fs.seekg(0, fs.beg);

    vector<Camera> db;

    Camera tmp;

    while (fs.tellg() <= eof) {

        tmp.read(fs);
        db.push_back(tmp);
        tmp.nullify();
        if (fs.tellg() >= eof)
            break;
    }
    fs.close();

    printDb(db);

    //fs.open(path, fstream::in | fstream::out | fstream::binary);
    //editDb(db, fs);
    //fs.close();
    //printDb(db);

    while (true)
    {

        int field = 0;

        cout << "Виберіть дію ввівши відповідне число" << endl
            << "1 - Пошук моделей фотоапаратів за ціною" << endl
            << "2 - Пошук моделей фотоапаратів за країною виробника" << endl
            << "3 - Визначення найпопулярніших моделей фотоапаратів" << endl
            << "4 - Редагувати дані" << endl;

            while ((field < 1) || (field > 4))
            {
                cin >> field;
            }

            string input = "a";
            vector<Camera> res;
            fs.open(path, fstream::in | fstream::out | fstream::binary);

            switch (field) {
            case 1:

                cout << "Введіть максимальну ціну" << endl;

                while (!validateNumber(input))
                {
                    cin >> input;
                }
                
                res = findPrice(db, stoi(input));
                
                res = sort(res);
                printDb(res);
                break;
            case 2:
                cout << "Введіть країну" << endl;
                 cin >> input;
                res = findCountry(db, input);
                
                if (res.size() > 0) {
                    res = sort(res);
                    printDb(res);
                }
                else {
                    cout << "Фотоапаратів цієї країни не знайдено" << endl;
                }


                break;
            case 3:
                res = getTop(db);
                printDb(res);
                break;
            case 4:
                editDb(db,fs);
                printDb(db);
                break;
            default:
                break;
            }
            input = "a";
            res.clear();
            fs.close();
    }

}

