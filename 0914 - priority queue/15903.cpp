

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, n2,n3;
    int ans =0;
    int fir,sec,ca;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin >> n >>n2;

    for(int i=0;i<n;i++) {
        cin >> n3;
        pq.push(n3);
    }

    while(n2--){
        fir=pq.top();
        pq.pop();
        sec=pq.top();
        pq.pop();
        ca=fir+sec;
        pq.push(ca);
        pq.push(ca);
    }


    while (!pq.empty()) {

        ans=ans+pq.top();
        pq.pop();
    }
    cout << ans;


}