
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


    cout << v.size();


}