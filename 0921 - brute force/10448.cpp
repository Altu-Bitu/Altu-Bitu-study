//
// Created by 반예원 on 2021/09/27.
//

//
// Created by 반예원 on 2021/09/27.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int SIZE = 10;

vector<int> isPrime() {
    vector<int> prime(SIZE + 1, 0);

    for(int i=1;i<prime.size();i++){
        prime[i]=(i*(i+1)/2);
    }


    return prime;
}

int main(){
    int n,n2;
    int sum=0;
    vector<int> prime = isPrime();


    cin >> n;

    while(n--){
        int a;
        cin >> a;
        int sum=0;
        for(int i=0;i<prime.size();i++){
            for(int j=0;j<3;j++){
                if(sum==a){
                    cout << 1 ;
                }
                sum=sum+prime[i]*j;

            }
            if(sum==a){
                cout << 1 ;
            }
        }

    }
    cout << sum ;


}