#include <iostream>
#include "SandPile.h"

using namespace std;

int main() {


    int test1[] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    int test2[] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    int test3[] = {4, 0, 0, 0, 10, 0, 0, 0, 0};


    // MINIMUM/REQUIRED TESTS
    SandPile pile1, pile2, pile3;

    pile1.setPile(test1);
    cout << "test1 before stabilization: " << pile1.toString();
    pile1.stabilize();
    cout << " after: " << pile1.toString() << endl;

    pile2.setPile(test2);
    cout << "test2 before stabilization: " << pile2.toString();
    pile2.stabilize();
    cout << " after: " << pile2.toString() << endl;

    pile3.setPile(test3);
    cout << "test3 before stabilization: " << pile3.toString();
    pile3.stabilize();
    cout << " after: " << pile3.toString() << endl;


    // ADDITIONAL TESTS
    int test4[] = {59, 89, 4, 16, 4, 0, 3, 99, 100}; // test large numbers
    int test5[] = {3, 1, 3, 1, 0, 1, 3, 1, 3}; // test stable pile
    int test6[] = {3, -1, 5, 5, 5, 9, 0, 0, 0}; // test negative number


    SandPile pile4, pile5, pile6;

    // each element should be under 4, even though they started out large
    pile4.setPile(test4);
    cout << "test4 before stabilization: " << pile4.toString();
    pile4.stabilize();
    cout << " after: " << pile4.toString() << endl;

    // should be the same before and after stabilization
    pile5.setPile(test5);
    cout << "test5 before stabilization: " << pile5.toString();
    pile5.stabilize();
    cout << " after: " << pile5.toString() << endl;

    // should give message to user and create and print the Sandpile, but not
    // stabilize
    pile6.setPile(test6);
    cout << "test6 before stabilization: " << pile6.toString();
    pile6.stabilize();
    cout << " after: " << pile6.toString() << endl;


    return 0;
}
