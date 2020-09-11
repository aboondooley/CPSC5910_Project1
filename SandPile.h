//
// Created by Alie on 9/10/2020.
//

#ifndef PROJECT1_SANDPILES_SANDPILE_H
#define PROJECT1_SANDPILES_SANDPILE_H

const int ARRAY_SIZE = 9;
class SandPile {

public:

    void setPile(const int *cells); // the array of ints given by the caller is constant bc we will actually copy
    // the integers into our own object

    bool isStable() const;

    void stabilize(); //not constant bc we need to change the values in our object
    // are parameters needed? -> yes it needs to result of isStable I believe

    std::string toString() const;


private:
    int pile[ARRAY_SIZE];
    int* toppleList() const;
    void topple(const int* topple_list);
    void giveToNeighbors(const int* neighbors);
    int* getNeighbors(const int* toppleList) const;

};


#endif //PROJECT1_SANDPILES_SANDPILE_H

// Sources
// Geeks for Geeks how to return an int array in C++: https://www.geeksforgeeks.org/return-local-array-c-function/