/*
    Problem 6

    Author: Shane Waxler
*/

#include <iostream>
#include <math.h>

using namespace std;

int sumOfSquares(int n){
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += pow(i,2);
    }
    return s;
}

int squareOfSum(int n){
    int s = 0;
    for(int i = 0; i <= n; i++){
        s+=i;
    }
    return pow(s,2);
}

int main(){
    cout << sumOfSquares(100) - squareOfSum(100) << endl;
    return 0;
}
