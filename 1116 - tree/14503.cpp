//
// Created by 반예원 on 2021/11/22.
//

#include <iostream>
#include <algorithm>

using namespace std;

int board[55][55];

int c;
int answer=0;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};

void dfs(int a, int b){
    for (int i = 0; i < 8; i++) { //가능한 방향의 정점(자식노드) 모두 탐색
        int nr = a + dr[i];
        int nc = b + dc[i];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc]) //탐색하려는 정점이 범위 내에 있고, 땅이라면
            dfs(nr, nc); //바로 탐색(깊게 탐색)
    }



int main(){
    int a,b;
    cin>>n>>m;

    cin >> a >> b >> c;

    if(c==3){
        c = 1;
    }
    else if(c==1) {
        c = 3;
    }
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    }
    dfs(a,b);
    cout<<result;
    return 0;

}