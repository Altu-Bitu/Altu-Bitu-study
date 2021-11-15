#define MAX 987654321
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dp[1000001];
int before[1000001];


vector<int> back(int x, vector<int> &path) {
    vector<int> result(0); //Lis의 마지막 원소 인덱스부터 들어감
    while (x != -1) {
        result.push_back(x);
        x = path[x]; //다음 경로
    }
    return result;
}


int main() {
    dp[1] = 0;
    before[1] = -1;
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;

          if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
          if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }
    }
    cout << dp[n];


}
