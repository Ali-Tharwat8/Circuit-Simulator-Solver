#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <unordered_set>
#include "Resistor.h"
#include "CurrentSource.h"
#include "VoltageSource.h"
#include "Wire.h"
#include <utility> // For std::pair

class Solver {
private:

    int numNodes;
    Eigen::MatrixXd G;
    Eigen::VectorXd I;
    Eigen::VectorXd V;
    unordered_set<int> uniqueNodes;
    bool Ground = 0;

    vector<Component*> components;
    vector<Resistor*> resistors;
    vector<VoltageSource*> Voltages;
    vector<CurrentSource*> Currents;
    vector<Wire*> Wires;

    void updateNodeCount(Component* component);
    bool isValidSystem() const;
    bool isValidIndex(int index) const;
    void printSystem() const;

public:

    Solver();

    Eigen::MatrixXd getG();
    Eigen::MatrixXd getI();
    int getMatrixSize();
    double getVoltage(int node) const;
    void getCurrent();
    int getNumNodes() const;

    void addComponent(Component* component);
    void stamp();
    void solve();
    void zeroV();
    
    void printV();
    //void noGroundSolution();

};
#endif
