/*
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> charCount;

        for (int i = 0; i < nums.size(); i++) {

            charCount[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (auto it : charCount) {

            minHeap.push({it.second, it.first});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;

        while (k > 0) {

            result.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        return result;
    }
};
