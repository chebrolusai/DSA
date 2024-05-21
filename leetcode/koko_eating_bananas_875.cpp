/*
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
*/

class Solution {
public:

    bool canEat (vector<int>& piles, int speed, int h ) {

        int count = 0;

        for(int i=0; i<piles.size();i++) {

            count += piles[i]/speed;

            if ( piles[i] % speed > 0 ) {
                count++;
            }

            if ( count > h ) {
                return false;
            }

        }
 
        return true;

    }


    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1;

        int end   = *max_element(piles.begin(), piles.end());

        int result = end;

        while(start <= end) {

            int mid = start + (end-start)/2;

            if(canEat(piles,mid,h)) {
                result = mid;
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }

        }

        return result;

    }
};
