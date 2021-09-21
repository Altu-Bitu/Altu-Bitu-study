

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, n2;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    cin >> n;

    while (n--) {
        //입력
        cin >> n2;
        if(n2!=0)
            pq.push(make_pair(abs(n2),n2));
        if(n2==0){
            if(!pq.empty()){
            cout << pq.top().second<<"\n";
            pq.pop();}
            else
                cout << 0<<"\n";
        }
    }


}