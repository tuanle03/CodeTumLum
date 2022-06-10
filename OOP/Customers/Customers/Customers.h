//
//  Customers.h
//
//  Created by Tuan on 6/3/22.
//

#include <string>
#include <iostream>
#include <limits>

using namespace std;

class Customer
{
private:
    std::string Name;
    double MoneyPay;
    int numPurchase;
    double UnitPrice;

public:
    Customer(const std::string name, int numpurchase, double price);
    Customer();
    ~Customer();
    
    void SetMoneyPay(double money);
    void SetName(std::string name);
    void SetnumPurchase(int n);
    void SetUnitprice(double price);
    
    std::string GetName() { return Name; }
    int GetnumPurchase() { return numPurchase; }
    double GetMoneyPay() { return MoneyPay; }
    double GetUnitPrice() { return UnitPrice; }
    void Out() {
        cout << "Name: " << GetName() << endl;
        cout << "Money pay: " << GetMoneyPay() << endl;
    }
    
    virtual void Input() {
        string name;
//        cin.ignore(0);
        getline(cin, name);
        cin.ignore(0);
        SetName(name);
        int num; cin >> num;
        SetnumPurchase(num);
        float price; cin >> price;
        SetUnitprice(price);
        this -> CaculateMoneyPay();
    }
    virtual void CaculateMoneyPay() = 0;
};

class A : public Customer
{
public:
    A();
    A(const string name, int numpurchase, double price);
    ~A();
    virtual void CaculateMoneyPay();
};

class B : public Customer {
    int UsageYear;
    double Discount;
public:
    B();
    B(const std::string name, int numpurchase, double price, int year);
    ~B();
    void SetUsageYear(int year);
    void SetDiscount();
    int GetUsageYear() { return UsageYear; }
    double GetDiscount() { return Discount; }
    void Input() {
        int year; cin >> year;
        SetUnitprice(year);
        CaculateMoneyPay();
    }
    virtual void CaculateMoneyPay();
};

class C : public Customer {
public:
    C(const string name, int numpurchase, double price);
    C();
    ~C();
    virtual void CaculateMoneyPay();
};

