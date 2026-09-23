#include "config.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <string>


Config::Config(const std::string &filename){

    if(loadConfig(filename) != 0){
        std::cerr << "Config file could not be open" <<std::endl;
    }
}

int Config::loadConfig(const std::string &filename){
    std::ifstream config (filename);

    if(!config.is_open()){
        std::cerr << "Could not open " << filename << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> validLines;

    while(std::getline(config, line)){
        std::string::size_type index = line.find('#');

        if(index != std::string::npos){
            line = line.substr(0, index);
        }

        std::string::size_type first_index = line.find_first_not_of(" \t");
        if(first_index == std::string::npos){
            continue;
        }
        std::string::size_type last_index = line.find_last_not_of(" \t");

        line = line.substr(first_index, (last_index - first_index) + 1);
        validLines.push_back(line);
    }
    std::string tokens = validLines[0];
    std::istringstream ss(tokens);
    
    ss >> NUM_NODES;
    ss >> MIN_PER_ACTIVE;
    ss >> MAX_PER_ACTIVE;
    ss >> MIN_SEND_DELAY;
    ss >> SNAPSHOTDELAY;
    ss >> MAX_NUMBER;
    
    for(int i = 0; i < NUM_NODES; i++){
        tokens = validLines[i + 1];
        std::istringstream nodeStream(tokens);

        NodeInfo node;
        nodeStream >> node.id;
        nodeStream >> node.hostname;
        nodeStream >> node.listenPort;

        nodeInfo.push_back(node);
    }

    int j = 0;
    for(int i = (NUM_NODES + 1); i <= (2*NUM_NODES); i++){


        NodeInfo& node = nodeInfo[j];

        std::istringstream adjacentStream(validLines[i]);
        int neighbor;

        while(adjacentStream >> neighbor){
            node.adjacentNeighbors.push_back(neighbor);
        }
        j++;
    }

    std::cout << "Config Loaded Successfully\n" 
              << "===============\n"
              << "# of nodes: " << NUM_NODES
              << " Min Per Active: " << MIN_PER_ACTIVE
              << " Max Per Active: " << MAX_PER_ACTIVE
              << " Min Send Delay: " << MIN_SEND_DELAY
              << " Snapshot Delay: " << SNAPSHOTDELAY
              << " Max Number of Msgs: " << MAX_NUMBER << "\n";
    std::cout << "Node Info\n" << "=========\n";

    for(auto node : nodeInfo){
        std::cout << "ID: " << node.id
                  << " Hostname: " << node.hostname
                  << " Port #: " << node.listenPort
                  << " Neighbors: ";
        for(auto neighbor : node.adjacentNeighbors){
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }

    


    return 0;
}