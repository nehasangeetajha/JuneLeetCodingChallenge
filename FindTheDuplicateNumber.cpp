https://leetcode.com/explore/featured/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3371/

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/

//IndexSolution O(n) - time, O(1) - space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      for(int i = 0;i<nums.size();i++)
      {
          int index = abs(nums[i])-1;
          nums[index]*=-1;
          if(nums[index]>0)
              return abs(nums[i]);
      }
        return -1;
    }
};


//SortingSolution O(nlogn) - time, O(1) - space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      for(int i = 0;i<nums.size();i++)
      {
          if(nums[i]==nums[i+1])
              return nums[i+1];
      }
        return -1;
    }
};