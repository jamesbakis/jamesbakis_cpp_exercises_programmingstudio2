#include "Env.h"

Env::Env()
{
    this->height = 0;
    this->width = 0;

    envStructure = nullptr;
    start = nullptr;
}

Env::Env(unsigned int height, 
        unsigned int width, 
        char** envStructure, mcpp::Coordinate* start):
                        height(height),
                        width(width)
{    
    std::cout << height << width << std::endl;
    this->envStructure = new char*[height];
    for (unsigned int i = 0; i < height; ++i) {
        this->envStructure[i] = new char[width];
    }

    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
        this->envStructure[i][j] = envStructure[i][j];
        }
    }
    
    this->start = start;
}

Env::Env(const Env & other) {
    this->height = other.height;
    this->width = other.width;
    
    this->start = new mcpp::Coordinate(0, 0, 0);
    *(this->start) = *(other.start);
    delete other.start;
    this->envStructure = new char*[height];
    for (unsigned int i = 0; i < height; ++i) {
        envStructure[i] = new char[width];
    }
   
    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
        envStructure[i][j] = other.envStructure[i][j];
        }
    }
    
}

Env::~Env()
{
    for (unsigned int i = 0; i < height; ++i) {
         delete envStructure[i];
         envStructure[i] = nullptr;    
    }
    delete envStructure;
    envStructure = nullptr;
}


unsigned int Env::getHeight(void) const {
    return this->height;
}

unsigned int Env::getWidth(void) const {
    return this->width;
}

void Env::setHeight(unsigned int height){
    this->height = height;
}

void Env::setWidth(unsigned int width){
    this->width = width;
}

//Identify is there are any issues
void Env::setStart(mcpp::Coordinate* start){
    *(this->start) = *start;
}

mcpp::Coordinate* Env::getStart(void) const{
    return this->start;
}

//Identify is there are any issues
void Env::setEnvStructure(char** envStructure){
    this->envStructure = envStructure;
}

char** Env::getEnvStructure(void) const{
    return this->envStructure;
}

