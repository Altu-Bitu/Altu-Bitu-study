//
// Created by banya on 2021-10-04.
//

#include <iostream>
#include <vector>
using namespace std;
int knapsack_1(int n, vector<pair<int,int>> &s) {
    vector<int> dp( 1500010, 0);
    int ans;
    int cmax = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        cmax = max(cmax, dp[i]);
        if (i + s[i].first > n + 1)
            continue;

        dp[i + s[i].first] = max(cmax + s[i].second, dp[i + s[i].first]);
    }
    ans = cmax;


    return ans;
}


int main(){

    int n;
    cin >> n;
    vector <pair<int,int>> s(n+1,{0,0});
    for (int i=1;i<=n;i++){
        cin >> s[i].first >> s[i].second;
    }

    cout << knapsack_1(n, s) << '\n';

    return 0;
}//
// Created by banya on 2021-10-04.
//

