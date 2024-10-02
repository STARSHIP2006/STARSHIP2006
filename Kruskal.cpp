#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (vector<int, int, int> &a, vector<int, int, int> &b)
{
    return a[2]<b[2];
}
// Find the root (or representative) of the set containing i with path compression
int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);  // Path compression
    }
    return parent[i];
}

// Union by rank of two sets x and y
void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree
int kruskal(int V, vector<vector<int>>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    // Initialize union-find structures
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    int mstCost = 0;
    vector<pair<int, int>> mst;  // To store the edges in the MST

    // Iterate over the sorted edges and construct the MST
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // Check if the current edge forms a cycle
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            mst.push_back({u, v});
            mstCost += weight;
            unionSets(parent, rank, rootU, rootV);
        }
    }

    // Output the edges in the MST (optional)
    cout << "Edges in MST:\n";
    for (const auto& edge : mst) {
        cout << edge.first << " -- " << edge.second << endl;
    }

    return mstCost;
}

int main() {
    int V = 4;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},  // {vertex1, vertex2, weight}
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstCost = kruskal(V, edges);
    cout << "Total cost of MST: " << mstCost << endl;

    return 0;
}
