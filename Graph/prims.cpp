#include <iostream>
using namespace std;

// Function to implement Prim's algorithm
void prims(int n, int cost[5][5]) {
    int i, j, u, v, mincost = 0, visited[5], ne = 1;
    int min = 999; // Initialize min to a large value (infinity)

    // Mark all nodes as unvisited initially
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "The edges considered for MST:" << endl;

    // Start from the first node
    visited[0] = 1;

    // Loop until the number of edges included in MST is less than (n-1)
    while (ne < n) {
        // Reset min to infinity for the current iteration
        min = 999;

        // Find the smallest edge that connects the visited set to the unvisited set
        for (i = 0; i < n; i++) {
            if (visited[i]) { // Only consider nodes that are already in the MST
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        // Update min and the edge indices if a smaller edge is found
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Include the smallest edge found in the MST
        if (!visited[v]) {
            cout << ne << " Edge: " << u << " - " << v << " = " << min << endl;
            mincost += min;
            visited[v] = 1; // Mark the newly included node as visited
            ne++; // Increment the edge count
        }

        // Mark the selected edge as used by setting its cost to infinity
        cost[u][v] = cost[v][u] = 999;
    }

    cout << "Cost of constructing MST is: " << mincost << endl;
}

int main() {
    int i, j, n, cost[5][5];

    // Read the number of nodes
    cout << "Read number of nodes: ";
    cin >> n;

    // Read the cost adjacency matrix
    cout << "Read cost matrix: " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> cost[i][j];
            // Treat zero cost (no edge) as infinity
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    // Call the Prim's algorithm function
    prims(n, cost);

    return 0;
}
