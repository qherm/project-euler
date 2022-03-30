/*
    Problem 500

    Author: Shane Waxler

    Intuition: Perhaps this is a factorial question wherein
    the smallest number with n divisors is (n-1)! ('-1' 
    because you can exclude the number itself)
*/

#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

// int numDivisors(int n){
//     if(n==1)
//         return 1;

//     cout << 1 << endl;
//     int divisors = 2;

//     if(n%2==0){
//         cout << 2 << endl;
//         divisors++;
//         for(int i = 3; i <= n/2; i++){
//             if(n%i==0){
//                 divisors++;
//                 cout << i << endl;
//             }
//         }
//     } else{
//         for(int i = 3; i <= n/2; i+=2){
//             if(n%i)
//                 divisors++;
//         }
//     }

//     return divisors;
// }

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

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



unordered_map<int,int> divisors(int n, unordered_map<int,int> divs){
    if(n == 1 || n == 0)
        return divs;

    if(n%2 == 0){
        if(divs.find(2) != divs.end()){
            divs[2] += 1;
        } else {
            divs.insert(make_pair(2,1));
        }
        return divisors(n/2, divs);
    } else if(n%3==0){
        if(divs.find(3) != divs.end()){
            divs[3] += 1;
        } else {
            divs.insert(make_pair(3,1));
        }
        return divisors(n/3, divs);
    } else if(isPrime(n)){
        if(divs.find(n) != divs.end()){
            divs[n] += 1;
        } else {
            divs.insert(make_pair(n,1));
        }
        return divs;
    }

    for(int i = 5; i < n/2 + 1; i++){
        if(isPrime(i) && n%i==0){
            if(divs.find(i) != divs.end()){
                divs[i] += 1;
            } else {
                divs.insert(make_pair(i,1));
            }
            return divisors(n/i, divs);
        }
    }

    return divs;
}

int main(){
    unordered_map<int,int> um;
    print_map(divisors(120,um));
    return 0;
}