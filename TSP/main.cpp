#include <iostream>
#include "header.h"

int main() {
    // Define the distance matrix for the cities
    // For simplicity, let's assume there are 4 cities with the following distances between them
    std::vector<std::vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Create an instance of TravelingSalesman
    TravelingSalesman tsp(dist.size(), dist);

    // Solve the TSP problem and print the result
    int result = tsp.solve();
    std::cout << "The minimum cost of the TSP tour is: " << result << std::endl;

    return 0;
}

