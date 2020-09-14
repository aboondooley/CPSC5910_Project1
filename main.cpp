#include <iostream>
#include "SandPile.h"
using namespace std;

int main() {


    int test1[] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    int test2[] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    int test3[] = {4, 0, 0, 0, 10, 0, 0, 0, 0};

    SandPile pile1, pile2, pile3;

    pile1.setPile(test1);
    pile1.stabilize();
    cout << pile1.toString() << endl;

    pile2.setPile(test2);
    pile2.stabilize();
    cout << pile2.toString() << endl;

    pile3.setPile(test3);
    pile3.stabilize();
    cout << pile3.toString() << endl;

    return 0;
}
 /*
  * TESTS
test1 before stabilization: 0 0 0 / 0 4 0 / 0 0 0 after: 0 1 0 / 1 0 1 / 0 1 0
test2 before stabilization: 4 0 0 / 0 4 0 / 0 0 0 after: 0 2 0 / 2 0 1 / 0 1 0
test3 before stabilization: 4 0 0 / 0 10 0 / 0 0 0 after: 0 3 0 / 3 2 2 / 0 2 0
*/