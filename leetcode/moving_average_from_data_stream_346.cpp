/*
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 * Implement the MovingAverage class:
 * MovingAverage(int size) Initializes the object with the size of the window size.
 * double next(int val) Returns the moving average of the last size values of the stream.
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
*/

class MovingAverage {
public:

    queue<int> stream;
    int window_size;
    double running_sum;

    MovingAverage(int size) {
        window_size = size;
        running_sum = 0;
    }
    
    double next(int val) {
        
        if (stream.size() < window_size) {
            stream.push(val);
            running_sum += val;
            
            return running_sum/stream.size();
        }

        running_sum -= stream.front();

        stream.pop();

        stream.push(val);
        running_sum += val;

        return running_sum/stream.size();

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
