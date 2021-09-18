//
// Created by 반예원 on 2021/09/16.
//



#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include<algorithm>
using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {

    if( a.second > b.second)
       return a.second > b.second;
    if (a.first.size() > b.first.size())
        return a.first > b.first;
    return  a.first < b.first;

}
int main() {
    int n, n2;
    string cmd;
    stack<string> s;
    map<string, int> m;



    cin >> n >> n2;
    while (n--) {
        cin >> cmd;
        if (cmd.size() > n2-1)
            m[cmd]++;

    }
    vector<pair<string,int>> vec( m.begin(), m.end() );
    sort(vec.begin(), vec.end(), cmp);

    for (auto num : vec) {
        cout << num.first << "\n";
    }




}