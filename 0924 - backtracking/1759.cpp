//
// Created by banya on 2021-09-29.
//

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;
char num[SIZE];

vector<char> arr;

bool check[SIZE+1];
int n,m;
void backtracking(int cnt){
    if(cnt == n){
        for(int i=0;i<cnt;i++)
            cout <<num[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0;i<m;i++){
        if(!check[arr[i]]){

            num[cnt] = arr[i];
            check[arr[i]]= true;
            backtracking(cnt+1);
            check[arr[i]]=false;}
    }

}
int main(){
    char x;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x;
        arr.push_back(x);
    }

    for(int i=0;i<m;i++){
        cout << arr[i];
    }
    backtracking(0);

}

