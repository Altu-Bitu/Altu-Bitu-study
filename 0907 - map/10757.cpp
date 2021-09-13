//
// Created by 반예원 on 2021/09/13.
//

//
// Created by banya on 2021-09-09.
//

#include <iostream>

#include <math.h>
#include <map>
using namespace std;

int main(){
    string n,n2,n4;
    int large;
    int a = 0;
    int ans=0;
    int ans2=0;
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

    for(int i=large-1;i>-1;i--){

        ans= n[i]+n2[i];
        if(ans>10){
            ans=ans+(i*10);
            ans2=ans2+ans;}
        else
            ans=ans+(i*10);
            ans2=ans2+ans;

    }
    cout << ans2;
}