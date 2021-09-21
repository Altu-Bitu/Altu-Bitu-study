//
// Created by banya on 2021-09-19.
//

#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> arr;
#define SIZE 10000
int main(){
    char arr[SIZE];

    cin >> arr;


    for(int i =1 ;i<arr.size();i++)
    {   if(arr[i]=="_")
        cout << arr[i];
    }



    cout << arr;


}