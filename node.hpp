#ifndef NODEINFO_HPP
#define NODEINFO_HPP

#include <vector>
#include <string>
#include "nodeinfo.hpp"



class Node{
    private:
        std::vector<int> vectorClock;
        std::vector<int> adjacentNeighbors;
        int id;
        int listenPort;
        std::string hostname;


    public:
        Node(int id, const NodeInfo& info);
        void modifyClock(int index, int value);
        int getId() const;
        int getPort() const;
        const std::vector<int>& getVectorClock() const;
        const std::vector<int>& getAdjacentNeighbors() const;
        const std::string& getHostName() const;
};

#endif