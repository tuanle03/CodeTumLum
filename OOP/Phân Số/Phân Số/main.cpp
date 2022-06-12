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
#include "PhanSo.h"

#define TuanLe ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define NAME ""
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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

PhanSo::PhanSo() {
    tuso = 0;
    mauso = 1;
}

PhanSo::PhanSo(int t, int m) {
    tuso = t;
    mauso = m;
}

void PhanSo::getPhanSo() {
    cin >> tuso >> mauso;
    if (mauso == 0) {
        mauso = 1;
    }
}

void PhanSo::outPhanSo() {
    int temp = gcd(tuso, mauso);
    cout << tuso/temp << "/" << mauso/temp << endl;
}

PhanSo PhanSo::Cong(PhanSo b) {
    return PhanSo((tuso*b.mauso) + (mauso*b.tuso), mauso*b.mauso);
}

PhanSo PhanSo::Tru(PhanSo b) {
    return PhanSo((tuso*b.mauso) - (mauso*b.tuso), mauso*b.mauso);
}

PhanSo PhanSo::Nhan(PhanSo b) {
    return PhanSo(this->tuso*b.tuso, this->mauso*b.mauso);
}

PhanSo PhanSo::Chia(PhanSo b) {
    return PhanSo(this->tuso*b.mauso, this->mauso*b.tuso);
}

int main(){
    TuanLe;
    //    freopen(NAME".inp", "r", stdin);
    //    freopen(NAME".out", "w", stdout);
    //    clock_t start, end;
    //    start = clock();
    //    int t; cin >> t;
    //    while (t--) {
    //        Solve();
    //    }
    PhanSo ps1, ps2;
    ps1.getPhanSo();
    ps2.getPhanSo();
    ps1.Cong(ps2).outPhanSo();
    ps1.Tru(ps2).outPhanSo();
    ps1.Nhan(ps2).outPhanSo();
    ps1.Chia(ps2).outPhanSo();
    //    end = clock();
    //    cout << ((double) (end-start))/ CLOCKS_PER_SEC << endl;
}

