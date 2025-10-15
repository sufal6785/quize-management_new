//
// Created by User on 9/3/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_QUIZ_H
#define QUIZ_MANAGEMENT_NEW_QUIZ_H
#include <string>
#include <vector>

#include "Question.h"
using namespace std;

namespace model {
    class Quiz {
    private:
        string id;
        string title;
        vector<Question> question;
        int score;
        int correct;
        int wrong;

        void load();

    public:
        Quiz();

        Quiz(const string &quiz_id, const string &quiz_title);

        //id and title should be initialized while loading file
        // void setId(const string & i);
        // void setTitle(const string &t);

        string getId() const;
        string getTitle() const;
        int getScore() const;
        int getCorrect() const;
        int getWrong() const;

        void display() const;
        void takeQuiz();
        void report() const;
    };
} // model

#endif //QUIZ_MANAGEMENT_NEW_QUIZ_H
