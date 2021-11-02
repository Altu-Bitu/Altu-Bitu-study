//
// Created by 반예원 on 2021/11/01.
//
#include <iostream>
#include <vector>

using namespace std;
vector<int> num2(100001,0);
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n , n2;
    int ans=0;
    int ans3=0;
    cin >> n >> n2;
    vector<int> num(n,0);
    for(int i=0;i<n;i++)
        cin >> num[i];

    for(int i=0;i<n;i++) {
        if (num2[num[i]] <= n2-1) {

            num2[num[i]]++;
            ans3++;

        } else {
            ans = max(ans, ans3);
            i=i-ans3;
            num2.assign(100001,0);
            ans3 = 0;
        }
    }
    ans = max(ans, ans3);
    cout << ans;
}