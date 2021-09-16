//
// Created by 반예원 on 2021/09/13.
//

//


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n,n2,sum;
    int cnt = 0;

    map <string, int> m;
    vector <string> v;

    cin >> n >> n2;

    for(int i=0;i<n+n2;i++){
        string input;
        cin >> input;
        m[input]++;
        if(m[input] > 1)
            v.push_back(input);
    }
    sort(v.begin(),v.end());

    cout << v.size() << "\n";
    for (auto iter:v)
        cout << iter << "\n";

}