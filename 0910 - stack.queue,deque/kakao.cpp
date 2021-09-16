//
// Created by 반예원 on 2021/09/16.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> s;
    int answer = 0;
    for(int i=0;i<moves.size();i++)
    {
        int check = moves[i] - 1;
        for(int j=0;j<board.size();j++)
        {
            if(board[j][check] != 0)
            {
                if(!s.empty() && s.top() == board[j][check])
                {
                    s.pop();
                    answer += 2;
                }
                else
                    s.push(board[j][check]);
                board[j][check] = 0;
                break;
            }
        }
    }
    return answer;
}