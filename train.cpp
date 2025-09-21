#include "train.h"

Train::Train() : driver(nullptr) {}

void Train::addLocomotive(const Locomotive& locomotive) {
    locomotives.push_back(locomotive);
}

void Train::removeLocomotive(int index) {
    if (index >= 0 && index < static_cast<int>(locomotives.size())) {
        locomotives.erase(locomotives.begin() + index);
    }
}

const std::vector<Locomotive>& Train::getLocomotives() const {
    return locomotives;
}

void Train::assignDriver(Traindriver* traindriver) {
    this->driver = traindriver;
}

void Train::removeDriver() {
    this->driver = nullptr;
}

Traindriver* Train::getDriver() const {
    return driver;
}

double Train::getBasePower() const {
    double totalPower = 0.0;
    for (const auto& locomotive : locomotives) {
        totalPower += locomotive.getPower();
    }
    return totalPower;
}

double Train::getTotalPower() const {
    double basePower = getBasePower();
    
    // Wenn ein Zugführer zugewiesen ist, wird die Zugkraft basierend auf dessen Erfahrung angepasst
    if (driver != nullptr) {
        double experienceBonus = driver->getExperience();
        // Die Erfahrung wirkt als Multiplikator (z.B. 1.2 für 20% Bonus)
        return basePower * (1.0 + experienceBonus);
    }
    
    return basePower;
}