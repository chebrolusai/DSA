/*
 * Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 * Since the result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    static bool compare(const std::string& a, const std::string& b) {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int>& nums) {
        
        unordered_map<int,vector<string>> priority;

        for(int i=0; i<nums.size(); i++) {

            string str = to_string(nums[i]);

            int first_digit = str[0] - '0';

            priority[first_digit].push_back(str);

        }

        if ( priority.size() == 1 && priority.count(0) > 0 ) {
            return "0";
        }

        string result = "";

        for(int i=9; i>=0; i--) {

            if(priority.count(i) > 0) {
                
                sort(priority[i].begin(),priority[i].end(),compare );

                for(auto it: priority[i]) {
                    result += it;
                }

            }

        }

        return result;

    }
};
