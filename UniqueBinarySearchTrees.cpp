//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
    unordered_map<int,int>map;
public:
    int numTrees(int n) {
        if((n==0)||(n==1))
            return 1;
        int count = 0;
        if(map[n])
            return map[n];
        for(int i =1;i<=n;i++)
            count+=numTrees(i-1)*numTrees(n-i);
        map[n] =count;
        return count;
    }
};
