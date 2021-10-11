//
// Created by iw040 on 2021-10-05.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> v;

void divide(int a,int left, int right) {

    int sub=1;

    sub = a / 3;
    for (int j = left; j < a; j++) {
        for (int k = right; k < a; k++) {
            if (i % 3 == 1 && k % 3 == 1)
                v[sub+j]
                divide(a / 3,left+3,right-6);
        }
    }


}

int main() {
    int a;

    //입력
    cin >> a ;
    v.assign(a, vector<int>(a, 0));

    //연산 & 출력
     divide(a,1,a);
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(v[i][j]==0)
                cout << "*" ;
            else
                cout << " ";}
    cout << "\n";
    }
}