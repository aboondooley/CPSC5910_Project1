//
// Created by Alie on 9/10/2020.
// for Seattle University, CPSC 5005, Fall 2020
// Contains several tests for the SandPile class and also a main function
// that runs the assignment tests.
//

#include <iostream>
#include "SandPile.h"
#include <math.h>

using namespace std;
/**
 * From Lab 1, tests the stabilization method as well as setPile and toString
 * @param test_name = a string that will print what you decide to name the test
 * @param args = a const int array that the SandPile will be made of
 */
void lab1Tests(const string test_name, const int *args){
    SandPile sand;
    sand.setPile(args);
    cout << test_name << " before stabilization: " << sand.toString();
    sand.stabilize();
    cout << " after: " << sand.toString() << endl;
}

/**
 * Tests the addPile() method as well as the constructor and toString methods
 * @param test_name = a string that prints what you want the test to be called
 * @param a = the SandPile to be added to - this sandpile will change
 * @param b = the SandPile that provides the values to add - constant
 */
void testAddPile(const string test_name, int *a, const int *b){
    SandPile sandA(a), sandB(b);
    cout << test_name << " a: " << sandA.toString() <<
    "  b: " << sandB.toString();
    sandA.addPile(sandB);
    cout << "  a + b: " << sandA.toString() << endl;
}

/**
 * Tests the no-arg constructor and the addPile() method, and isInGroup. It adds
 * the SandPile to zero and then tests whether that pile is in the abelian group
 * @param test_name = string that prints what you want the test to be called
 * @param a = a string that will be added to zero
 */
void testAddToZero(const string test_name, int *a){
    SandPile other(a);
    string result;
    if (other.isInGroup())
        result = " (the same => in group)";
    else
        result = " (different => out group)";
    cout << test_name << " + zero: " << other.toString() << result << endl;
}

/**
 * Tests the inGroup method
 * @param test_name = string that you would like to name the test
 * @param test = a SandPile to test if it's in the abelian group
 */
void testInGroup(const string test_name, SandPile &test){
    cout << "inInGroup " << test_name << " " << test.toString();
    if (test.isInGroup())
        cout << " is in group (expect yes)" << endl;
    else
        cout << " is not in group (expect not)" << endl;
}



/**
 * Tests EVERY POSSIBLE 3x3 SandPile with values 0-3
 * This function uses nested loops. At the end, it prints out how many
 * SandPiles were tested and how many were in the abelian group
 */
