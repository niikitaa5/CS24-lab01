// Nikita Sharma A009T32
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

Car::Car(){
    manufacturer = nullptr;
    model = nullptr;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
    manufacturer = new char[strlen(manufacturerName) + 1];
    strcpy(manufacturer, manufacturerName);
    model = new char[strlen(modelName) + 1];
    strcpy(model, modelName);
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    backseatDoors = backseatDoorDesign;
    seatCount = numSeats;
}

Car::Car(Car const& o){
    manufacturer = new char[strlen(o.manufacturer) + 1];
    strcpy(manufacturer, o.manufacturer);
    model = new char[strlen(o.model) + 1];
    strcpy(model, o.model);
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    backseatDoors = o.backseatDoors;
    seatCount = o.seatCount;
}

Car& Car::operator=(Car const& o) {
    if (this != &o) {
        delete[] manufacturer;
        manufacturer = new char[strlen(o.manufacturer) + 1];
        strcpy(manufacturer, o.getManufacturer());
        delete[] model;
        model = new char[strlen(o.model) + 1];
        strcpy(model, o.getModel());
        struct PerformanceStats oStats = o.getStats();
        zeroToSixtyNs = oStats.zeroToSixtyNs;
        headonDragCoeff = oStats.headonDragCoeff;
        horsepower = oStats.horsepower;
        backseatDoors = o.getBackseatDoors();
        seatCount = o.getSeatCount();
    }
    return *this;
}


Car::~Car() {
    delete[] manufacturer;
    delete[] model;
}


char const* Car::getManufacturer() const{
    return manufacturer;
}

char const* Car::getModel() const {
    return model;
}

PerformanceStats Car::getStats() const {
    return PerformanceStats{horsepower, zeroToSixtyNs, headonDragCoeff}; 
}

uint8_t Car::getSeatCount() const {
    return seatCount;
}

DoorKind Car::getBackseatDoors() const{
    return backseatDoors;
};

void Car::manufacturerChange(char const* const newManufacturer) {
    manufacturer = new char[strlen(newManufacturer) + 1];
    strcpy(manufacturer, newManufacturer);
};

void Car::modelNameChange(char const* const newModelName) {
    model = new char[strlen(newModelName) + 1];
    strcpy(model, newModelName);
};

void Car::reevaluateStats(PerformanceStats newStats) {
    horsepower = newStats.horsepower;
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
};

void Car::recountSeats(uint8_t newSeatCount) {
    seatCount = newSeatCount;
};

void Car::reexamineDoors(DoorKind newDoorKind) {
    backseatDoors = newDoorKind;
};


// int main() {
//     struct PerformanceStats p = {5,10,15};
//     char const* const manu = "Ford";
//     char const* const mod = "Thunderbird";
//     Car *c1 = new Car();
//     c1->modelNameChange(mod);
//     c1->manufacturerChange(manu);
//     string str = c1->getModel();
//     string str2 = c1->getManufacturer();
//     cout << str << endl << str2 << endl;
//     delete c1;

//     c1.recountSeats(3);
//     c1.reexamineDoors(Sliding);
//     int x = c1.getSeatCount();
//     int y = c1.getBackseatDoors();
//     cout << x << endl << y << endl;

//     Car c2(c1);
//     x = c2.getSeatCount();
//     y = c2.getBackseatDoors();
//     cout << x << endl << y << endl;

//     Car c3(c1.getModel(), c1.getManufacturer(), p, 2, Hinge);
//     string str3 = c3.getModel();
//     string str4 = c3.getManufacturer();
//     cout << str3 << endl << str4 << endl;

//     struct PerformanceStats q = c3.getStats();
//     cout << q.horsepower << endl << q.zeroToSixtyNs << endl << q.headonDragCoeff << endl;
//     struct PerformanceStats r = {1,2,3};
//     c3.reevaluateStats(r);
//     struct PerformanceStats s = c3.getStats();
//     cout << s.horsepower << endl << s.zeroToSixtyNs << endl << s.headonDragCoeff << endl;

//     Car c4 = c1;
//     x = c4.getSeatCount();
//     y = c4.getBackseatDoors();
//     cout << x << endl << y << endl;
// }
