//
// Created by banya on 2021-09-05.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> arr;

int bubbleSort(string arr2) {
    int cnt = 0;

    for (int i = 0; i < arr2.length(); i++) {

        for (int j = 1; j < arr2.length() ; j++) {
            if ((arr2[i] == arr2[j] )& (arr2[i] != arr2[j-1] ) &(j-i>0)) {

                cnt++;
            }

        }
    }
    return cnt;
}

int main() {
    int n;
    int cnt2;
    cnt2 = 0;
    //입력
    cin >> n;
    arr.assign(n, "");

    for (int i = 0; i < n; i++)
        cin >> arr[i]  ;

    //연산
//    sort(a.begin(), a.end(), cmpAdv);
    for (int i = 0; i < n; i++)
        if(bubbleSort(arr[i]) == 0)
            cnt2++;


    cout << cnt2 << " ";

}