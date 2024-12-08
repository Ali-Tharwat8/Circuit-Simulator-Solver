#pragma once
#include "solver.h"
#include <iomanip>
#include <windows.h>

//#define RESET "\033[0m"
//#define RED "\033[31m"
//#define GREEN "\033[32m"
//#define YELLOW "\033[33m"
//#define BLUE "\033[34m"
//#define MAGENTA "\033[35m"
//#define CYAN "\033[36m"
//#define BOLD "\033[1m"
//#define UNDERLINE "\033[4m"

class simulateGUIInput
{

private:

    Solver solver;

public:

    simulateGUIInput(Solver& s) : solver(s) 
    {
    }

    // Function to set console text color
    void setColor(int textColor, int bgColor) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor + (bgColor * 16));
    }

    // Function to dynamically center text with optional border
    void printCenteredDynamic(const string& text, int consoleWidth, char borderChar = ' ') {
        int padding = max((consoleWidth - static_cast<int>(text.size())) / 2, 0);
        cout << std::string(padding, borderChar) << text << string(padding, borderChar) << "\n";
    }

    void Simulate() {
        string input;

        // Reset console background to black
        system("color 07"); // 0 = Black Background, 7 = White Text

        // Get console width dynamically
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

        // Title display
        setColor(14, 0); // Yellow text on black background
        cout << "\n\n";
        printCenteredDynamic("\u2554" + string(40, '\u2550') + "\u2557", consoleWidth);
        printCenteredDynamic(" \u2551            CIRCUIT SIMULATOR           \u2551", consoleWidth);
        printCenteredDynamic("\u255A" + string(40, '\u2550') + "\u255D", consoleWidth);
        cout << "\n\n";

        while (true) {
            setColor(7, 0); // White text on black background
            cout << "Enter component type (";

            setColor(12, 0); // Red for Resistor
            cout << "R = Resistor";

            setColor(7, 0); // White
            cout << " || ";

            setColor(9, 0); // Blue for Voltage Source
            cout << "V = Voltage Source";

            setColor(7, 0);
            cout << " || ";

            setColor(10, 0); // Green for Current Source
            cout << "I = Current Source";

            //setColor(7, 0);
            cout << " || ";

            setColor(14, 0); // Yellow for Wire
            cout << "W = Wire";

            setColor(7, 0);
            cout << " || ";

            setColor(13, 0); // Magenta for Quit
            cout << "Q = Quit and solve";

            setColor(7, 0);
            cout << "): ";

            cin >> input;

            if (input == "Q" || input == "q") {
                setColor(13, 0); // Magenta for Quit
                cout << "Exiting simulation.\n\n";
                break;
            }

            if (input == "R" || input == "r") {
                int node1, node2;
                double resistance;

                setColor(7, 0);
                cout << "node1 = ";
                cin >> node1;
                cout << "node2 = ";
                cin >> node2;
                cout << "Resistance (In Ohm) = ";
                cin >> resistance;

                Resistor* resistor = new Resistor(node1, node2, resistance);
                solver.addComponent(resistor);

                setColor(12, 0); // Red for Resistor
                cout << "R (" << node1 << ", " << node2 << ", " << resistance << ")\n";
            }
            else if (input == "V" || input == "v") {
                int node1, node2;
                double voltage;

                setColor(7, 0);
                cout << "Node1 (From) = ";
                cin >> node1;
                cout << "Node2 (To) = ";
                cin >> node2;
                cout << "Voltage (In Volt) = ";
                cin >> voltage;

                VoltageSource* voltageSource = new VoltageSource(node1, node2, voltage);
                solver.addComponent(voltageSource);

                setColor(9, 0); // Blue for Voltage Source
                cout << "V (" << node1 << ", " << node2 << ", " << voltage << ")\n";
            }
            else if (input == "I" || input == "i") {
                int node1, node2;
                double current;

                setColor(7, 0);
                cout << "Node1 (From) = ";
                cin >> node1;
                cout << "Node2 (To) = ";
                cin >> node2;
                cout << "Current (In Ampere) = ";
                cin >> current;

                CurrentSource* currentSource = new CurrentSource(node1, node2, current);
                solver.addComponent(currentSource);

                setColor(10, 0); // Green for Current Source
                cout << "I (" << node1 << ", " << node2 << ", " << current << ")\n";
            }
            else if (input == "W" || input == "w") {
                int node1, node2;

                setColor(7, 0);
                cout << "Node1 = ";
                cin >> node1;
                cout << "Node2 = ";
                cin >> node2;

                Wire* wire = new Wire(node1, node2);
                solver.addComponent(wire);

                setColor(14, 0);
                cout << "W (" << node1 << ", " << node2 << ")\n";
            }
            else 
            {
                setColor(4, 0); // Red for invalid input
                cout << "Invalid input. Please try again.\n";
            }
        }
        setColor(7, 0);
        solver.stamp();
        setColor(11, 0);
        solver.solve();
        solver.printV();
    }




   /* void Simulate()
    {
        std::string input;

        std::cout << "\t\t\t\t\t\tCircuit Simulator\n\t\t\t\t\t    ------------------------\n\n";

        while (true) {

            std::cout << "Enter component type to add (R = Resistor || V = Voltage Source || I = Current Source || W = Wire || Q = Quit ans solve): ";
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
    }*/
};

