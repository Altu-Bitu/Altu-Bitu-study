//
// Created by banya on 2021-09-29.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 6;
int num[SIZE];
int num2[SIZE];
bool num_chk[10001];
vector<int> arr;
int n,m;

void backtracking(int cnt){
    if(cnt == m){

        for(int i=0;i<cnt;i++)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<arr.size();i++){
            num[cnt] = arr[i];
            backtracking(cnt+1);

    }

}
int main(){

    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(!num_chk[a]){
            arr.push_back(a);
            num_chk[a]=true;
        }
    }
    sort(arr.begin(), arr.end());

    backtracking(0);




}
