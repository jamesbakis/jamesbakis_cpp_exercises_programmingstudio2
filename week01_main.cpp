#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"
#include <exception>

#define TESTING_ON

/*
The code below has some issues.
We will be fixing along the way. Do not assume correctness.
*/

int main(void){

    //Read the height and width
    unsigned int envHeight = 0;
    unsigned int envWidth = 0;

    try{
        //Read env size
        ReadEnvSize(envHeight, envWidth);

        // Read the structure of the environment
        char** envStructure;
        envStructure = new char*[envHeight];
        for(unsigned int i =0; i < envHeight; i++){
            envStructure[i] = new char[envWidth];
        }
        readEnvStdin(envStructure, envHeight, envWidth);

        // Read the start coordinate
        mcpp::Coordinate* start = nullptr;
        ReadEnvStart(&start);

        // Create instance of Env class
        
        Env env(envHeight, envWidth, envStructure, start);
        
        //delete memory
        // for(unsigned int i =0; i < envHeight; i++){
        //     delete[] envStructure[i];
        //     envStructure[i] = nullptr;
        // }

        // delete[] envStructure;
        // envStructure = nullptr;
        
        Env env2(env);
        start = new mcpp::Coordinate(123, 200, 187);
        
        env2.setStart(start);
        
        //Construct the environment
        BuildEnvironment(&env);
        BuildEnvironment(&env2);

        #ifdef TESTING_ON
        //Testing build
        std::cout << std::endl;
        std::cout << "Enter the region to check (startx starty startz height width):" << std::endl;
        int startx, starty, startz; 
        unsigned int hgt, wdt;

        std::cin >> startx;
        std::cin >> starty;
        std::cin >> startz;
        std::cin >> wdt;
        std::cin >> hgt;
        
        
        mcpp::MinecraftConnection mc;
        for(unsigned int h = 0; h<hgt; h++){
            
            for(unsigned int w = 0; w<wdt; w++){
                mcpp::BlockType block1 = mc.getBlock(mcpp::Coordinate(startx + w,starty, startz+h));
                mcpp::BlockType block2 = mc.getBlock(mcpp::Coordinate(startx + w,starty+1, startz+h));
                if( block1 == mcpp::Blocks::BRICKS && block2 == mcpp::Blocks::BRICKS){
                    std::cout << 'b';
                }else if (block1 == mcpp::Blocks::AIR && block2 == mcpp::Blocks::AIR){
                    std::cout << 'a';
                }else{
                    std::cout << 'e';
                }
            }
            std::cout << std::endl;

        }
        #endif


        

        
        std::cout << "test" << std::endl;
    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
