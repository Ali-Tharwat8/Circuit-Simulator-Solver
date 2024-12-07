#include "simulateGUIInput.h"

int main() 
{
    Solver solver;
    simulateGUIInput Sim(solver);
    Sim.Simulate();
    return 0;
}


//void simulateGUIInput(Solver& solver)
//{
//    std::string input;
//
//    std::cout << "\t\t\t\t\t\tCircuit Simulator\n\t\t\t\t\t    ------------------------\n\n";
//
//    while (true) {
//
//        std::cout << "Enter component type to add (R = Resistor || V = Voltage Source || I = Current Source || Q = Quit ans solve): ";
//        std::cin >> input;
//
//        if (input == "Q" || input == "q")
//        {
//            std::cout << "Exiting simulation.\n";
//            break;
//        }
//
//        if (input == "R" || input == "r") {
//            int node1, node2;
//            double resistance;
//
//            std::cout << "node1 = ";
//            std::cin >> node1;
//            std::cout << "node2 = ";
//            std::cin >> node2;
//            std::cout << "Resistance (In Ohm) = ";
//            std::cin >> resistance;
//
//            Resistor* resistor = new Resistor(node1, node2, resistance);
//            solver.addComponent(resistor);
//
//            std::cout << "R (" << node1 << ", " << node2 << ", " << resistance << ") " << "\n";
//
//        }
//
//
//        else if (input == "V" || input == "v")
//        {
//            int node1, node2;
//            double voltage;
//
//            std::cout << "Node1 (From) = ";
//            std::cin >> node1;
//            std::cout << "Node2 (To) = ";
//            std::cin >> node2;
//            std::cout << "Voltage (In Volt) = ";
//            std::cin >> voltage;
//
//            VoltageSource* voltageSource = new VoltageSource(node1, node2, voltage);
//            solver.addComponent(voltageSource);
//
//            std::cout << "V (" << node1 << ", " << node2 << ", " << voltage << ") " << "\n";
//
//        }
//
//
//        else if (input == "I" || input == "i") {
//            int node1, node2;
//            double current;
//
//            std::cout << "Node1 (From) = ";
//            std::cin >> node1;
//            std::cout << "Node2 (To) = ";
//            std::cin >> node2;
//            std::cout << "Current (In volt) = ";
//            std::cin >> current;
//
//            CurrentSource* currentSource = new CurrentSource(node1, node2, current);
//            solver.addComponent(currentSource);
//
//            std::cout << "I (" << node1 << ", " << node2 << ", " << current << ") " << "\n";
//        }
//
//
//        else
//        {
//            std::cout << "Invalid input. Please try again.\n";
//        }
//    }
//    std::cout << Component::getComponentCount() << "\n" << solver.getNumNodes() << "\n" << VoltageSource::getVoltageSourceCount();
//    solver.stamp();
//    solver.solve();
//    solver.printV();
//}
