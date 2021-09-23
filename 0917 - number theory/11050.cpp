//
// Created by banya on 2021-09-23.
//

#include <iostream>

using namespace std;


int main(){
    //입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k,k2,ans,ans2;
    cin >> n >> k;
    ans=1;
    ans2=1;
    k2 = k;
    if(n-k < k) {
        k = n - k;
        k2 = k;
    }


    while (k--){
        ans=ans*n;
        ans2=ans2*(k+1);
        n=n-1;
    }
    if(ans2==0)
        cout << 1 ;
    else
        cout <<  ans/ans2 ;




}
