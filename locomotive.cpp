#include "locomotive.h"

Locomotive::Locomotive(double power) : power(power) {}

double Locomotive::getPower() const {
    return power;
}

void Locomotive::setPower(double power) {
    this->power = power;
}