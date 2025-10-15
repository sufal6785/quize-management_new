//
// Created by User on 9/3/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_RESULT_H
#define QUIZ_MANAGEMENT_NEW_RESULT_H
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

namespace model {
    class Result {
        string student_id;
        string quiz_id;
        int score;

    public:
        Result();

        Result(const string &st_id, const string &qz_id, int scr);

        string getStudentId() const;

        string getQuizId() const;

        int getScore() const;
    };
} // model

#endif //QUIZ_MANAGEMENT_NEW_RESULT_H
