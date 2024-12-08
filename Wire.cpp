#include "Wire.h"
#include <iostream>

int Wire::WireCount = 0;

Wire::Wire(int n1, int n2, int v, int idx) : Component(n1, n2) 
{
    // WARNING : currentIndex is uninitialized
    // currentIndex = idx;
    WireCount++;
}

void Wire::setCurrentIndex(int idx)
{
    currentIndex = idx;
}

int Wire::getCurrentIndex() const
{
    return currentIndex;
}

int Wire::getWireCount()
{
    return WireCount;
}

string Wire::getType() const {
    return "Wire";
}

void Wire::stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) {

    int n1 = getNode1();
    int n2 = getNode2();

    int idx = getCurrentIndex();

    if (n1 == 0 || n2 == 0)
    {
        if (n1 == 0)
        {
            G(n2 - 1, idx - 1) += 1.0;
            G(idx - 1, n2 - 1) += 1.0;
        }
        else
        {
            G(n1 - 1, idx - 1) -= 1.0;
            G(idx - 1, n1 - 1) -= 1.0;
        }
    }
    else
    {
        if (n1 > 0)
        {
            G(n1 - 1, idx - 1) -= 1.0;
            G(idx - 1, n1 - 1) -= 1.0;
        }

        if (n2 > 0) {
            G(n2 - 1, idx - 1) += 1.0;
            G(idx - 1, n2 - 1) += 1.0;
        }
    }
    I(idx - 1) = 0;
}

void Wire::displayWire()
{
    cout << "W(" << getNode1() << ", " << getNode2() << ")\n";
}

void Wire::display_W_I()
{
    cout << "W(" << getNode1() << ", " << getNode2() << ")" << "\t I = " << getI() << "\n";
}

Wire::~Wire()
{
    WireCount--;
}