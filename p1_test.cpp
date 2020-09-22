// TODO include file header

#include <iostream>
#include "SandPile.h"

using namespace std;

void lab1Tests(string test_name, const int *args){
    SandPile sand;
    sand.setPile(args);
    cout << test_name << " before stabilization: " << sand.toString();
    sand.stabilize();
    cout << " after: " << sand.toString() << endl;
}

void testAddPile(string test_name, int *a, const int *b){
    SandPile sandA(a), sandB(b);
    cout << test_name << " a: " << sandA.toString() <<
    "  b: " << sandB.toString();
    sandA.addPile(sandB);
    cout << "  a + b: " << sandA.toString() << endl;


}
/*
void testAllSandPiles(){
    SandPile test;
    int array_size = test.COLS * test.ROWS;
    int max_stable = test.MAX_STABLE;
    int count = 0;
    int cells[array_size];

    for (int i=0;i<array_size;i++){ // 1
        for (int i=0;i<array_size;i++){
            for (int i=0;i<array_size;i++){ // 3
                for (int i=0;i<array_size;i++){
                    for (int i=0;i<array_size;i++){ // 5
                        for (int i=0;i<array_size;i++){
                            for (int i=0;i<array_size;i++){ // 7
                                for (int i=0;i<array_size;i++){
                                    for (int i=0;i<array_size;i++){ //9

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
*/

int main() {

    // LAB ONE TESTS
    // MINIMUM/REQUIRED TESTS
    int test1[] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    int test2[] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    int test3[] = {4, 0, 0, 0, 10, 0, 0, 0, 0};

    lab1Tests("test1", test1);
    lab1Tests("test2", test2);
    lab1Tests("test3", test3);

    // ADDITIONAL TESTS
    int test4[] = {59, 89, 4, 16, 4, 0, 3, 99, 100}; // test large numbers
    int test5[] = {3, 1, 3, 1, 0, 1, 3, 1, 3}; // test stable pile
    int test6[] = {3, -1, 5, 5, 5, 9, 0, 0, 0}; // test negative number
    int test7[] = {4, 4, 0, 0, 10, 0, 0, 0, 0};
    int test8[] = {4, 4, 4, 10, 10, 0, 22, 1, 5};

    // each element should be under 4, even though they started out large
    lab1Tests("test4", test4);
    // should be the same before and after stabilization
    lab1Tests("test5", test5);
    // should give message to user and create and print the Sandpile, but not
    // stabilize
    lab1Tests("test6", test6);

    lab1Tests("test7", test7);
    lab1Tests("test8", test8);


    cout << "1 % 3 = " << 1%3 << ", 16 % 8 = " << 16%8 << endl;


    // PROJECT 1 TESTS
    // MINIMUM REQUIRED TESTS
    int a1[] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    int b1[] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    int a2[] = {1, 2, 0, 2, 1, 1, 0, 1, 3};
    int b2[] = {1, 2, 0, 2, 1, 1, 0, 1, 3};
    int a3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int b3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};

    testAddPile("add1", a1, b1);
    testAddPile("add2", a2, b2);
    testAddPile("add3", a3, b3);


    int all3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    SandPile all_three(all3);
    cout << "all 3's + zero: " << all_three.toString() << " (the same => ";
    if (all_three.isInGroup()){
       cout << "in group)" << endl;
    } else {
        cout << "out group)" << endl;
    }


    return 0;
}

