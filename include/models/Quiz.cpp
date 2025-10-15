//
// Created by User on 9/3/2025.
//

#include "Quiz.h"
#include <fstream>
#include <iostream>

#include "Utility.h"
using namespace Utility;

namespace model {
    //Loaded with question
    Quiz::Quiz() : score(0), correct(0), wrong(0) {
        load();
    }

    //Can be used for adding new quiz
    Quiz::Quiz(const string &quiz_id, const string &quiz_title) : score(0), correct(0), wrong(0) {
        id = quiz_id;
        title = quiz_title;
        load();
    }

    void Quiz::load() {
        ifstream file;
        file.open("include/quiz/quiz.txt");
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


    // void quiz::setId(const string &i) {
    //     id = i;
    // }
    //
    // void quiz::setTitle(const string &t) {
    //     title = t;
    // }

    string Quiz::getId() const { return id; }

    string Quiz::getTitle() const { return title; }


    int Quiz::getScore() const {
        return score;
    }

    int Quiz::getCorrect() const {
        return  correct;
    }

    int Quiz::getWrong() const {
        return  wrong;
    }


    void Quiz::display() const {
        cout << "quiz id: " << id << endl << title << endl;
        const size_t size = question.size();
        for (int i = 0; i < size; i++) {
            question[i].display();
        }
    }

    void Quiz::takeQuiz() {
        const size_t size = question.size();
        for (int i = 0; i < size; i++) {
            question[i].display();
            //answer should be character, change needed
            string answer = getInputString("Enter your answer: ");
            if (answer == question[i].getCorrect()) {
                correct++;
            } else { wrong++; }
        }
        score = correct - wrong;
    }

    void Quiz::report() const {
        cout << "\nCorrect answer: " << correct << endl;
        cout << "Wrong answer: " << wrong << endl;
        cout << "\nYour obtained mark: " << score << endl;
    }
} // model
