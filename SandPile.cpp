//
// Created by Alie on 9/10/2020.
//

#include <iostream>
#include "SandPile.h"

void SandPile::setPile(const int *cells) {
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
    return std::__cxx11::string();
}

int *SandPile::toppleList() const {
    return nullptr;
}

void SandPile::topple(const int *topple_list) {

}

void SandPile::giveToNeighbors(const int *neighbors) {

}

int *SandPile::getNeighbors(const int *toppleList) const {
    return nullptr;
}
