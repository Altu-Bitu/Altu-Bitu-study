//
// Created by banya on 2021-09-27.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    vector <int> v;


    cin >> n >> m;

    int n2 = 2*n;
    int j=10000;
    v.assign(n2, 0);
    for(int i=0;i<n2;i++){
        cin  >> v[i];

    }

    int j2=10000;
    while (j--) {
        int cnt=0;
        for (int i = 0; i < n2; i++) {
            if(i<n-1 || i ==n2-1)
                v[i]--;

        }
        int a = v[n2-1];
        v.pop_back();
    v.insert(v.begin(),1,a);

        for (int i = 0; i < n2; i++) {
            cout << v[i] <<" ";
        }

        for (int i = 0; i < n2; i++) {
            if (v[i] <=0) {
                cnt++;
            }
        }
        cout << "cnt :["<< j <<"]";
        if(cnt >= m){
            cout << j2-j;
            break;}
    }


}