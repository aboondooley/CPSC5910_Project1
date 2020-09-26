Here is my recursion attempt. It fails with exit code -1073741571 (0xC00000FD) at around 16,000-18,000 recursive calls. I am not sure how to get to 262144 recursive calls!

But here's what I did:
 
This is a helper function (not the same as yours) that carries over the value if it goes over 3 (max_stable)
/**
* Helper function that checks to make sure that there are no fours in the
* array. If a four (max_stable+1) is found, the cell is set back to zero and the cell in
* front of it (if there is an cell in front) is incremented. This way, the
* recursive function only ever needs to increment the array at index [0].
* This function takes care of the rest!
* @param cells = an array that holds the updated pile values
* @param max_stable = a constant, no cells should be greater than this value
* @param array_size = a constant, used to loop through all of the cells
* @return cells = returns the updated cells, with the fours 'carried over'
*/
int *recHelper(int *cells, const int max_stable, const int array_size){
   for (int i = 0; i < array_size; i++){
       if (cells[i] > max_stable){
           cells[i] = 0;
           if (i < (array_size - 1))
               cells[i+1] += 1;
       }
   }
   return cells;
}

And here is the recursive testing function:


/**
* Recursive function that tests all of the possible 3X3 (although, could be
* any size) SandPiles to see if there are in the abelian group. It keeps
* track of how many possible SandPiles there are (set M) and how many are in
* the abelian group (set S).
* @pre an array of all zeros must be passed in to start and inTotal and
* inGroup must be set to zero as well
* @post nothing is returned, but inTotal and inGroup will be updated for the
* caller to use
* @param cells = an array of cells to create a SandPile with and test
* @param inTotal = a counter that keeps track of the total number of
* SandPiles that have been tested
* @param inGroup = another counter that keeps track of the number of
* SandPiles in the abelian group
* @param max_stable = the max number of grains in a cell before it has to
* topple (const)
* @param array_size = the number of cells in the array (const)
*/

void testAllSandPilesRec(int *cells, int &inTotal, int &inGroup, const int
max_stable, const int array_size){
if (inTotal == pow((max_stable+1), array_size)){
return;
}
SandPile sand(cells);

if (sand.isInGroup()){
inGroup++;
}
inTotal++;

cells[0]++;
cells = recHelper(cells, max_stable, array_size);
testAllSandPilesRec(cells, inTotal, inGroup, max_stable, array_size);

}

in p1_test.cpp: 
int main() {
// TEST RECURSIVE IMPLEMENTATION OF TESTING ALL SANDPILES
int *inGroup = new int;
int *inTotal = new int;
*inGroup = 0; *inTotal = 0;
int array_size = 9;
int max_stable = 3;
int values[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

testAllSandPilesRec(values, *inTotal, *inGroup, max_stable, array_size);

cout << "sand piles in group: " << *inGroup << endl;
cout << "out of total 3x3 sand piles: " << *inTotal << endl;

delete inGroup; // need to delete bc new keyword used
delete inTotal;
return 0;
}



 


