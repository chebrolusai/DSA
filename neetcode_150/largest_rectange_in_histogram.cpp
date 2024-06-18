/*
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int>right(n);
        vector<int>left(n);
        rightsmaller(heights,right,n);
        leftsmaller(heights,left,n);
        int result=0;
        for(int i=0;i<n;i++)
        {
            result=max(result,(right[i]-left[i]-1)*heights[i]);
        }
        return result;
    }
    void rightsmaller(vector<int>&heights,vector<int>&arr,int n)
    {
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push({heights[i],i});
                arr[i]=n;
            }
            else if(heights[i]>st.top().first)
            {
                arr[i]=st.top().second;
                st.push({heights[i],i});
            }
            else
            {
                while(!st.empty()&&heights[i]<=st.top().first)
                {
                    st.pop();
                }
                if(st.empty())
                {
                     st.push({heights[i],i});
                     arr[i]=n;
                }
                else 
                {
                    arr[i]=st.top().second;
                    st.push({heights[i],i});
                }
            }
        }
    }
    void leftsmaller(vector<int>&heights,vector<int>&arr,int n)
    {
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({heights[i],i});
                arr[i]=-1;
            }
            else if(heights[i]>st.top().first)
            {
                arr[i]=st.top().second;
                st.push({heights[i],i});
            }
            else
            {
                while(!st.empty()&&heights[i]<=st.top().first)
                {
                    st.pop();
                }
                if(st.empty())
                {
                     st.push({heights[i],i});
                     arr[i]=-1;
                }
                else 
                {
                    arr[i]=st.top().second;
                    st.push({heights[i],i});
                }
            }
        }
    }
    
};
