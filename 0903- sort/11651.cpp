//
// Created by banya on 2021-09-05.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int x1, x2;
};



//비교함수(good)
bool cmpAdv(const info &i1, const info &i2) {

    if (i1.x2 == i2.x2) //
        return i1.x1 < i2.x1;
    return i1.x2 < i2.x2;
}


int main() {
    int n;
    vector<info> a;

    //입력
    cin >> n;
    a.assign(n, {});

    for (int i = 0; i < n; i++)
        cin >> a[i].x1 >>a[i].x2;

    //연산
    sort(a.begin(), a.end(), cmpAdv);

    //출력
    for (int i = 0; i < n; i++)
        cout << a[i].x1 << " "<< a[i].x2 << '\n';
}