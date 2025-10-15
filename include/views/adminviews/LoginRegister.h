//
// Created by Niloy on 10/7/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_LOGINREGISTER_H
#define QUIZ_MANAGEMENT_NEW_LOGINREGISTER_H
#include <iostream>
#include <limits>
#include "AdminPortal.h"
#include "welcome.h"
#include "../../models/Admin.h"
#include "../../models/Utility.h"
using namespace Utility;

namespace adminview {
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
            cout << "                  ADMIN AUTHENTICATION                    \n";
            cout << "==========================================================\n";
            cout << "                                                          \n";
            cout << "Please choose an option to continue:                     \n";
            cout << "                                                          \n";
            cout << "    1. Login                                             \n";
            cout << "       I already have an admin account                   \n";
            cout << "       Manage quizzes and student accounts               \n";
            cout << "                                                          \n";
            cout << "    2. Register                                          \n";
            cout << "       I'm new to the system                             \n";
            cout << "       Create a new admin account                        \n";
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
            cout << "                      ADMIN LOGIN                         \n";
            cout << "==========================================================\n\n";

            string id = getInputString("Admin ID: ");
            string pass = getInputString("Password: ");

            cout << "\n Authenticating...\n";

            auto user = make_unique<Admin>();
            const shared_ptr<Admin> admin = dynamic_pointer_cast<Admin>(
                user->loginUser(id, pass));

            if (admin) {
                cout << "\n==========================================================\n";
                cout << "              LOGIN SUCCESSFUL!                           \n";
                cout << "==========================================================\n";
                cout << "\n Welcome back, " << admin->getName() << "!\n";
                cout << " Redirecting to Admin Menu...\n";

                waitForUser();
                AdminPortal::action(admin);
            } else {
                cout << "\n==========================================================\n";
                cout << "                 LOGIN FAILED                             \n";
                cout << "==========================================================\n";
                cerr << "\n Authentication failed. Please check your credentials.\n";
                cerr << "                                                          \n";
                cerr << " Possible reasons:                                        \n";
                cerr << "  - Incorrect Admin ID                                    \n";
                cerr << "  - Incorrect Password                                    \n";
                cerr << "  - Account does not exist                                \n";
                cerr << "                                                          \n";

                waitForUser();
                login_or_register();
            }
        }

        static void registerView() { // NOLINT(*-no-recursion)
            cout << "==========================================================\n";
            cout << "                   ADMIN REGISTRATION                     \n";
            cout << "==========================================================\n\n";

            cout << "Please provide your information:\n\n";

            string name = getInputString("Full Name: ");
            string id = getInputString("Admin ID: ");
            string pass = getInputString("Password: ");
            string course_code = getInputString("Course Code: ");

            cout << "\n Processing registration...\n";

            if (!isExistInFile("admin-list.dat", id)) {
                auto admin = make_unique<Admin>();
                bool status = admin->admin_register(name, id, pass, course_code);

                if (status) {
                    cout << "\n==========================================================\n";
                    cout << "            REGISTRATION SUCCESSFUL!                      \n";
                    cout << "==========================================================\n";
                    cout << "\n Congratulations, " << name << "!\n";
                    cout << " Your admin account has been created successfully.\n";
                    cout << "                                                          \n";
                    cout << " Account Details:                                         \n";
                    cout << "  Name: " << name << "\n";
                    cout << "  Admin ID: " << id << "\n";
                    cout << "  Course Code: " << course_code << "\n";
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
                cerr << "  - Admin ID '" << id << "' already exists                \n";
                cerr << "  - Invalid information provided                          \n";
                cerr << "  - System error                                          \n";
                cerr << "                                                          \n";
                cerr << " Please try again with a different Admin ID.\n";

                waitForUser();
                login_or_register();
            }
        }
    };
}

#endif //QUIZ_MANAGEMENT_NEW_LOGINREGISTER_H
