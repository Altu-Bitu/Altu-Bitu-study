//
// Created by 반예원 on 2021/11/01.
//

#include<iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main() {
    map<int, string> number; //번호가 입력되면 이름을 출력
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt=0;
    int n;
    vector<char> wordd;
    string word;

    cin >> n;
    cin >> word;
    number[0] = word; //key : 번호, value : 이름
    for()
    word.sort(word.begin(),word.end());
    for(int i=1;i<word.size();i++)
    {
        cin >> input2;
        number[i] = input2; //key : 번호, value : 이름
        number[i].sort(number[i].begin(),number[i].end());
        if(number[i]==number[0])
            cnt++
    }

    cout << cnt;
}