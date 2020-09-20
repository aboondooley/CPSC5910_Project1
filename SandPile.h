//
// Created by Alie on 9/10/2020.
//

#ifndef PROJECT1_SANDPILES_SANDPILE_H
#define PROJECT1_SANDPILES_SANDPILE_H

# include <vector>



class SandPile {

public:
    static const int ROWS = 3; // number of rows
    static const int COLS = 3; // number of columns -
    // allows for non-square configurations
    static const int MAX_STABLE = 3; // user can control how many pieces of
    // sand are stable

    /**
     * Set the values of each cell in this sand pile.
     * @param cells 1st row elements, then 2nd, etc., all in one flat array
     */
    void setPile(const int *cells); // copies the integers into a new object
    SandPile(); // constructor with no arguments gives a zero
    SandPile(const int *cells);
    /**
     * Is this sand pile stable or will it topple?
     * I.e., if there are any cells over 3 (SandPile::MAX_STABLE) then it will
     * topple.
     *
     * @return true if it won't topple, false if it will
     */
    bool isStable() const;


    /**
     * Topple this sand pile until it is stable (according to toppling rules).
     * Each unstable cell spills one grain of sand in each direction.
     * If they fall off the edge that's ok.
     * No return and no arguments needed.
     */
    void stabilize(); // not constant bc we need to update the Sandpile if
    // unstable

    /**
     * Get a string suitable for printing out.
     * @return a 3-line string with the contents of this sand pile
     */
    std::string toString() const;

    /**
    * Add in the cells of another sand pile into this one and restabilize.
    * I.e., implements: this = this + other, and then stabilize.
    * @param other    addend sand pile
    */
    void addPile(const SandPile &other);


private:
    static const int ARRAY_SIZE = ROWS * COLS;
    int *pile;
    bool allPositive = true; // keeps track of whether there was a negative
    // value in the Sandpile

    // 4 helper functions for stabilize()
    // Creates a vector of indexes that need to be toppled (> 3)
    std::vector<int> toppleList() const;

    // Takes 4 grains of sand from each index in the topple_list
    void topple(const std::vector<int> topple_list);

    // Creates a vector of indexes that neighbor the indexes in topple_list
    void giveToNeighbors(const std::vector<int> neighbors);

    // Adds 1 grain of sand to each index in the neighbors vector
    std::vector<int> getNeighbors(const std::vector<int> topple_list) const;

};


#endif //PROJECT1_SANDPILES_SANDPILE_H

// Sources
// Geeks for Geeks how to return an int array in C++:
// https://www.geeksforgeeks.org/return-local-array-c-function/