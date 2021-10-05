#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

ci dir[4] = {{0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0}}; //하

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    //뱀 초기화
    deque<ci> snake;
    snake.push_front(ci(0, 0));
    board[0][0] = 1;

    int t = 0, head = 0; //시간, 뱀의 머리 방향
    while (true) { //break 전까지 반복
        t++; //시간 증가
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first;
        int nc = snake.front().second + dir[head].second;
        //뱀의 꼬리 초기화

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)
            break;

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0; //몸길이 줄여서 칸 값비우기
            snake.pop_back(); //젤 뒤에값 삭제
        }

        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc));
        board[nr][nc] = 1; // 이동후 칸 값 1로 채우기

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4;
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4;
    }
    return t;
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */
int main() {
    int n, k, row, col, l, x;
    char c;

    //입력
    cin >> n >> k; //보드 크기와, 사과 갯수 입력 받기
    vector<vector<int>> board(n, vector<int>(n)); //보드 선언
    for (int i = 0; i < k; i++) {
        cin >> row >> col; //사과의 row, col 입력 받기
        board[row - 1][col - 1] = 2; //사과 표시
    }
    cin >> l; //뱀의 방향 변환 횟수 입력 받기
    map<int, char> cmd;
    for (int i = 0; i < l; i++) { //회전 정보
        cin >> x >> c;
        cmd[x] = c;
    }

    //연산 & 출력
    cout << playGame(n, board, cmd);
}