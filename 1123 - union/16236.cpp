//
// Created by 반예원 on 2021/11/29.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;
typedef pair<int, int> ci;
typedef tuple<int, int,int> ci2;
int answer;

int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};

//Find 연산


//Union 연산
void unionInput( vector<vector<int>> &board,int a, int b) {
    queue <ci> q;
    vector <ci2> eatableFish;

    q.push({a,b});
    while(!q.empty()){

        }
}



int main() {
    int n;
    cin >> n;
    int a,b;
    //입력
    vector<vector<int>> board(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 9)
                a= i;
                b= j;
        }
    }
    //연산
    while (n--) {
        unionInput(board,a,b);
    }

    cout << answer;
}