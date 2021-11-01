//
// Created by 반예원 on 2021/11/01.
//

#include<iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int maxMenu(int n, int n2,int n3,int n4, vector<int> &sushi){
    int section_visitor = 0;
    int x;
    x= n-n2;
    for (int i = 0; i < n3; i++) {
        section_visitor -= visitor[i - x]; //이번 윈도우에 제외되는 값
        section_visitor += visitor[i]; //이번 윈도우에 추가되는 값
        if (section_visitor > ans) { //최대 방문자 수가 갱신된다면
            cnt = 1;
            ans = section_visitor;
        } else if (section_visitor == ans) //최대 방문자 수와 같다면
            cnt++;
    }


}
int main() {
    int n,n2,n3,n4;
    int num;
    int ans;

    cin >> n >> n2 >> n3 >> n4;
    vector<int> sushi(n, 0);
    for(int i=0;i<n;i++){
        cin >> sushi[i];
    }
    ans = maxMenu(n,n2,n3,n4,sushi);

}