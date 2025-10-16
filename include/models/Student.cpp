//
// Created by Sufal on 8/9/2025.
//

#include "Student.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Quiz.h"
#include "Utility.h"
using namespace Utility;

namespace model {
    Student::Student() : User(), student_file(makeFile()) {
    }

    Student::Student(const string &name, const string &id, const string &pass) : User(name, id, pass),
        student_file(makeFile()) {
    }

    bool Student::registerUser(const string &name, const string &id, const string &pass) {
        if (!isExistInFile("student-list.dat", id)) {
            return saveToFile("student-list.dat", name, id, pass);
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

    void Student::attendQuiz(const string &qz) {
        string file_name = "include/quiz/" + qz + ".txt";
        ifstream file;
        file.open(file_name);
        if (!file.is_open()) {
            cout << "Failed to open quiz file..." << endl;
            return;
        }
        string quizId, quizTitle;
        getline(file, quizId);
        getline(file, quizTitle);

        Quiz quiz(quizId, quizTitle);
        quiz.takeQuiz();
        if (saveResult(getId(), quizId, quiz.getScore())) {
            quiz.report();
        }
    }

    void Student::loadResultsByStudents() {
        ifstream file(student_file);

        if (!result.empty()) {
            result.clear();
        }

        if (!file.is_open()) {
            cout << "No results found for " << getName() << endl;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string quiz_id;
            string comma;
            string score;

            ss >> quiz_id >> comma >> score;

            int scr = stoi(score);
            result.emplace_back(getId(), quiz_id, scr);
        }
    }

    vector<Result> Student::getResult() {
        loadResultsByStudents();
        return result;
    }
}
