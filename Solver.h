#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <unordered_set>
#include "Resistor.h"
#include "CurrentSource.h"
#include "VoltageSource.h"




class Solver {


private:
    int numNodes;
    Eigen::MatrixXd G;
    Eigen::VectorXd I;
    Eigen::VectorXd V;
    std::unordered_set<int> uniqueNodes;

    std::vector<Component*> components;
    std::vector<Resistor*> resistors;
    std::vector<VoltageSource*> Voltages;
    std::vector<CurrentSource*> Currents;

    void updateNodeCount(Component* component);
    bool isValidSystem() const;
    bool isValidIndex(int index) const;
    void printSystem() const;


public:
    Solver();
    void addComponent(Component* component);
    void solve();
    double getVoltage(int node) const;
    //double getCurrent(int componentIndex);
    int getNumNodes() const;
    //void clearResistors();// Print the conductance matrix and current vector
    void printV() const;

    Eigen::MatrixXd getG();
    Eigen::MatrixXd getI();

    void stamp();

};

#endif
