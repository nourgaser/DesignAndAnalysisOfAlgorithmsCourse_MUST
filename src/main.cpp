#include <iostream>
#include "utils.h"
#include "hungarian.h"

int main()
{
    srand(time(NULL)); // seed random to current time

    int m;
    cout << "Enter m, the size of the cost matrix (m x m): ";
    cin >> m;

    // initialize an (mxm) cost matrix with random costs (1-20)
    vector<vector<int>> costMatrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> t;
        for (int j = 0; j < m; j++)
        {
            t.push_back((rand() % 20) + 1);
        }
        costMatrix.push_back(t);
    }

    printMatrix(costMatrix);
    time_t before;
    vector<int> solution;
    time_t after;

    //========Hungarian Method===========
    {
        HungarianAlgorithm HungAlgo;
        cout << "Hungarian method: starting timer\n";
        before = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        double cost = HungAlgo.Solve(costMatrix, solution);
        after = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        cout << "=======Optimal Solution========\n";
        for (int i = 0; i < m; i++)
            cout << i << " ";
        cout << "Total\n";
        solution.push_back(cost);
        printVector(solution);
        printMatrix(costMatrix, solution);
        cout << "Done in " << after - before << "ms\n";
    }

    //==============Brute Force (Exhaustive Search)============
    {
        if (m > 10)
        {
            cout << "Brute force method only works well for values of m <= 10" << endl;
            if (m > 12)
                return 0;
        }
        cout << "Brute force: starting timer\n";
        before = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        solution = exhaustiveSearch(costMatrix);
        after = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        cout << "=======Optimal Solution========\n";
        for (int i = 0; i < m; i++)
            cout << i << " ";
        cout << "Total\n";
        printVector(solution);
        printMatrix(costMatrix, solution);
        cout << "Done in " << after - before << "ms\n";
    }

    return 0;
}