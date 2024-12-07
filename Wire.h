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

    int getCurrentIndex() const;
    void setCurrentIndex(int idx);

    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    static int getWireCount();

    std::string getType() const override;

    void displayWire();
    void display_W_I();
};
