//
// Created by User on 8/15/2025.
//

#include "Utility.h"
#include <fstream>
#include <limits>

namespace Utility {
    string getInputString(const string &prompt) {
        string input;
        cout << prompt;
        getline(cin, input);
        return input;
    }

    int getValidChoice(int low, int up) {
        int choice;
        while (true) {
            cin >> choice;

            // Handle invalid input (non-numeric)
            if (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input! Please enter a number (" << low << " - " << up << "): ";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            if (choice >= low && choice <= up) {
                return choice;
            }

            cout << "Invalid choice! Please enter " << low << " - " << up << ": ";
        }
    }

    string file(const string &id, const string &user) {
        string f;
        f += user;
        f += "_";
        f += id;
        f += ".dat";
        return f;
    }

    bool isExistInFile(const string &fileName, const string &userid) {
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

    bool saveToFile(const string &fileName, const string &name, const string &id, const string &pass) {
        if (ofstream file(fileName, ios::app); file.is_open()) {
            file << name << "\n" << id << "\n" << pass << "\n";
            return true;
        }
        return false;
    }

    bool saveToFile(const string &fileName, const string &name, const string &id, const string &pass,
                    const string &course_code) {
        if (ofstream file(fileName, ios::app); file.is_open()) {
            file << name << "\n" << id << "\n" << pass << "\n" << course_code << "\n";
            return true;
        }
        return false;
    }

    // void saveResult(const string &st_id, const string &qz_id, int score) {
    //     const string studentFile = "result/student/" + st_id + ".txt";
    //     ofstream sFile(studentFile, ios::app);
    //     sFile<<qz_id<<","<<score<<"\n";
    //     sFile.close();
    //
    //     const string quizFile = "result/quiz/" + qz_id + ".txt";
    //     ofstream qFile(quizFile, ios::app);
    //     qFile<<st_id<<","<<score<<"\n";
    //     qFile.close();
    // }

    bool saveResult(const string &st_id, const string &qz_id, int score) {
        // Save to student file
        const string studentFile = "result/student/" + st_id + ".txt";
        ofstream sFile(studentFile, ios::app);
        if (!sFile.is_open()) {
            cerr << "Error: Cannot open " << studentFile << endl;
            return false;
        }
        sFile << qz_id << " , " << score << "\n";
        bool success1 = sFile.good();
        sFile.close();

        // Save to quiz file
        const string quizFile = "result/quiz/" + qz_id + ".txt";
        ofstream qFile(quizFile, ios::app);
        if (!qFile.is_open()) {
            cerr << "Error: Cannot open " << quizFile << endl;
            return false;
        }
        qFile << st_id << " , " << score << "\n";
        bool success2 = qFile.good();
        qFile.close();

        return success1 && success2;
    }
}
