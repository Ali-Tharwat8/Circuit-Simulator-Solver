#pragma once
#include "Component.h"


class CurrentSource : public Component
{
    double current;
    static int currentsourcecount;

public:

    CurrentSource(int n1, int n2, double i);
    ~CurrentSource();

    void setCurrent(double i);
    double getCurrent() const;
    static int getcurrentcount();
    string getType() const;

    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;

    void displayCurrentSource();
    
};
