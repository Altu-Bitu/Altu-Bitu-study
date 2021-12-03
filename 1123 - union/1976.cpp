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
        return node; //루트 정점 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //도시 행위치 루트 정점 xp 저장
    int yp = findParent(y); //도시 열위치 루트 정점 yp 저장

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return; //리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; // 루트 xp 값에 yp추가하여, xp 갱신
        parent[yp] = xp; //루트 yp에 xp 저장
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; // 루트 yp 값에 xp추가하여, yp 갱신
        parent[xp] = yp; //루트 xp에 yp 저장
    }
}

/**
 * 입력으로 주어지는 i, j 도시의 연결정보를 통해 서로소 집합을 만든 후,
 * 여행 계획으로 세운 도시들이 모두 같은 집합에 속하는지 확인하는 문제
 */

int main() {
    int n, m, a, b, input;

    //입력
    cin >> n >> m; //도시와 계획에 속한 도시들의 수 입력 받기
    parent.assign(n + 1, -1); //-1로 벡터 초기화
    for (int i = 1; i <= n; i++) { //도시의 연결 정보 입력 받기
        for (int j = 1; j <= n; j++) {
            cin >> input; //연결 정보 입력 받기
            if (input) //두 정점이 연결되어 있다면
                unionInput(i, j);  //도시의 위치 함수 전달
        }
    }
    cin >> a; //시작 정점
    while (--m) {
        cin >> b;
        if (findParent(a) != findParent(b)) { //서로 다른 집합이라면 -> 해당 경로 불가능
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}