#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <limits>

// Class to represent a solution to the TSP problem
class TravelingSalesman {
public:
    // Constructor
    TravelingSalesman(int n, std::vector<std::vector<int>>& dist);

    // Function to solve the TSP problem
    int solve();

private:
    // Helper function to calculate the minimum cost path recursively
    int tspRecursive(int mask, int pos);

    // Number of cities
    int numCities;

    // Distance matrix
    std::vector<std::vector<int>> distance;

    // Memoization table
    std::vector<std::vector<int>> dp;
};

#endif // HEADER_H

