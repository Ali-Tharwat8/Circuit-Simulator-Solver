#include "Component.h"

int Component::componentCount = 0;

Component::Component(int n1, int n2)
{
    if (validateNodes(n1, n2))
    {
        node1 = n1;
        node2 = n2;
        ++componentCount;
    }
}

Component::~Component() 
{
    --componentCount;
}

int Component::getNode1() const 
{
    return node1;
}
int Component::getNode2() const 
{
    return node2;
}
int Component::getComponentCount() 
{
    return componentCount;
}

bool Component::validateNodes(int n1, int n2) {
    return n1 >= 0 && n2 >= 0 && n1 != n2;
}