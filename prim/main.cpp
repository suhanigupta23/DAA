#include <iostream>
#include "prim.h"

using namespace std;

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    int mstCost = g.primMST();
    cout << "Minimum Spanning Tree cost: " << mstCost << endl;

    return 0;
}
