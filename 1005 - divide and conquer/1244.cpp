

#include <iostream>
#include <vector>

using namespace std;

vector<int> swich;
vector<pair<int,int>> v;

void divide(int n, int k) {

    for (int i = 0; i < k; i++) {

    if (v[i].first == 1) {
        for (int j = 1; j <= n; j++) {
            if (v[i].second * j > n)
                break;
            if (v[i].second * j <= n) {
                swich[v[i].second * j] =  !swich[v[i].second * j];
            }
        }
    }
    else{
        swich[v[i].second] = !swich[v[i].second];
        for(int j=1;j<=n;j++){
            if(v[i].second-j >=1  && v[i].second+j <=n)
            {
                if (swich[v[i].second - j] == swich[v[i].second + j])//
                {
                    swich[v[i].second - j] = !swich[v[i].second - j];
                    swich[v[i].second + j] = !swich[v[i].second + j];

                } else
                    break;
            }
        }
    }
}
}

int main() {
    int n,k;

    //입력
    cin >> n; //스위치 갯수
    swich.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
            cin >> swich[i];
    }
    cin >> k; //학생수
    v.assign(k,{0,0});
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >>  v[i].second;
    }

     divide(n, k);
//    for (int i = 1; i <= n; i++) {
//        cout << i << swich[i] << "\n";
//    }

    //출력
    for (int i = 1; i <= n; i++)
    {   cout << swich[i] << " ";
        if(i>=20  && i%20==0)
            cout << "\n";

    }
    return 0;
}