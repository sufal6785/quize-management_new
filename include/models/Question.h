//
// Created by User on 9/3/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_QUESTION_H
#define QUIZ_MANAGEMENT_NEW_QUESTION_H
#include <iostream>
using namespace std;

namespace model {
    class Question {
    private:
        string id;
        string question;
        string opA, opB, opC, opD;
        string correctAnswer;

    public:
        Question();

        void setId(const string &i);
        void setQuestion(const string &q);
        void setOpA(const string &op);
        void setOpB(const string &op);
        void setOpC(const string &op);
        void setOpD(const string &op);
        void setCorrectAns(const string &ans);

        string getId() const;
        string getQuestion() const;
        string getOpA() const;
        string getOpB() const;
        string getOpC() const;
        string getOpD() const;
        string getCorrect() const;


        void display() const;
    };
} // model

#endif //QUIZ_MANAGEMENT_NEW_QUESTION_H
