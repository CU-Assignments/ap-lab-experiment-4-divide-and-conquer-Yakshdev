#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
 
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int sum = 0;

        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0; 

    
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

    
        return leftSum + rightSum;
    }

    int maxSubArrayHelper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left]; 

        int mid = left + (right - left) / 2;

        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);

        
        return max({leftMax, rightMax, crossMax});
    }

    
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Output: " << sol.maxSubArray(nums1) << endl; // Expected output: 6

    vector<int> nums2 = {1};
    cout << "Output: " << sol.maxSubArray(nums2) << endl; // Expected output: 1

    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Output: " << sol.maxSubArray(nums3) << endl; // Expected output: 23

    return 0;
}
