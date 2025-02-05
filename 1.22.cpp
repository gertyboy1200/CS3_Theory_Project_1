#include <iostream>
#include <random>

#define N 10000

using namespace std;

int main()
{
    int id[N], sz[N], ht[N];
    int i, j, p, q, r;
    r = 0;
    int* arr1 = new int[N];
    int* arr2 = new int[N];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, N - 1);

    //initialize arrays
    //initial height of each tree is 0
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
        ht[i] = 0;
    }

    int powOfTen = 1;

    for(int exponent = 0; exponent <=6; exponent++){
        int powOfTen = 1;
        for(int i = 0; i < exponent; i++){
            powOfTen *= 10;
        }
            cout << powOfTen;
            cout << endl;

        //read inout pairs
        for(i = 0; i < powOfTen; i++)
        {
            cout << "test2";
            for (int i = 0; i < N; i++)
            {
                arr1[i] = dist(gen);
                arr2[i] = dist(gen);
            }

            //Program 1.4
            for (i = p; i != id[i]; i = id[i])
                id[i] = id[id[i]];
            for (j = q; j != id[j]; j = id[j])
                id[j] = id[id[j]];

            if (i == j)
                continue;
                cout << "test3";
            //weighted union Program 1.3 (with exception of ht[])
            if (sz[i] < sz[j])
            {
                id[i] = j;
                sz[j] += sz[i];
                if (ht[i] + 1 > ht[j])
                    ht[j] = ht[i] + 1;
            }

            else
            {
                id[j] = i;
                sz[i] += sz[j];
                if (ht[j] + 1 > ht[i])
                    ht[i] = ht[j] + 1;
            }

            cout << " " << p << " " << q << endl;
            //for testing purposes
            // std::cout << "The height of the tree is: " << ht[i] << std::endl;
            // std::cout << "The size of the tree is: " << sz[i] << std::endl;
        }
    }

    cout << "The height of the tree is: " << ht[i] << std::endl;
    cout << "The size of the tree is: " << sz[i] << std::endl;

    return 0;
}