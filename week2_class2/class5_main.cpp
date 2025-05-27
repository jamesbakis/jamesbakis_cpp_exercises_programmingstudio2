#include <iostream>
#include <exception>
#include <random>
#include <chrono>
#include <thread>

#include <mcpp/mcpp.h>

#include "Utils.h"

#define MAX_ITER 1000

void someDelay(void);

int main(void){

    

    try{
        //Read the length and width
        unsigned int xLength = 0;
        unsigned int zLength = 0;

        mcpp::Coordinate basePoint(0,0,0);

        //Read the field parameters
        bool retVal = false;
        while (!retVal)
        {
            retVal = ReadFieldParameters(basePoint, xLength, zLength);
            if(!retVal){
                std::cout << "Input Error:  Enter H W X Y Z" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        
        

        // setup the field
        //TODO

        someDelay();
        //deploy agent
        //TODO

        someDelay();
        //searching treasure
        
        someDelay();

    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}

// We will not cover the libraries chrono or thread in this cause.
// simply use them for very few things.
void someDelay(void){
    std::cout << "Waiting ...";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
    std::cout << "Done" << std::endl;
}