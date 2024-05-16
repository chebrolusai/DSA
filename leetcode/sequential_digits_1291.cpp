/*
 * An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
 * Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
 *
 * https://leetcode.com/problems/sequential-digits/description/
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        string low_string  = to_string(low);
        string high_string = to_string(high);

        int min_digits = low_string.size();
        int max_digits = high_string.size();

        vector<int>result;

        int curr = min_digits;

        while ( curr <= max_digits ) {

            int power = curr - 1;
            for(int i = 1; i < 10 - power; i++) {

                int digit  = i;
                int number = 0;
                int power = curr - 1;
                while(power >= 0) {
                    number += digit * pow(10,power);
                    digit++;
                    power--;
                }
                if ( number >= low && number <= high ) {
                    result.push_back(number);
                }

                if ( number > high ) {
                    return result;
                }

            }

            curr++;

        }

        return result;

    }
};
