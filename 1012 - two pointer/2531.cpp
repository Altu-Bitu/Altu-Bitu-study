//
// Created by 반예원 on 2021/11/01.
//

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0);

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;
    sushi[c]++;

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        sushi[belt[i]]++;
        if (sushi[belt[i]] == 1)
            section_sushi++; //종류에 +쿠폰으로 먹은 초밥 수
    }

    int ans = section_sushi;
    int left = 0, right = k - 1;
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; //포함하였을때 수 하나 빼기
        if (!sushi[belt[left]]) //0이 아니라몀
            section_sushi--;

        //윈도우의 양 끝 이동
        left = (left + 1) % n;
        right = (right + 1) % n;

        sushi[belt[right]]++; //양끝 이동 후 오른쪽 끝 벨트값 ++
        if (sushi[belt[right]] == 1) //1이라면 카운트 ++
            section_sushi++;

        ans = max(ans, section_sushi); //max로 비교후 더 max인값 an s로
    } while (left);
    return ans;
}

/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */
int main() {
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> belt[i];

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c);
}