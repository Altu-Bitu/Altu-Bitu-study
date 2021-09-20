//
// Created by banya on 2021-09-19.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<int, int> > s;
    int num, height;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> height;

        while (!s.empty()) {

            if (height < s.top().second) { // s.top().second
                cout << s.top().first << " ";
                break;
            }

            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        }

        s.push(make_pair(i + 1, height));
    }


}