// //
// // Created by User on 8/16/2025.
// //
//
#include "Admin.h"

#include <filesystem>
#include <fstream>

#include "Utility.h"
using namespace std;
using namespace Utility;

namespace model {
    Admin::Admin() : User() {
    }

    Admin::Admin(const string &code) : User() {
        course_code = code;
    }

    Admin::Admin(const string &name, const string &id, const string &pass, const string &code) : User(name, id, pass) {
        course_code = code;
    }

    void Admin::setCourseCode(const string &code) {
        course_code = code;
    }

    string Admin::getCourseCode() {
        return course_code;
    }

    bool Admin::registerUser(const string &name, const string &id, const string &pass) {
        if (!isExistInFile("admin-list.dat", id)) {
            return saveToFile("admin-list.dat", name, id, pass);
        }
        return false;
    }

    //for course code, we need an extra function instead of pure virtual function
    bool Admin::admin_register(const string &name, const string &id, const string &pass, const string &course_code) {
        if (!isExistInFile("admin-list.dat", id)) {
            return saveToFile("admin-list.dat", name, id, pass, course_code);
        }
        return false;
    }


    shared_ptr<User> Admin::loginUser(const string &id, const string &pass) {
        ifstream file;
        file.open("admin-list.dat");
        if (file.is_open()) {
            string name, savedId, savedPass, course;
            while (getline(file, name) && getline(file, savedId) &&
                   getline(file, savedPass), getline(file, course)) {
                if (savedId == id && savedPass == pass)
                    return make_shared<Admin>(name, savedId, savedPass, course);
            }
        }

        return nullptr;
    }

    bool Admin::addQuiz(const string &quiz_id, const string &quiz_title) {
        const string &file_name = "include/quiz/" + quiz_id + ".txt";

        ofstream file(file_name);
        if (file.is_open()) {
            file << quiz_id << "\n" << quiz_title << "\n";
            return true;
        }
        return false;
    }


    bool Admin::addQuestion(const Question &question, const string &quiz_id) {
        const string &filename = "include/quiz/" + quiz_id + ".txt";
        if (ofstream file(filename,ios::app); file.is_open()) {
            file << question.getId() << endl;
            file << question.getQuestion() << endl;
            file << question.getOpA() << endl;
            file << question.getOpC() << endl;
            file << question.getOpD() << endl;
            file << question.getCorrect() << endl;
            return true;
        }
        return false;
    }

    //
}
