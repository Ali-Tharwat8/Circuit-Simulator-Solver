#include "Solver.h"

void simulateGUIInput(Solver& solver);


int main() 
{

    
    /*std::cout << "\nAfter stamping the resistor1:\n";
    Resistor R1(1, 2, 3);
    R1.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    std::cout << "\nAfter stamping the resistor2:\n";
    Resistor R2(2, 0, 1);
    R2.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    std::cout << "\nAfter stamping the resistor3:\n";
    Resistor R3(2, 0, 4);
    R3.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    std::cout << "\nAfter stamping the resistor4:\n";
    Resistor R4(0, 1, 5);
    R4.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";*/

    
    /*Resistor R1(-1, 5, -5);
    R1.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    Resistor R5(-1, -2, 5);
    R5.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    Resistor R2(-1, 5, 5);
    R2.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";
    
    Resistor R3(0, 1, -5);
    R3.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    Resistor R4(0, 2, 5);
    R4.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";*/

    /*CurrentSource I1(0, 1, -5);
    I1.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";
    CurrentSource I2(1, 0, 2);
    I2.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";*/

    /*CurrentSource I1(0, 2, -5);
    I1.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";
    CurrentSource I2(-1, 3, 2);
    I2.stamp(G, I);
    CurrentSource I3(0, 1, -5.2);
    I3.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";
    CurrentSource I4(4, 0, 2.5);
    I4.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";*/

    /*Resistor R1(1, 2, 1);
    R1.stamp(G, I);
    std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";*/


    //Resistor R1(0, 4, 3);
    //Resistor R2(0, 1, 1);
    //Resistor R3(0, 4, 4);
    //Resistor R4(0, 0, 5);
    //Resistor R5(1, 2, 15);
    //Resistor R6(5, 3, 19.2);
    //Resistor R7(3, 4, 5.6);
    //Resistor R8(3, 2, 3);
    //R1.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";
    //R2.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";
    //R3.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";
    //R4.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";

    //R5.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";
    //R6.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";
    //R7.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\n";
    //R8.stamp(G, I);
    //std::cout << "Matrix G:\n" << G;
    //CurrentSource I3(1, 4, -5);
    //CurrentSource I2(5, 0, 1);
    //I3.stamp(G, I);
    //std::cout << "\nVector I:\n" << I << "\n";
    //I2.stamp(G, I);
    //std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";

    //Solve the linear system G * V = I
    /*if (G.determinant() != 0) 
    {
        V = G.colPivHouseholderQr().solve(I);
        std::cout << "Voltages at nodes:\n" << V << std::endl;
    }
    else 
    {
        std::cerr << "Error: Matrix G is singular; the system cannot be solved." << std::endl;
    }*/

/*Resistor R1(1, 2, 1);
Resistor R2(2, 0, 1);
Resistor R3(1, 4, 1);
Resistor R4(0, 3, 1);
Resistor R5(3, 5, 1);

VoltageSource V1(0, 1, 12, 6);
VoltageSource V2(1, 5, 12, 7);

CurrentSource I1(4, 3, 1);

int numNodes = 5;
int numVoltage = VoltageSource::getVoltageSourceCount();
Eigen::MatrixXd G = Eigen::MatrixXd::Zero(numNodes + numVoltage, numNodes + numVoltage);
Eigen::VectorXd I = Eigen::VectorXd::Zero(numNodes + numVoltage);
Eigen::VectorXd V = Eigen::VectorXd::Zero(numNodes + numVoltage);

std::cout << "Before stamping the resistor:\n";
std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";



R1.stamp(G, I);
R2.stamp(G, I);
R3.stamp(G, I);
R4.stamp(G, I);
R5.stamp(G, I);

V1.stamp(G, I);
V2.stamp(G, I);

I1.stamp(G, I);

std::cout << "Matrix G:\n" << G << "\nVector I:\n" << I << "\n";


if (G.determinant() != 0)
{
    V = G.colPivHouseholderQr().solve(I);
    for (int i = numNodes; i < numNodes + numVoltage; i++)
    {
        V(i) = 0;
    }
    std::cout << "Voltages at nodes:\n" << V << std::endl;
}
else
{
    std::cerr << "Error: Matrix G is singular; the system cannot be solved." << std::endl;
}*/


Solver solver;
simulateGUIInput(solver);

    return 0;
}


void simulateGUIInput(Solver& solver) 
{
    std::string input;

    std::cout << "\t\t\t\t\t\tCircuit Simulator\n\t\t\t\t\t    ------------------------\n\n";

    while (true) {                                              
     
        std::cout << "Enter component type to add (R = Resistor || V = Voltage Source || I = Current Source || Q = Quit ans solve): ";
        std::cin >> input;

        if (input == "Q" || input == "q") 
        {
            std::cout << "Exiting simulation.\n";
            break;
        }

        if (input == "R" || input == "r") {
            int node1, node2;
            double resistance;

            std::cout << "node1 = ";
            std::cin >> node1;
            std::cout << "node2 = ";
            std::cin >> node2;
            std::cout << "Resistance (In Ohm) = ";
            std::cin >> resistance;

            Resistor* resistor = new Resistor(node1, node2, resistance);
            solver.addComponent(resistor);

            std::cout << "R (" << node1 << ", " << node2 << ", " << resistance << ") " << "\n";

        }


        else if (input == "V" || input == "v")
        {
            int node1, node2;
            double voltage;

            std::cout << "Node1 (From) = ";
            std::cin >> node1;
            std::cout << "Node2 (To) = ";
            std::cin >> node2;
            std::cout << "Voltage (In Volt) = ";
            std::cin >> voltage;

            VoltageSource* voltageSource = new VoltageSource(node1, node2, voltage);
            solver.addComponent(voltageSource);

            std::cout << "V (" << node1 << ", " << node2 << ", " << voltage << ") " << "\n";

        }


        else if (input == "I" || input == "i") {
            int node1, node2;
            double current;

            std::cout << "Node1 (From) = ";
            std::cin >> node1;
            std::cout << "Node2 (To) = ";
            std::cin >> node2;
            std::cout << "Current (In volt) = ";
            std::cin >> current;

            CurrentSource* currentSource = new CurrentSource(node1, node2, current);
            solver.addComponent(currentSource);

            std::cout << "I (" << node1 << ", " << node2 << ", " << current << ") " << "\n";
        }


        else
        {
            std::cout << "Invalid input. Please try again.\n";
        }
    }
    std::cout << Component::getComponentCount() << "\n" << solver.getNumNodes() << "\n" << VoltageSource::getVoltageSourceCount();
    solver.stamp();
    solver.solve();
    solver.printV();
}
