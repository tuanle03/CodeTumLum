//#include <bits/stdc++.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include "Customer.h"

#define TuanLe ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define NAME "XYZ"
#define FORT(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(long i = a; i > b; --i)
#define ll long long
#define ff first
#define ss second
#define pll pair<long long, long long>
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define mod 998244353
#define maxn 100005
#define ma 1005

//    /\_/\     //     /\_/\
//   (>'.'<)    //    (='.'=)
//   ( U U )    //    / > < \

using namespace std;

Customer::Customer(const std::string name, int numpurchase, double price) {
    SetName(name);
    SetnumPurchase(numPurchase);
    SetUnitprice(price);
}

Customer::Customer() {
    SetName("");
    SetnumPurchase(0);
    SetUnitprice(0);
}

Customer::~Customer() {}

void Customer::SetMoneyPay(double money) {
    MoneyPay = money;
}

void Customer::SetnumPurchase(int n) {
    numPurchase = n;
}

void Customer::SetUnitprice(double price) {
    UnitPrice = price;
}

void Customer::SetName(std::string name){
    Name=name;
}

A::A() {}

A::A(const string name, int numpurchase, double price) : Customer(name, numpurchase, price) {
    CaculateMoneyPay();
}

A::~A() {}

void A::CaculateMoneyPay() {
    double money;
    money = GetnumPurchase() * GetUnitPrice() * (1 + 0.1);
    SetMoneyPay(money);
}

B::B() {
    SetUsageYear(0);
    SetDiscount();
}

B::B(const string name, int numpurchase, double price, int year) : Customer(name, numpurchase, price) {
    SetUsageYear(year);
}

B::~B(){}

void B::SetUsageYear(int year) {
    UsageYear = year;
}

void B::SetDiscount() {
    Discount = GetUsageYear() * 5 / 100;
    if (Discount > 0.5) {
        Discount = 0.5;
    }
}

void B::CaculateMoneyPay() {
    SetDiscount();
    double money;
    money = GetnumPurchase() * GetUnitPrice() * (1 - GetDiscount()) * (1 + 0.1);
    SetMoneyPay(money);
}

C::C(const std::string name, int numpurchase, double price) : Customer(name, numpurchase, price) {}
C::C(){}
C::~C(){}
void C::CaculateMoneyPay(){
    double money;
    money = GetnumPurchase() * GetUnitPrice() * 0.5 * (1 + 0.1);
    SetMoneyPay(money);
}

void Solve(){
    int x, y, z;
    cin >> x >> y >> z;
    vector<Customer *> Vcustomer;
    Vcustomer.resize(0);
    double Sum = 0;
    FORT(i, 1, x) {
        Vcustomer.push_back(new A);
        Vcustomer.back() -> Input();
        Sum += Vcustomer.back()->GetMoneyPay();
    }
    FORT(i, 1, y) {
        Vcustomer.push_back(new B);
        Vcustomer.back() -> Input();
        Sum += Vcustomer.back()->GetMoneyPay();
    }
    FORT(i, 1, z) {
        Vcustomer.push_back(new C);
        Vcustomer.back()->Input();
        Sum += Vcustomer.back()->GetMoneyPay();
   }
    cout << x << " " << y << " " << z << endl;
    for (int i = 0; i < Vcustomer.size(); i++) {
        (*Vcustomer[i]).Out();
    }
    cout << "Sum: " << Sum << endl;
}

int main(){
    TuanLe;
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

    Solve();

}


