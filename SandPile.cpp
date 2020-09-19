//TODO create documentation for the sandpile class as a whole

//
// Created by Alie on 9/10/2020.
// I added green comment chunks for the private helper functions I created.
//

#include <iostream>
#include <vector>
#include "SandPile.h"

using namespace std;

// Creates a Sandpile with the values given by the user
// If the value contain a negative number, a warning is given to the user and
// the Sandpile is created but will refuse to stabilize.
// This is my interpretation of the advice to do nothing if there is a negative
// value.
void SandPile::setPile(const int *cells) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        this->pile[i] = cells[i];
        if (cells[i] < 0) {
            allPositive = false; // adds a flag that there is a negative value
        }
    }

    if (!allPositive) {
        // gives a  warning to the user that there is a negative value
        cout << "Oh no, there is a negative value! \nThe Sandpile will refuse"
                " to stabilize.\nPlease try again." << endl;
    }
}

// Checks to see if the Sandpile is stable (no cells > MAX_STABLE)
bool SandPile::isStable() const {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (this->pile[i] > MAX_STABLE) {
            return false;
        }
    }
    return true;
}

/*
stabilize() uses 4 private helper functions to complete it's task
1. toppleList()
2. topple()
3. getNeighbors()
4. giveToNeighbors()

First, stabilize() will check to see if the pile is already stable
using isStable(), and if not, uses the four helper functions.
However, if there is a negative number in the Sandpile, it will refuse to
 stabilize.
 */
void SandPile::stabilize() {
    vector<int> topple_list;
    vector<int> neighbors;
    if (allPositive){ // refuses to stabilize if there is a negative number
        while (!isStable()) {
            topple_list = toppleList(); //indexes of those to topple
            topple(topple_list);
            neighbors = getNeighbors(topple_list);
            giveToNeighbors(neighbors);
        }
    }
}


//Creates a visual representation of the Sandpile for printing
std::string SandPile::toString() const {
    string s = "";
    if (ARRAY_SIZE>0){
        s += to_string(pile[0]);
        for (int i = 1; i < ARRAY_SIZE; i++) {
            s += " ";
            if (i % ROWS == 0) { s += "/ "; }
            s += to_string(pile[i]);
        }

    }


    return s;
}

/**
 * First helper function for stabilize()
 * Goes through each element of the Sandpile and creates a list (stored in a
 * vector) that need to be "toppled" (>MAX_STABLE) and passes the list back
 * @return a vector of indexes to topple
 */
vector<int> SandPile::toppleList() const {
    vector<int> topple_list; // Create space to hold
    // list of indexes to topple (>MAX_STABLE)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (this->pile[i] > MAX_STABLE) {
            topple_list.push_back(i);
        }
    }

    return topple_list;
}

/**
Second helper function for stabilize()
A vector of elements to topple is passed in
for each element in the vector, 4 is subtracted from that element
 @arg a vector of indexes to topple
 */
void SandPile::topple(const vector<int> topple_list) {
    for (int i = 0; i < topple_list.size(); i++) {
        this->pile[topple_list[i]] -= 4;
    }
}

/**
Third helper function for stabilize()
A vector of elements that have been toppled is passed in
All the neighbors for each element that was toppled are added to the list
of neighbors and passed back
A neighbor can be added multiple times, if it neighbors multiple toppled
cells
 @arg vector of indexes that have toppled
 @return vector of indexes of neighbors of those toppled
*/
vector<int> SandPile::getNeighbors(const vector<int> topple_list) const {
    vector<int> neighbors;
    for (int i = 0; i < topple_list.size(); i++) {

        switch (topple_list[i]) {
            // hardcoded values which is fine for a 9x9 Sandpile
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

/**
Fourth helper function for stabilize()
A vector of neighbors is passed in. One peice of sand is subtracted from
each neighbor.
Again, a neighbor can appear multiple times, as it can neighbor multiple
toppled cells
 @arg vector of indexes that contain neighbors of topples cells
 */
void SandPile::giveToNeighbors(const vector<int> neighbors) {
    for (int i = 0; i < neighbors.size(); i++) {
        this->pile[neighbors[i]] += 1;
    }
}


