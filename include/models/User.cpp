//
// Created by User on 8/9/2025.
//

#include "User.h"
#include <fstream>
#include <filesystem>
#include <vector>
using  namespace std::filesystem;

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

    vector<string> User::showAvailableQuiz() {
        // Replace with the path to your desired directory
        const string path_string = "include/quiz"; // "." represents the current directory
        const path path_to_directory(path_string);
        vector<string> aq;
        try {
            // Check if the path exists and is a directory
            if (exists(path_to_directory) && is_directory(path_to_directory)) {

                // Iterate over the entries in the directory
                for (const auto& entry : directory_iterator(path_to_directory)) {
                    // Check if the entry is a regular file
                    if (is_regular_file(entry.status())) {
                        aq.push_back(entry.path().stem().string());
                    }
                }
            } else {
                cout << "The specified path is not a directory or does not exist." << endl;
            }
        } catch (const filesystem_error& ex) {
            cerr << "Filesystem error: " << ex.what() << endl;
        }

        // if (!aq.empty()) {
        //     cout<<"Available Quizzes:\n";
        //     for (const auto &quiz: aq) {
        //         cout<<quiz<<endl;
        //     }
        // } else {
        //     cout<<"OOPs!!! No quiz is available...";
        // }

        return aq;
    }

}
