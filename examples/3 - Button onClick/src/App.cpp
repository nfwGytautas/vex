/**
 * @file App.cpp
 * @author nfwGytautas
 * @date 10/29/22
 */

#include <iostream>

#include "vex/ui/elements/Button.h"

extern "C" {

__attribute__((visibility("default"))) void button_onClick(vex::ui::elements::Button* btn) {
    std::cout << btn->getSize().x << " " << btn->getSize().y << "\n";
}

__attribute__((visibility("default"))) void button_onClick2(vex::ui::elements::Button* btn) {
    std::cout << "Second callback\n";
}
}
