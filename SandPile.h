//
// Created by Alie on 9/10/2020.
//

#ifndef PROJECT1_SANDPILES_SANDPILE_H
#define PROJECT1_SANDPILES_SANDPILE_H

const int ARRAY_SIZE = 9;
class SandPile {

public:

    /**
     * Set the values of each cell in this sand pile.
     * @param cells 1st row elements, then 2nd, etc., all in one flat array
     */
    void setPile(const int *cells); // the array of ints given by the caller is constant bc we will actually copy
    // the integers into our own object

    /**
     * Is this sand pile stable or will it topple?
     * I.e., if there are any cells over 3 (SandPile::MAX_STABLE) then it will topple.
     *
     * @return true if it won't topple, false if it will
     */
    bool isStable() const;

    /**
     * Topple this sand pile until it is stable (according to toppling rules).
     * Each unstable cell spills one grain of sand in each direction. If they fall
     * off the edge that's ok.
     */
     //TODO need to update the header for stabilize()
    void stabilize(); //not constant bc we need to change the values in our object
    // are parameters needed? -> yes it needs to result of isStable I believe

    /**
     * Get a string suitable for printing out.
     * @return a 3-line string with the contents of this sand pile
     */
    std::string toString() const;


private:
    int pile[ARRAY_SIZE];
    std::vector<int>* toppleList() const;
    void topple(const std::vector<int>* topple_list);
    void giveToNeighbors(const std::vector<int>* neighbors);
    std::vector<int>* getNeighbors(const std::vector<int>* topple_list) const;

};


#endif //PROJECT1_SANDPILES_SANDPILE_H

// Sources
// Geeks for Geeks how to return an int array in C++: https://www.geeksforgeeks.org/return-local-array-c-function/