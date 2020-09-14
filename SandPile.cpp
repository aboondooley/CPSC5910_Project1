//
// Created by Alie on 9/10/2020.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "SandPile.h"
using namespace std;

void SandPile::setPile(const int *cells) {
    // TODO add an edge case to do nothing if a number is negative (or type
    //  is not a number)
    for (int i = 0; i < ARRAY_SIZE; i++){
        this->pile[i] = cells[i];
    }
}

bool SandPile::isStable() const {
    for (int i = 0; i < ARRAY_SIZE; i++){
        if (this->pile[i] > 3){
            return false;
        }
    }
    return true;
}

void SandPile::stabilize() {
    vector<int> topple_list;
    vector<int> neighbors;
    while (!isStable()){
        topple_list = toppleList(); //indexes of those to topple
        topple(topple_list);
        neighbors = getNeighbors(topple_list);
        giveToNeighbors(neighbors);
    }
}

std::string SandPile::toString() const {
    string s = "";
    //int c = 0;
    for (int i = 0; i < ARRAY_SIZE; i++){
        if (i == 3 || i == 6){s+="/";}
        //c = pile[i];
        s += to_string(pile[i]);
    }

    return s;
}

vector<int> SandPile::toppleList() const {
    vector<int> topple_list; // Create space to hold
    // list of indexes to topple (>3)
    for (int i = 0; i < ARRAY_SIZE; i++){
        if (this->pile[i] > 3){
            topple_list.push_back(i);
        }
    }

    return topple_list;
}

void SandPile::topple(const vector<int> topple_list) {
    //const int n = topple_list.size();
    for (int i = 0; i < topple_list.size(); i++){
        this->pile[topple_list[i]]-=4;
    }
}

vector<int> SandPile::getNeighbors(const vector<int> topple_list) const {
    vector<int> neighbors;
    //const int n = topple_list.size();
    //const int s = sqrt(ARRAY_SIZE);
    for (int i = 0; i < topple_list.size(); i++){
        /*if (i+1>=0&&i+1<9) {neighbors->push_back(i+1);}
        if (i-1>=0&&i-1<9) {neighbors->push_back(i-1);}
        if (i+s>=0&&i+s<9) {neighbors->push_back(i+s);}
        if (i-s>=0&&i-s<9) {neighbors->push_back(i-s);}
         */

        switch (topple_list[i]) {
            case 0:
                neighbors.push_back(1);
                neighbors.push_back(3);
                break;
            case 1:
                neighbors.push_back(0);
                neighbors.push_back(2);
                neighbors.push_back(4);
                break;
            case 2:
                neighbors.push_back(1);
                neighbors.push_back(5);
                break;
            case 3:
                neighbors.push_back(0);
                neighbors.push_back(4);
                neighbors.push_back(6);
                break;
            case 4:
                neighbors.push_back(1);
                neighbors.push_back(3);
                neighbors.push_back(5);
                neighbors.push_back(7);
                break;
            case 5:
                neighbors.push_back(2);
                neighbors.push_back(4);
                neighbors.push_back(8);
                break;
            case 6:
                neighbors.push_back(3);
                neighbors.push_back(7);
                break;
            case 7:
                neighbors.push_back(4);
                neighbors.push_back(6);
                neighbors.push_back(8);
                break;
            case 8:
                neighbors.push_back(5);
                neighbors.push_back(7);
                break;
        }

    }
    return neighbors;
}

void SandPile::giveToNeighbors(const vector<int> neighbors) {
    for (int i = 0; i < neighbors.size(); i++){
        this->pile[neighbors[i]]+=1;
    }
}


