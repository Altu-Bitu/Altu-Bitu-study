//
// Created by 반예원 on 2021/11/30.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node; //루트 정점값을 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); // 첫번째의 점 값 find Parent에서 받은 루트 정점값 xp에 저장
    int yp = findParent(y);// 두번째의 점 값 find Parent에서 받은 루트 정점값 yp에 저장
    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //false로 리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];  //xp값 yp값 더하여 갱신
        parent[yp] = xp; //두번째의 점값에 xp 저장
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; // 위와 반대로 적용
        parent[xp] = yp;
    }
    return true; //true로 리턴
}

/**
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */
int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m; //점의 개수와, 진행된 차례수 입력 받기
    parent.assign(n, -1); //-1로 벡터 초기화
    for (int i = 0; i < m; i++) { //m 만큼 반복하여 두점의 번호 입력 받기
        cin >> x >> y; //입력 받기

        //연산 & 출력
        if (!unionInput(x, y)) { //유니온 할 수 없음 = 사이클이 생성됨
            cout << i + 1; //유니온 할 수 없다면, i번째의 값에 +1값 출력
            return 0;
        }
    }
    cout << 0;
}
