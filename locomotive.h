#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H

class Locomotive {
private:
    double power; // Zugkraft

public:
    Locomotive(double power);
    double getPower() const;
    void setPower(double power);
};

#endif // LOCOMOTIVE_H