/*
    Problem 4

    Author: Shane Waxler
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isPalindrome(int n){
    std::vector<int> forward;
    std::vector<int> backward;
    while(n != 0){
        forward.insert(forward.begin(), n%10);
        backward.push_back(n%10);
        n = n / 10;
    }
    for(int i = 0; i < forward.size(); i++){
        if(backward.at(i) != forward.at(i)){
            return false;
        }
    }
    return true;
}

int main(){
    set<int> sAll;
    int max = 0;
    for(int i = 999; i > 99; i--){
        for(int j = 999; j > 99; j--){
            if(sAll.find(i*j) == sAll.end() && i*j > max){
                if(isPalindrome(i*j)){
                    max = i*j;
                }
                sAll.insert(i*j);
            }
        }
    }
    cout << max << endl;
    return 0;
}
