//
// Created by 반예원 on 2021/11/23.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>> &graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) { // graph 사이즈 만큼 반복
        int next_node = graph[node][i].first; //  그래프 첫번째값 nextnode
        if (next_node == parent) //부모 노드와 일치시 continue
            continue;

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.first > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.first;  // len 갱신
            pos = dfs_search.second; // 노드거리 갱신
        }
    }
    return {len, pos};
}

/**
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */
int main() {
    int n, p, c, w;

    //입력
    cin >> n; //노드 갯수 입력 받기
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); // 그래프 초기화
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w; // 세개 정수 입력 받기
        graph[p].emplace_back(c, w);
        graph[c].emplace_back(p, w);
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.second, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력
    cout << second_node.first;
}