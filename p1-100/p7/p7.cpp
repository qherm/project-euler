/*
    Problem 7

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

int nthPrimeNumber(int n){
    int primes = 1;
    int i = 3;
    while(true){
        if(isPrime(i))
            primes++;
        if(primes == n)
            return i;
        i+=2;
    }
    return 0;
}

int main(){
    cout << nthPrimeNumber(10001) << endl;
    return 0;
}