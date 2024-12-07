#pragma once
#include "Component.h"

class Resistor : public Component 
{
private:
    double resistance;
    static int resistorCount;
public:
    Resistor(int n1, int n2, double r);
    ~Resistor();
    double getResistance() const;

    void setResistance(double r);

    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    std::string getType() const override;

    static int getResistorCount();
    void displayResistor();
    void display_R_I();

};
