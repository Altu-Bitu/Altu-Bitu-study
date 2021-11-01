//
// Created by 반예원 on 2021/11/01.
//
#include <iostream>
#include <vector>

using namespace std;
vector<int> num2(100001,0);
int main(){
    int n , n2;
    int ans=0;
    int ans3=0;
    cin >> n >> n2;
    vector<int> num(n,0);
    for(int i=0;i<n;i++)
        cin >> num[i];

    for(int i=0;i<n;i++) {
        if (num2[num[i]] < n2) {
            num2[num[i]]++;
            ans3++;
        } else {
            ans = max(ans, ans3);
            ans3 = 0;
        }
    }
    cout << ans;
}