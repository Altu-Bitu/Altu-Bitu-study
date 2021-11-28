//
// Created by 반예원 on 2021/11/23.
//

#include <iostream>
#include <vector>

using namespace std;

//단절점, 단절선 파악 함수
string isTrue(int t, int k, vector<vector<int>> &tree) {
    if (t == 2) // 단절선인지에대한 질의 확인
        return "yes"; //yes 리턴
    if (tree[k].size() >= 2) //트리의 사이즈 2개 이상이라면
        return "yes"; //단절점 으로 리턴
    return "no"; //해당사항없다면 리턴
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() {
    ios_base::sync_with_stdio(false); // 입력 속도 향상
    cin.tie(NULL);
    int n, a, b, q, t, k;

    //입력
    cin >> n; //트리의 정점 개수 N 입력 받기
    vector<vector<int>> tree(n + 1, vector<int>(0)); // 2차원 벡터 초기화
    for (int i = 0; i < n - 1; i++) { // N-1개 줄에 걸쳐 간선의 정보 a,b
        cin >> a >> b; // a,b 입력 받기
        tree[a].push_back(b); // 트리 저장
        tree[b].push_back(a);
    }
    cin >> q;
    while (q--) { // 질의의 개수 입력 받기
        cin >> t >> k;
        cout << isTrue(t, k, tree) << '\n';
    }
    return 0;
}
