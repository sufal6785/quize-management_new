//
// Created by User on 8/15/2025.
//

#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
using namespace std;

namespace Utility {
    string getInputString(const string &prompt);

    int getValidChoice(int low, int up);

    string file(const string &id, const string &user = "student");

    bool isExistInFile(const string &fileName, const string &userid);

    bool saveToFile(const string &fileName, const string &name, const string &id, const string &pass);
}


#endif //UTILITY_H
