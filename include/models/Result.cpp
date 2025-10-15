//
// Created by User on 9/3/2025.
//

#include "Result.h"

namespace model {
    Result::Result() : score(0) {
    }

    Result::Result(const string &st_id, const string &qz_id, int scr) {
        student_id = st_id;
        quiz_id = qz_id;
        score = scr;
    }

    string Result::getStudentId() const {
        return student_id;
    }

    string Result::getQuizId() const {
        return quiz_id;
    }

    int Result::getScore() const {
        return  score;
    }

} // model
