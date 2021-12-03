//
// Created by 반예원 on 2021/11/30.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) { //함수 및 인자 선언
    int tot_time = 0; //총 시간 선언
    for (int i = 0; i < n; i++) { //세로만큼 반복
        for (int j = 0; j < m; j++) { //가로만큼 반복
            if (land[i][j] > height) { //블록 제거
                b += (land[i][j] - height);  //만약 높이보다 랜드의 높이가 높다면 블록인벤토리에 저장
                tot_time += 2 * (land[i][j] - height); // 인벤토리에 넣는 작업 시간 소요 저장
            } else if (land[i][j] < height) { //블록 쌓기
                b -= (height - land[i][j]); //블록의 수 감소
                tot_time += (height - land[i][j]); // 블록위에 올리는 시간 저장
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1;
    return tot_time; //총 걸리는 시간 리턴
}

/**
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */
int main() {
    int n, m, b, min_height = 256, max_height = 0; // 세로,가로,블록수 선언

    //입력
    cin >> n >> m >> b; //입력 받기
    vector<vector<int>> land(n, vector<int>(m, 0)); //2차원 벡터로 land 공간 선언
    for (int i = 0; i < n; i++) { //n만큼 반복하고
        for (int j = 0; j < m; j++) { //m만큼 반복 => 공간 값 입력 받기
            cin >> land[i][j]; // 블록 높이 입력 받기
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0; // 최소 시간 INF로 초기화, 높이도 0으로 초기화
    for (int i = min_height; i <= max_height; i++) { // 제일 높은 땅 높이 만큼 반복
        int t = mineLand(n, m, b, i, land); // mineLand값 리턴 값 저장
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t;
            height = i;
        }
    }

    //출력
    cout << min_time << ' ' << height;
}