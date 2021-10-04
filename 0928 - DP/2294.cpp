//
// Created by banya on 2021-10-04.
//

#include <iostream>
#include <vector>
using namespace std;
int knapsack_1(int n, int k, vector<int> &coin) {
    vector<int> dp(100010, 0);
    for (int i = 0; i < k; i++) dp[i] = 2e9;
    for (int i = 0; i < n; i++) dp[coin[i]] = 1;


    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j < k; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);

        }
    }

    if (dp[k] == 2e9) cout << -1 << endl;
    return   dp[k-1];
}


int main(){

    int n,k;
    cin >> n >> k;
    vector <int> coin(n,0);
    for (int i=0;i<n;i++){
        cin >> coin[i];
    }

    cout << knapsack_1(n, k, coin) << '\n';
}