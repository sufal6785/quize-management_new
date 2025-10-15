// //
// // Created by User on 8/11/2025.
// //
// #include <iostream>
//
// #include "../views/studentviews/StudentPortal.h"
// #include "adminviews/AdminPortal.h"
// using namespace std;
// using namespace adminview;
// #include "MainView.h"
//
// namespace view {
//     void MainView::Gretting() {
//
//         cout << "\n\n";
//         cout << "========================================================\n";
//         cout << "               QUIZ MANAGEMENT SYSTEM                  \n";
//         cout << "========================================================\n";
//         cout << "                                                        \n";
//         cout << "    Welcome to our comprehensive quiz Management       \n";
//         cout << "    Platform! Manage quizzes, track performance,       \n";
//         cout << "    and enhance learning experiences.                  \n";
//         cout << "                                                        \n";
//         cout << "      Students: Take quizzes and view results          \n";
//         cout << "      Admins: Create and manage quiz content           \n";
//         cout << "                                                        \n";
//         cout << "========================================================\n";
//         cout << "\n";
//     }
//
//     void MainView::Options() {
//
//         cout << "==================== LOGIN PORTAL ====================\n";
//         cout << "                                                        \n";
//         cout << "Please select your role to continue:                   \n";
//         cout << "                                                        \n";
//         cout << "    1. Student Login                                   \n";
//         cout << "       -> Take quizzes and view your results            \n";
//         cout << "                                                        \n";
//         cout << "    2. Admin Login                                     \n";
//         cout << "       -> Manage quizzes and student accounts           \n";
//         cout << "                                                        \n";
//         cout << "========================================================\n";
//         cout << "Enter your choice (1 or 2): ";
//     }
//
//     void MainView::select() {
//         int choice;
//         cin >> choice;
//         if (choice == 1) {
//             StudentPortal::student_home();
//         }
//         if (choice == 2) {
//             AdminPortal::admin_home();
//         }
//     }
//
//     void MainView::home() {
//         Gretting();
//         Options();
//         select();
//     }
//
// }

//
// Created by User on 8/11/2025.
//
#include <iostream>
#include <limits>
#include "../views/studentviews/StudentPortal.h"
#include "adminviews/AdminPortal.h"
#include "MainView.h"

#include "../models/Utility.h"
using namespace std;
using namespace adminview;

namespace view {

    void MainView::Gretting() {
        cout << "\n\n";
        cout << "==========================================================\n";
        cout << "                 QUIZ MANAGEMENT SYSTEM                   \n";
        cout << "==========================================================\n";
        cout << "                                                          \n";
        cout << "     Welcome to our comprehensive Quiz Management        \n";
        cout << "     Platform! Manage quizzes, track performance,        \n";
        cout << "     and enhance learning experiences.                   \n";
        cout << "                                                          \n";
        cout << "       Students: Take quizzes and view results           \n";
        cout << "       Admins: Create and manage quiz content            \n";
        cout << "                                                          \n";
        cout << "==========================================================\n";
        cout << "\n";
    }

    void MainView::Options() {
        cout << "==========================================================\n";
        cout << "                     LOGIN PORTAL                         \n";
        cout << "==========================================================\n";
        cout << "                                                          \n";
        cout << "Please select your role to continue:                     \n";
        cout << "                                                          \n";
        cout << "    1. Student Login                                     \n";
        cout << "       Take quizzes and view your results                \n";
        cout << "                                                          \n";
        cout << "    2. Admin Login                                       \n";
        cout << "       Manage quizzes and student accounts               \n";
        cout << "                                                          \n";
        cout << "    3. Exit                                              \n";
        cout << "       Close the application                             \n";
        cout << "                                                          \n";
        cout << "==========================================================\n";
        cout << "\n Enter your choice (1-3): ";
    }

    void MainView::select() {

        switch (Utility::getValidChoice(1,3)) {
            case 1:
                cout << "\n Redirecting to Student Portal...\n";
                StudentPortal::student_home();
                break;

            case 2:
                cout << "\n Redirecting to Admin Portal...\n";
                AdminPortal::admin_home();
                break;

            case 3:
                cout << "\n==========================================================\n";
                cout << "        Thank you for using Quiz Management System!      \n";
                cout << "                    Goodbye!                              \n";
                cout << "==========================================================\n\n";
                exit(0);
                break;

            default:
                cout << "\n Invalid choice! Please select 1, 2, or 3.\n";
                cout << "\n>>> Press Enter to continue...";
                cin.get();
                home(); // Restart
                break;
        }
    }

    void MainView::home() {
        Gretting();
        Options();
        select();
    }
}
