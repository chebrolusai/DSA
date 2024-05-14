/*
 * In a special ranking system, each voter gives a rank from highest to lowest to all teams participating in the competition.
 * The ordering of teams is decided by who received the most position-one votes. If two or more teams tie in the first position, we consider the second position to resolve the conflict, if they tie again, we continue this process until the ties are resolved. If two or more teams are still tied after considering all positions, we rank them alphabetically based on their team letter.
 * You are given an array of strings votes which is the votes of all voters in the ranking systems. Sort all teams according to the ranking system described above.
 * Return a string of all teams sorted by the ranking system.
 *
 * https://leetcode.com/problems/rank-teams-by-votes/description/
*/

class Solution {
public:

    bool compare(char &a, char &b, int size, map<pair<char, int>, int> &char_rank_count) {
        for (int i = 1; i < size; i++) {
            if (char_rank_count[{a, i}] != char_rank_count[{b, i}]) {
                return char_rank_count[{a, i}] > char_rank_count[{b, i}];
            }
        }
        return a < b;
    }

    string rankTeams(vector<string>& votes) {
        
        vector<char> teams;

        int size = votes[0].size();
        map<pair<char,int>,int> char_rank_count;

        for(int i =0; i<votes[0].size(); i++) {
            teams.push_back(votes[0][i]);
        }

        for( int i=0; i<votes.size(); i++ ) {

            int rank = 1;

            for(int j=0; j<votes[i].size(); j++) {

                char_rank_count[{votes[i][j],rank}]++;
                rank++;

            }

        }

        sort(teams.begin(), teams.end(), [&](char a, char b) {
            return compare(a, b, size, char_rank_count);
        });

        string result(teams.begin(), teams.end());
        return result;

    }
};
