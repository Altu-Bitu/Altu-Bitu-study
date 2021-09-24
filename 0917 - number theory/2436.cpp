//
// Created by banya on 2021-09-23.
//

#include <iostream>
#include <vector>
#include <cmath>
//항상 x >= y 이므로 대소관계를 체크하지 않음
int calcGCD(int x, int y) {
    int tmp; // 임시 저장 변수
    while (y != 0) { //
        tmp = x % y; // x를 y로 나눈 나머지를 tmp에 저장
        x = y; // y값을 x에
        y = tmp;//다시 y에 나머지값
    }
    return x; // y가 0일때 x리턴
}

/**
 * 최대공약수를 G, 최소공배수를 L 이라고 하자.
 * G*L = A*B 이고
 * A = G*a, B = G*b로 나타낼 수 있다.
 * 이에 따라 G*L = G*G*a*b라 할 수 있고 이를 정리하면
 * L/G = a*b 이다.
 *
 * A+B가 최소가 되려면, a+b가 최소가 되어야 하고, 그러기 위해선 a, b의 차이가 최소여야 한다.
 */
int main() {
    int gcd, lcm;

    //입력
    cin >> gcd >> lcm; // 최대 공약수랑 공배수 입력 받기

    //연산
    int ab = lcm / gcd; // 최대공배수 / 최대 공약수
    int a = -1, b = -1; //
    for (int i = sqrt(ab); i > 0; i--) { //a, b의 차이가 가장 작을 제곱근부터 체크
        if (ab % i != 0) //
            continue;
        //i가 ab의 약수라면
        int tmp_a = i, tmp_b = ab / i;
        //두 수가 서로소인지 체크 -> 만약 두 수가 서로소가 아니라면 두 수의 최대공약수가 gcd가 될 수 없음
        if (calcGCD(tmp_b, tmp_a) == 1) { //최대 공약수가 1이면 == 서로소면
            a = tmp_a; // a값은,tmp_a
            b = tmp_b; // b는 tmp_b의 값
            break;
        }
    }

    //출력
    cout << a * gcd << ' ' << b * gcd;
}