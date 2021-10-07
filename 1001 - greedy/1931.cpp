//
// Created by banya on 2021-10-06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int,int> ci;
bool cmp(const ci &a, const ci &b){
    if(a.second!=b.second)
        return a.second < b.second;//회의가 끝나는 시간이 빠른순으로
    return a.first < b.first;  //끝나는 시간이 같다면, 시작 시간이 빠른 순으로
}
int maxMeeting(int n, vector <ci> meeting){
    int end = meeting[0].second;
    int cnt = 1;
    for(int i=1;i< n;i++){
        if(end <= meeting[i].first){
            cnt++;
            end = meeting[i].second;
        }
    }
return cnt;
}
int main(){
    int n;

    cin >> n;
    vector <ci> meeting(n,ci(0,0));\
    for(int i = 0;i<n;i++)
    cin >> meeting[i].first >> meeting[i].second;

    sort(meeting.begin(),meeting.end(),cmp);
    cout << maxMeeting(n,meeting) << "\n";

    return 0;
}