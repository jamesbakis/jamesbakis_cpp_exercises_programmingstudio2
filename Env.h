#ifndef ENV
#define ENV

#include <mcpp/mcpp.h>

/*
The implimentation of the class below has some issues. 
We will be fixing along the way. Do not assume correctness.
*/


class Env
{
public:
    /*
    Constructors
    */
    Env();
    Env(unsigned int height, 
        unsigned int width, 
        char** envStructure, mcpp::Coordinate* start);
    ~Env();

    //other methods

    unsigned int getHeight(void) const;
    unsigned int getWidth(void) const;

    void setHeight(unsigned int height);
    void setWidth(unsigned int width);

    void setStart(mcpp::Coordinate* start);
    mcpp::Coordinate* getStart(void) const;

    void setEnvStructure(char** envStructure);
    char** getEnvStructure(void) const;



private:
    unsigned int height;
    unsigned int width;

    mcpp::Coordinate* start;

    char** envStructure;

};

#endif //ENV