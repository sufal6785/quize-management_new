//
// Created by User on 8/9/2025.
//
#include <iostream>

#include "include/models/Quiz.h"
#include "include/models/Student.h"
#include "include/models/Admin.h"
#include "include/models/User.h"
#include "include/models/Utility.h"
#include "include/views/MainView.h"
#include "include/views/studentviews/LoginRegister.h"
#include "include/views/studentviews/StudentPortal.h"
using namespace view;
using namespace model;

#include <fstream>
#include <filesystem>
using namespace filesystem;

int main() {
    // StudentPortal::student_home();
    // auto user = make_unique<Student>();
    // // const shared_ptr<User> user = student->loginUser(id, pass);
    // const shared_ptr<User> student =user->loginUser("ss","123");
    // student->display();
    // quiz qz;
    // qz.setId("quiz01");
    // qz.setTitle("Sufal Mia");
    // qz.display();

    // auto user = make_unique<Student>();
    // // const shared_ptr<User> student = user->showAvailableQuiz();
    //
    // user->showAvailableQuiz();

    //Writing Question
    // auto user = make_unique<Student>();
    // const shared_ptr<User> student = user->loginUser("ss","123");
    // vector<Question> questions;
    // while (true) {
    //
    //     Question qs;
    //     string i, q, a, b, c, d,ans;
    //     cout<<"id: ";cin>>i;
    //     cout<<"qus: ";cin>>q;
    //     cout<<"a: ";cin>>a;
    //     cout<<"b: ";cin>>b;
    //     cout<<"c: ";cin>>c;
    //     cout<<"d: ";cin>>d;
    //     cout<<"ans: ";cin>>ans;
    //
    //     qs.setId(i);
    //     qs.setQuestion(q);
    //     qs.setOpA(a);
    //     qs.setOpB(b);
    //     qs.setOpC(c);
    //     qs.setOpD(d);
    //     qs.setCorrectAns(ans);
    //
    //     questions.push_back(qs);
    //     char ch;
    //     cout<<"Enter 'q' to exit"<<endl;
    //     cin>>ch;
    //     if (ch == 'q') break;
    // }
    //
    // ofstream file;
    // file.open("sufal.txt", ios::app);
    // if (file.is_open()) {
    //     for (const auto& l:questions) {
    //         file<<l.getId()<<endl;
    //         file<<l.getQuestion()<<endl;
    //         file<<l.getOpA()<<endl;
    //         file<<l.getOpB()<<endl;
    //         file<<l.getOpC()<<endl;
    //         file<<l.getOpD()<<endl;
    //         file<<l.getCorrect()<<endl;
    //     }
    // }

    //Login Admin
    // auto user = make_unique<Admin>();
    // const shared_ptr<User> admin = user->loginUser("ss","123");


    //Register Admin
    // Admin admin("sufal", "ss", "123", "101");
    // if (admin.admin_register(admin.getName(), admin.getId(), admin.getPass(), admin.getCourseCode())) {
    // if (admin){
    //     cout << "Successful." << endl;
    // } else cerr << "Unsuccessful." << endl;

    Question q;
    q.setId("1");
    q.setQuestion("Question");
    q.setOpA("a");
    q.setOpB("b");
    q.setOpC("c");
    q.setOpD("d");
    q.setCorrectAns("a");

    //Checking the methods for Admin.cpp
    const auto user = make_unique<Admin>();
    const shared_ptr<Admin> admin = dynamic_pointer_cast<Admin>(
    user->loginUser("ss","123"));
    if (admin) {
        // admin->addQuiz("cse",getInputString("Enter a title: "));
        admin->addQuestion(q,"cse");
        cout<<"Successful.";
    }else {
        cerr<<"Unsuccessful"<<endl;
    }
}
