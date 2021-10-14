//
// Created by banya on 2021-10-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> arr;

int ans(int a,int b){
    int sum=0;
    int midsol2=0;
    int temp=0;
    for(int i =0;i<a;i++){
      sum=sum+arr[i];
    }
    int midsol =sum/b;
    for(int i=0;i<a;i++){
        midsol2=accumulate(arr.end()-i, arr.end(), 0);

        if(midsol2 > midsol)
        {   temp = midsol2;
            break;}}
    return temp;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, input;

    //입력
    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산


    cout << ans(n,m);

}