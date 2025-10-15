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
        string course_code;

    public:
        Admin();

        explicit Admin(const string &code);

        Admin(const string &name, const string &id, const string &pass, const string &code);

        void setCourseCode(const string &code);

        string getCourseCode();

        //course code is not written in the admin-list.dat
        bool registerUser(const string &name, const string &id, const string &pass) override;

        bool admin_register(const string &name, const string &id, const string &pass, const string &course_code);

        shared_ptr<User> loginUser(const string &id, const string &pass) override;


        bool addQuiz(const string &quiz_id, const string &quiz_title);

        bool addQuestion(const Question &question, const string &quiz_id);

        bool addStudent(Student &student);

        vector<Student> allStudents();

        // void setResult(Result &result);

    };
}


#endif //ADMIN_H
