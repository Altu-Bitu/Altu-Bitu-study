//
// Created by banya on 2021-10-07.
//

//
// Created by banya on 2021-10-07.
//

#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n,k;
    cin >> n >> k ;

    vector <int> v(n,0);
    for(int i =0;i<n;i++){
        cin >> v[i] ;

    }
    int sum=n-k;

    for(int i =0;i<n;i++){
        while(k--) {
            if (v[i] > 1)
                if (v[i] % 10 == 0)
                    sum = sum+(v[i] / 10);

        }

    }
    cout << sum;

}