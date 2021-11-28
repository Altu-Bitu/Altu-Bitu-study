#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    //칸의 좌표와 방향, 초기화한 보드값 가져오기
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    // 초기화
    int step = 0; //회전 카운트 선언
    int ans = 0;
    while (true) { //반복문
        if (board[r][c] == 0) { //값이 0일시
            board[r][c] = 2; //2값으로 값 바꾸기
            ans++; //ans값 증가
        }

        if (step == 4) { //step 값 4라면
            if (board[r - dr[d]][c - dc[d]] == 1)
                //한바퀴 돌아 제자리로 만들기
                return ans;
            r -= dr[d]; //  칸 좌표 초기화
            c -= dc[d];//  칸 좌표 초기화
            step = 0; // step 값 으로 초기화
        } else { //4가 아니라면
 면          d = (d + 3) % 4; // 방향 변경
            if (board[r + dr[d]][c + dc[d]]) { // 값이 잇다면
                step++; //회전 카운트 값 증가
                continue;
            }
            r += dr[d]; //칸 좌표 값 갱신
            c += dc[d];
            step = 0; // step 0 값으로 생신
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d;
    // 세로크기, 가로크기 입력 받고 칸의 좌표와 방향 입력 받기
    vector<vector<int>> board(n, vector<int>(m, 0));
    // 보드 2차원 벡터 초기화
    for (int i = 0; i < n; i++) { //보드값 입력 받기
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0;
}
