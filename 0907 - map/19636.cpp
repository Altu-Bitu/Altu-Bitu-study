//
// Created by banya on 2021-09-13.
//

//
// Created by banya on 2021-09-09.
//

#include <iostream>

#include <math.h>
#include <map>
using namespace std;

int main(){
    int n1, n2,n3 ;
    int m1, m2,m3 ;
    int k;

    map<string, int> name; //이름이 입력되면 번호 출력
    map<int, string> number; //번호가 입력되면 이름을 출력

    string ans;
    cin >> n1 >> n2 >> n3;
    cin >> m1 >> m2 >> m3;

    if(n1-(n2+m3-m2)*m1<=0)
        cout << "Danger Diet";
    else
        cout << n1-(n2+m3-m2)*m1 <<" "<< n2;
    k = n1-(n2+m3-m2)*m1;
    while(m1--){

        if(n2+m3-m2 > n3) {
            n1= n1-(n2+m3-m2);
            k = floor((n2 + m3 - m2) / 2);
            n2 = n2 - k;

        }
        else
            n1= n1-(n2+m3-m2);
    }
    cout << "\n";
    if(n1>k)
        ans="YOYO";
    else
        ans="NO";
    if(n1<=0 || n2 <=0)
        cout << "Danger Diet";
    else
        cout << n1 <<" "<< n2 <<" "<<ans;
}