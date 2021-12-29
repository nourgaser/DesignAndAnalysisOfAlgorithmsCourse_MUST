#include "utils.h"
// vector<int> hungarianMethod(const vector<vector<int>> &m) {}

// print matrix with optional highlighting
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

void allPermutations(const vector<vector<int>> &m, vector<int> v, int start, int end, vector<int> &minPermutation, int &min)
{
    if (start == end)
    {
        int sum = m[0][v[0]];
        for (int i = 1; i < m.size(); i++)
        {
            sum += m[i][v[i]];
        }
        if (sum < min)
        {
            min = sum;
            minPermutation = v;
            minPermutation.push_back(sum);
        }
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(v[i], v[start]);
        allPermutations(m, v, start + 1, end, minPermutation, min);
        swap(v[i], v[start]);
    }
}

vector<int> exhaustiveSearch(const vector<vector<int>> &m)
{
    vector<int> res;
    for (int i = 0; i < m.size(); i++)
        res.push_back(i);
    int min = INT16_MAX;
    allPermutations(m, res, 0, m.size() - 1, res, min);
    return res;
}