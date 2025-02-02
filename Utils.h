//
// Created by xpolas on 2/2/25.
//

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>

class Utils {
public:
    static void writeOutput(std::ostream& out1, std::ostream& out2, const std::string& text) {
        out1 << text << std::endl;
        out2 << text << std::endl;
    }
};

#endif //UTILS_H
