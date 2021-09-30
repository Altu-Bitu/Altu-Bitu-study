//
// Created by banya on 2021-09-29.
//

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;
int num[SIZE];
char num2[SIZE];
vector<char> arr;

bool check[SIZE+1];
int n,m;
void backtracking(int cnt){
    if(cnt == m){
        for(int i=0;i<cnt;i++)
            cout <<num[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(!check[arr[i]]){

            num[cnt] = arr[i];
            check[arr[i]]= true;
            backtracking(cnt+1);
            check[arr[i]]=false;}
    }

}
int main(){

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
    backtracking(0);

}//
// Created by banya on 2021-09-30.
//

