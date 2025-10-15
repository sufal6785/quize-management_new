//
// Created by Sufal on 8/9/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "Result.h"
#include "User.h"


namespace model {
    class Student : public User {
    private:
        string student_file;
        vector<Result> result;
        string makeFile() {
            return "result/student/" + getId() + ".txt";
        }

    public:
        Student();

        Student(const string &name, const string &id, const string &pass);

        bool registerUser(const string &name, const string &id, const string &pass) override;

        shared_ptr<User> loginUser(const string &id, const string &pass) override;

        void attendQuiz(const string &qz);

        void loadResultsByStudents();

        vector<Result> getResult() ;

        // void showResult();
    };
}


#endif //STUDENT_H
