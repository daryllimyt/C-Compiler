#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <iostream>

class Util {
   public:
    static const bool DEBUG = true;

    static void abort() {
        if (DEBUG) {
            std::cerr << "[INFO] Terminating program\n";
        }
        std::exit(-1);
    }
};

#endif