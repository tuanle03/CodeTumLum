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

void Solve(){
    string a[ma];
    FORT(i, 0, 7) {
        cin >> a[i];
    }
    int r = 0, c = 0;
    FORT(i, 1, 6) {
        FORT(j, 1, 6) {
            if (a[i - 1][j - 1] == '#' and a[i + 1][j - 1] == '#' and a[i - 1][j + 1] == '#' and a[i + 1][j + 1] == '#') {
                r = i; c = j;
                break;
            }
        }
    }
    cout << r+1 << " " << c+1 << endl;
}

int main(){
    TuanLe;
    //    freopen(NAME".inp", "r", stdin);
    //    freopen(NAME".out", "w", stdout);
    //    clock_t start, end;
    //    start = clock();
        int t; cin >> t;
        while (t--) {
            Solve();
        }
    //    end = clock();
    //    cout << ((double) (end-start))/ CLOCKS_PER_SEC << endl;
}

