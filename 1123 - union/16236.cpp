//
// Created by 반예원 on 2021/11/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0}; // row방향 배열
    int dc[4] = {0, 0, -1, 1}; // col방향 배열

    int min_dist = INF; //가능한 물고기 최대 마리.
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; // 상어 방문 체크
    q.push(shark); //상어 위치 큐에 저장
    while (!q.empty()) { // 빈곳 없을때까지 반복
        int row = q.front().first; //row 값
        int col = q.front().second;// col
        int dist = visited[row][col]; // 상어의 방문 여부
        q.pop(); // 젤 위에꺼 제거

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;
        for (int i = 0; i < 4; i++) { // 반복 하기
            int nr = row + dr[i]; //nr 선언
            int nc = col + dc[i];//nc 선언
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)
                //이동할 수 없다면 끝냄
                continue;

            visited[nr][nc] = visited[row][col] + 1;
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); // list에  값 추가
                min_dist = visited[nr][nc]; // 최소 거리에 저장
                continue;
            }
            q.push({nr, nc}); // 물고기 행과 열값 큐에 저장
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}};

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second < p2.second;
    });
    return {min_dist - 1, list[0]};
}
/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0;
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //종료
        ans += result.first; // nextPos에서 반환한 결과값의 첫번째 ans에 추가
        cnt++; //카운트 세기
        if (cnt == size) { //상어 크기 증가
            cnt = 0; //카운트 초기화
            size++; //상어 크기 증가
        }

        //상어 이동
        ci pos = result.second; // 두번째로상어 이동하기
        board[shark.first][shark.second] = 0; // 이전값 상어 초기화
        shark = pos; //이동시키기
    }
    return ans; // ans 반환
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n;
    pair<int, int> shark_pos; //상어 위치 변수 선언

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); //입력받은 n만큼 공간 상태 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //상태 입력 받기
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); //상어 위치 저장
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board); // ans 출력
}