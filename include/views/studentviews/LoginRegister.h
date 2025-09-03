//
// Created by User on 8/11/2025.
//

#ifndef LOGINREGISTER_H
#define LOGINREGISTER_H
#include <iostream>
#include "StudentPortal.h"
#include "welcome.h"
#include "../../models/Student.h"
#include "../../models/Utility.h"
using namespace Utility;

namespace view {
    using namespace model;

    class LoginRegister {
    public:
        static void login_or_register() { // NOLINT(*-no-recursion)
            cout << "\n";
            cout << "Please choose an option to continue:                   \n";
            cout << "                                                        \n";
            cout << "    1. LOGIN                                           \n";
            cout << "       -> I already have a student account              \n";
            cout << "       -> Access my quizzes and results                 \n";
            cout << "                                                        \n";
            cout << "    2. REGISTER                                        \n";
            cout << "       -> I'm new to the system                         \n";
            cout << "       -> Create a new student account                  \n";
            cout << "                                                        \n";
            cout << "========================================================\n";
            cout << "Enter your choice (1 for Login, 2 for Register): \n";

            int choice = getValidChoice(1,2);

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

            auto student = make_unique<Student>();
            const shared_ptr<User> user = student->loginUser(id, pass);

            if (user) {
                cout << "Congratulations." << endl;
                StudentPortal::action();
            } else {
                cout << "Invalid credentials" << endl;
                login_or_register();
            }
        }

        static void registerView() { // NOLINT(*-no-recursion)
            string name = getInputString("Enter your name: ");
            string id = getInputString("Enter your id: ");
            string pass = getInputString("Enter your password: ");

            auto student = make_unique<Student>();
            bool status = student->registerUser(name, id, pass);

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
#endif //LOGINREGISTER_H
