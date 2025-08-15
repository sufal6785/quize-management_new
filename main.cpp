//
// Created by User on 8/9/2025.
//
#include <iostream>

#include "include/models/Student.h"
#include "include/models/User.h"
#include "include/models/Utility.h"
#include "include/views/MainView.h"
#include "include/views/studentviews/LoginRegister.h"
#include "include/views/studentviews/StudentPortal.h"
using namespace view;
using namespace model;

int main() {
    // User *user = new Student();
    // if (const shared_ptr<User> users = user->loginUser("nn", "123")) {
    //     const shared_ptr<Student> st = dynamic_pointer_cast<Student>(users);
    //     st->display();
    // } else cout << "Failed" << endl;

    // StudentPortal::Welcome();
    // StudentPortal::options();


    // Clear screen (works on most systems)
    // #ifdef _WIN32
    //     system("cls");
    // #else
    //         system("clear");
    // #endif

    // MainView::Gretting();
    // MainView::Options();
    // MainView::select();
    // StudentPortal::MainView();
    LoginRegister::guest();         //***

    // User *users = new Student();
    // const shared_ptr<User> user = users->loginUser("ss", "123");
    // user->display();
    // int ch = getValidChoice();
    // cout<<ch;
}
