//
// Created by Ayesha on 9/3/2025.
//

#include "Question.h"

namespace model {
    Question::Question() {
        id = "";
        question = opA = opB = opC = opD = correctAnswer = "";
    }

    Question::Question(const string &id_, const string &q, const string &a, const string &b, const string &c, const string &d, const string &ans) {
        id = id_;
        question = q;
        opA = a;
        opB = b;
        opC = c;
        opD = d;
        correctAnswer = ans;
    }


    void Question::setId(const string &i) { id = i; }
    void Question::setQuestion(const string &q) { question = q; }
    void Question::setOpA(const string &op) { opA = op; }
    void Question::setOpB(const string &op) { opB = op; }
    void Question::setOpC(const string &op) { opC = op; }
    void Question::setOpD(const string &op) { opD = op; }
    void Question::setCorrectAns(const string &ans) { correctAnswer = ans; }

    string Question::getId() const { return id; }
    string Question::getQuestion() const { return question; }
    string Question::getOpA() const { return opA; }
    string Question::getOpB() const { return opB; }
    string Question::getOpC() const { return opC; }
    string Question::getOpD() const { return opD; }
    string Question::getCorrect() const { return correctAnswer; }

    void Question::display() const {
        cout << id <<". "<< question << endl;
        cout << opA << endl;
        cout << opB << endl;
        cout << opC << endl;
        cout << opD << endl;
    }
} // model
