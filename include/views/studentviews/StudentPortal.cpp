// //
// // Created by User on 8/9/2025.
// //
//
// #include "StudentPortal.h"
// #include "welcome.h"
// #include "LoginRegister.h"
// using namespace Utility;
//
// namespace view {
//     void StudentPortal::options() {
//         cout << "\n=================== MAIN MENU ===================\n";
//         cout << "Please select an option from the menu below:\n\n";
//         cout << "1. Attend quiz\n";
//         cout << "2. View All Active Quizzes\n";
//         cout << "3. See Result of a quiz\n";
//         cout << "4. See All Results\n";
//         cout << "5. See Attended quiz List\n";
//         cout << "6. Logout\n";
//         cout << "=================================================\n";
//         cout << "Enter your choice (1-6): ";
//     }
//
//     void StudentPortal::select(const shared_ptr<Student> &student) {
//         cout << "\nPlease select an option: " << endl;
//         cout << "1. Main menu\n";
//         cout << "2. Logout\n";
//         cout << "\nEnter your choice: ";
//         if (getValidChoice(1, 2) == 1) {
//             action(student);
//         } else {
//             exit(1);
//         }
//     }
//
//
//     void StudentPortal::action(const shared_ptr<Student> &student) {
//         //action(shared_ptr<User> student)
//         options();
//         int choice = getValidChoice(1, 6);
//
//         switch (choice) {
//             case 1: {
//                 vector<string> aq = student->showAvailableQuiz();
//
//                 if (!aq.empty()) {
//                     cout << "Available Quizzes:\n";
//
//                     const size_t size = aq.size();
//
//                     for (int i = 0; i < size; i++) {
//                         cout << i + 1 << ". " << aq[i] << endl;
//                     }
//
//                     cout << "Enter the quiz serial number: ";
//                     int ch = getValidChoice(1, 1 + static_cast<int>(size));
//
//                     student->attendQuiz(aq[ch - 1]);
//                 } else {
//                     cout << "OOPs!!! No quiz is available...";
//                 }
//
//                 break;
//             }
//             case 2: {
//                 vector<string> aq = student->showAvailableQuiz();
//                 if (!aq.empty()) {
//                     cout << "Available Quizzes:\n";
//                     for (int i = 0; i < aq.size(); i++) {
//                         cout << i + 1 << ". " << aq[i] << endl;
//                     }
//                 } else {
//                     cout << "OOPs!!! No quiz is available...";
//                 }
//                 break;
//             }
//             case 3:
//                 cout << "seeQuizResult()";
//                 break;
//             case 4: {
//                 vector<Result> results = student->getResult();
//                 if (results.empty()) {
//                     cout << "No result available for " << student->getName() << endl;
//                 } else {
//                     cout << student->getName() << ", your attended quizzes results are: " << endl;
//                     for (const auto &r: results) {
//                         cout << "Quiz ID: " << r.getQuizId() << "\n" << "Score: " << r.getScore() << endl;
//                     }
//                 }
//                 break;
//             }
//             case 5: {
//                 vector<Result> results = student->getResult();
//                 if (results.empty()) {
//                     cout << student->getName() << ", you don't attend any quizzes" << endl;
//                 } else {
//                     cout << student->getName() << ", your attended quizzes are: " << endl;
//                     int cnt = 0;
//                     for (const auto &r: results) {
//                         cnt++;
//                         cout << cnt << ". " << r.getQuizId() << endl;
//                     }
//                 }
//                 break;
//             }
//             case 6:
//                 exit(1);
//                 break;
//             default:
//                 cout << "Unexpected error occurred. Please try again.\n";
//                 break;
//         }
//         select(student);
//     }
//
//     void StudentPortal::student_home() {
//         Welcome::welcome();
//         LoginRegister::login_or_register();
//     }
// }

//
// Created by User on 8/9/2025.
//

#include "StudentPortal.h"
#include "welcome.h"
#include "LoginRegister.h"
#include <iomanip>
#include <limits>
using namespace Utility;

namespace view {

