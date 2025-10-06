//
// Created by User on 8/9/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"


namespace model {
    class Student : public User {
    private:
        string student_file;

        void makeFile() {
            student_file = student_file + "_" + getId() + ".dat";
        }

    public:
        Student();

        Student(const string &name, const string &id, const string &pass);

        bool registerUser(const string &name, const string &id, const string &pass) override;

        shared_ptr<User> loginUser(const string &id, const string &pass) override;
    };
}


#endif //STUDENT_H
