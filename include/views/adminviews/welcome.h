//
// Created by User on 10/7/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_WELCOME_H
#define QUIZ_MANAGEMENT_NEW_WELCOME_H

#include <iostream>
#include "AdminPortal.h"
using namespace std;
namespace adminview {
    using namespace model;

    class Welcome {
    public:
        static void welcome() {
            cout << "\n";
            cout << "================================================\n";
            cout << "        WELCOME TO THE ADMIN PORTAL          \n";
            cout << "================================================\n";
            cout << "\n";
        }
    };
}
#endif //QUIZ_MANAGEMENT_NEW_WELCOME_H