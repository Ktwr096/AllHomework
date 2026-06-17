#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Details {
    string engine;
    string color;
    int owners;
};

struct Car {
    string brand;
    string model;
    int year;
    float price;
    string bargain;
    Details data;
};

Car create_car(Car& c) {
    cout << "Brand/Model/Year/Price/Bargain(Yes/No): ";
    cin >> c.brand >> c.model >> c.year >> c.price >> c.bargain;
    return c;
}

void details(Details& d) {
    cout << "Engine/Color/Number of owners: ";
    cin >> d.engine >> d.color >> d.owners;
}

void stats(Car& c) {
    cout << left << setw(12) << c.brand << setw(12) << c.model << setw(8) << c.year << setw(10) << c.price << setw(10) << c.bargain << setw(10) << c.data.engine << setw(10) << c.data.color << setw(8) << c.data.owners << endl;
}

int main() {
    int amount;
    cout << "How much cars you have" << endl;
    cin >> amount;
    vector<Car> info(amount);

    cout << "Enter car info: brand, model, year, price, bargain, details" << endl;
    for (int i = 0; i < amount; ++i) {
        cout << "Num " << i + 1 << endl;
        create_car(info[i]);
        details(info[i].data);
        cout << endl;
    }

    cout << left << setw(6) << "No" << setw(12) << "brand" << setw(12) << "model" << setw(8) << "year" << setw(10) << "price" << setw(10) << "bargain" << setw(10) << "engine" << setw(10) << "color" << setw(8) << "owners" << endl;

    for (int i = 0; i < amount; ++i) {
        cout << left << setw(6) << i + 1;
        stats(info[i]);
    }
}