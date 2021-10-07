//
// Created by banya on 2021-10-06.
//

#include <iostream>
#include <vector>
using namespace std;
int coinCnt(int n,int k, vector<int> &coin){
    int cnt =0 ;//필요한 동전 개수 카운트
    for(int i=n-1;i>=0;i--){
        if(k==0)
            break;
        if(coin[i]<=k){
            cnt +=(k/coin[i]);
            k=k%coin[i];
        }
    }
    return cnt;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> coin(n,0);
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    cout << coinCnt(n,k,coin);
    return 0;
}