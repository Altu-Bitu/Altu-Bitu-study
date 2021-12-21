//
// Created by 반예원 on 2021/12/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//위상정렬 + DP
vector<vector<int>> topologicalSort(int n, vector<int> &indegree, vector<vector<ci>> &graph) {
    queue<int> q; //큐 선언
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); //각 부품이 몇 개 필요한지 저장

    for (int i = 1; i <= n; i++) { //n번만큼 반복
        if (!indegree[i]) { //진입차수가 0이라면 -> 기본 부품
            q.push(i); //큐값에 저장
            dp[i][i] = 1; //기본 부품 초기화
        }
    }
    while (!q.empty()) { //큐값이 비기 전까지 반복
        int node = q.front(); //큐맨위값 저장
        q.pop(); //빼기

        for (int i = 0; i < graph[node].size(); i++) { //graph사이즈만큼 반복
            int next_node = graph[node][i].first; //node-i 그래프 값 새노드값에 저장
            int cnt = graph[node][i].second; //필요한 부품 수
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //새 노드값 큐에 저장

            for (int j = 1; j <= n; j++) //n번만큼 반복
                dp[next_node][j] += dp[node][j] * cnt; //(현재 정점을 이루는 부품 개수 * 필요한 현재 정점의 개수)를 더함
        }
    }
    return dp; //dp값 반환하기
}

/**
 * 각 부품마다 종류별 필요한 부품 개수를 저장하기 위해 2차원 배열 사용 (행: 부품, 열: 행을 이루는데 각 부품별 필요한 개수)
 * 위상 정렬 순서에 따라, 이어진 다음 정점의 부품별 개수를 (현재 정점을 이루는 부품별 개수 * 필요한 현재 정점 수)를 더해주며 구함
 */

int main() {
    int n, m, x, y, k;

    //입력
    cin >> n >> m; //n,m 입력 받기
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); // graph 선언
    vector<int> indegree(n + 1, 0); // indegree 벡터 선언
    while (m--) { //m번만큼 입력 받기
        cin >> x >> y >> k; //y -> x
        indegree[x]++; //완제품 값 indegree벡터에 저장
        graph[y].push_back({x, k}); // 기본 부품 y값과 필요갯수 k값 입력 받기
    }

    //연산
    vector<vector<int>> result = topologicalSort(n, indegree, graph);
    //위상 정렬 함수 사용하여 값 저장

    //출력
    for (int i = 1; i <= n; i++) {
        if (result[i][i]) //기본 부품이라면
            cout << i << ' ' << result[n][i] << '\n';
    }
    return 0;
}