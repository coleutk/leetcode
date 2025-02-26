class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // We are keeping track of the total sum throughout the array iteration
        // If at any point:
        //  The current sum is odd, meaning that the total sum of our current subarray is odd
        //  Now think: if the total sum up to this point is odd, this means that we can subtract
        //  all of the previous even subarray totals up to this point that are even because (odd - even = odd)
        //  
        //  If it may help to see it in action, lets take a look here:
        //  [4 2 1 2 3 5]
        //  sum at each step:
        //  [4 6 7 9 12 17]
        //  Now let's say we are in the final spot (17). This is an odd sum. Now count how many even subarray sums
        //  we have before this: its 4 (0, 4, 6, 12)
        //  Now see that if we were to take 17 and subtract any of these values, we would still get an odd total
        //  subarray sum for each, meaning we would add 4 to our result
        //  Also, if you notice, all of these subarray totals are contiguous:
        //  0 = []
        //  4 = [4]
        //  6 = [4, 2]
        //  12 = [4, 2, 1, 2, 3]
        //  And remember that these would be the subarrays that are cut off from out total subarray that forms 17,
        //  which is the entire array in this case
        //  And since each of these start from the beginning, we could just slice them off and be left with whatever
        //  the odd subarray sum is after that. For example if we wanted to see what choosing the even subarray sum
        //  of 6 would look like to chop off we would have:
        //  Subarray of current total sum (17) = [4, 2, 1, 2, 3, 5]
        //  Subarray of even subarray sum (6) = [4, 2]
        //  Doing 17 - 6, we will get 11, which is represented by [1, 2, 3, 5] (the remaining subarray after chopping)
        //  
        //  The logic described above applies THE EXACT SAME to evens because even - odd = odd

        const int MOD = 1000000007;
        int sum = 0;
        int evenSums = 1; // (subtracting 0)
        int oddSums = 0;
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum % 2 == 1) {
                // odd sum
                res = (res + evenSums) % MOD;
                oddSums++;
            } else {
                // even sum
                res = (res + oddSums) % MOD;
                evenSums++;
            }
        }
        return res;
    }
};
