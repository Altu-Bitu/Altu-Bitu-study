//
// Created by 반예원 on 2021/09/27.
//
#include <iostream>

using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int w;
    int w2;
bool an = true;
for (int i=1;i<10000;i++){

    for(int j=1;j<10000;j++){
        w=0;
        w2=0;
        w=i*2;
        w2=(j-2)*2;

        if(w+w2==a && a == i*j-b){
            cout << j << " " << i ;
            an= false;
            break;
        }

    }
    if(an == false)
        break;
}

}