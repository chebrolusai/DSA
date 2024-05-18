#include <iostream>
#include <vector>

using namespace std;

int number_of_times_rotated(vector<int> &numbers)
{
    const int N = numbers.size();

    int start = 0;
    int end = N - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        int next_element = (mid + 1) % N;
        int prev_element = (mid - 1 + N) % N;

        if (numbers[mid] <= numbers[next_element] && numbers[mid] <= numbers[prev_element])
        {
            return mid;
        }

        if (numbers[0] <= numbers[mid])
        {
            start = mid + 1;
        }

        else if (numbers[N - 1] >= numbers[mid])
        {
            end = mid - 1;
        }
    }

    return -1;
}

int binary_search_between_two_indexes(vector<int> &numbers, int start, int end, int target)
{
    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (numbers[mid] == target)
        {
            return mid;
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

    return -1;
}

int main()
{
    int temp[] = {11, 12, 15, 18, 2, 5, 6, 8};
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));
    int min_number_index = number_of_times_rotated(numbers);

    int search_number = 12;

    int result = binary_search_between_two_indexes(numbers, 0, min_number_index, search_number);

    if (result == -1)
    {
        result = binary_search_between_two_indexes(numbers, min_number_index + 1, numbers.size() - 1, search_number);
    }

    cout << "Index of search number: " << result;
}
