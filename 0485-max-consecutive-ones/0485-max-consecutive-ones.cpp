class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , maxCount = 0;
        for(auto x : nums){
            if(x == 1){
                count++;
                maxCount = max(maxCount,count);
            }else{  // x == 0    // jaise hi 0 aa jaye count ko 0 se reinitialize kar do
                count = 0;
            }
        }
        return maxCount;
    }
};