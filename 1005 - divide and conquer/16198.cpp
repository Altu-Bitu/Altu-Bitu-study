//
// Created by banya on 2021-10-11.
//

#include <iostream>
#include <vector>
using namespace std;
int ans=0;
vector<int> v;
void maxx(int sum)
{
    if(v.size()==3) {

        ans= max(ans, sum);
        return;
    }

    for(int i=2;i<v.size()-1;i++){

        int in = v[i];
        int bes=v[i-1]*v[i+1];

        v.erase(v.begin()+i);
        maxx(sum+bes);
        v.insert(v.begin()+i,in);


    }


}
int main(){
    int n;
    cin >>n;
    v.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> v[i];
    maxx(0);
    cout << ans;
}