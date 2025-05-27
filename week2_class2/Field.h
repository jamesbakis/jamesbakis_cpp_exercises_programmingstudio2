#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <mcpp/mcpp.h>

#define WALL_HEIGHT 5

class Field
{
public:
    
    Field();
    ~Field();


    /*
    create an osstream with the parameters of a given Field
    */
    friend std::ostream& operator<<(std::ostream& os, const Field& f);

private:

};

#endif //FIELD_H