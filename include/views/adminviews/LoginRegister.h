//
// Created by User on 10/7/2025.
//

#ifndef QUIZ_MANAGEMENT_NEW_LOGINREGISTER_H
#define QUIZ_MANAGEMENT_NEW_LOGINREGISTER_H
#include <iostream>
#include "AdminPortal.h"
#include "../../models/Admin.h"
#include "../../models/Utility.h"
using namespace Utility;

namespace adminview {
    using namespace model;

    class LoginRegister {
    public:
        static void login_or_register() { // NOLINT(*-no-recursion)
            cout << "\n";
            cout << "Please choose an option to continue:                    \n";
            cout << "                                                        \n";
            cout << "    1. LOGIN                                            \n";
            cout << "       -> I already have an admin account               \n";
            cout << "       -> Manage quizzes and student accounts           \n";
            cout << "                                                        \n";
            cout << "    2. REGISTER                                         \n";
            cout << "       -> I'm new to the system                         \n";
            cout << "       -> Create a new admin account                    \n";
            cout << "                                                        \n";
            cout << "========================================================\n";
            cout << "Enter your choice (1 for Login, 2 for Register): \n";

            int choice = getValidChoice(1, 2);

            if (choice == 1) {
                cout << "\nRedirecting to Login...\n";
                loginView();
            }
            if (choice == 2) {
                cout << "\nRedirecting to Registration...\n";
                registerView();
            }
        }


        static void loginView() { // NOLINT(*-no-recursion)
            string id = getInputString("Enter userid: ");
            string pass = getInputString("Enter password: ");

            const auto user = make_unique<Admin>();
            const shared_ptr<Admin> admin = dynamic_pointer_cast<Admin>(
                user->loginUser(id, pass));

            if (admin) {
                cout << "Congratulations." << endl;
                AdminPortal::action(admin);
            } else {
                cout << "Invalid credentials" << endl;
                login_or_register();
            }
        }

        static void registerView() { // NOLINT(*-no-recursion)
            string name = getInputString("Enter your name: ");
            string id = getInputString("Enter your id: ");
            string pass = getInputString("Enter your password: ");
            string course_code = getInputString("Enter your course_code: ");


             auto admin = make_unique<Admin>();

             bool status =   admin->admin_register(name,id, pass,course_code);

            if (status) {
                cout << "Congratulations " << name << "!!!\nYour registration has been completed...";
                cout << "\nRedirecting to Login Menu...\n";
                login_or_register();
            } else {
                cout << "Oops!!! Username already exist...!!!\n";
                login_or_register();
            }
        }
    };
    }

#endif //QUIZ_MANAGEMENT_NEW_LOGINREGISTER_H
