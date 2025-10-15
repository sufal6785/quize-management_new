//
// Created by User on 10/7/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_ADMINPORTAL_H
#define QUIZ_MANAGEMENT_NEW_ADMINPORTAL_H
#include "../../models/Admin.h"
using namespace model;

namespace adminview {
    class AdminPortal {
    public:

        static  void options();

        static void select(const shared_ptr<Admin> &admin);

        static void action(const shared_ptr<Admin> & user);

        static void admin_home();
    };
} // adminview

#endif //QUIZ_MANAGEMENT_NEW_ADMINPORTAL_H