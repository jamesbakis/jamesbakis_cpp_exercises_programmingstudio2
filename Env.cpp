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
    this->envStructure = envStructure;
    this->start = start;
}

Env::~Env()
{
    //TODO
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
    this->start = start;
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

