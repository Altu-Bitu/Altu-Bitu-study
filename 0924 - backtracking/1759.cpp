//
// Created by banya on 2021-09-29.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
const int SIZE = 8;
char num[10];

vector<char> arr;
set<string> v;
bool check[1000];
int n,m;
void backtracking(int cnt){
    if(cnt == n){
        char num2[size(num)];
        string ans;

        int s =0;
        for(int i=0;i<n;i++) {
            if (num[i] == 'a' || num[i] == 'e' || num[i] == 'i' || num[i] == 'o' || num[i] == 'u')
                s++;
        }
        if(s>=1){
            for(int i=0;i<n;i++)
            num2[i] = num[i];

            sort(num2,num2+n);
            for(int i=0;i<n;i++)
                ans=ans+num2[i] ;

                v.insert(ans);


            return;
        }


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
    sort(arr.begin(), arr.end());

    backtracking(0);
    for (auto iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << '\n';

}

