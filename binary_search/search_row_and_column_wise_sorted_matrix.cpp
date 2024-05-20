#include <iostream>
#include <vector>

using namespace std;

bool search_in_row_and_column_sorted_matrix(vector<vector<int>> &numbers, int target)
{

    int i = 0;
    int j = numbers[0].size() - 1;

    while (i >= 0 && i < numbers.size() && j >= 0 && j < numbers[0].size())
    {
        if (numbers[i][j] == target)
        {

            cout << "i: " << i << " " << "j: " << j;
            return true;
        }

        if (numbers[i][j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> vect{
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    bool present = search_in_row_and_column_sorted_matrix(vect, 19);

    if (!present)
    {
        cout << "Not found";
    }
}
