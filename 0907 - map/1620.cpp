//
// Created by banya on 2021-09-10.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n,m;
    string input;
    map<string, int> name;
    map<int, string> number;

    cin >>n>>m;
    for(int i =1; i<=n;i++){
        cin >> input;
        name[input]=i;
        number[i]=input;
    }
while(m--){
    cin >>input;
    if(isdigit(input[0]))
        cout<< number[stoi(input)] <<'\n'; //stoi : string to int
        else
            cout << name[input] << "\n";

}
}
