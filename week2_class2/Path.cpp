#include "Path.h"

Path::Path(){

}

Path::~Path(){

}

//Adds a node to path
void Path::pushCoordinate(mcpp::Coordinate loc){
    mcpp::Coordinate* temp = new mcpp::Coordinate(loc.x, loc.y, loc.z);
    savePath.push_back(temp);
}


// return the current length of the path
unsigned int Path::getLength(void){
    return savePath.size();
}

/*
Returns the last coordinate in path and removes it.
Contract:
        Assume there are nodes in path to pop 
*/
mcpp::Coordinate Path::popCoordinate(void){
    mcpp::Coordinate retCoord(0,0,0);
    if(!savePath.empty()){
        retCoord.x = savePath.back()->x;
        retCoord.y = savePath.back()->y;
        retCoord.z = savePath.back()->z;

        savePath.pop_back();
    }
    return retCoord;
}

std::ostream& operator<<(std::ostream& os, const Path& p){
    os << "Path has " << p.savePath.size() << " nodes." << std::endl;
    for(int i = 0; i < p.savePath.size(); i++){
        os << "[" << i << "] \t :" << *(p.savePath[i]) << std::endl; 
    }

    return os;
}

