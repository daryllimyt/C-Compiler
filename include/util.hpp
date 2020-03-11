#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>

class Util 
{
public:
    static const bool DEBUG = false;

    static void abort() 
    {
        if (DEBUG) 
        {
            std::cerr << std::endl << "Aborting." << std::endl;
        }
    std::exit(-1);
    }
};

#endif