/*
    Problem 2

    Author: Shane Waxler
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> fibnums = {1, 2};
    int num;
    int sum = 2;
    for(int i = 1; i < 10000; i++){
        num = fibnums[i] + fibnums[i-1];
        fibnums.push_back(num);
        if(num % 2 == 0)
            sum+=num;

        if(num >= 4000000)
            break;
    }
    cout << sum << endl;
    return 0;
}
