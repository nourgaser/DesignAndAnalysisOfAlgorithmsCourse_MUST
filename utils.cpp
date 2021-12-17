#include "utils.h"
// vector<int> hungarianMethod(const vector<vector<int>> &m) {}

//print matrix with optional highlighting
void printMatrix(const vector<vector<int>> &costMatrix, const vector<int> &highlightedIndices)
{
    for (int i = 0; i < costMatrix.size(); i++)
        cout << "=======";
    cout << "\n";
    for (int i = 0; i < costMatrix.size(); i++)
    {
        for (int j = 0; j < costMatrix.size(); j++)
        {
            cout << ((highlightedIndices[i] == j) ? "*" : "") << costMatrix[i][j] << "\t";
        }
        cout << "\n"
             << ((i == costMatrix.size() - 1) ? "" : "\n");
    }
    for (int i = 0; i < costMatrix.size(); i++)
        cout << "=======";
    cout << "\n";
}
void printMatrix(const vector<vector<int>> &costMatrix)
{
    for (int i = 0; i < costMatrix.size(); i++)
        cout << "=======";
    cout << "\n";
    for (int i = 0; i < costMatrix.size(); i++)
    {
        for (int j = 0; j < costMatrix.size(); j++)
        {
            cout << costMatrix[i][j] << "\t";
        }
        cout << "\n"
             << ((i == costMatrix.size() - 1) ? "" : "\n");
    }
    for (int i = 0; i < costMatrix.size(); i++)
        cout << "=======";
    cout << "\n";
}

void printVector(const vector<int> &v)
{
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void allPermutations(vector<int> v, int start, int end, vector<vector<int>> &res)
{
    if (start == end)
    {
        res.push_back(v);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(v[i], v[start]);
        allPermutations(v, start + 1, end, res);
        swap(v[i], v[start]);
    }
}

vector<int> exhaustiveSearch(const vector<vector<int>> &m)
{
    vector<vector<int>> permutations;
    vector<int> indices;
    for (int i = 0; i < m.size(); i++)
        indices.push_back(i);

    allPermutations(indices, 0, indices.size() - 1, permutations);

    vector<int> res(m.size());
    res.push_back(INT16_MAX);
    for (auto &&p : permutations)
    {
        int sum = 0;
        for (int i = 0; i < m.size(); i++)
            sum += m[i][p[i]];
        p.push_back(sum);
        if (sum < res[m.size()])
            res = p;
    }

    // if (m.size() < 7)
    // {
    //     cout << "==========All Solutions=============\n";
    //     for (auto &&p : permutations)
    //     {
    //         printVector(p);
    //     }
    // }

    return res;
}