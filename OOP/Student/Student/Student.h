#include<cstring>
#include<iostream>

#ifndef Student_h
#define Student_h

using namespace std;

class Student {
    std::string stucode, name, address, phone, ranked;
    
public:
    Student();
//    ~Student();
    Student(string stucode, string name, string address, string phone, string ranked);
    void setStudent();
    void display();
    string getStucode();
    string getRanked();
    void compare(string stu1);
};

#endif /* Student_h */
