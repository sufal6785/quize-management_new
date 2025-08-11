//
// Created by User on 8/9/2025.
//

#include "Student.h"

#include <fstream>

namespace model {
    Student::Student() : User() {
    }

    Student::Student(const string &name, const string &id, const string &pass) : User(name, id, pass) {
    }

    bool Student::registerUser(const string &name, const string &id, const string &pass) {
        if (!isExist("student-list.dat", id)) {
            ofstream file;
            file.open("student-list.dat", ios::app);
            if (file.is_open()) {
                file << name << "\n" << id << "\n" << pass << "\n";
                return true;
            } else cout << "Error: couldn't open file for writing." << endl;
        }
        return false;
    }

    shared_ptr<User> Student::loginUser(const string &id, const string &pass) {
        ifstream file;
        file.open("student-list.dat");
        if (file.is_open()) {
            string name, savedId, savedPass;
            while (getline(file, name) && getline(file, savedId) && getline(file, savedPass)) {
                if (savedId == id && savedPass == pass)
                    return make_shared<Student>(name, savedId, savedPass);
            }
        }

        return nullptr;
    }
}
