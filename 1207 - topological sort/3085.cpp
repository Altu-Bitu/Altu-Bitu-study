//
// Created by 반예원 on 2021/12/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board; //보드 선언
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int cntCandy(int n, int row, int col, int dir) { //사탕 개수세기
    int ans = 0, cnt = 0; //ans와 cnt값 선언
    char cur = ' '; //cur 문자열 선언
    for (int i = 0; i < n; i++) { //해당 n만큼 반복하기
        if (cur == board[row][col]) { //연속된 사탕인경우
            cnt++; //갯수 증가
            ans = max(ans, cnt); //갯수와 ans비교후 최대값 갱신
        } else { //불연속
            cnt = 1; //1로 설정
            cur = board[row][col];// 해당 행,열의 보드 값 char에 대입
        }
        row += dr[dir];  //row값 방향값 더하여 갱신
        col += dc[dir]; //col값 방향값 더하여 갱신
    }
    return ans; //최종 ans 반환
}

int findCandy(int n) {
    int ans = 0; //ans값 0으로초기화
    for (int i = 0; i < n; i++) { //n만큼 반복하기
        ans = max(ans, cntCandy(n, 0, i, 0)); //같은 열에 대해
        ans = max(ans, cntCandy(n, i, 0, 1)); //같은 행에 대해
    }
    return ans; //최종 ans값 반환하기
}

int switchCandy(int n, int row, int col, char candy) { //사탕 바꾸기
    int ans = 0; //닶 초기화
    for (int i = 0; i < 2; i++) { //오른쪽, 아래에 있는 사탕과 바꿔보기
        int nr = row + dr[i], nc = col + dc[i]; // nr, nc에 좌표 값 늘려서 값 저장
        if (nr < n && nc < n && candy != board[nr][nc]) { //사탕 바꿀 수 있는 경우
            swap(board[row][col], board[nr][nc]); // 바꾸기
            ans = max(ans, findCandy(n)); //
            swap(board[row][col], board[nr][nc]);
        }
    }
    return ans;
}

/**
 * 입력 범위가 크지 않으므로 바꿀 수 있는 사탕을 모두 바꿔보며 먹을 수 있는 사탕 계산
 * 오른쪽, 아래에 있는 사탕과만 바꿔도 모든 경우 고려 가능(왼쪽, 위 고려 X)
 *
 * 1. 사탕의 색이 다른 사탕만 교환하기
 * 2. 각 열, 행이 모두 같은 사탕일 때 사탕의 개수가 갱신되지 않도록 주의 (ans 갱신을 line 18~21에서 하는 경우)
 */
int main() {
    int n, max_candy = 0;

    //입력
    cin >> n; //n값 입력 받기
    board.assign(n, vector<char>(n, ' ')); // 보드값 초기화하기
    for (int i = 0; i < n; i++) //입력받은 n만큼 반복하여
        for (int j = 0; j < n; j++)
            cin >> board[i][j]; //보드값 넣기

    //연산
    for (int i = 0; i < n; i++) { //이중반복하여 연산 진행
        for (int j = 0; j < n; j++)
            max_candy = max(max_candy, switchCandy(n, i, j, board[i][j])); // switchCandy 함수 리턴 후 값과 최대 캔디 비교후
            //최대값 갱신
    }

    //출력
    cout << max_candy; // 최대값 출력
}