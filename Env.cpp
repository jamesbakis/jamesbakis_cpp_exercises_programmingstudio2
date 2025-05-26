#include "Env.h"

Env::Env()
{
    this->height = 0;
    this->width = 0;

    envStructure = nullptr;
    start = nullptr;
}

Env::Env(unsigned int height, unsigned int width, char** envStructure, mcpp::Coordinate* start): height(height),width(width)
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

    for (size_t i = 0; i < height; ++i) {
        delete[] envStructure[i];
    }
    delete[] envStructure;

    this->start = new mcpp::Coordinate(0, 0, 0);
    *(this->start) = *start;
    delete start;

}

Env::Env(const Env& other):
    height(other.height),
    width(other.width)
{
    this->envStructure = new char*[this->height];
    for (size_t i = 0; i < this->height; ++i) {
        this->envStructure[i] = new char[this->width];
    }
    this->start = new mcpp::Coordinate();
    *this->start = *other.start;
}

Env::~Env(){
    if(envStructure != nullptr){
        for(unsigned int i =0; i < height; i++){
            delete[] envStructure[i];
        }
        delete[] envStructure;
    }
    if(start != nullptr){
        delete start;
    }
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
    if (this->start == nullptr) {
        this->start = new mcpp::Coordinate();
    }
    *(this->start) = *start;
    delete start;
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

