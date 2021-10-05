#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//n번 인덱스부터 계산
int maxMoney_n(int n, vector<ci> &counsel) {
    vector<int> dp(n + 2, 0);
    //7일부터~ 1일까지 반복
    for (int i = n; i >= 1; i--) {

        dp[i] = dp[i + 1]; //우선 i번째 상담 안하는 경우
        //해당 날짜의 이전 dp값 저장
        if (i + counsel[i].first <= n + 1) { //i번째 상담이 가능한 경우
            //현재 dp값 vs 상담 날짜일과 상담시 걸리는시간의 dp + 상담시 이득
            //변경
            dp[i] = max(dp[i], dp[i + counsel[i].first] + counsel[i].second);
        }
    }
    //퇴사전 마지막 날 수익 반환
    return dp[1];
}

/**
 * 풀이 1. 1번 인덱스 부터
 * 1번째 날부터 시작하여 i번째 날을 끝으로 하는 상담 최댓값 저장하기
 * 현재 날을 상담하는 걸 택하면 현재 날에 상담이 걸리는 날을 더한 날의 최댓값이 변경됨
 *
 * 풀이 2. n번 인덱스 부터
 * n번째 날부터 시작하여 i번째 날을 시작으로 하는 상담 최댓값 저장하기
 * 현재 날을 상담하는 걸 택하면 현재 날에 상담이 걸리는 날을 더한 날의 최댓값에 현재 날 상담값을 더해줌. 즉 i번째가 변경됨
 * 마지막엔 1번째 날부터 n번째 날까지의 최댓값이 저장되었을 dp[1] 출력
 */

int main() {
    int n;

    //입력
    cin >> n; //총일수 입력받기
    vector<ci> counsel(n + 1); //pair로 선언한 벡터
    for (int i = 1; i <= n; i++) { //걸리는 시간과 받는 금액 입력 받기
        cin >> counsel[i].first >> counsel[i].second;
    }

    cout << maxMoney_n(n, counsel) << '\n';

    return 0;
}