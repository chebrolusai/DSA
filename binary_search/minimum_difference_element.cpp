#include <iostream>
#include <vector>

using namespace std;

int mininum_difference_number(vector<int> &numbers, int target)
{

    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (numbers[mid] == target)
        {
            return 0;
        }

        if (numbers[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    int floor = numbers[end];
    int ceil = numbers[start];

    return min(abs(target - floor), abs(target - ceil));
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

    int result = mininum_difference_number(numbers, 10);

    cout << "Minimum difference: " << result;
}
