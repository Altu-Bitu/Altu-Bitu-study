//
// Created by banya on 2021-09-05.
//
#include <iostream>
#include <vector>

using namespace std;

//정렬할 배열
vector<int> arr;


//향상된 버블 정렬
int bubbleSortAdv(int n,int b,int c ){
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if(((arr[i]-b)%c)==0 )
            cnt=cnt+(1+(((arr[i]-b)/c)));
        else
            cnt=cnt+(1+(((arr[i]-b)/c) +1));
    }
    return cnt;

}

int main() {
    int n;
    int b,c;
    b=0;
    c=0;
    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> b >> c;

    //연산
    //bubbleSort(n);

    cout <<  bubbleSortAdv(n,b,c) << '\n';
}