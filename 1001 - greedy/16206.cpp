#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const int &a, const int &b) { // 정렬 cmp 선언
    if (a % 10 == 0 && b % 10 == 0) //둘 다 나누어 떨어지면 짧은 것부터
        return a < b; // 짧은것 우선으로
    return a % 10 == 0; //나누어떨어지는 게 먼저 오도록 정렬
}

//롤케이크 자르는 함수
int cutCakeRoll(int n, int m, vector<int> &cake) {
    int ans = 0;

    for (int i = 0; i < n; i++) {//케이크 갯수만큼 반복
        int cut = cake[i] / 10; //자르는 횟수
        if (cake[i] % 10 == 0) //나머지가 0이면
            cut--; //자르는 횟수 감소
        if (cut <= m) { //모두 자르기 가능한 경우
            m -= cut;
            ans += cake[i] / 10;
        } else { //다 못자르는 경우 -> 한 번 자를 때 1개씩 나오므로 m 더함
            ans += m; //자를기회가 m번 남은 것이므로 +m을 한다/
            break;
        }
    }

    return ans;
}

/**
 * 길이가 10인 롤케이크 개수의 최댓값을 구하는 문제
 * 길이가 10이상인 롤케이크를 잘라보자. 기본적으로 한 번 자르면 1개씩 나오게 된다.
 * 이때, 10으로 나누어 떨어지는 길이를 먼저 잘라야 한다. (ex. 15를 한 번 자르면 1개가 생기지만, 20을 한 번 자르면 2개가 생김)
 * 10으로 나누어 떨어지는 길이 중에서도, 작은 길이를 먼저 잘라야 한다. (ex. 20을 한 번 자르면 2개가 생기지만, 30을 한 번 자르면 1개가 생김)
 * 10으로 나누어 떨어지지 않는 다른 수끼리는 순서가 상관 없다.
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m; // 롤케이크 갯수와 최대횟수
    vector<int> cake(n, 0); //케이크 담을 배열
    for (int i = 0; i < n; i++) //입력 받기
        cin >> cake[i];

    //연산  => 10으로 나누어 떨어지는 거 순서 먼저
    sort(cake.begin(), cake.end(), cmp);

    //연산 & 출력
    cout << cutCakeRoll(n, m, cake) << '\n';

    return 0;
}