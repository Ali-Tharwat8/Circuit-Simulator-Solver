#pragma once
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
using namespace std;

class Component {
protected:

    int node1, node2;      
    static int componentCount;
    double I;

public:

    // Constructor & Destructor
    Component(int n1 = -1, int n2 = -1);
    virtual ~Component();

    // Setters & Getters
    void setI(double i = 0);
    double getI();
    int getNode1() const;
    int getNode2() const;
    static int getComponentCount();         // Returns Number of Components
    virtual string getType() const = 0;     // Returns Type of Component (Virtual) (Implementation in Component Classes)

    // Stamping Component Information into Conductance & Current Matrices (Virtual)
    virtual void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) = 0;

private:
    // Ensures Node Values are Positive & Not Equal
    bool validateNodes(int n1, int n2);
};
