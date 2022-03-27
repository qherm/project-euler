/*
    Problem 3

    Author: Shane Waxler
*/

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n){
    if (n == 2 || n == 3)
        return true;
    if(n%2 == 0 || n < 2)
        return false;
    for(int i = 3; i < pow(n, 0.5)+1; i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long num = 600851475143;
    for(int i = pow(num,0.5)-1; i >=3; i-=2){
        if(num%i == 0){
            if(isPrime(i)){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
