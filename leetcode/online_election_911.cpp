/*
 * You are given two integer arrays persons and times. In an election, the ith vote was cast for persons[i] at time times[i].
 * For each query at a time t, find the person that was leading the election at time t. Votes cast at time t will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.
 * Implement the TopVotedCandidate class:
 * TopVotedCandidate(int[] persons, int[] times) Initializes the object with the persons and times arrays.
 * int q(int t) Returns the number of the person that was leading the election at time t according to the mentioned rules.
 *
 * https://leetcode.com/problems/online-election/description/
*/

class TopVotedCandidate {
public:
    vector<int> max_votes;
    vector<int> time_period;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> votes;
        int max_voted_candidate = -1;
        int current_lead = -1;

        time_period = times;

        for (int i = 0; i < persons.size(); i++) {
            votes[persons[i]]++;

            if (votes[persons[i]] >= votes[current_lead]) {
                current_lead = persons[i];
            }

            max_votes.push_back(current_lead);
        }
    }

    int binarySearch(vector<int>& times, int target) {
        int start = 0;
        int end = times.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (times[mid] == target) {
                return mid;
            }

            if (times[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return end;
    }

    int q(int t) {
        int index = binarySearch(time_period, t);
        return max_votes[index];
    }
};
