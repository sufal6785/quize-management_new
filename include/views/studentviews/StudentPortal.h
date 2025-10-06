//
// Created by User on 8/9/2025.
//

#ifndef STUDENTPORTAL_H
#define STUDENTPORTAL_H
#include "../../models/Student.h"


namespace view {
    using namespace model;

    class StudentPortal {
    public:

        static  void options();

        static void action(const shared_ptr<User> & user);

        static void student_home();
    };
}


#endif //STUDENTPORTAL_H
