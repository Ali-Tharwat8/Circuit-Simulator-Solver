#pragma once
#include "Component.h"

class VoltageSource : public Component 
{
    double voltage;         
    int currentIndex;        
    static int voltageSourceCount;

public:
    VoltageSource(int n1 = -1, int n2 = -1, double v = 0.0, int idx = -1);
    ~VoltageSource();

    double getVoltage() const;
    int getCurrentIndex() const;

    void setVoltage(double v);
    void setCurrentIndex(int idx);

    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    static int getVoltageSourceCount();

    std::string getType() const override;

    void displayVoltageSource();
    void display_VC_I();
};
