//
// Created by banya on 2021-10-07.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

string solution(string number, int k) {
    int answer = 0;
    string answer3="";
    for (int i = 0; i<number.size()-1 ; i++)
        for(int j=i;j<number.size();j++)

        {
            string number2 = number;
            for(int l=0;l<k;k++)
            {number2.erase(l,1);}

            cout << number2 << '  ';
            if(answer < stoi(number2))
                answer = stoi(number2);
        }

    answer3=to_string(answer);;
    return answer3;

}