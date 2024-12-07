#include "Solver.h"

Solver::Solver() : numNodes(0), V(Eigen::VectorXd())
{
    G.setZero();
    I.setZero();
}

void Solver::updateNodeCount(Component* component)
{
    if (component)
    {
        if (component->getNode1() != 0)
            uniqueNodes.insert(component->getNode1());
        if (component->getNode2() != 0)
            uniqueNodes.insert(component->getNode2());
        /*if (component->getNode1() == 0 || component->getNode2() == 0)
            Ground = true;*/
    }
}

bool Solver::isValidSystem() const 
{
    return (G.rows() == G.cols()) && (G.rows() == I.size()) && (numNodes > 0);
}

void Solver::addComponent(Component* component) 
{
    if (component) 
    {
        updateNodeCount(component);
        components.push_back(component);


        if (auto* resistor = dynamic_cast<Resistor*>(component)) 
        {
            resistors.push_back(resistor);
        }
        else if (auto* voltageSource = dynamic_cast<VoltageSource*>(component)) 
        {
            Voltages.push_back(voltageSource);
        }
        else if (auto* currentSource = dynamic_cast<CurrentSource*>(component)) 
        {
            Currents.push_back(currentSource);
        }
        else if (auto* wire = dynamic_cast<Wire*>(component))
        {
            Wires.push_back(wire);
        }

        int newNumNodes = uniqueNodes.size();
        int numVoltages = Voltages.size();
        int numWires = Wires.size();

        if (newNumNodes + numVoltages > numNodes) 
        {
            int newSize = newNumNodes + numVoltages + numWires;
            G.conservativeResize(newSize, newSize);
            I.conservativeResize(newSize);

            G.block(numNodes, 0, newSize - numNodes, newSize).setZero();
            G.block(0, numNodes, newSize, newSize - numNodes).setZero();
            I.segment(numNodes, newSize - numNodes).setZero();

            numNodes = newNumNodes;
        }
    }
}


void Solver::solve()
{
    if (isValidSystem()) 
    {
        if (getG().determinant() != 0)
        {
            V = G.colPivHouseholderQr().solve(I);
            /*this->zeroV();*/
        }
        else
            std::cout << "\n No solution";
    } 
    else
        std::cout << "\n Not valid system";
}


void Solver::printSystem() const
{
    std::cout << "Matrix G (Conductance matrix):\n" << G << std::endl;
    std::cout << "Vector I (Current vector):\n" << I << std::endl << "_______________________________________________________________\n";
}

void Solver::printV()
{
    getCurrent();

    for (int i = 1; i <= numNodes; i++)
    {
        std::cout << "Voltage at node \"" << i << "\" = " << getVoltage(i) << "\n";
    }

    for (int i = 0; i < resistors.size(); i++)
    {
        resistors.at(i)->display_R_I();
    }
    for (int i = 0; i < Voltages.size(); i++)
    {
        Voltages.at(i)->display_VC_I();
    }
    for (int i = 0; i < Currents.size(); i++)
    {
        Currents.at(i)->displayCurrentSource();
    }
    for (int i = 0; i < Wires.size(); i++)
    {
        Wires.at(i)->display_W_I();
    }
}



Eigen::MatrixXd Solver::getG()
{
    return G;
}

Eigen::MatrixXd Solver::getI()
{
    return I;
}

void Solver::stamp()
{
    for (int i = 0; i < Voltages.size(); i++)
    {
        Voltages.at(i)->setCurrentIndex(numNodes + 1 + i);
    }

    for (int i = 0; i < Wires.size(); i++)
    {
        Wires.at(i)->setCurrentIndex(numNodes + Voltages.size() + 1 + i);
    }

    for (int i = 0; i < components.size(); i++)
    {
        components[i]->stamp(G, I);
        printSystem();
    }
}




double Solver::getVoltage(int node) const 
{

    if(isValidIndex(node) && V.size() != 0)
        return V(node - 1);
}



bool Solver::isValidIndex(int index) const 
{
    return index >= 0 && index <= numNodes;
}

int Solver::getNumNodes() const 
{
    return numNodes;
}

void Solver::zeroV()
{
    for (int i = 0; i < getMatrixSize(); i++)
    {
        if (abs(V(i)) < .00001)
            V(i) = 0;
    }
}

int Solver::getMatrixSize()
{
    return numNodes + Voltages.size() + Wires.size();
}

void Solver::getCurrent()
{
    double I;
    int j = 0;
    std::cout << "\n";
    for (int i = 0; i < resistors.size(); i++)
    {   
        if(resistors.at(i)->getNode1() != 0 && resistors.at(i)->getNode2() != 0)
        {
            I = (getVoltage(resistors.at(i)->getNode1()) - getVoltage(resistors.at(i)->getNode2())) / resistors.at(i)->getResistance();
            resistors.at(i)->setI(I);
        }
        else
        {
            if (resistors.at(i)->getNode1() == 0)
            {
                I = -getVoltage(resistors.at(i)->getNode2()) / resistors.at(i)->getResistance();
                resistors.at(i)->setI(I);
            }
            else
            {
                I = getVoltage(resistors.at(i)->getNode1()) / resistors.at(i)->getResistance();
                resistors.at(i)->setI(I);
            }

        }
    }
    std::cout << "\n";

    for (int i = 0; i < Voltages.size(); i++)
    {
        Voltages.at(i)->setI(-(V(numNodes + i)));
    }
    std::cout << "\n";

    for (int i = 0; i < Wires.size(); i++)
    {
        Wires.at(i)->setI(-(V(numNodes + Voltages.size() + i)));
    }
}
