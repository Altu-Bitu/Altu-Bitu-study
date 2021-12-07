//
// Created by 반예원 on 2021/12/07.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //nodq 반환
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //부모 찾고 선언
    int yp = findParent(y);//부모 찾고 선언

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //false로 반환
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; // 노드 개수갱신
        parent[yp] = xp; //다시 xp 를 갱신 하여 부모로
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; // 노드 개수갱신
        parent[xp] = yp;//다시 yp 를 갱신 하여 부모로
    }
    return true; //true로 반환
}

int kruskal(int n, int idx, vector<tp> &edges) { //인자 받기
    int cnt = 0, sum = 0; //카운트와 합계 선언
    for (int i = idx; i < edges.size(); i++) { //벡터사이즈만큼 반복
        if (cnt == n - 1) //n-1개의 간선을 모두 연결함
            break;
        int dist = get<0>(edges[i]); // 튜플로부터 값 가져오기
        int x = get<1>(edges[i]);// 튜플로부터 값 가져오기
        int y = get<2>(edges[i]);// 튜플로부터 값 가져오기

        if (unionInput(x, y)) { //유니온 후 true시
            cnt++; //개수 증가
            sum += dist; //거리 더하여 ㄱ갱신
        }
    }
    if (cnt < n - 1) //mst를 만들 수 없음
        return 0; //0으로 반환
    return sum; //총 거리 반환
}

/**
 * MST 알고리즘을 여러 번 실행해도 될까?
 * 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
 *    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
 *    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 * 2. 간선 재사용을 위해 우선순위 큐가 아닌 벡터에 저장하고 크루스칼 알고리즘 k번 실행
 * 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
 *    -> 제외될 간선은 배열의 0번째 간선부터 1, 2, 3번째 간선으로 순차적 제외
 * 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없으므로 flag 변수로 불필요한 연산 절약
 */
int main() {
    int n, m, k, x, y;
    //정점 개수 간선 개수 턴 수 두정점 번호

    cin >> n >> m >> k; // 정점 개수, 간선 개수, 턴수 입력 받기
    vector<tp> edges; //재사용할거라 우선순위 큐가 아닌 벡터에 저장
    for (int i = 1; i <= m; i++) { // 간선 수 만큼 반복하여
        cin >> x >> y; //두 정점 입력 받기
        edges.emplace_back(i, x, y); // 벡터의원소 끝에 값추가
    }

    bool flag = false; //bool 선언
    for (int i = 0; i < k; i++) {
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' '; //0출력
            continue;
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edges); //크루스칼 알고리즘 사용
        if (ans == 0) //반환 닶이 0이라면
            flag = true;//flag값 true로 변경
        cout << ans << ' ';
    }
}