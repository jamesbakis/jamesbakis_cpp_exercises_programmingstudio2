#include "Agent.h"
#include <random>



#define NUM_MOVES 8

Agent::Agent(unsigned int id, mcpp::Coordinate location)
{
    mcpp::MinecraftConnection mc;
    this->id = id;
    this->location.x = location.x;
    this->location.y = location.y;
    this->location.z = location.z;

}

Agent::~Agent()
{
}

bool Agent::checkMove(mcpp::Coordinate next){

    bool valid = true;

    //check if the next location is reachable
    int heightDiff = next.y - this->location.y;
    if(heightDiff > 1){
        valid = false;
    }

    return valid;
}

bool Agent::randomStep(void){
    mcpp::MinecraftConnection mc;
    bool success = false;

    std::random_device r;
    std::default_random_engine engine(r());

    // possible moves - one step around current
    int moves[NUM_MOVES][2] = { {-1,-1}, {-1,0}, {-1,1}, 
                        {0,-1},          {0,1}, 
                        {1,-1},  {1, 0}, {1, 1}};

    int movesIndices[NUM_MOVES] ={0,1,2,3,4,5,6,7};

    

    // randomly shuffle the moves so that we will 
    // have a random order.
    for (int i=NUM_MOVES-1; i>0; --i) {
        std::uniform_int_distribution<int> d(0,i);
        int inx = d(engine);
        int temp = movesIndices[inx];
        movesIndices[inx] = movesIndices[i];
        movesIndices[i] = temp;
    }

    // for(int i=0; i<NUM_MOVES; i++){
    //     std::cout << movesIndices[i] << ", ";
    // }
    // std::cout << std::endl;

    // take a step
    for(int i = 0; i < NUM_MOVES && success == false; i++){
        mcpp::Coordinate next;
        next.x = this->location.x + moves[movesIndices[i]][0];
        next.z = this->location.z + moves[movesIndices[i]][1];
        next.y = mc.getHeight(next.x, next.z) + 1;

        bool valid = checkMove(next);
        if(valid){
            this->location.x = next.x;
            this->location.y = next.y;
            this->location.z = next.z;
            mc.setBlock(this->location, mcpp::Blocks::LIME_CARPET);
            //mc.setPlayerPosition(this->location);

            success = true;
        }

    }
    return success;
}

bool Agent::isBlockInNeighborhood(mcpp::BlockType block, mcpp::Coordinate& treasureCoord){
    mcpp::MinecraftConnection mc;

    bool retValue = false;

    for(int x = -1; x < 2 && retValue==false; x++){
        for(int z = -1; z < 2 && retValue==false; z++){
            int y = mc.getHeight(this->location.x + x, this->location.z + z);
            mcpp::Coordinate checkLoc(this->location.x + x, y, this->location.z + z); 

            if(mc.getBlock(checkLoc) == block){
                treasureCoord.x = checkLoc.x;
                treasureCoord.y = checkLoc.y;
                treasureCoord.z = checkLoc.z;
                retValue = true;
            }
            
        }
    }

    return retValue;
}


std::ostream& operator<<(std::ostream& os, const Agent& f){
    os << "Agent " << f.id << " is at: " << f.location;
    return os;
}