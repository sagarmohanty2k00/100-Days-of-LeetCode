#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    set<int> row, col;
    cout << "LOG: Entered into the function" << endl;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    
    cout << "LOG: first loop over" << endl;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (row.find(i) != row.end() or col.find(j) != col.end())
            {
                matrix[i][j] = 0;
            }
        }
    }

    cout << "LOG: second loop over" << endl;

}

int main()
{
    // code here
    vector<vector<int>> matrix;
    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        matrix.push_back({});
        int ele;
        for (int j = 0; j < size; j++)
        {
            cin >> ele;
            matrix[i].push_back(ele);
        }
    }

    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}