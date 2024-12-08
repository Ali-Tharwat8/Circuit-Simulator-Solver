#pragma once
#include "VoltageSource.h"

class Wire : public Component
{
private:

    static int WireCount;
    double voltage;
    int currentIndex;

public:

    Wire(int n1 = -1, int n2 = -1 , int v = 0 , int idx = 0);
    ~Wire();

    void setCurrentIndex(int idx);
    int getCurrentIndex() const;
    static int getWireCount();
    string getType() const override;

    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    void displayWire();
    void display_W_I();
};
