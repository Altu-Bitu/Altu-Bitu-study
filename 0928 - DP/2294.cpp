//
// Created by banya on 2021-10-04.
//

#include <iostream>
#include <vector>
using namespace std;
int knapsack_1(int n, int k, vector<int> &coin) {
    vector<int> dp(100010, 0);
    for (int i = 1; i <= k; i++) dp[i] = 2e9;
    for (int i = 1; i <= n; i++) dp[coin[i]] = 1;


    for (int i = 1; i <= n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);

        }
    }

    if (dp[k] == 2e9) return -1;
    return   dp[k];
}


int main(){

    int n,k;
    cin >> n >> k;
    vector <int> coin(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> coin[i];
    }

    cout << knapsack_1(n, k, coin) << '\n';

    return 0;
}