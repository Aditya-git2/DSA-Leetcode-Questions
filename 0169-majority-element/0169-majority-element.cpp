class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
            if(freq[x] > n/2) return x;
        }
        return -1;   // if maj ele not found
    }
};