//
// Created by User on 10/7/2025.
//

#include "AdminPortal.h"

#include "../../models/Question.h"
#include "../../models/Utility.h"
#include "../adminviews/LoginRegister.h"
#include "../adminviews/welcome.h"
using namespace Utility;

namespace adminview {
    void AdminPortal::options() {
        cout << "\n=================== MAIN MENU ===================\n";
        cout << "Please select an option from the menu below:\n\n";
        cout << "1. Create quiz\n";
        cout << "2. Create question\n";
        cout << "3. View All Active Quizzes\n";
        // cout << "3. See Result of a quiz\n";
        // cout << "4. See All Results\n";
        // cout << "5. See Attended quiz List\n";
        cout << "4. Logout\n";
        cout << "=================================================\n";
        cout << "Enter your choice (1-4): ";
    }

    void AdminPortal::action(const shared_ptr<Admin> &admin) {
        options();

        switch (getValidChoice(1, 4)) {
            case 1: {
                const string quiz_id = getInputString("Enter Quiz Id: ");
                const string title = getInputString("Enter Quiz Title: ");
                if (admin->addQuiz(quiz_id,title)) {
                    cout<<"Successfully added "<<quiz_id<<endl;
                }else {
                    cerr<<"Cannot add "<<quiz_id<<endl;
                }
                break;
            }
            case 2: {
                //What will happen, when quiz id will not 1find.
                string quiz_id = getInputString("Enter Quiz id: ");
                string id = getInputString("Enter Question id: ");
                string quest = getInputString("Enter Question: ");
                string a = getInputString("Enter option A: ");
                string b = getInputString("Enter option B: ");
                string c = getInputString("Enter option C: ");
                string d = getInputString("Enter option D: ");
                string ans = getInputString("Enter correct Answer: ");

                Question question(id,quest,a,b,c,d,ans);
                if (admin->addQuestion(question, quiz_id)) {
                    cout<<"Successfully added..."<<endl;
                }else {
                    cerr<<"Cannot added..."<<endl;
                }
                break;

            }
            case 3:
                admin->showAvailableQuiz();
                break;
            // case 3:
            //     cout << "seeQuizResult()";
            //     break;
            case 4:
                cout << "seeAllResults()";
                break;
            case 5:
                cout << "seeAttendedQuizList()";
                break;
            case 6:
                cout << "logout()";
                break;
            default:
                cout << "Unexpected error occurred. Please try again.\n";
                break;
        }
    }

    void AdminPortal::admin_home() {
        Welcome::welcome();
        LoginRegister::login_or_register();
    }


} // view
