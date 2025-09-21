#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include <memory>
#include "locomotive.h"
#include "traindriver.h"

class Train {
private:
    std::vector<Locomotive> locomotives;
    Traindriver* driver; // Optionaler Zugführer (kann nullptr sein)

public:
    Train();
    ~Train() = default;
    
    // Lokomotiven-Management
    void addLocomotive(const Locomotive& locomotive);
    void removeLocomotive(int index);
    const std::vector<Locomotive>& getLocomotives() const;
    
    // Zugführer-Management
    void assignDriver(Traindriver* traindriver);
    void removeDriver();
    Traindriver* getDriver() const;
    
    // Berechnung der Gesamtzugkraft (angepasst basierend auf Zugführer-Erfahrung)
    double getTotalPower() const;
    
    // Basis-Zugkraft ohne Erfahrungsbonus
    double getBasePower() const;
};

#endif // TRAIN_H