//
// Created by User on 8/9/2025.
//

#include "User.h"
#include <fstream>

namespace model {
    User::User(const string &name, const string &id, const string &pass) {
        user_name = name;
        userid = id;
        password = pass;
    }

    void User::set() {
        cout << "Enter your name: \n";
        cin >> user_name;
        cout << "Enter your userid: \n";
        cin >> userid;
        cout << "Enter password: \n";
        cin >> password;
    }

    string User::getId() {
        return userid;
    }

    string User::getName() {
        return user_name;
    }

    string User::getPass() {
        return password;
    }


    void User::display() const {
        cout << "Your name: " << user_name << endl;
        cout << "Your userid: " << userid << endl;
    }

    bool User::isExist(const string &fileName, const string &userid) {
        ifstream file;
        file.open(fileName);
        if (file.is_open()) {
            string name, id, pass;
            while (getline(file, name) && getline(file, id) && getline(file, pass)) {
                if (userid == id) {
                    return true;
                }
            }
        } else if (!file.is_open()) return false; //file doesn't exist
        return false;
    }
}
