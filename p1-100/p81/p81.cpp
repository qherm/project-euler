/*
    Problem 81

    Author: Shane Waxler
    Method: Uniform Cost Search where actions are either down or right.
*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>
#include <queue>
#include <utility>

using namespace std;

typedef std::pair<int,int> coords;
typedef std::pair<coords, int> coord_val_pair;

struct coordValComp {
    bool operator()(
        coord_val_pair const& a,
        coord_val_pair const& b)
    {
        return a.second > b.second;
    }
};

std::vector<int> tokenize(std::stringstream& ss, char del){
    std::vector<int> r;
    std::string token;
    while(std::getline(ss, token, del)){
        r.push_back(stoi(token));
    }

    return r;
}

int main(){
    std::ifstream file;
    file.open("p081_matrix.txt");
    std::string line;
    std::vector< std::vector<int> > matrix;

    while(getline(file,line)){
        std::stringstream ss(line);
        std::vector<int> temp = tokenize(ss, ',');
        matrix.push_back(temp);
    }
    file.close();

    std::priority_queue< coord_val_pair, std::vector<coord_val_pair>,  coordValComp> frontier;
    coord_val_pair state(coords(0,0), matrix.at(0).at(0));
    std::set< coords > visited;
    frontier.push(state);
    while(!frontier.empty()){
        state = frontier.top();
        frontier.pop();
        int i = state.first.first;
        int j = state.first.second;
        if(i == 79 && j == 79){
            break;
        }
        int right = i + 1;
        int down = j + 1;
        if(right < 80){
            coords nextCoordsRight(right,j);
            coord_val_pair rightCVP(nextCoordsRight, state.second + matrix.at(right).at(j));
            if(visited.find(nextCoordsRight) == visited.end()){
                visited.insert(nextCoordsRight);
                frontier.push(rightCVP);
            }
        }
        if(down < 80){
            coords nextCoordsDown(i,down);
            coord_val_pair leftCVP(nextCoordsDown, state.second + matrix.at(i).at(down));
            if(visited.find(nextCoordsDown) == visited.end()){
                visited.insert(nextCoordsDown);
                frontier.push(leftCVP);
            }
        }
    }
    cout << state.second << endl;
    return 0;
}