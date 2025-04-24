#include "header.h"
#include <iostream>
#include <vector>
#include <limits>

TravelingSalesman::TravelingSalesman(int n, std::vector<std::vector<int>>& dist)
    : numCities(n), distance(dist) {
    // Initialize the dp table with -1 (indicating not visited)
    dp.resize(1 << n, std::vector<int>(n, -1));
}

int TravelingSalesman::solve() {
    // Start from city 0 and have visited no other cities
    return tspRecursive(1, 0);
}

int TravelingSalesman::tspRecursive(int mask, int pos) {
    // If all cities have been visited, return the distance to the starting city
    if (mask == (1 << numCities) - 1) {
        return distance[pos][0];
    }

    // Check if the result is already computed for this state
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = std::numeric_limits<int>::max();

    // Try all the cities that have not been visited yet
    for (int city = 0; city < numCities; ++city) {
        if ((mask & (1 << city)) == 0) {
            // Recurse by visiting the city
            int newAns = distance[pos][city] + tspRecursive(mask | (1 << city), city);
            ans = std::min(ans, newAns);
        }
    }

    // Memorize the result for this state
    dp[mask][pos] = ans;
    return ans;
}

