

//
// Created by banya on 2021-09-08.
//

//
// Created by 반예원 on 2021/09/08.
//

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
bool cmpAdv(const info &i1, const info &i2) {

    return i1.x1 < i2.x1; //이름이 사전 순으로 증가하는 순서
}


int main() {

    int n2 = 0;

    //입력
    cin >> n2;

    while(n2--)
    {
        int n;
        int cnt = 0;
        int bestScore = 0;
        cin >> n;
        vector<info> a;
        a.assign(n,{});

        for (int i = 0; i < n; i++)
        cin >> a[i].x1 >> a[i].x2;

    sort(a.begin(), a.end(),cmpAdv);


    bestScore = a[0].x2;
    for (int i = 1; i < n; i++){

        if(a[i].x2 < bestScore) {
            bestScore = a[i].x2;
            cnt++;
        }
            }
    if(n2 == 1){
        cout << "\n";
        cout << cnt+1;}
    else
        cout << cnt+1;
    }

}