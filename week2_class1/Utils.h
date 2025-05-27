#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include <exception>

void ReadEnvSize(unsigned int& envHeight, unsigned int& envWidth){

    std::cout << "Enter the size of the rectangular Environment (H, W): " << std::endl;
    std::cin >> envHeight;
    std::cin >> envWidth;

    if (envHeight == 0 || envWidth == 0){
        throw std::invalid_argument("Height and width arguments are not correct!");
    }
}

void ReadEnvStart(mcpp::Coordinate** start){
    int x=0;
    int y=0;
    int z=0;
    bool success = true;

    std::cout << "Enter the start coordinate of rectangular Environment (X, Y, Z): " << std::endl;
    
    std::cin >> x;
    if(std::cin.fail()){
        success = false;
    }

    std::cin >> y;
    if(std::cin.fail()){
        success = false;
    }

    std::cin >> z;
    if(std::cin.fail()){
        success = false;
    }

    if(success){
         *start = new mcpp::Coordinate(x, y, z);
    }else{
        throw std::invalid_argument("Start coordinate incorrect!");
    }
   
    
}


void readEnvStdin(char** EnvStruct, unsigned int height, unsigned int width){
    unsigned int charsRead = 0;
    char readC;

    for (unsigned int row = 0; row < height; row++){
        for (unsigned int col = 0; col < width; col++){
            if(std::cin.good()){
                std::cin >> readC;
                if(readC == 'x' || readC == '.'){
                    EnvStruct[row][col] = readC;
                    ++charsRead;
                }
            }
        }
        
    }

    if (charsRead != (height * width)) {
        std::string errorString = "Error reading env - only read ";
        errorString += std::to_string(charsRead);
        errorString += " characters";
        throw std::invalid_argument(errorString);
    }
    
}



//Contract: expects the env->getEnvStructure() to return a 2D array containing 'x' 
// and '.'. 
void BuildEnvironment(Env* env){
    mcpp::MinecraftConnection mc;
    mc.setPlayerPosition(*(env->getStart()) + mcpp::Coordinate(-1, 0, -1));
    
    for(unsigned int h =0; h < env->getHeight(); h++){
        for(unsigned int w = 0; w < env->getWidth(); w++){
            if((env->getEnvStructure())[h][w] == 'x'){
                mc.setBlock(*(env->getStart()) + mcpp::Coordinate(h, 0, w), mcpp::Blocks::BRICKS);
                mc.setBlock(*(env->getStart()) + mcpp::Coordinate(h, 1, w), mcpp::Blocks::BRICKS);
            }
        }
    }
}
