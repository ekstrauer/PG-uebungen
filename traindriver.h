#ifndef TRAINDRIVER_H
#define TRAINDRIVER_H

#include <string>
#include <vector>

class Traindriver {
private:
    std::string name;
    double experience; // Erfahrung als Dezimalzahl
    static std::vector<Traindriver*> allDrivers; // Statische Liste aller Zugführer

public:
    Traindriver(const std::string& name, double experience);
    ~Traindriver();
    
    // Getters
    std::string getName() const;
    double getExperience() const;
    
    // Setters
    void setName(const std::string& name);
    void setExperience(double experience);
    
    // Statische Methode zum Löschen aller Zugführer
    static void deleteAll();
    
    // Statische Methode zum Abrufen aller Zugführer
    static const std::vector<Traindriver*>& getAllDrivers();
};

#endif // TRAINDRIVER_H