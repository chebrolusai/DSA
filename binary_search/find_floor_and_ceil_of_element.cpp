#include <iostream>
#include <vector>

using namespace std;

int find_floor(vector<int> &numbers, int target)
{
    int result = -1;

    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (numbers[mid] == target)
        {
            return numbers[mid];
        }

        if (numbers[mid] < target)
        {
            result = numbers[mid];
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return result;
}

int find_ceil(vector<int> &numbers, int target)
{
    int result = -1;

    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (numbers[mid] == target)
        {
            return numbers[mid];
        }

        if (numbers[mid] > target)
        {
            result = numbers[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return result;
}

vector<int> find_floor_and_ceil_of_element(vector<int> &numbers, int target)
{
    vector<int> result;

    result.push_back(find_floor(numbers, target));
    result.push_back(find_ceil(numbers, target));

    return result;
}

int main()
{
    int temp[] = {
        2,
        5,
        6,
        8,
        11,
        12,
        15,
        18,
    };
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));

    vector<int> result = find_floor_and_ceil_of_element(numbers, 11);

    cout << "floor: " << result[0] << endl
         << "ceil: " << result[1];
}
