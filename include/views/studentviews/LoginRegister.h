//
// Created by Niloy on 8/11/2025.
//

#ifndef LOGINREGISTER_H
#define LOGINREGISTER_H
#include <iostream>
#include <limits>
#include "StudentPortal.h"
#include "../../models/Student.h"
#include "../../models/Utility.h"
using namespace Utility;

namespace view {
    using namespace model;

    class LoginRegister {
    public:
        // Helper function to pause and wait for user
        static void waitForUser() {
            cout << "\n>>> Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        static void login_or_register() { // NOLINT(*-no-recursion)
            cout << "\n==========================================================\n";
            cout << "                 STUDENT AUTHENTICATION                   \n";
            cout << "==========================================================\n";
            cout << "                                                          \n";
            cout << "Please choose an option to continue:                     \n";
            cout << "                                                          \n";
            cout << "    1. Login                                             \n";
            cout << "       I already have a student account                  \n";
            cout << "       Access my quizzes and results                     \n";
            cout << "                                                          \n";
            cout << "    2. Register                                          \n";
            cout << "       I'm new to the system                             \n";
            cout << "       Create a new student account                      \n";
            cout << "                                                          \n";
            cout << "    3. Back to Main Menu                                 \n";
            cout << "       Return to role selection                          \n";
            cout << "                                                          \n";
            cout << "==========================================================\n";
            cout << "\n Enter your choice (1-3): ";

            int choice = getValidChoice(1, 3);

            switch (choice) {
                case 1:
                    cout << "\n Redirecting to Login...\n\n";
                    loginView();
                    break;
                case 2:
                    cout << "\n Redirecting to Registration...\n\n";
                    registerView();
                    break;
                case 3:
                    cout << "\n Returning to Main Menu...\n";
                    return;
                default:
                    break;
            }
        }


        static void loginView() { // NOLINT(*-no-recursion)
            cout << "==========================================================\n";
            cout << "                     STUDENT LOGIN                        \n";
            cout << "==========================================================\n\n";

            string id = getInputString("Student ID: ");
            string pass = getInputString("Password: ");

            cout << "\n Authenticating...\n";

            auto user = make_unique<Student>();
            const shared_ptr<Student> student = dynamic_pointer_cast<Student>(
                user->loginUser(id, pass));

            if (student) {
                cout << "\n==========================================================\n";
                cout << "              LOGIN SUCCESSFUL!                           \n";
                cout << "==========================================================\n";
                cout << "\n Welcome back, " << student->getName() << "!\n";
                cout << " Redirecting to Student Portal...\n";

                waitForUser();
                StudentPortal::action(student);
            } else {
                cout << "\n==========================================================\n";
                cout << "                 LOGIN FAILED                             \n";
                cout << "==========================================================\n";
                cerr << "\n Authentication failed. Please check your credentials.\n";
                cerr << "                                                          \n";
                cerr << " Possible reasons:                                        \n";
                cerr << "  - Incorrect Student ID                                  \n";
                cerr << "  - Incorrect Password                                    \n";
                cerr << "  - Account does not exist                                \n";
                cerr << "                                                          \n";

                waitForUser();
                login_or_register();
            }
        }

        static void registerView() { // NOLINT(*-no-recursion)
            cout << "==========================================================\n";
            cout << "                  STUDENT REGISTRATION                    \n";
            cout << "==========================================================\n\n";

            cout << "Please provide your information:\n\n";

            string name = getInputString("Full Name: ");
            string id = getInputString("Student ID: ");
            string pass = getInputString("Password: ");

            cout << "\n Processing registration...\n";

            if (!isExistInFile("student-list.dat", id)) {
                auto student = make_unique<Student>();
                bool status = student->registerUser(name, id, pass);

                if (status) {
                    cout << "\n==========================================================\n";
                    cout << "            REGISTRATION SUCCESSFUL!                      \n";
                    cout << "==========================================================\n";
                    cout << "\n Congratulations, " << name << "!\n";
                    cout << " Your account has been created successfully.\n";
                    cout << "                                                          \n";
                    cout << " Account Details:                                         \n";
                    cout << "  Name: " << name << "\n";
                    cout << "  Student ID: " << id << "\n";
                    cout << "                                                          \n";
                    cout << " You can now login with your credentials.\n";

                    waitForUser();
                    cout << "\n Redirecting to Login...\n";
                    login_or_register();
                }
            } else {
                cout << "\n==========================================================\n";
                cout << "              REGISTRATION FAILED                         \n";
                cout << "==========================================================\n";
                cerr << "\n Unable to create your account.\n";
                cerr << "                                                          \n";
                cerr << " Possible reasons:                                        \n";
                cerr << "  - Student ID '" << id << "' already exists              \n";
                cerr << "  - Invalid information provided                          \n";
                cerr << "  - System error                                          \n";
                cerr << "                                                          \n";
                cerr << " Please try again with a different Student ID.\n";

                waitForUser();
                login_or_register();
            }
        }
    };
}
#endif //LOGINREGISTER_H
