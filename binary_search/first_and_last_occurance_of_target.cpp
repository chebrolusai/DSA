#include <iostream>
#include <vector>

using namespace std;

int search_for_first_or_last_occurance(vector<int> &numbers, int target, bool first)
{
    int start = 0;
    int end = numbers.size() - 1;

    int result = -1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (numbers[mid] == target)
        {
            result = mid;
            if (first == true)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
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

    return result;
}

vector<int> find_first_and_last_occurance(vector<int> &numbers, int target)
{
    vector<int> result;

    result.push_back(search_for_first_or_last_occurance(numbers, target, true));
    result.push_back(search_for_first_or_last_occurance(numbers, target, false));

    return result;
}

int main()
{
    int temp[] = {11, 23, 35, 41, 45, 45, 45, 52, 67};
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));
    vector<int> result = find_first_and_last_occurance(numbers, 45);

    cout << "start index: " << result[0] << endl;
    cout << "end index: " << result[1] << endl;
}
