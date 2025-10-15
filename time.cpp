#include<iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;

string getTime(){
auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&now_time);

    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d %H:%M:%S");
    string time = ss.str();

    return time;
}

int main() {

    cout<<getTime()<<endl;

    return 0;
}

