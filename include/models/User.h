//
// Created by User on 8/9/2025.
//

#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <memory>

namespace model {
    using namespace std;

    class User {
    private:
        string user_name;
        string userid;
        string password;

    public:
        User() = default;

        User(const string &name, const string &id, const string &pass);

        virtual ~User() = default;

        void set();

        void display() const;

        static bool isExist(const string &fileName, const string &userid);

        string getName();

        string getId();

        string getPass();

        virtual bool registerUser(const string &name, const string &id, const string &pass) = 0;

        virtual shared_ptr<User> loginUser(const string &id, const string &pass) = 0;

        //quiz
        vector<string> showAvailableQuiz();
    };
}


#endif //USER_H
