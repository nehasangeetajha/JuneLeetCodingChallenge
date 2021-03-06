//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3365/
/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
*/

class Solution {
    vector<int>power;
    string ret;
    int prime = 19260817;
    
public:
    string robincarp(string &s,int&k)
    {
        if(k==0)
            return "";
        long long int hash = 0;
        unordered_map<int,vector<int>>mp;
        for(int i = k-1;i>=0;i--)
        {
            hash=(hash%prime+(power[k-1-i]*(s[i]-'a'+1))%prime)%prime;
        }int i=0,j=k-1;
        mp[hash]=vector<int>(1,0);
        bool flag=0;
        while(j<s.size()){
            hash=(hash%prime-((power[k-1]*(s[i]-'a'+1))%prime)+prime)%prime;
            hash=(hash%prime*26%prime)%prime;
            i++;
            j++;
            if(j<s.size()){
                hash=(hash%prime+((power[0]*(s[j]-'a'+1))%prime))%prime;
                if(mp.find(hash)!=mp.end()){
                    for(auto ind:mp[hash]){
                        if (strcmp((s.substr(ind,k)).data(), s.substr(i, k).data()) == 0) {
                        return s.substr(ind,k);
                    }
                    }
                    mp[hash].push_back(i);
                }
                else{
                    mp[hash]=vector<int>(1,i);
                }
            }
        }
        return "";
        
    }
    
    
    string longestDupSubstring(string S) {
        power.resize(S.size()+1);
        power[0]=1;
        for(int i =1;i<=S.size();i++)
            power[i] = (26*power[i-1])%prime;
        
        int l=0,r=S.size()-1;
        string ans="";
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            string valid = robincarp(S,mid);
            if(valid.size()>0)
            {
                if(valid.size()>ans.size())
                    ans = valid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};
