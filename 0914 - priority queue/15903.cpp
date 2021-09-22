

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, n2,n3;
    long long ans =0;
    long long fir,sec,ca;
    priority_queue<long long ,vector<long long >,greater<long long>> pq;
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