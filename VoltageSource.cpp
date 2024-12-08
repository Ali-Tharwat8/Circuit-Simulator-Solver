#include "VoltageSource.h"

int VoltageSource::voltageSourceCount = 0;


VoltageSource::VoltageSource(int n1, int n2, double v, int idx) : Component(n1, n2), voltage(v)
{
    this->setCurrentIndex(idx);
    ++voltageSourceCount;
}

void VoltageSource::setVoltage(double v)
{
    voltage = v;
}

double VoltageSource::getVoltage() const 
{
    return voltage;
}

int VoltageSource::getVoltageSourceCount()
{
    return voltageSourceCount;
}

void VoltageSource::setCurrentIndex(int idx)
{
    if (idx > 0)
        currentIndex = idx;
    else
        idx = -1;
}

int VoltageSource::getCurrentIndex() const 
{
    return currentIndex;
}

string VoltageSource::getType() const
{
    return "VoltageSource";
}

void VoltageSource::stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) {

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
    I(idx - 1) = voltage;
}

void VoltageSource::displayVoltageSource()
{
    cout << "V(" << getNode1() << ", " << getNode2() << ", " << getVoltage() << ")\n";
}

void VoltageSource::display_VC_I()
{
    // Same Suggestion as in Resistor Display Function :)
    cout << "V(" << getNode1() << ", " << getNode2() << ", " << getVoltage() << ")" << "\t I = " << getI() << "\n";
}

VoltageSource::~VoltageSource()
{
    {
        --voltageSourceCount;
    }
}