/*
    Problem 46

    Author: Shane Waxler
*/

#include <iostream>
#include <math.h>

using namespace std;

/*
    Methodology:
        If (n - prime number)/2 is not a 
        perfect square, return false.
*/

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

bool isSumOfPrimeAndTwiceSquare(int n){
    for(int i = 1; i < n; i+=2){
        if(isPrime(i)){
            double prospect = (n - i)/2.0;
            double sqProspect = pow(prospect, 0.5);
            if(sqProspect == floorf(sqProspect) || sqProspect == ceil(sqProspect)){
                cout << n << " = " << i << " + 2*" << sqProspect << "^2" << endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int i = 3;
    while(true){
        if(!isPrime(i)){
            if(!isSumOfPrimeAndTwiceSquare(i))
                break;
        }
        i+=2;
    }
    cout << i << endl;
    return 0;
}
