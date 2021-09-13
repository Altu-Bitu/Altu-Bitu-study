//


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    //입력
    cin >> n;

    while (n--){
        int n1,k;
        k=1;
        cin >> n1;
        map <string, int> m;
        map <int, string> m1;
        int b = 0;
        int c = 1;
        for(int i =0; i<n1;i++){
            string input,input1;

            cin >> input >>input1;
            if(m.count(input1)){

                k++;
                m[input1]=k;
                m1[k]=input1;
            }
            else

                m[input1]=1;
                m1[1]=input1;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            int a = it->second;
            b = b+a;
            c=c*a;
        }

        if(m.size() == 1)
            c=0;

        cout << b+c;

    }

}