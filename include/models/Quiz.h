//
// Created by User on 9/3/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_QUIZ_H
#define QUIZ_MANAGEMENT_NEW_QUIZ_H
#include <string>
#include <vector>

#include "Question.h"
#include "Result.h"
using namespace std;

namespace model {
    class Quiz {
    private:
        string id;
        string title;
        vector<Question> question;
        vector<Result> result;
        int score;
        int correct;
        int wrong;
        string quiz_file;

        string makeFile() {
            return "result/quiz/" + getId() + ".txt";
        }

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

        void loadResultByQuiz();
        vector<Result> getResult();
    };
} // model

#endif //QUIZ_MANAGEMENT_NEW_QUIZ_H
