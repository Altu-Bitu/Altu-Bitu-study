//
// Created by 반예원 on 2021/11/23.
//

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6;

int cntPassword(int n, string s) { //암호 사이즈와, 암호 인자로 받기
    vector<int> dp(n + 1, 0); // dp벡터 초기화
    if (s[0] == '0') //s[0]이 0이면
        return 0; // 0리턴 !

    dp[0] = dp[1] = 1; //s[0]의 암호 해석 경우의 수 1로 초기화
    for (int i = 2; i <= n; i++) {  // 2~n 까지 반복
        if (s[i - 1] == '0' && (s[i - 2] < '1' || s[i - 2] > '2'))
            return 0;

        if (s[i - 1] != '0')
            dp[i] += dp[i - 1]; //  s의 i-1값이 0이아니면 dp 값 갱신

        if (s[i - 2] == '1' || (s[i - 1] <= '6' && s[i - 2] == '2'))
            // 암호 s의 i-2값이 1 or 임호 s의 i-1값이 6이하 or 임호 s의 i-2값이 2
            dp[i] += dp[i - 2]; // dp 값 갱신

        dp[i] %= MOD; // MOD 값으로 나누고 생신
    }
    return dp[n]; //dp 리턴
}
/**
 * dp[i] = i인덱스까지 암호 해석할 수 있는 경우의 수 저장
 * => dp[i] = dp[i-1] + dp[i-2] (단, dp[i-1]과 dp[i-2]에서 이어서 암호 만들 수 있는 경우만)
 *
 * 1. '0' 혼자는 암호 해석 불가
 * 2. 처음 시작이 '0'인 경우 주의
 * 3. 현재 수가 '0'인데 앞의 수가 '1'이나 '2'가 아닌 경우 -> 암호 해석할 수 없음
 * 4. 두 개의 수를 하나의 알파벳으로 고려할 때, 26이하의 수인지 잘 확인해야 함
 *
 * 본 풀이는 dp 배열 인덱스를 편하게 관리하기 위해 1번 인덱스부터 시작
 */

int main() {
    string s;

    //입력
    cin >> s;
//암호입력 받기
    //연산 & 출력
    cout << cntPassword(s.length(), s) << '\n'; //값 출력
    return 0;
}
