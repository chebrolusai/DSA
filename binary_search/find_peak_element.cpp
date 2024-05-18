#include <iostream>
#include <vector>

using namespace std;

int find_peak_element(vector<int> &numbers)
{
    const int N = numbers.size();

    if (N == 1)
    {
        return numbers[0];
    }

    if (N == 2)
    {
        return max(numbers[0], numbers[1]);
    }

    int start = 0;
    int end = N - 1;

    int result = -1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (mid == 0 && numbers[mid] > numbers[1])
        {
            return numbers[mid];
        }

        else if (mid == N - 1 && numbers[N - 1] > numbers[N - 2])
        {
            return numbers[N - 1];
        }

        if (numbers[mid] > numbers[mid + 1] && numbers[mid] > numbers[mid - 1])
        {
            return numbers[mid];
        }

        if (numbers[mid] < numbers[mid + 1])
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
    int temp[] = {5, 10, 20, 15};
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));

    int result = find_peak_element(numbers);

    cout << "Peak element: " << result;
}
