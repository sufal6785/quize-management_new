//
// Created by User on 8/16/2025.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include <string>
#include "Question.h"
#include "Quiz.h"
#include "Result.h"
#include "Student.h"
using namespace std;

namespace model {
    class Admin : public User {
    private:
        int course_code;

    public:
        Admin(int course_code);

        Admin(const string &name, const string &id, const string &pass, int course_code);

        void addStudent(Student &student);

        void addQuiz(Quiz &quiz);

        void addQuestion(Question &question);

        void setResult(Result &result);

        bool registerUser(const string &name, const string &id, const string &pass) override;

        shared_ptr<User> loginUser(const string &id, const string &pass) override;
    };
}


#endif //ADMIN_H
