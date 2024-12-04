//#include "Wire.h"
//#include <stdexcept>
//#include <iostream>
//
//int Wire::WireCount = 0;
//
//
//Wire::Wire(int n1, int n2) : Component(n1, n2) 
//{
//}
//
//Wire::~Wire() 
//{
//}
//
//void Wire::stamp(Eigen::MatrixXd& G, Eigen::VectorXd& I) {
//    int node1 = getNode1() - 1;  // Convert to 0-based index
//    int node2 = getNode2() - 1;  // Convert to 0-based index
//
//    // Ensure valid node indices
//    if (node1 < -1 || node1 >= G.rows() || node2 < -1 || node2 >= G.cols()) {
//        throw std::out_of_range("Wire stamp failed: node indices are out of range.");
//    }
//
//    if (node1 == -1 || node2 == -1) {
//        // If one node is ground, skip stamping since ground nodes are implicit
//        return;
//    }
//
//    // Stamp large conductance (ideal wire)
//    double largeConductance = 1e9;  // Large value to enforce V(node1) ? V(node2)
//    G(node1, node1) += largeConductance;
//    G(node2, node2) += largeConductance;
//    G(node1, node2) -= largeConductance;
//    G(node2, node1) -= largeConductance;
//
//    std::cout << "Wire stamped between nodes " << node1 + 1 << " and " << node2 + 1 << ".\n";
//}
//
//
//std::string Wire::getType() const {
//    return "Wire";
//}
//
//int Wire::getWireCount()
//{
//    return WireCount;
//}
