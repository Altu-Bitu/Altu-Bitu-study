//
// Created by iw040 on 2021-09-10.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
const int SIZE = 10001;

int main() {
    int n, k;
    string cmd;
    deque<int> q;
    int y;
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push_back" ) {
            cin >> k;
//            if (!full()) //라이브러리 사용시 필요 없음
//                q.push(k);
            q.push_back(k);
            continue;
        }
        if (cmd == "push_front" ) {
            cin >> k;
//            if (!full()) //라이브러리 사용시 필요 없음
//                q.push(k);
            q.push_front(k);
            continue;
        }
        if (cmd == "pop_back" ) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                y = q.back();
                q.pop_back();
                cout << y << '\n';
            }
            continue;
        }
        if (cmd == "pop_front" ) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                y = q.front();
                q.pop_front();
                cout << y << '\n';
            }
            continue;
        }

        if (cmd == "size") {
            cout << q.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << q.empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
            continue;
        }
        if (cmd == "back") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
            continue;
        }
    }

}