#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <iostream>

class Util {
   public:
//    static const bool hehe = true;
    static const bool qemu = true;
    static const bool debug = false;
    static const bool viewStartTags = false;
    static const bool viewEndTags = false;
    static const bool viewAllNodesContext = false;

    static void abort() {
        if (debug) {
            std::cerr << "[INFO] Terminating program\n";
        }
        std::exit(-1);
    }
};

#endif