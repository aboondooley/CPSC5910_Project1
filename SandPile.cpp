//
// Created by Alie on 9/10/2020.
//

#include <iostream>
#include <vector>
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

}

std::string SandPile::toString() const {
    return std::string();
}

vector<int>* SandPile::toppleList() const {
    vector<int>* topple_list = new vector<int>; // Create space to hold
    // list of indexes to topple (>3)
    for (int i = 0; i < ARRAY_SIZE; i++){
        if (this->pile[i] > 3){
            topple_list->push_back(i);
        }
    }

    return topple_list;
}

void SandPile::topple(const vector<int> topple_list) {
    const int n = topple_list.size();
    int t = 0;
    for (int i = 0; i < n; i++){
        t = topple_list[i];
        this->pile[t]-=4;
    }
}

vector<int>* SandPile::getNeighbors(const vector<int> topple_list) const {

    return nullptr;
}

void SandPile::giveToNeighbors(const vector<int> neighbors) {

}


