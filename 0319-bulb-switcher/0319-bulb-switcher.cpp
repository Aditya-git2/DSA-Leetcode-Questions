class Solution {
public:
    int bulbSwitch(int n) {
    /*
    Round 0 => [0,0,0,0,0]   // all bulbs OFF initially
    Round 1 => [1,1,1,1,1]   // toggle every bulb → all ON
    Round 2 => [1,0,1,0,1]   // toggle every 2nd bulb → bulbs 2,4 OFF
    Round 3 => [1,0,0,0,1]   // toggle every 3rd bulb → bulbs 3,6…(only 3rd here) OFF, 3rd toggled
    Round 4 => [1,0,0,1,1]   // toggle every 4th bulb → bulb 4 ON
    Round 5 => [1,0,0,1,0]   // toggle every 5th bulb → bulb 5 OFF
*/
 // observation => all perfect square bulbs are on

        return sqrt(n);
    }
};

/*  Brute force approach => Time limit exceeded
class Solution {
public:
    int bulbSwitch(int n) {
        // Create a boolean array of size n+1 (1-based indexing for bulbs)
        // Initially all bulbs are OFF (false = 0)
        vector<bool> bulb(n+1, 0);

        // Loop through each round from 1 to n
        for (int round = 1; round <= n; round++) {
            // In each round, toggle every 'round'-th bulb
            // Example: round = 2 → toggle bulbs 2, 4, 6, ...
            for (int i = round; i <= n; i += round) {
                bulb[i] = !bulb[i];  // Toggle bulb state (ON <-> OFF)
            }
        }

        // Count how many bulbs are ON after all rounds
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (bulb[i]) count++;
        }

        return count;  // Return the total ON bulbs
    }
};

*/