    // Helper function to pause and wait for user
    void waitForUser() {
        cout << "\n>>> Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Helper function to display section header
    void displaySectionHeader(const string& title) {
        cout << "\n==========================================================\n";
        cout << "   " << left << setw(47) << title << " \n";
        cout << "==========================================================\n\n";
    }

    void StudentPortal::options() {
        cout << "\n==========================================================\n";
        cout << "                      MAIN MENU                            \n";
        cout << "==========================================================\n";
        cout << "                                                           \n";
        cout << "   1. Attend Quiz                                          \n";
        cout << "      Take an available quiz now                           \n";
        cout << "                                                           \n";
        cout << "   2. View All Active Quizzes                           \n";
        cout << "      See all quizzes available for you                    \n";
        cout << "                                                           \n";
        cout << "   3. View Result of a Quiz                             \n";
        cout << "      Check your score for a specific quiz                 \n";
        cout << "                                                           \n";
        cout << "   4. View All Results                                  \n";
        cout << "      See results from all quizzes you've taken            \n";
        cout << "                                                           \n";
        cout << "   5. View Attended Quiz History                        \n";
        cout << "      See list of quizzes you have completed               \n";
        cout << "                                                           \n";
        cout << "   6. Logout                                             \n";
        cout << "      Exit your account                                    \n";
        cout << "                                                           \n";
        cout << "===========================================================\n";
        cout << "\n Enter your choice (1-6): ";
    }

    void StudentPortal::select(const shared_ptr<Student> &student) {
        cout << "\n==========================================================\n";
        cout << "             What would you like to do next?         \n";
        cout << "==========================================================\n";
        cout << "\n  1. Return to Main Menu\n";
        cout << "  2. Logout\n";
        cout << "\n Enter your choice: ";

        if (getValidChoice(1, 2) == 1) {
            action(student);
        } else {
            cout << "\n Successfully logged out. Thank you for using the system!\n\n";
            exit(1);
        }
    }

    void StudentPortal::action(const shared_ptr<Student> &student) {
        // Display welcome message with student name
        cout << "\n====================================================\n";
        cout << "   Welcome, " << left << setw(38) << student->getName() << " \n";
        cout << "====================================================\n";

        options();
        int choice = getValidChoice(1, 6);

        switch (choice) {
            case 1: {
                displaySectionHeader("ATTEND QUIZ");

                vector<string> aq = student->showAvailableQuiz();

                if (!aq.empty()) {
                    cout << " Available Quizzes:\n";
                    cout << string(60, '-') << "\n";

                    const size_t size = aq.size();

                    for (int i = 0; i < size; i++) {
                        cout << "  [" << (i + 1) << "] " << aq[i] << "\n";
                    }

                    cout << string(60, '-') << "\n";
                    cout << "\n Enter the quiz number to attend: ";
                    int ch = getValidChoice(1, static_cast<int>(size));

                    cout << "\n Loading quiz...\n";
                    student->attendQuiz(aq[ch - 1]);
                    cout << "\n Quiz completed successfully!\n";
                } else {
                    cout << "  No quizzes are currently available.\n";
                    cout << "  Please check back later or contact your instructor.\n";
                }

                waitForUser();
                break;
            }

            case 2: {
                displaySectionHeader("ALL ACTIVE QUIZZES");

                vector<string> aq = student->showAvailableQuiz();

                if (!aq.empty()) {
                    cout << " Currently Available Quizzes:\n";
                    cout << string(60, '-') << "\n";

                    for (int i = 0; i < aq.size(); i++) {
                        cout << "  [" << (i + 1) << "] " << aq[i] << "\n";
                    }

                    cout << string(60, '-') << "\n";
                    cout << "\n Total quizzes available: " << aq.size() << "\n";
                } else {
                    cout << " No quizzes are currently available.\n";
                    cout << " New quizzes will appear here when your instructor adds them.\n";
                }

                waitForUser();
                break;
            }

            case 3: {
                displaySectionHeader("VIEW QUIZ RESULT");
                cout << " This feature will be available soon.\n";
                cout << " You'll be able to check individual quiz results here.\n";
                waitForUser();
                break;
            }

            case 4: {
                displaySectionHeader("ALL QUIZ RESULTS");

                vector<Result> results = student->getResult();

                if (results.empty()) {
                    cout << "  No results available yet.\n";
                    cout << "  Results will appear here after you complete quizzes.\n";
                } else {
                    cout << " Results Summary for " << student->getName() << ":\n";
                    cout << string(60, '-') << "\n";
                    cout << left << setw(30) << "  Quiz ID" << setw(15) << "Score" << "\n";
                    cout << string(60, '-') << "\n";

                    for (const auto &r: results) {
                        cout << "  " << left << setw(28) << r.getQuizId()
                             << setw(15) << r.getScore() << "\n";
                    }

                    cout << string(60, '-') << "\n";
                    cout << "\n Total quizzes completed: " << results.size() << "\n";
                }

                waitForUser();
                break;
            }

            case 5: {
                displaySectionHeader("QUIZ HISTORY");

                vector<Result> results = student->getResult();

                if (results.empty()) {
                    cout << " You haven't attended any quizzes yet.\n";
                    cout << " Quiz history will appear here after you take your first quiz.\n";
                } else {
                    cout << " Quizzes Attended by " << student->getName() << ":\n";
                    cout << string(60, '-') << "\n";

                    int cnt = 0;
                    for (const auto &r: results) {
                        cnt++;
                        cout << "  [" << cnt << "] " << r.getQuizId() << "\n";
                    }

                    cout << string(60, '-') << "\n";
                    cout << "\n Total quizzes attended: " << cnt << "\n";
                }

                waitForUser();
                break;
            }

            case 6: {
                cout << "\n Logging out...\n";
                cout << "  Thank you for using the Student Portal, " << student->getName() << "!\n\n";
                exit(1);
                break;
            }

            default:
                cout << "\n An unexpected error occurred.\n";
                cout << "   Please try again or contact support if the problem persists.\n";
                waitForUser();
                break;
        }

        select(student);
    }

    void StudentPortal::student_home() {
        Welcome::welcome();
        LoginRegister::login_or_register();
    }
}
