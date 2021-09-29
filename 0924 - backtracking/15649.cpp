//
// Created by banya on 2021-09-29.
//

#include <iostream>

using namespace std;
const int SIZE = 8;
int num[SIZE];
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
        if(!check[i]){

        num[cnt] = i;
        check[i]= true;
        backtracking(cnt+1);
        check[i]=false;}
    }

}
int main(){

    cin >> n >> m;

    backtracking(0);

}