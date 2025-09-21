#include "traindriver.h"
#include <algorithm>

// Definition der statischen Variablen
std::vector<Traindriver*> Traindriver::allDrivers;

Traindriver::Traindriver(const std::string& name, double experience) 
    : name(name), experience(experience) {
    allDrivers.push_back(this);
}

Traindriver::~Traindriver() {
    // Entfernen aus der statischen Liste
    auto it = std::find(allDrivers.begin(), allDrivers.end(), this);
    if (it != allDrivers.end()) {
        allDrivers.erase(it);
    }
}

std::string Traindriver::getName() const {
    return name;
}

double Traindriver::getExperience() const {
    return experience;
}

void Traindriver::setName(const std::string& name) {
    this->name = name;
}

void Traindriver::setExperience(double experience) {
    this->experience = experience;
}

void Traindriver::deleteAll() {
    for (Traindriver* driver : allDrivers) {
        delete driver;
    }
    allDrivers.clear();
}

const std::vector<Traindriver*>& Traindriver::getAllDrivers() {
    return allDrivers;
}