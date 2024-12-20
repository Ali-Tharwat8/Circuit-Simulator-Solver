#include "Resistor.h"

int Resistor::resistorCount = 0;

Resistor::Resistor(int n1, int n2, double r) : Component(n1, n2), resistance(1) 
{ 
    setResistance(r);
    ++resistorCount;
}

void Resistor::setResistance(double r)
{
    if (r > 0.0)
    {
        resistance = r;
    }
}

double Resistor::getResistance() const 
{
    return resistance;
}

int Resistor::getResistorCount()
{
    return resistorCount;
}

string Resistor::getType() const
{
    return "Resistor";
}

void Resistor::stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) 
{
    double conductance = 1.0 / resistance;
    int n1 = getNode1();
    int n2 = getNode2();

    if (n1 <= G.rows() && n2 <= G.rows() && n1 != n2)
    {
        if (n1 == 0 || n2 == 0)
        {
            if (n1 == 0)
                G(n2 - 1, n2 - 1) += conductance;
            else
                G(n1 - 1, n1 - 1) += conductance;
        }
        else
        {
            if (n1 > 0)
            {
                G(n1 - 1, n1 - 1) += conductance;
            }
            if (n2 > 0)
            {
                G(n2 - 1, n2 - 1) += conductance;
            }
            if (n1 > 0 && n2 > 0) {
                G(n1 - 1, n2 - 1) -= conductance;
                G(n2 - 1, n1 - 1) -= conductance;
            }
        }
    }
}

void Resistor::displayResistor()
{
    cout << "R(" << this->getNode1() << ", " << getNode2() << ", " << getResistance() << ")\n";
}

void Resistor::display_R_I()
{
    // Suggestion : Call displayResistor(); using Resolution Scope , then print I
    cout << "R(" << getNode1() << ", " << getNode2() << ", " << getResistance() << ")" << "\t I = " << getI() << "\n";
}

Resistor::~Resistor()
{
    if (resistorCount > 0)
    {
        --resistorCount;
    }
}