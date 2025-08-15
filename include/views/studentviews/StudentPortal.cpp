//
// Created by User on 8/9/2025.
//

#include "StudentPortal.h"

#include "LoginRegister.h"
using namespace Utility;

namespace view {
    void StudentPortal::options() {
        cout << "\n=================== MAIN MENU ===================\n";
        cout << "Please select an option from the menu below:\n\n";
        cout << "1. Attend Quiz\n";
        cout << "2. View All Active Quizzes\n";
        cout << "3. See Result of a Quiz\n";
        cout << "4. See All Results\n";
        cout << "5. See Attended Quiz List\n";
        cout << "6. Logout\n";
        cout << "=================================================\n";
        cout << "Enter your choice (1-6): ";
    }


    void StudentPortal::MainView() {
        options();
        int choice = getValidChoice(1,6);

        switch (choice) {
            case 1:
                cout << "attendQuiz()";
                break;
            case 2:
                cout << "viewAllActiveQuizzes()";
                break;
            case 3:
                cout << "seeQuizResult()";
                break;
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
}
