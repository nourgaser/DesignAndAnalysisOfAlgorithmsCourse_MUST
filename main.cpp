#include <iostream>
#include "utils.h"

int main()
{
    srand(time(NULL)); //seed random to current time

    int m;
    cout << "Enter m, the size of the cost matrix (m x m): ";
    cin >> m;

    //initialize an (mxm) cost matrix with random costs (1-10)
    vector<vector<int>> costMatrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> t;
        for (int j = 0; j < m; j++)
        {
            t.push_back((rand() % 10) + 1);
        }
        costMatrix.push_back(t);
    }

    printMatrix(costMatrix);

    cout << "Starting timer\n";
    time_t before = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    vector<int> solution = exhaustiveSearch(costMatrix);
    time_t after = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    cout << "=======Optimal Solution========\n";
    for (int i = 0; i < m; i++)
        cout << i << " ";
    cout << "Total\n";
    printVector(solution);
    printMatrix(costMatrix, solution);
    cout << "Done in " << after - before << "ms\n";

    return 0;
}