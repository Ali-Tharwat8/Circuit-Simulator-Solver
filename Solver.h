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
    std::unordered_set<int> uniqueNodes;
    bool Ground = 0;

    std::vector<Component*> components;
    std::vector<Resistor*> resistors;
    std::vector<VoltageSource*> Voltages;
    std::vector<CurrentSource*> Currents;
    std::vector<Wire*> Wires;

    void updateNodeCount(Component* component);
    bool isValidSystem() const;
    bool isValidIndex(int index) const;
    void printSystem() const;


public:
    Solver();
    void addComponent(Component* component);
    void solve();
    double getVoltage(int node) const;
    void getCurrent();
    int getNumNodes() const;
    void printV();
    void zeroV();
    //void noGroundSolution();
    int getMatrixSize();

    Eigen::MatrixXd getG();
    Eigen::MatrixXd getI();

    void stamp();
};



#endif
