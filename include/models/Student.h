//
// Created by User on 8/9/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"


namespace model {
    class Student : public User {
    public:
        Student();

        Student(const string &name, const string &id, const string &pass);

        bool registerUser(const string &name, const string &id, const string &pass) override;

        shared_ptr<User> loginUser(const string &id, const string &pass) override;
    };
}


#endif //STUDENT_H
