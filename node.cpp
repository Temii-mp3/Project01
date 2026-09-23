#include "node.hpp"


Node::Node(const NodeInfo& info, int n){
    id = info.id;
    hostname = info.hostname;
    adjacentNeighbors = info.adjacentNeighbors;
    listenPort = info.listenPort;
    vectorClock.assign(n, 0);
}