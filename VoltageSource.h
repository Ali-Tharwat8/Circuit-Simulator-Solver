#pragma once
#include "Component.h"

class VoltageSource : public Component 
{
    double voltage;         
    int currentIndex;        
    static int voltageSourceCount;

public:

    // Constructor & Destructor
    VoltageSource(int n1 = -1, int n2 = -1, double v = 0.0, int idx = -1);
    ~VoltageSource();


    // Setters & Getters
    void setVoltage(double v);
    double getVoltage() const;
    static int getVoltageSourceCount(); // Returns the number of Voltage Sources in order to adjust the Matrix Size

    void setCurrentIndex(int idx);      // Sets the index of the Voltage Source
    int getCurrentIndex() const;

    string getType() const override;

    // Stamping (as before)
    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    // Display Functions (as before)
    void displayVoltageSource();
    void display_VC_I();
};
