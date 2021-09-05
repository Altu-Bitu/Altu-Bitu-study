//
// Created by banya on 2021-09-05.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//정렬할 배열, 정렬된 배열

vector<int> arr;
//합병 정렬 (divide)


int main(){
    int n;

    cin>>n;
    arr.assign(n, 0);
    for(int i = 0; i < n ; i++)
        cin >> arr[i];

    sort(arr.begin(),arr.end());
    cout << *min_element(arr.begin(),arr.end()) << " ";
    cout << *max_element(arr.begin(),arr.end());

}