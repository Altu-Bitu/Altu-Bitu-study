//
// Created by 반예원 on 2021/12/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 4;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<ci>> findCard(vector<vector<int>> &board) { //존재하는 모든 카드의 위치를 리턴하는 함수
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //최대 카드 수
    int cnt = 0; //cnt 값 초기화
    for (int i = 0; i < SIZE; i++) { // 배열크기만큼 반복
        for (int j = 0; j < SIZE; j++) { // 반복
            cnt = max(cnt, board[i][j]); //cnt값에, cnt와 board배열 최대값 비교후 갱신
            if (board[i][j]) //카드라면 위치 저장
                card_pos[board[i][j]].emplace_back(i, j); //카드 값 있다면 위치 저장하기
        }
    }
    card_pos.resize(cnt + 1); //실제 존재하는 카드의 수만큼 크기 조절
    return card_pos; //저장한 카드 위치 벡터 반환
}

pair<int, int> ctrl(int row, int col, int dir, vector<vector<int>> &tmp) { //컨트롤로 이동하는 좌표를 리턴하는 함수
    while (true) { //무한 반복
        row += dr[dir]; //해당 row에 방향값 더하기
        col += dc[dir];//해당 col에 방향값 더하기
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) //해당 방향에 카드가 하나도 없다면 그 방향의 가장 마지막 칸으로 이동
            return make_pair(row - dr[dir], col - dc[dir]);
        if (tmp[row][col] != 0) //누른 키 방향에 있는 가장 가까운 카드
            return make_pair(row, col); //좌표 반환
    }
}

int bfs(int r1, int c1, int r2, int c2, vector<vector<int>> &tmp) { //현재 커서에서 목표 카드로 이동하는 가장 적은 비용을 리턴하는 함수
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0)); // 방문했는지 확인 배열
    queue<pair<int, int>> q; // 큐 선언
    visited[r1][c1] = 1; //반드시 엔터를 누르게 될 것. 엔터를 미리 눌렀다 가정하고 1로 표시
    q.push({r1, c1}); //큐에 값 넣기

    while (!q.empty()) { //빈값이 없을때까지 반복
        int row = q.front().first; // 큐 프론트값 첫번째꺼 row에 대입
        int col = q.front().second; // 큐 프론트값 두번째꺼 col 에 대입
        int dist = visited[row][col]; // 방문한 위치 값 체크
        q.pop(); // 위에값 제거

        if (row == r2 && col == c2) //목표 카드에 도달했다면
            return dist; // 방문한 위치 값 반환

        for (int i = 0; i < 4; i++) { //컨트롤 입력 이동
            pair<int, int> np = ctrl(row, col, i, tmp); //컨트롤 이동 함수 pair저장
            if (visited[np.first][np.second]) // 해당 좌표 값의 first, second 값 존재 여부 확인
                continue; //반복
            visited[np.first][np.second] = dist + 1; // visited에 체크하기
            q.push(np); //큐에 값 대입
        }

        for (int i = 0; i < 4; i++) { //방향키 입력 이동
            int nr = row + dr[i], nc = col + dc[i];
            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || visited[nr][nc])
                continue;
            visited[nr][nc] = dist + 1;
            q.push({nr, nc});
        }
    }
    return -1; //목표 카드에 도달하지 못함 (실제로는 일어나지 않는 일)
}

int matchCard(int bit, int num, int r, int c, vector<int> &seq, vector<vector<ci>> &cards, vector<vector<int>> tmp){ //조합에 대해 카드를 매칭하는 함수
    int ans = 0; // 정답 0으로 초기화
    for (int i = 0; i < num; i++) { // 카드개수 만큼 반복
        int cur = seq[i]; //이번에 매칭할 캐릭터
        int now = 0; //해당 캐릭터의 0번째 카드부터 선택한다고 가정
        if (bit & (1 << i)) //만약 해당 위치의 비트가 1을 표시했다면 1번째 카드부터 선택
            now = 1; // now 변경

        for (int j = 0; j < 2; j++) { //2번 반복하기
            now = (now + j) % 2; //이번에 매칭할 카드 인덱스
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //이번에 매칭할 카드 위치
            ans += bfs(r, c, nr, nc, tmp); //현재 커서에서 목표 카드까지 이동하는 비용

            //카드 삭제 + 커서 이동
            tmp[nr][nc] = 0; //카드 삭제하기
            r = nr; // nr값 r에 대입하여 커서 이동
            c = nc; //nc값 c에 대입하여 커서 이동
        }
    }
    return ans;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9; //답 초기화

    vector<vector<ci>> cards = findCard(board); //존재하는 모든 카드의 위치
    int card_cnt = cards.size() - 1; //카드의 개수

    vector<int> seq(card_cnt); //순열을 위한 배열
    for (int i = 0; i < card_cnt; i++) // 카드의 개수 만큼 반복
        seq[i] = i + 1; // //배열에 저장

    do { //가능한 모든 카드 순서에 대해
        for (int bit = 0; bit < (1 << card_cnt); bit++) { //0, 1번째 카드 중 어떤 카드를 먼저 뒤집을지 결정
            answer = min(answer, matchCard(bit, card_cnt, r, c, seq, cards, board)); //더 작은값으로 갱신
        }
    } while (next_permutation(seq.begin(), seq.end()));
    return answer;
}

/**
 * 아이디어
 * 1. 범위가 크지 않음
 * 2. 존재하는 모든 카드의 종류는 6개, 카드 2장이 한 쌍을 이룬다.
 * 3. 뒤집을 카드 순서를 정하는 모든 경우의 수는 6!(카드 순서) * 2^6(2개의 카드 중 어떤 카드를 먼저 뒤집을지) -> 브루트포스 가능
 * 4. 이번에 목표로 하는 카드에 대해 현재 커서에서 목표 카드까지 가는 최단 경로를 구하며 이동 횟수 전부 구하고 최솟값 갱신
 *
 * 구현
 * 1. 존재하는 모든 카드의 위치를 저장하며 카드의 개수 세기 (findCard)
 * 2. 가능한 모든 카드의 순서(next_permutation)와 각 카드를 뒤집을 순서(bitmask)를 결정
 *    ex) seq = {3, 1, 2}, bit = 011 일 때
 *        3번, 1번, 2번 카드의 순서로 뒤집는다.
 *        3번 카드는 1번째 카드부터, 1번 카드는 0번째 카드부터, 2번 카드는 1번째 카드부터 뒤집는다.
 *        bit의 011이 앞에서부터 각각 1, 2, 3번 카드와 대응함
 * 3. 현재 카드 순서와 각 카드를 뒤집는 순서에 대한 커서 이동 횟수 계산 (matchCard)
 *    현재 커서 위치와 목표 카드 위치에 대해 bfs 함수 실행
 *    컨트롤 입력을 고려해야 하기 때문에 4방향에 대한 방향 이동에 추가로 컨트롤 입력도 처리한다.(ctrl)
 * 4. 매 조합에 따라 board가 갱신되므로 board를 복사한 tmp 사용
 * 공식 풀이 : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
 */
int main() {
    vector<vector<int>> board = {{1, 0, 0, 3},
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0}};
    cout << solution(board, 1, 0);
}