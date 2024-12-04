#pragma once
#include "Component.h"


class CurrentSource : public Component
{
    double current;
    static int currentsourcecount;

public:
    CurrentSource(int n1, int n2, double i);
    double getCurrent() const;
    void setCurrent(double i);
    std::string getType() const;
    void stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) override;
    static int getcurrentcount();
    ~CurrentSource();
    
};
