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

#define TuanLe ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define NAME ""
#define FORT(i, a, b) for(int i = a; i < b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ff first
#define ss second
#define pll pair<long long, long long>
#define pii pair<int, int>
#define vp vector<pll>
#define endl "\n"
#define all(a) a.begin, a.end()
#define maxn 10005
#define ma 1005

//    /\_/\     //     /\_/\
//   (>'.'<)    //    (='.'=)
//   ( U U )    //    / > < \

using namespace std;

int arr[maxn], n;
vector<pair<int, int>> a;

int binarysearch(int x, int l, int h) {
    if (l > h) return -1;
    int mid = (l + h) / 2;
    if (a[mid].ff == x) {
        return a[mid].ss;
    }
    if (a[mid].ff < x) return binarysearch(x, mid + 1, h);
    return binarysearch(x, l, mid - 1);
}

int linersearch(int x) {
    FORT(i, 0, n) {
        if (a[i].ff == x) {
            return i;
        }
    }
    return -1;
}

void InterchangeSort(int ar[]) {
    FORT(i, 0, n-1) {
        FORT(j, i+1, n) {
            if (ar[i] > ar[j]) {
                swap(ar[i], ar[j]);
            }
        }
    }
    FORT(i, 0, n) cout << ar[i] << " ";
}

void SelectionSort(int ar[]) {
    int min;
    FORT(i, 0, n-1) {
        min = i;
        FORT(j, i+1, n) {
            if (ar[j] < ar[min]) {
                min = j;
            }
        }
        swap(ar[i], ar[min]);
    }
    FORT(i, 0, n) cout << ar[i] << " ";
}

void InsertionSort(int ar[]) {
    int key;
    FORT(i, 1, n) {
        key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key) {
            ar[j+1] = ar[j];
            j -= 1;
        }
        ar[j+1] = key;
    }
    FORT(i, 0, n) cout << ar[i] << " ";
}

void Process() {
    cout << "Nhập số lượng phần tử: " << endl;
    cin >> n;
    FORT(i, 0, n) {
        cin >> arr[i];
        a.push_back(make_pair(arr[i], i));
        
    }
    cout << "Nhập số cần tìm: " << endl;
    int x; cin >> x;
    cout << "Vị trí của số cần tìm bằng phương pháp tìm kiếm tuyến tính là: ";
    if (linersearch(x) == -1) {
        cout << "Không tìm thấy!" << endl;
    }
    else cout << linersearch(x) << endl;
    cout << "Vị trí của số cần tìm bằng phương pháp tìm kiếm nhị phân là: ";
    sort(a.begin(), a.end());
    if (binarysearch(x, 0, n-1) == -1) {
        cout << "Không tìm thấy!" << endl;
    }
    else cout << binarysearch(x, 0, n-1) << endl;
    cout << "Sắp xếp theo giải thuật đổi chỗ trực tiếp: " << endl;
    InterchangeSort(arr);
    cout << endl << "Sắp xếp theo giải thuật chọn trực tiếp: " << endl;
    SelectionSort(arr);
    cout << endl << "Sắp xếp theo giải thuật chèn trực tiếp: " << endl;
    InsertionSort(arr);
    cout << endl;
}

int main(){
    TuanLe;
//    #ifndef ONLINE_JUDGE
//        freopen("Test.inp", "r", stdin);
//        freopen("Test.out", "w", stdout);
//    #endif
    //    clock_t start, end;
    //    start = clock();
    Process();
    //    end = clock();
    //    cout << ((double) (end-start))/ CLOCKS_PER_SEC << endl;
}
