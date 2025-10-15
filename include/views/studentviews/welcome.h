//
// Created by Ayesha on 8/11/2025.
//

#ifndef WELCOME_H
#define WELCOME_H

#include <iostream>
#include "../../models/Student.h"

namespace view {
    using namespace model;

    class Welcome {
    public:
        static void welcome() {
            cout << "\n";
            cout << "================================================\n";
            cout << "        WELCOME TO THE STUDENT PORTAL          \n";
            cout << "================================================\n";
            cout << "\n";
        }
    };
}
#endif //WELCOME_H
