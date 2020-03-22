#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <iostream>

class Util {
   public:
    static const bool debug = true;
    static const bool viewStartTags = true;
    static const bool viewEndTags = true;
    static const bool viewAllNodesContext = true;

    static void abort() {
        if (debug) {
            std::cerr << "[INFO] Terminating program\n";
        }
        std::exit(-1);
    }
};

#endif