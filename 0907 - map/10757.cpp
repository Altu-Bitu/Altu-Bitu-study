//
// Created by 반예원 on 2021/09/13.
//

//
// Created by banya on 2021-09-09.
//

#include <iostream>
#include<string>
#include <math.h>
#include <map>
using namespace std;

int main(){
    string n,n2,n4;
    int large;
    int a = 0;
    int ans=0;
    int ans2=0;
    string result;

    n4="";


    cin >> n >> n2;

    if(n.length()>n2.length()){
        string n3;
        large = n.length();
        a= large-n2.length();
        for(int i=0;i<a;i++)
            n3 = n3 +"0";
        n2=n3+n2;
    }

    else {
        string n3;
        large = n2.length();
        a= large-n.length();
        for(int i=0;i<a;i++)
            n3 = n3 +"0";
        n=n3+n;

    }
    int carry=0;

    while (n.size()!=0 && n2.size() !=0)
    {
        int aback = n.back() - '0'; //문자열에서 맨마지막 문자를 숫자로 바꿈
        int bback = n2.back() - '0'; //마찬가지

        int remain = (carry + aback+bback) % 10;
        carry = (carry+aback+bback)/10;
        result = (char)(remain+"0")+result;
        n.pop_back();
        n2.pop_back();

    }
    if(carry) //마지막 자리 까지 다더했는데 캐리가 있으면 캐리를 맨앞에 붙여줘야함.
        result = (char)(carry+'0') + result;
    cout << result << endl;
}