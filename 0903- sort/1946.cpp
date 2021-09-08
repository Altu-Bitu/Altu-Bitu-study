//
// Created by 반예원 on 2021/09/08.
//

//
// Created by banya on 2021-09-05.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int x1, x2;
};

//비교함수(good)
int cmpAdv(struct info i1,int n,vector<info> a ) {
    int cnt = 0;
    for (int i =0; i<n ;i++){
        if(i1.x1 < a[i].x1 || i1.x2 < a[i].x2 )
            cnt++;
    }

    if(cnt == n-1 ){
        cnt = 1 ;
        return cnt;
    }
    else{
        cnt = 0;
        return cnt;
    }

}


int main() {
    int n;


    //입력
    cin >> n;

    for (int i = 0; i < n; i++) {
        int n3;
        n3 = 0;
        int n2;
        n2 = 0;
        int cnt;
        vector<info> a;
        cin >> n2;
        a.assign(n2, {});

        cnt = 0;
        for (int i = 0; i < n2; i++)
            cin >> a[i].x1 >> a[i].x2;

        //출력
        for (int i = 0; i < n2; i++) {
            n3 = cmpAdv(a[i], n2, a);

            cnt = cnt + n3;

        }

        if(i == 0){
            cout << "\n";
            cout << cnt ;}
        else{
            cout << cnt ;
        }


    }
}