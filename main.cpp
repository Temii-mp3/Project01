#include <iostream>
#include "config.hpp"
#include "node.hpp"


int main(int argc, char* argv[]){
    
    if(argc < 2 || argc >3){
        std::cerr << "Invalid usage of program, only include name of config file" << std::endl;
    }

    std::string filename = argv[1];
    Config *configObject = new Config(filename);

    if(argv[3] == nullptr){
        //TODO: Implemenet picking random node
    }else{

    }
    

    











    delete configObject;
    return 0;


}