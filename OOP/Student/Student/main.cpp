//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include "Student.h"

#define TuanLe ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Fort(i, a, b) for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)

using namespace std;

Student::Student(){
    stucode = name = address = phone = ranked = "";
}

Student::Student(string stucode, string name, string address, string phone, string ranked){
    this -> stucode = stucode;
    this -> name = name;
    this -> address = address;
    this -> phone = phone;
    this -> ranked = ranked;
}

void Student::setStudent(){
    cout << "Enter student code: ";
    cin >> stucode;
    cin.ignore(1);
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter GPA (E: Excellent/ G: Good/ A: Average/ B: Below Average/ W: Weak): ";
    cin >> ranked;
}

void Student::display(){
    cout << stucode << " | " << name << " | " << address << " | " << phone << " | " << ranked << endl;
}

string Student::getRanked(){
    return ranked;
}

string Student::getStucode(){
    return stucode;
}

int main(){
    TuanLe;
    Student a[1000];
    int temp = 0;
    cout << "1: Add student" << endl << "2: Show list" << endl << "3: Statistic" << endl << "4: Compare" << endl << "0: Exit" << endl;
    int t; cin >> t;
    while (t != 0) {
        if (t == 1) {
            temp++;
            a[temp].setStudent();
        }
        else if(t == 2) {
            Fort(i, 1, temp){
                a[i].display();
            }
        }
        else if (t == 3) {
            int cntE = 0, cntG = 0, cntA = 0, cntB = 0, cntW = 0;
            Fort(i, 1, temp) {
                if (a[i].getRanked() == "E") cntE++;
                if (a[i].getRanked() == "G") cntG++;
                if (a[i].getRanked() == "A") cntA++;
                if (a[i].getRanked() == "B") cntB++;
                if (a[i].getRanked() == "W") cntW++;
            }
            cout << "E: " << cntE << " G: " << cntG << " A: " << cntA << " B: " << cntB << " W: " << cntW << endl;
        }
        else if (t == 4) {
            string std1, std2;
            string ranked1, ranked2;
            cout << "Enter student code: ";
            cin >> std1;
            cout << "Enter student code: ";
            cin >> std2;
            Fort(i, 1, temp) {
                if (a[i].getStucode() == std1) {
                    ranked1 = a[i].getRanked();
                }
                if (a[i].getStucode() == std2) {
                    ranked2 = a[i].getRanked();
                }
            }
            if (ranked1 == "" || ranked2 == "") {
                cout << "Not found in list" << endl;
            }
            else {
                cout << std1 << " " << ranked1 << endl;
                cout << std2 << " " << ranked2 << endl;
            }
        }
        else cout << "Input is false! Please re-enter!" << endl;
        cin >> t;
    }
}
