#include <iostream>
#include <random>

using namespace std;

void findUnions(int N){
    int* id = new int[N];
    int* sz = new int[N];
    int i, j, p, q;
    int numOfUnions = 0;
    int edgeCount = 0;

    for (i = 0; i < N; i++){
        id[i] = i;
        sz[i] = 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, N - 1);

    while (numOfUnions != N - 1){
        p = dist(gen);
        q = dist(gen);
        edgeCount++;  // Increment edge counter for every generated pair

        // Path compression
        for (i = p; i != id[i]; i = id[i]){
            id[i] = id[id[i]];
        }
        for (j = q; j != id[j]; j = id[j]){
            id[j] = id[id[j]];
        }

        if (i == j)
            continue;

        // Weighted union
        if (sz[i] < sz[j]){
            id[i] = j;
            sz[j] += sz[i];
        } else{
            id[j] = i;
            sz[i] += sz[j];
        }

        numOfUnions++;
    }

    cout << "Done with N=" << N << endl;
    cout << "Total edges processed: " << edgeCount << endl;
    cout << "number of unions: " << numOfUnions << endl;

    delete[] id;
    delete[] sz;
}

int main() {
    int N3 = 1000;
    int N4 = 10000;
    int N5 = 100000;
    int N6 = 100000;

    findUnions(N3);
    findUnions(N4);
    findUnions(N5);
    findUnions(N6);

    return 0;
}









