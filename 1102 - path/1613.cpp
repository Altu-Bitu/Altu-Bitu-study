//
// Created by 반예원 on 2021/11/08.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> history(402, vector<int>(402,0));
void solve(int n){
    int i,j,k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (history[i][k] == 1 && history[k][j] == 1)
                    history[i][j] = 1, history[j][i] = -1;
}

int main(){
    int a,b,d,e;
    cin >> a >> b;

    for(int i=0;i<b;i++){
        cin >> d >> e;
        history[d][e] = -1;
        history[e][d] = -1;
    }
    solve(a);
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> d >> e;
        cout << history[d][e];
    }
}

//참고:http://melonicedlatte.com/algorithm/2018/11/16/002936.html