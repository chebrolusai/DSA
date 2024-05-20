#include <iostream>
#include <vector>

using namespace std;

bool students_required(vector<int> &pages, int k, int max_pages)
{

    int count = 1;
    int sum = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        sum += pages[i];

        if (sum > max_pages)
        {
            count++;
            sum = pages[i];
        }

        if (count > k)
        {
            return false;
        }
    }

    return true;
}

int allocate_min_number_of_pages(vector<int> &pages, int k)
{

    int start = *max_element(pages.begin(), pages.end());

    int end = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        end += pages[i];
    }

    int result = -1;
    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (students_required(pages, k, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return result;
}

int main()
{

    int temp[] = {10, 20, 30, 25, 40};
    vector<int> numbers(temp, temp + sizeof(temp) / sizeof(temp[0]));

    cout << allocate_min_number_of_pages(numbers, 2);
}
