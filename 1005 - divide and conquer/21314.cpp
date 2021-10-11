//
// Created by banya on 2021-10-11.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<char> v;
    string a;
    cin >> a;
    v.assign(a.length(),0);
    for(int i=0;i< a.length();i++){

        v[i]=a[i];}

    for(int i=0;i< a.length();i++)
        cout << v[i];

}