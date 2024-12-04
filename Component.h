#pragma once
#include <Eigen/Dense>
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

class Component {
protected:
    int node1, node2;      
    static int componentCount;

public:
    Component(int n1 = -1, int n2 = -1);
    virtual ~Component();
    int getNode1() const;
    int getNode2() const;
    static int getComponentCount();
    virtual std::string getType() const = 0;
    virtual void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) = 0;

private:

    bool validateNodes(int n1, int n2);
};
