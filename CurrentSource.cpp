#include "CurrentSource.h"

int CurrentSource::currentsourcecount = 0;

CurrentSource::CurrentSource(int n1, int n2, double i) : Component(n1, n2), current(i)
{
    currentsourcecount++;
}

void CurrentSource::setCurrent(double i)
{
    current = i;
}

double CurrentSource::getCurrent() const 
{
    return current;
}

int CurrentSource::getcurrentcount()
{
    return currentsourcecount;
}

string CurrentSource::getType() const
{
    return "CurrentSource";
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

void CurrentSource::displayCurrentSource()
{
    // Same suggestion as before :)
    cout << "I(" << getNode1() << ", " << getNode2() << ", " << getCurrent() << ")\n";
}

CurrentSource::~CurrentSource()
{
    currentsourcecount++;
}