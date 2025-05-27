#include <iostream>
#include <mcpp/mcpp.h>

bool ReadFieldParameters(mcpp::Coordinate& basePoint, unsigned int& xLength, unsigned int& zLength){

    bool success = true;
    std::cout << "Enter the Length and Width of the field: " << std::endl;
    std::cin >> xLength;
    std::cin >> zLength;

    if (xLength < 4 || zLength < 4){
        success = false;
        xLength = 0;
        zLength = 0;
    }

    int basePointX=0;
    int basePointY=0;
    int basePointZ=0;
    
    if(success){
        std::cout << "Enter the basePoint coordinate (X, Y, Z): " << std::endl;
        
        std::cin >> basePointX;
        if(std::cin.fail()){
            success = false;
        }

        std::cin >> basePointY;
        if(std::cin.fail()){
            success = false;
        }

        std::cin >> basePointZ;
        if(std::cin.fail()){
            success = false;
        }

        if(success){
            basePoint.x = basePointX;
            basePoint.y = basePointY;
            basePoint.z = basePointZ;
        }else{
            basePoint.x = 0;
            basePoint.y = 0;
            basePoint.z = 0;
        }
    }

    return success;

}