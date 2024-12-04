#include "CurrentSource.h"

int CurrentSource::currentsourcecount = 0;
// Constructor
CurrentSource::CurrentSource(int n1, int n2, double i) : Component(n1, n2), current(i)
{
    currentsourcecount++;
}


double CurrentSource::getCurrent() const 
{
    return current;
}

void CurrentSource::setCurrent(double i) 
{
    current = i;
}

void CurrentSource::stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) {
    int n1 = getNode1();
    int n2 = getNode2();
    if (n1 <= G.rows() && n2 <= G.rows())
    { 
        if (n1 == 0 || n2 == 0)
        {
            if (n1 == 0)
                I[n2 - 1] += current;
            else
                I[n1 - 1] -= current;
        }
        else
        {
            if (n1 >= 0)
            {
                I[n1 - 1] -= current;
            }
            if (n2 >= 0)
            {
                I[n2 - 1] += current;
            }
        }
    }
}

int CurrentSource::getcurrentcount()
{
    return currentsourcecount;
}

CurrentSource::~CurrentSource()
{
    currentsourcecount++;
}

std::string CurrentSource::getType() const
{
    return "CurrentSource";
}