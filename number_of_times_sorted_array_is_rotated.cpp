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

int main()
{
    int temp[] = {11, 12, 15, 18, 2, 5, 6, 8};
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));
    int result = number_of_times_rotated(numbers);

    cout << "No of times rotated: " << result;
}
