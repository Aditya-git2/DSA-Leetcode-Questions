class Solution {
public:

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int val : nums) {
            int freq = 0;
            for (int ele : nums) {
                if (ele == val)
                    freq++;
            }
            if (freq > n / 2)
                return val;
        }
     // this line will never execute since majority element will always exist
        return -1; 
    }

    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     unordered_map<int,int>freq;
    //     for(int x:nums){
    //         freq[x]++;
    //         if(freq[x] > n/2) return x;
    //     }
    //     return -1;   // if maj ele not found
    // }
};