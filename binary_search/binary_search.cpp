#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &numbers, int target)
{
    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (numbers[mid] == target)
        {
            return mid;
        }

        else if (numbers[mid] > target)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int temp[] = {11, 23, 35, 41, 48, 64, 67};
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));
    int result = binary_search(numbers, 35);

    cout << "Found at index: " << result;
}
