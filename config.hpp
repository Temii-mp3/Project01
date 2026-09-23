#pragma once

#include <vector>
#include <string>
#include "nodeinfo.hpp"

class Config{

    private:    
         int NUM_NODES;
         int MIN_PER_ACTIVE;
         int MAX_PER_ACTIVE;
         int MIN_SEND_DELAY;
         int SNAPSHOTDELAY;
         int MAX_NUMBER;
         std::vector<NodeInfo> nodeInfo;
        int loadConfig(const std::string& filename);

        public:
            Config(const std::string& filename);
            int getNumNodes() const;
            int getMinPerActive() const;
            int getMaxPerActive() const;
            int getMinSendDelay() const;
            int getSnapShotDelay() const;
            int getMaxNumber() const;
            const NodeInfo& getNodeInfo(int id) const; //sending unmodifiable ref to nodeInfo object


};