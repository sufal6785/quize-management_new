//
// Created by User on 8/11/2025.
//
#include <iostream>

#include "../views/studentviews/StudentPortal.h"
using namespace std;
#include "MainView.h"

namespace view {
    // void MainView::Gretting() {
    //     //Here anyonew will See a welcme message like welcome to the quiz-Management or something else
    //     //which will suit more for the ui;
    // }
    //
    // void MainView::Options() {
    //     //here one will see two options, 1. Student login
    //     //2. Admin login
    void MainView::Gretting() {
        // Here anyone will see a welcome message like welcome to the quiz-Management or something else
        // which will suit more for the UI

        cout << "\n\n";
        cout << "========================================================\n";
        cout << "               QUIZ MANAGEMENT SYSTEM                  \n";
        cout << "========================================================\n";
        cout << "                                                        \n";
        cout << "    Welcome to our comprehensive quiz Management       \n";
        cout << "    Platform! Manage quizzes, track performance,       \n";
        cout << "    and enhance learning experiences.                  \n";
        cout << "                                                        \n";
        cout << "      Students: Take quizzes and view results          \n";
        cout << "      Admins: Create and manage quiz content           \n";
        cout << "                                                        \n";
        cout << "========================================================\n";
        cout << "\n";
    }

    void MainView::Options() {
        // Here one will see two options, 1. Student login, 2. Admin login

        cout << "==================== LOGIN PORTAL ====================\n";
        cout << "                                                        \n";
        cout << "Please select your role to continue:                   \n";
        cout << "                                                        \n";
        cout << "    1. Student Login                                   \n";
        cout << "       -> Take quizzes and view your results            \n";
        cout << "                                                        \n";
        cout << "    2. Admin Login                                     \n";
        cout << "       -> Manage quizzes and student accounts           \n";
        cout << "                                                        \n";
        cout << "========================================================\n";
        cout << "Enter your choice (1 or 2): ";
    }

    void MainView::select() {
        int choice;
        cin >> choice;
        if (choice == 1) {
            StudentPortal::student_home();
        }
    }
}
