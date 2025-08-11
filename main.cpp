//
// Created by User on 8/9/2025.
//
#include <iostream>

#include "include/models/Student.h"
#include "include/models/User.h"
using namespace model;

int main() {
    User *user = new Student();
    if (const shared_ptr<User> users = user->loginUser("nn", "123")) {
        const shared_ptr<Student> st = dynamic_pointer_cast<Student>(users);
        st->display();
    } else cout << "Failed" << endl;
}
