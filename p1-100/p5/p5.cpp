/*
    Problem 5

    Author: Shane Waxler
*/

#include <iostream>

using namespace std;


/*
    This can be optimized by limiting the for-loop.
    E.g., n%20 == 0 entails n%4, n%2, n%5 == 0.
*/
bool evenlyDivisible1to20(int n){
    for(int j = 20; j > 0; j--){
        if(n%j != 0)
            return false;
    }
    return true;
}

int main(){
    int n = 40;
    while(true){
        if(evenlyDivisible1to20(n)){
            break;
        }
        n += 20;
    }
    cout << n << endl;
    return 0;
}
