//
// Created by 반예원 on 2021/12/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<string, int> indegree;
unordered_map<string, vector<string>> graph;

//위상정렬
vector<string> topologicalSort(set<string> &item) { //위상 정렬
    vector<string> result; //결과값 벡터 선언
    priority_queue<string, vector<string>, greater<>> pq, pq_temp;
    //우선 순위 큐 선언하기
    for (auto iter = item.begin(); iter != item.end(); iter++) { //아이템 값 iter로 반복
        if (indegree.find(*iter) == indegree.end()) //진입차수가 존재하지 않는다면(0 이라면)
            pq.push(*iter); //해당 아이템값 큐에 저장
    }
    while (!pq.empty()) { //큐가 빌때까지 반복
        string node = pq.top(); //해당 윗값 스트링에 저장
        pq.pop(); //값 빼기

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) { //그래프 사이즈만큼 반복
            string next_node = graph[node][i]; //새로운 스트링 변수에 다음 노드값 저장
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (indegree[next_node] == 0) //연결된 정점의 진입차수가 0이 되었다면
                pq_temp.push(next_node); //우선 pq_temp에 삽입
        }
        if (pq.empty() && !pq_temp.empty()) //이전에 진입차수가 0이였던 정점을 모두 탐색했고, 새로 탐색할 정점이 있다면
            swap(pq, pq_temp); //해당 정점과, 새로탐색정점 swqp 하기
    }
    return result; //결과 벡터 반환
}

/**
 * 문자열을 인덱스로 사용해야 하기때문에 map을 사용
 *
 * !주의! 일반 map을 사용하면 시간초과. 따라서 map보다 검색 속도가 빠른 unordered_map 사용해야 함
 *       -> map은 이진 탐색 트리 형태로 key값을 정렬해서 시간 복잡도가 logN 이지만, unordered_map은 hash형태로 저장해서 시간 복잡도가 1이다
 * !주의! 위상 정렬을 할 때 원래는 여러 결과가 가능하지만 해당 문제는 순서배치가 중요 (순서는 예제 3 참고)
 *       1. 진입차수가 0인 정점들끼리 정렬해서 사용해야 함
 *       2. 진입차수가 0인 정점이 동시에 여러 개일 경우 해당 정점들을 먼저 순서에 배치해야 함.
 *      -> 따라서 우선순위 큐를 사용하여 진입차수가 0인 정점들을 관리. 이때 동시에 진입차수가 0이 된 정점들을 먼저 배치해야 하므로 우선순위 큐를 2개 사용.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입출력 속도 향상하기
    set<string> item; //존재하는 아이템(정점)
    int n; //n값 선언
    string a, b; //스트링 a,b값 선언

    //입력
    cin >> n; //n 값 입력 받기
    while (n--) { //n 번 만큼 입력 받기
        cin >> a >> b; //a < b
        indegree[b]++; //진입차수 증가
        graph[a].push_back(b); //단방향 그래프
        item.insert(a); //아이템 삽입
        item.insert(b); //아이템 삽입
    }

    //연산
    vector<string> result = topologicalSort(item); // item값 위상정렬후 result벡터에 저장

    //출력
    if (result.size() != item.size()) { // 모든 아이템 출력 못할시
        cout << "-1\n"; // -1 출력
        return 0;
    }
    for (int i = 0; i < result.size(); i++) //결과 사이즈 만큼 반복
        cout << result[i] << '\n'; //결과 값 출력

    return 0;
}