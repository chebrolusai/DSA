/*
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 *
 * https://leetcode.com/problems/daily-temperatures/description/
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> higherTempIndexes;

        int endIndex = temperatures.size() - 1;

        vector<int> result(temperatures.size(), 0);

        while (endIndex >= 0) {

            if (higherTempIndexes.empty()) {

                higherTempIndexes.push(endIndex);

            }

            else {

                if (temperatures[endIndex] <
                    temperatures[higherTempIndexes.top()]) {

                    result[endIndex] = higherTempIndexes.top() - endIndex;
                    higherTempIndexes.push(endIndex);

                } else {

                    while (!higherTempIndexes.empty() &&
                           temperatures[endIndex] >=
                               temperatures[higherTempIndexes.top()]) {

                        higherTempIndexes.pop();
                    }

                    if (!higherTempIndexes.empty()) {
                        result[endIndex] = higherTempIndexes.top() - endIndex;
                    }

                    higherTempIndexes.push(endIndex);
                }
            }

            endIndex--;
        }

        return result;
    }
};
