//
// Created by banya on 2021-10-07.
//

#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    int slen=0;
    vector <int> v(n,0);
    for(int i =0;i<n;i++){
        cin >> v[i];

    }
    for(int i =0;i<n-2;i++){

        for(int j =1;j<n-1;j++)
            for(int k =2;k<n;k++){
                if(v[i]+v[j] > v[k] && slen < (v[i]+v[j]+v[k]))

                    slen = v[i]+v[j]+v[k];

            }

    }
    if(slen ==0)
        cout << -1;
    else
        cout << slen;
}