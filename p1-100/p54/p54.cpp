/*
    Problem 54

    Author: Shane Waxler
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <istream>

using namespace std;

int rank(){
    return 0;
}

std::vector<string> tokenize(std::stringstream& ss, char del){
    std::vector<string> r;
    std::string token;
    while(std::getline(ss, token, del)){
        r.push_back(token);
    }

    return r;
}

int main(){
    ifstream file;
    file.open("poker.txt");
    file.close();
    return 0;
}
