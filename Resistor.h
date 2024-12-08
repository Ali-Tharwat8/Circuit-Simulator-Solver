#pragma once
#include "Component.h"

class Resistor : public Component 
{
private:

    double resistance;
    static int resistorCount;
public:

    // Constructor & Destructor
    Resistor(int n1, int n2, double r);
    ~Resistor();

    // Setters & Getters
    void setResistance(double r);
    double getResistance() const;
    static int getResistorCount();
    string getType() const override;
    
    // Stamping (Specified in Component Class)
    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    // Display Functions
    void displayResistor(); // Displays Resistor Information
    void display_R_I(); // Displays Resistor Info Along With Calculated Current

};
