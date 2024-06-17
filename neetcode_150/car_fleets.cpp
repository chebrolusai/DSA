/*
 * There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
 * You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.
 * A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
 * A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.
 * If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
 * Return the number of car fleets that will arrive at the destination.
 *
 * https://leetcode.com/problems/car-fleet/description/
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> pos_speed_vector;

        for (int i = 0; i < position.size(); i++) {
            pos_speed_vector.push_back({position[i], speed[i]});
        }

        sort(pos_speed_vector.begin(), pos_speed_vector.end());

        stack<double> fleet_times;

        for (int i = pos_speed_vector.size() - 1; i >= 0; i--) {

            double time = (double(target) - pos_speed_vector[i].first) /
                          pos_speed_vector[i].second;

            if (fleet_times.empty() || fleet_times.top() < time) {

                fleet_times.push(time);
            }
        }

        return fleet_times.size();
    }
};
