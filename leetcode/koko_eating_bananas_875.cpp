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
