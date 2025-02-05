#include <iostream>

using namespace std;

class unionFind {
private:

    int* id;  // Stores the parent/root of each element
    int* sz;  // Stores the size of each connected component
    int size; // Number of elements in the set

public:

    // Constructor
    unionFind(int n) : size(n) {
        id = new int[n]; // Allocate memory for parent array
        sz = new int[n]; // Allocate memory for size array
        for (int i = 0; i < n; i++) {
            id[i] = i;  // Each element is its own parent (self-loop)
            sz[i] = 1;   // Each tree starts with a single node
        }
    }

    // Destructor
    ~unionFind() {
        delete[] id;
        delete[] sz;
    }

    // Find function with path compression to flatten the tree
    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]]; // Path compression: makes future operations faster
            p = id[p];         // Move up the tree
        }
        return p;
    }

    // Union function: Connects two elements if they are not already connected
    bool unionSets(int p, int q) {
        int rootP = find(p); // Find the root of element p
        int rootQ = find(q); // Find the root of element q
        if (rootP == rootQ) return false; // Already connected, no need to merge

        // Merge smaller tree into the larger tree for better balance
        if (sz[rootP] < sz[rootQ]) {
            id[rootP] = rootQ;
            sz[rootQ] += sz[rootP]; // Update size of the new root
        } else {
            id[rootQ] = rootP;
            sz[rootP] += sz[rootQ]; // Update size of the new root
        }
        return true; // Successfully merged the two components
    }
};

// Function that generates random pairs and performs union-find operations
int randomunionFind(int n) {
    unionFind uf(n);
    int edges = 0, unions = 0;

    // Keep generating random connections until we have n-1 successful unions
    while (unions < n - 1) {
        int p = rand() % n; // Randomly pick first node
        int q = rand() % n; // Randomly pick second node
        edges++; // Count each attempted connection

        if (uf.unionSets(p, q)) {
            unions++; // Only count successful unions
        }
    }
    return edges; // Return total edges (attempted connections)
}

int main() {
    srand(time(nullptr)); // Seed the random number generator
    
    // Run the experiment for different values of N (10^3, 10^4, 10^5, 10^6)
    for (int exp = 3; exp <= 6; exp++) {
        int n = 1;
        for (int i = 0; i < exp; i++) n *= 10; 

        cout << "Running for N = " << n << endl;
        int edges = randomunionFind(n); // Perform random unions
        cout << "N = " << n << ", Total edges generated: " << edges << endl;
    }
    
    return 0;
}
