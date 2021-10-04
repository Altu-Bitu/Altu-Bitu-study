//
// Created by banya on 2021-10-04.
//

//
// Created by BaeSuA on 2021-09-28.
//

#include <iostream>
#include <vector>

using namespace std;


//
////2차원 dp 활용 냅색
//int knapsack_2(int n, int k, vector<info> &product) {
//    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//
//    for (int i = 1; i <= n; i++) { //각 물품에 대해, i: 물품 번호, j: 최대 배낭 무게
//        for (int j = 1; j < product[i].w; j++) //우선 해당 물품을 배낭에 넣을 수 없는 경우
//            dp[i][j] = dp[i - 1][j]; //그 전 물품에 대한 현재 무게의 최댓값 저장
//        for (int j = product[i].w; j <= k; j++) //해당 물품을 배낭에 넣는게 가능한 경우
//            dp[i][j] = max(dp[i - 1][j - product[i].w] + product[i].v, dp[i - 1][j]); //배낭에 넣는 경우와 안 넣는 경우 중 최댓값 저장
//    }
//
//    return dp[n][k];
//}
//
////1차원 dp 활용 냅색
//int knapsack_1(int n, int k, vector<info> &product) {
//    vector<int> dp(k + 1, 0);
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = k; j >= product[i].w; j--) //j: 최대 배낭 무게, 1차원이니 무게 k부터 시작(거꾸로)
//            dp[j] = max(dp[j - product[i].w] + product[i].v, dp[j]);
//    }
//
//    return dp[k];
//}

int main() {
    int n, k,k2;

    //입력
    cin >> n;
    cin >> k;
    vector <pair<int,int>> v(k+1,{0,0});

    for (int i = 1; i <= k; i++)
        cin >> v[i].first >> v[i].second;
    cin >> k2;
    vector <pair<int,char>> v2(k2+1,{0,0});
    for (int i = 1; i <= k2; i++)
        cin >> v2[i].first >> v2[i].second;



    return 0;
}