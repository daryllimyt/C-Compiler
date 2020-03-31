#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <iostream>

class Util {
   public:
   static const bool hehe = false;
    static const bool qemu = true;
    static const bool debug = hehe;
    static const bool viewStartTags = hehe;
    static const bool viewEndTags = hehe;
    static const bool viewAllNodesContext = hehe;

    static void abort() {
        if (debug) {
            std::cerr << "[INFO] Terminating program\n";
        }
        std::exit(-1);
    }
};

#endif