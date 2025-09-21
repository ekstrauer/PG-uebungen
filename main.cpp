#include <iostream>
#include <vector>
#include <string>
#include "train.h"
#include "locomotive.h"
#include "traindriver.h"

using namespace std;

void displayMenu() {
    cout << "\n=== Zugsystem Verwaltung ===" << endl;
    cout << "1. Zug erstellen" << endl;
    cout << "2. Lokomotive zu Zug hinzufügen" << endl;
    cout << "3. Zugführer erstellen" << endl;
    cout << "4. Zugführer zu Zug zuweisen" << endl;
    cout << "5. Zugkraft anzeigen" << endl;
    cout << "6. Alle Zugführer anzeigen" << endl;
    cout << "7. Alle Zugführer löschen" << endl;
    cout << "8. Zugführer von Zug entfernen" << endl;
    cout << "0. Beenden" << endl;
    cout << "Wählen Sie eine Option: ";
}

void createTraindriver() {
    string name;
    double experience;
    
    cout << "Name des Zugführers: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Erfahrung (Dezimalzahl, z.B. 0.2 für 20% Bonus): ";
    cin >> experience;
    
    Traindriver* newDriver = new Traindriver(name, experience);
    cout << "Zugführer '" << name << "' mit Erfahrung " << experience << " wurde erstellt." << endl;
}

void displayAllDrivers() {
    const auto& drivers = Traindriver::getAllDrivers();
    
    if (drivers.empty()) {
        cout << "Keine Zugführer vorhanden." << endl;
        return;
    }
    
    cout << "\n=== Alle Zugführer ===" << endl;
    for (size_t i = 0; i < drivers.size(); ++i) {
        cout << i + 1 << ". " << drivers[i]->getName() 
             << " (Erfahrung: " << drivers[i]->getExperience() << ")" << endl;
    }
}

int main() {
    vector<Train> trains;
    int choice;
    
    cout << "Willkommen im Zugsystem!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                trains.emplace_back();
                cout << "Neuer Zug erstellt. Zug #" << trains.size() << endl;
                break;
            }
            
            case 2: {
                if (trains.empty()) {
                    cout << "Zuerst muss ein Zug erstellt werden." << endl;
                    break;
                }
                
                cout << "Zug auswählen (1-" << trains.size() << "): ";
                int trainIndex;
                cin >> trainIndex;
                
                if (trainIndex < 1 || trainIndex > static_cast<int>(trains.size())) {
                    cout << "Ungültiger Zug." << endl;
                    break;
                }
                
                cout << "Zugkraft der Lokomotive: ";
                double power;
                cin >> power;
                
                trains[trainIndex - 1].addLocomotive(Locomotive(power));
                cout << "Lokomotive mit Zugkraft " << power << " zu Zug #" << trainIndex << " hinzugefügt." << endl;
                break;
            }
            
            case 3: {
                createTraindriver();
                break;
            }
            
            case 4: {
                if (trains.empty()) {
                    cout << "Zuerst muss ein Zug erstellt werden." << endl;
                    break;
                }
                
                displayAllDrivers();
                const auto& drivers = Traindriver::getAllDrivers();
                
                if (drivers.empty()) {
                    cout << "Keine Zugführer verfügbar." << endl;
                    break;
                }
                
                cout << "Zug auswählen (1-" << trains.size() << "): ";
                int trainIndex;
                cin >> trainIndex;
                
                if (trainIndex < 1 || trainIndex > static_cast<int>(trains.size())) {
                    cout << "Ungültiger Zug." << endl;
                    break;
                }
                
                cout << "Zugführer auswählen (1-" << drivers.size() << "): ";
                int driverIndex;
                cin >> driverIndex;
                
                if (driverIndex < 1 || driverIndex > static_cast<int>(drivers.size())) {
                    cout << "Ungültiger Zugführer." << endl;
                    break;
                }
                
                trains[trainIndex - 1].assignDriver(drivers[driverIndex - 1]);
                cout << "Zugführer '" << drivers[driverIndex - 1]->getName() 
                     << "' zu Zug #" << trainIndex << " zugewiesen." << endl;
                break;
            }
            
            case 5: {
                if (trains.empty()) {
                    cout << "Zuerst muss ein Zug erstellt werden." << endl;
                    break;
                }
                
                cout << "Zug auswählen (1-" << trains.size() << "): ";
                int trainIndex;
                cin >> trainIndex;
                
                if (trainIndex < 1 || trainIndex > static_cast<int>(trains.size())) {
                    cout << "Ungültiger Zug." << endl;
                    break;
                }
                
                const Train& selectedTrain = trains[trainIndex - 1];
                cout << "\n=== Zug #" << trainIndex << " Information ===" << endl;
                cout << "Anzahl Lokomotiven: " << selectedTrain.getLocomotives().size() << endl;
                cout << "Basis-Zugkraft: " << selectedTrain.getBasePower() << endl;
                cout << "Gesamt-Zugkraft: " << selectedTrain.getTotalPower() << endl;
                
                if (selectedTrain.getDriver() != nullptr) {
                    cout << "Zugführer: " << selectedTrain.getDriver()->getName() 
                         << " (Erfahrung: " << selectedTrain.getDriver()->getExperience() << ")" << endl;
                } else {
                    cout << "Kein Zugführer zugewiesen." << endl;
                }
                break;
            }
            
            case 6: {
                displayAllDrivers();
                break;
            }
            
            case 7: {
                Traindriver::deleteAll();
                // Alle Zugführer-Zuweisungen in Zügen entfernen
                for (auto& train : trains) {
                    train.removeDriver();
                }
                cout << "Alle Zugführer wurden gelöscht." << endl;
                break;
            }
            
            case 8: {
                if (trains.empty()) {
                    cout << "Zuerst muss ein Zug erstellt werden." << endl;
                    break;
                }
                
                cout << "Zug auswählen (1-" << trains.size() << "): ";
                int trainIndex;
                cin >> trainIndex;
                
                if (trainIndex < 1 || trainIndex > static_cast<int>(trains.size())) {
                    cout << "Ungültiger Zug." << endl;
                    break;
                }
                
                trains[trainIndex - 1].removeDriver();
                cout << "Zugführer von Zug #" << trainIndex << " entfernt." << endl;
                break;
            }
            
            case 0: {
                cout << "Programm wird beendet..." << endl;
                break;
            }
            
            default: {
                cout << "Ungültige Option. Bitte versuchen Sie es erneut." << endl;
                break;
            }
        }
    } while (choice != 0);
    
    // Aufräumen: Alle Zugführer löschen
    Traindriver::deleteAll();
    
    return 0;
}