//
// Created by banya on 2021-09-23.
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//재귀함수로 구현한 유클리드 호제법
int gcdRecursion(int a, int b) {
    if (b == 0) //b가 0이면 a가 최대공약수
        return a;
    //a%b구한 후 b와 자리 바꾸어서 호출
    return gcdRecursion(b, a % b);
}

int main() {
    int t;
    string s;
    vector<int> v;
    //입력
    cin >> t;
    cin >> s;
    int ans=1;
//    //연산(입력으로부터 n, m 추출하기)
//    int index = s.find('*')|| s.find('/');//':' 위치 찾기
    int n = stoi(s); //: 이전의 문자를 숫자로 변경
//    int m = stoi(s.substr(index + 1, s.length())); //: 이후 문자를 숫자로 변경
//    cout << index;
    for(int i=2;i<s.length();i=i+4){
        if(s.substr(i,1)=="*")
            ans=ans*stoi(s.substr(i-2,1)) * 1;
        if(s.substr(i,1)=="/")
            ans=ans/stoi(s.substr(i-2,1)) / 1;


    }


    cout << n;


    return 0;
}