#pragma once

#include <string>
#include <vector>

struct NodeInfo{
    int id;
    std::string hostname;
    int listenPort;
    std::vector<int> adjacentNeighbors;
};
