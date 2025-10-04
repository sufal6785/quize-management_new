//
// Created by User on 9/3/2025.
//

#include "Quiz.h"
#include <fstream>
#include <iostream>

#include "Utility.h"
using namespace Utility;

namespace model {
    Quiz::Quiz() {
        score = 0;
        correct = 0;
        wrong = 0;
        load();
    }

    void Quiz::load() {
        ifstream file;
        file.open("include/Quiz/q.txt");
        if (!file.is_open()) {
            cout << "Failed" << endl;
            return;
        }
        string quizId, quizTitle;
        getline(file, quizId);
        getline(file, quizTitle);
        id = quizId;
        title = quizTitle;
        string qid, qst, a, b, c, d, corr;
        while (getline(file, qid) &&
               getline(file, qst) &&
               getline(file, a) &&
               getline(file, b) &&
               getline(file, c) &&
               getline(file, d) &&
               getline(file, corr)) {
            Question tem;
            tem.setId(qid);
            tem.setQuestion((qst));
            tem.setOpA(a);
            tem.setOpB(b);
            tem.setOpC(c);
            tem.setOpD(d);
            tem.setCorrectAns(corr);

            question.push_back(tem);
        }
    }


    // void Quiz::setId(const string &i) {
    //     id = i;
    // }
    //
    // void Quiz::setTitle(const string &t) {
    //     title = t;
    // }

    string Quiz::getId() const { return id; }

    string Quiz::getTitle() const { return title; }


    int Quiz::getScore() const {
        return score;
    }


    void Quiz::display() const {
        cout << "Quiz id: " << id << endl << title << endl;
        const size_t size = question.size();
        for (int i = 0; i < size; i++) {
            question[i].display();
        }
    }

    void Quiz::takeQuiz() {
        const size_t size = question.size();
        for (int i = 0; i < size; i++) {
            question[i].display();
            //answer should be caracter, change needed
            string answer = getInputString("Enter your answer: ");
            if (answer == question[i].getCorrect()) {
                correct++;
            } else { wrong++; }
        }
        score = correct - wrong;
    }

    void Quiz::report() const {
        cout << "Correct answer: " << correct << endl;
        cout << "Wrong answer: " << wrong << endl;
        cout << "\nYour obtained mark: " << score << endl;
    }
} // model
