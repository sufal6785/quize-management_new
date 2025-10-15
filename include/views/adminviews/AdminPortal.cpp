//
// Created by Sufal on 10/7/2025.
//

#include "AdminPortal.h"
#include <fstream>
#include "../../models/Question.h"
#include "../../models/Utility.h"
#include "../adminviews/LoginRegister.h"
#include "../adminviews/welcome.h"
#include <iomanip>
#include <limits>
using namespace Utility;

namespace adminview {
    // Helper function to pause and wait for user
    void waitForUser() {
        cout << "\n>>> Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Helper function to display section header
    void displaySectionHeader(const string &title) {
        cout << "\n==========================================================\n";
        cout << "   " << left << setw(47) << title << " \n";
        cout << "==========================================================\n\n";
    }

    void AdminPortal::options() {
        cout << "\n==========================================================\n";
        cout << "                   ADMIN MAIN MENU                         \n";
        cout << "==========================================================\n";
        cout << "                                                           \n";
        cout << "   1. Create Quiz                                          \n";
        cout << "      Set up a new quiz for students                       \n";
        cout << "                                                           \n";
        cout << "   2. Create Question                                      \n";
        cout << "      Add questions to an existing quiz                    \n";
        cout << "                                                           \n";
        cout << "   3. View All Active Quizzes                              \n";
        cout << "      See all quizzes in the system                        \n";
        cout << "                                                           \n";
        cout << "   4. View Result of a Quiz                                \n";
        cout << "      Check your score for a specific quiz                 \n";
        cout << "                                                           \n";
        cout << "   5. View All Results for Students                        \n";
        cout << "      See results from all quizzes you've taken            \n";
        cout << "                                                           \n";
        cout << "   6. View All Student                                     \n";
        cout << "      Register a new student account                       \n";
        cout << "                                                           \n";
        cout << "   7. Add Student                                          \n";
        cout << "      Register a new student account                       \n";
        cout << "                                                           \n";
        cout << "   8. Logout                                               \n";
        cout << "      Exit admin panel                                     \n";
        cout << "                                                           \n";
        cout << "==========================================================\n";
        cout << "\n Enter your choice (1-8): ";
    }

    void AdminPortal::select(const shared_ptr<Admin> &admin) {
        cout << "\n==========================================================\n";
        cout << "             What would you like to do next?               \n";
        cout << "==========================================================\n";
        cout << "\n  1. Return to Main Menu\n";
        cout << "  2. Logout\n";
        cout << "\n Enter your choice: ";

        if (getValidChoice(1, 2) == 1) {
            action(admin);
        } else {
            cout << "\n Successfully logged out. Thank you!\n\n";
            exit(1);
        }
    }

    void AdminPortal::action(const shared_ptr<Admin> &admin) {
        // Display welcome message with admin name
        cout << "\n====================================================\n";
        cout << "   Admin Panel - Welcome, " << left << setw(25) << admin->getName() << " \n";
        cout << "====================================================\n";

        options();

        switch (getValidChoice(1, 8)) {
            case 1: {
                displaySectionHeader("CREATE NEW QUIZ");

                const string quiz_id = getInputString("Enter Quiz ID: ");
                const string title = getInputString("Enter Quiz Title: ");

                cout << "\n Processing...\n";

                if (admin->addQuiz(quiz_id, title)) {
                    cout << "\n Quiz created successfully!\n";
                    cout << "  Quiz ID: " << quiz_id << "\n";
                    cout << "  Title: " << title << "\n";


                    string n = getInputString("How many questions do you want to want to add? ");
                    for (int i = 1; i <= stoi(n); i++) {
                        cout << "\n--- Question Details ---\n\n";
                        string id = to_string(i);
                        string quest = getInputString("Question Text: ");

                        cout << "\n--- Answer Options ---\n\n";
                        string a = getInputString("Option A: ");
                        string b = getInputString("Option B: ");
                        string c = getInputString("Option C: ");
                        string d = getInputString("Option D: ");

                        cout << "\n";
                        string ans = getInputString("Correct Answer (A/B/C/D): ");

                        Question question(id, quest, a, b, c, d, ans);

                        cout << "\n Processing...\n";

                        if (admin->addQuestion(question, quiz_id)) {
                            cout << "\n Question " << i << " added successfully!\n";
                        } else {
                            cerr << "\n Error: Cannot add question\n";
                            cerr << "  Possible reasons:\n";
                            cerr << "  - Question ID already exists in this quiz\n";
                            cerr << "  - Invalid question format\n";
                        }
                    }
                } else {
                    cerr << "\n Error: Cannot create quiz '" << quiz_id << "'\n";
                    cerr << "  Possible reasons:\n";
                    cerr << "  - Quiz ID already exists\n";
                    cerr << "  - Invalid quiz ID format\n";
                }

                waitForUser();
                break;
            }

            case 2: {
                displaySectionHeader("ADD QUESTION TO QUIZ");

                string quiz_id = getInputString("Enter Quiz ID: ");

                cout << "\n--- Question Details ---\n\n";
                string id = getInputString("Question ID: ");
                string quest = getInputString("Question Text: ");

                cout << "\n--- Answer Options ---\n\n";
                string a = getInputString("Option A: ");
                string b = getInputString("Option B: ");
                string c = getInputString("Option C: ");
                string d = getInputString("Option D: ");

                cout << "\n";
                string ans = getInputString("Correct Answer (A/B/C/D): ");

                Question question(id, quest, a, b, c, d, ans);

                cout << "\n Processing...\n";

                if (admin->addQuestion(question, quiz_id)) {
                    cout << "\n Question added successfully!\n";
                    cout << "  Quiz ID: " << quiz_id << "\n";
                    cout << "  Question ID: " << id << "\n";
                } else {
                    cerr << "\n Error: Cannot add question\n";
                    cerr << "  Possible reasons:\n";
                    cerr << "  - Quiz ID '" << quiz_id << "' does not exist\n";
                    cerr << "  - Question ID already exists in this quiz\n";
                    cerr << "  - Invalid question format\n";
                }

                waitForUser();
                break;
            }

            case 3: {
                displaySectionHeader("ALL ACTIVE QUIZZES");

                vector<string> quizzes = admin->showAvailableQuiz();

                if (!quizzes.empty()) {
                    cout << " Active Quizzes in System:\n";
                    cout << string(60, '-') << "\n";

                    for (int i = 0; i < quizzes.size(); i++) {
                        cout << "  [" << (i + 1) << "] " << quizzes[i] << "\n";
                    }

                    cout << string(60, '-') << "\n";
                    cout << "\n Total active quizzes: " << quizzes.size() << "\n";
                } else {
                    cout << " No quizzes available in the system.\n";
                    cout << " Create your first quiz using option 1.\n";
                }

                waitForUser();
                break;
            }

            case 4: {
                displaySectionHeader("VIEW QUIZ RESULT");
                vector<string> aq = admin->showAvailableQuiz();
                if (!aq.empty()) {
                    cout << " Available Quizzes:\n";
                    cout << string(60, '-') << "\n";

                    const size_t size = aq.size();

                    for (int i = 0; i < size; i++) {
                        cout << "  [" << (i + 1) << "] " << aq[i] << "\n";
                    }

                    cout << string(60, '-') << "\n";
                    cout << "\n Enter the quiz number to see Result:\n";
                    int ch = getValidChoice(1, static_cast<int>(size));
                    const string qz_file = "include/quiz/" + aq[ch - 1] + ".txt";

                    ifstream file(qz_file);
                    string qz_id;
                    string qz_tittle;
                    getline(file, qz_id);
                    getline(file, qz_tittle);

                    Quiz quiz(qz_id, qz_tittle);
                    vector<Result> results = quiz.getResult();

                    if (results.empty()) {
                        cout << "  No results available yet.\n";
                        cout << "  Results will appear here after student complete quizzes.\n";
                    } else {
                        cout << " Results Summary for " << quiz.getId() << ":\n";
                        cout << string(60, '-') << "\n";
                        cout << left << setw(33) << "  Student ID" << setw(15) << "Score" << "\n";
                        cout << string(60, '-') << "\n";

                        for (const auto &r: results) {
                            cout << "  " << left << setw(31) << r.getStudentId()
                                    << setw(15) << r.getScore() << "\n";
                        }

                        cout << string(60, '-') << "\n";
                        cout << "\n Total student : " << results.size() << "\n";
                    }
                } else {
                    cout << "  No quizzes are currently available.\n";
                    cout << "  Please check back later or contact your instructor.\n";
                }
                waitForUser();
                break;
            }

            case 5: {
                displaySectionHeader("ALL QUIZ RESULTS");

                vector<Student> students = admin->allStudents();
                for (auto student: students) {
                    vector<Result> results = student.getResult();

                    if (results.empty()) {
                        cout << string(60, '-') << "\n";
                        cout << "  No results available yet.\n";
                        cout << "  Results will appear here after " << student.getName() << " complete quizzes.\n";
                        cout << string(60, '-') << "\n";
                        cout << "\n Total quizzes completed by " << student.getName()
                                << ": " << results.size() << "\n\n";
                    } else {
                        cout << " Results Summary for " << student.getName() << ":\n";
                        cout << string(60, '-') << "\n";
                        cout << left << setw(30) << "  Quiz ID" << setw(15) << "Score" << "\n";
                        cout << string(60, '-') << "\n";

                        for (const auto &r: results) {
                            cout << "  " << left << setw(28) << r.getQuizId()
                                    << setw(15) << r.getScore() << "\n";
                        }

                        cout << string(60, '-') << "\n";
                        cout << "\n Total quizzes completed by " << student.getName()
                                << ": " << results.size() << "\n\n";
                    }
                }
                waitForUser();
                break;
            }

            case 6: {
                displaySectionHeader("VIEW ALL STUDENT");
                vector<Student> students = admin->allStudents();
                int cnt = 0;
                cout << string(60, '-') << "\n";
                cout << "All Student Details: \n";
                // cout << string(60, '-') << "\n";
                for (auto student: students) {
                    cout << string(60, '-') << "\n";
                    student.display();
                    cnt++;
                }
                cout << string(60, '-') << "\n";
                cout << "\n Total student: " << cnt << "\n";

                waitForUser();
                break;
            }

            case 7: {
                displaySectionHeader("ADD NEW STUDENT");

                string name = getInputString("Student Name: ");
                string id = getInputString("Student ID: ");
                string pass = getInputString("Password: ");

                Student student(name, id, pass);

                cout << "\n Processing...\n";

                if (admin->addStudent(student)) {
                    cout << "\n Student registered successfully!\n";
                    cout << "  Name: " << name << "\n";
                    cout << "  Student ID: " << id << "\n";
                    cout << "  The student can now login with their credentials.\n";
                } else {
                    cerr << "\n Error: Cannot register student\n";
                    cerr << "  Possible reasons:\n";
                    cerr << "  - Student ID already exists\n";
                    cerr << "  - Invalid student information\n";
                }

                waitForUser();
                break;
            }

            case 8: {
                cout << "\n Logging out...\n";
                cout << "  Thank you for using the Admin Portal!\n\n";
                exit(1);
                break;
            }

            default:
                cout << "\n An unexpected error occurred.\n";
                cout << "   Please try again or contact support if the problem persists.\n";
                waitForUser();
                break;
        }

        select(admin);
    }

    void AdminPortal::admin_home() {
        Welcome::welcome();
        LoginRegister::login_or_register();
    }
}