void testAllSandPiles(){
    SandPile test;
    int array_size = test.COLS * test.ROWS;
    int max_stable = test.MAX_STABLE;
    int inGroup = 0;
    int inTotal = 0;
    int cells[array_size];

    for (int i=0;i<=max_stable;i++){ // 1
        cells[0] = i;
        for (int j=0;j<=max_stable;j++){
            cells[1] = j;
            for (int k=0;k<=max_stable;k++){ // 3
                cells[2] = k;
                for (int l=0;l<=max_stable;l++){
                    cells[3] = l;
                    for (int m=0;m<=max_stable;m++){ // 5
                        cells[4] = m;
                        for (int n=0;n<=max_stable;n++){
                            cells[5] = n;
                            for (int o=0;o<=max_stable;o++){ // 7
                                cells[6] = o;
                                for (int p=0;p<=max_stable;p++){
                                    cells[7] = p;
                                    for (int q=0;q<=max_stable;q++){ //9
                                        cells[8] = q;
                                        test.setPile(cells);
                                        if (test.isInGroup()){
                                           inGroup++;
                                        }
                                        inTotal++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "sand piles in group: " << inGroup << endl;
    cout << "out of total " << test.ROWS << "x" << test.COLS << " sand piles: "
    << inTotal << endl;
}
/**
 * Tests the copy ctor, makes a copy using the copy ctor and then changes the
 * original and tests that the copy did not change
 * @param orig = the original SandPile to make the copy from
 * @param change = array of cells to change the original to, to test that it
 * is not a shallow copy
 */
void testCopyCtor(SandPile &orig, int *change){
    SandPile copy(orig);
    cout << "testCopyCtor: " << endl;
    cout << "Original SandPile: " << orig.toString() << " Copy SandPile: " <<
         copy.toString() << endl;
    orig.setPile(change);
    cout << "Set original to: " << orig.toString() << " print Copy: " << copy
            .toString() << " (expect different than original)" << endl;
}


/**
 * Tests the assignment operator overload for creating a new SandPile, then
 * changes the original and makes sure the other SandPile does not change
 * @param orig = the original SandPile to make the copy from
 * @param change = array of cells to change the original to, to test that it
 * is not a shallow copy
 */
void testOperatorOverload(SandPile &orig,int *change){
    SandPile other = orig;
    cout << "testOperatorOverload: " << endl;
    cout << "Original SandPile: " << orig.toString() << " Other SandPile: " <<
         other.toString() << endl;
    orig.setPile(change);
    cout << "Set original to: " << orig.toString() << " print other: " << other
            .toString() << " (expect different than original)" << endl;
}


/**
 * Main entry point for the tests.
 * Calls: lab1Tests(), testAddPile(), testAddToZero(),
 * testInGroup(), testAllPiles(), and testAllPilesRec()
 * @return 0
 */
int main() {


    // TEST ZERO WITH NO ARG CTOR
    SandPile zero;
    cout << "zero (using no-arg ctor):" << zero.toString() << endl;

    cout << endl;

    // LAB ONE TESTS
    // MINIMUM/REQUIRED TESTS
    int test1[] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    int test2[] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    int test3[] = {4, 0, 0, 0, 10, 0, 0, 0, 0};

    lab1Tests("test1", test1);
    lab1Tests("test2", test2);
    lab1Tests("test3", test3);
    cout << endl;

    // ADDITIONAL TESTS
    int test4[] = {59, 89, 4, 16, 4, 0, 3, 99, 100}; // test large numbers
    int test5[] = {3, 1, 3, 1, 0, 1, 3, 1, 3}; // test stable pile
    int test6[] = {3, -1, 5, 5, 5, 9, 0, 0, 0}; // test negative number
    int test7[] = {4, 4, 0, 0, 10, 0, 0, 0, 0};
    int test8[] = {4, 4, 4, 10, 10, 0, 22, 1, 5};
    cout << endl;

    // each element should be under 4, even though they started out large
    lab1Tests("test4", test4);
    // should be the same before and after stabilization
    lab1Tests("test5", test5);
    // should give message to user and create and print the Sandpile, but not
    // stabilize
    lab1Tests("test6", test6);
    cout << endl;

    // TESTS ADDED BY TA DOUG VIA CANVAS
    lab1Tests("test7", test7);
    lab1Tests("test8", test8);


    // PROJECT 1 TESTS
    // MINIMUM REQUIRED TESTS
    int a1[] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    int b1[] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    int a2[] = {1, 2, 0, 2, 1, 1, 0, 1, 3};
    int b2[] = {2, 1, 3, 1, 0, 1, 0, 1, 0};
    int a3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int b3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};

    testAddPile("add1", a1, b1);
    testAddPile("add2", a2, b2);
    testAddPile("add3", a3, b3);
    cout << endl;


    int all3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int all2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    testAddToZero("all 3's", all3);
    testAddToZero("all 2's", all2);

    int inGroup1[] = {3, 2, 2, 2, 1, 1, 3, 3, 3};
    int inGroup2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    SandPile iG1(inGroup1), iG2(inGroup2);
    testInGroup("test1", iG1);
    testInGroup("test2", iG2);
    cout << endl;

    testAllSandPiles();
    cout << endl;

    // ADDITIONAL TESTS

    // TESTING COPY CTOR
    int cells[] = {2, 3, 2, 1, 1, 1, 2, 3, 2}; // original values
    int change[] = {0, 0, 0, 1, 2, 1, 3, 3, 3}; // new values to set original to
    SandPile orig(cells);
    testCopyCtor(orig, change);
    cout << endl;

    // TESTING = OPERATOR OVERLOAD
    int newChange[] = {2, 1, 3, 3, 1, 2, 0, 0, 0};
    testOperatorOverload(orig, newChange);

    return 0;
}

