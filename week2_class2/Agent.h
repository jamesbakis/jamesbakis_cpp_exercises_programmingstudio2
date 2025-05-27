#ifndef AGENT_H
#define AGENT_H
#include <mcpp/mcpp.h>

class Agent
{

public:
    
    Agent();
    ~Agent();

    /*
    Print agent ID and current location to output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Agent& f);

private:
    

};

#endif //AGENT_H


