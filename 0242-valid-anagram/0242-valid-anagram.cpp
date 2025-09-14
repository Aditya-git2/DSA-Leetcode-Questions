class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort s and t => if both same => return true 
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s == t) return true;
        else return false;
    }
};