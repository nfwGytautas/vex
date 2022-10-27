/**
 * @file main.cpp
 * @author nfwGytautas
 * @date 10/27/22
 */

#include "vex/Vex.h"

/**
 * vex entry point
 * @return Error code or 0 if everything was ok
 */
int main(int args, char** argc) {
    vex::Vex vex_;
    return vex_.start(args, argc);
}
