// //
// // Created by User on 8/16/2025.
// //
//
// #include "Admin.h"
// #include <fstream>
// namespace model {
//     Admin::Admin(int course_code): User(), course_code(course_code) {
//     }
//
//     Admin::Admin(const string &name, const string &id, const string &pass, int course_code): User(name, id, pass),
//         course_code(course_code) {
//     }
//
//     shared_ptr<User> Admin::loginUser(const string &id, const string &pass) {
//         ifstream file;
//         file.open("admin-list.dat");
//         if (file.is_open()) {
//             string name, savedId, savedPass;
//             int savedCode;
//             while (getline(file, name) && getline(file, savedId) && getline(file, savedPass)&&getline(savedCode)) {
//                 if (savedId == id && savedPass == pass)
//                     return make_shared<Admin>(name, savedId, savedPass,savedCode);
//             }
//         }
//
//         return nullptr;
//     }
//
// }
