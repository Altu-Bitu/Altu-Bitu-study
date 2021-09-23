//
// Created by banya on 2021-09-23.
//

#include <iostream>
#include <vector>
#include <cmath>
const int SIZE = 5000000;
using namespace std;


int main(){
    //입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int ans,ans2;
    //입력
    ans = 0;
    ans2 = 0;
    cin >> n >> k;

    int num = n*k;

    int num2 = sqrt(num);

    for(int i=num2;i<num;i++) {

        if (num % i == 0) {
            ans = i;
            ans2 = num/i;
            break;
        }
    }
    cout << ans2 << " "<< ans;


    return 0;


}