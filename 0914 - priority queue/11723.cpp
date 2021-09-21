//
// Created by 반예원 on 2021/09/18.
//

//
// Created by 반예원 on 2021/09/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<int> heap_vec;
int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, n2;
    string x;// 연산 명령어
    set<int> s;

    cin >> n; // 수행해야 하는 연산의 수

    while (n--) {

        cin >> x;
        if (x == "all") {

            s={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            continue;
        }
        else if(x == "empty"){
            s.clear();
            continue;
        }else
            cin >> n2;

        if (x == "add") {
            if (s.count(n2) == 0) {
                s.insert(n2);
                continue;
            }
        }
        if (x == "remove") {
            if (s.count(n2) != 0) {
                s.erase(n2);
                continue;
            }
        }
        if (x == "check") {

            if (s.count(n2) == 0) {
                cout << 0  <<"\n";
                continue;
            } else{
                cout << 1 <<"\n";
                continue;
            }
        }



    if (x == "toggle") {
        if (s.count(n2) != 0) {
            s.erase(n2);


            continue;
        } else
        {s.insert(n2);
            continue;}
    }



    }
}





