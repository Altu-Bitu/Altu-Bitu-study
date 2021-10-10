

#include <iostream>
#include <vector>

using namespace std;

vector<int> swich;
vector<pair<int,int>> v;

void divide(int n, int k) {

    for (int i = 0; i < k; i++) {

    if (v[i].first == 1) {
        for (int j = 1; j < n; j++) {
            if (v[i].second * j > n)
                break;
            if (v[i].second * j <= n) {
                if (swich[v[i].second * j-1] == 0)
                    swich[v[i].second * j-1] = 1;
                else
                    swich[v[i].second * j-1] = 0;
            }
        }
    }
}
}

int main() {
    int n,k;

    //입력
    cin >> n; //스위치 갯수
    swich.assign(n, 0);
    for (int i = 0; i < n; i++) {
            cin >> swich[i];
    }
    cin >> k; //학생수
    v.assign(k,{0,0});
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >>  v[i].second;
    }

     divide(n, k);

    //출력
    for (int i = 0; i < n; i++) {
        cout << swich[i] << " ";
    }
}