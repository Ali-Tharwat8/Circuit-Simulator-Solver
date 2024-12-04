#include "VoltageSource.h"

int VoltageSource::voltageSourceCount = 0;


VoltageSource::VoltageSource(int n1, int n2, double v, int idx) : Component(n1, n2), voltage(v)
{
    this->setCurrentIndex(idx);
    ++voltageSourceCount;
}

VoltageSource::~VoltageSource() 
{
    {
        --voltageSourceCount;
    }
}

double VoltageSource::getVoltage() const 
{
    return voltage;
}

int VoltageSource::getCurrentIndex() const 
{
    return currentIndex;
}

void VoltageSource::setVoltage(double v) 
{
    voltage = v;
}

void VoltageSource::setCurrentIndex(int idx) 
{
    if (idx > 0)
        currentIndex = idx;
    else
        idx = -1;
}

int VoltageSource::getVoltageSourceCount() 
{
    return voltageSourceCount;
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

std::string VoltageSource::getType() const 
{
    return "VoltageSource";
}

