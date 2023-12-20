//
//  problem1.cpp
//  DSA
//
//  Created by sai chebrolu on 19/12/23.
//

/*
    PROBLEM: MAXIMUM SUM SUBARRAY OF SIZE K
    DESCRIPTION: Fild the max sum of all the possible subarrays of size exactly k - return the result subarray.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> max_sum_subarray(vector<int>& input, int k) {
    
    vector<int> result;
    
    int startIndex  = 0;
    int endIndex    = 0;
    int sum         = 0;
    int maxSum      = INT_MIN;
    
    while ( endIndex<input.size() ) {
        
        sum = sum + input[endIndex];
        
        if ( startIndex+endIndex+1 < k ) {
            
            endIndex++;
            
        }
        else {
                
            if ( sum > maxSum ) {
                
                result.assign(input.begin()+startIndex, input.begin()+endIndex+1);
                maxSum = sum;
                
            }
            
            sum = sum - input[startIndex];
            startIndex++;
            endIndex++;
            
        }
        
    }
    
    return result;
}



int main() {
    
    vector<int> v = {1,3,2,4,6,3,4,7,1,2};
    int k         = 3;
    
    cout<<endl<<"Input"<<endl;
    
    cout<<"Vector: ";
    
    for (const auto& number : v) {
        cout << number << " ";
    }
    
    cout<<endl<<"k: "<<k<<endl<<endl;
    
    cout<<"Output"<<endl;
    
    vector<int> result = max_sum_subarray(v,k);
    
    for (const auto& number : result) {
        cout << number << " ";
    }
    
    cout<<endl;
    
    return 0;
    
}
