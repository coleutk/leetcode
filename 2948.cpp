class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // The intuition behind this problem is that elements that are within
        // 'limit' absolute difference between one another can be grouped together.
        // All of the elements in a group can be swapped with one another in some
        // form or fashion, just be able to conclude that you CAN fully swap elements
        // in a group so that they are sorted. 
        // Take [6 3 5 1 2 9] for example with a limit of 1:
        //  You can make these groups: [3 1 2], [6 5], [9]
        //  With some number of swaps, you can order these arrays in sorted order.
        //  With this being said, you although you can sort the elements in each group,
        //  you still have to keep the elements bound to their respective positions in
        //  the original array. The array can become [5 1 6 2 3 9]. Notice how these groups
        //  were returned to the array in sorted order, but still kept their relative position
        //  to the other elements in the array? This is how we can reach the optimal solution
        //  Coding this up is a litle tricky but I will explain it well

        // First, we know that we need to sort the array to best find the groups, as neighboring
        // elements will have the closest differences to one another
        int n = nums.size();
        vector<int> numsSorted(nums.begin(), nums.end());
        sort(numsSorted.begin(), numsSorted.end());

        // We are going to keep a vector of queues to store the elements that are in the same group
        // The reason we are doing this is because as we add to each group, we know the elements will
        // be getting added by smallest to largest. When we pop those elements off the queue later to
        // replace the elements in our original array, we will want to be grabbing the smallest element
        // from each group first. So, as we add the elements to the groups, we want the first element
        // we add to be the first element that is popped from that group later on

        // Now, this part isnt very tough. BUT, it is a little tricky to know how we're going to know
        // exactly what group to pull from as we iterate through the original array. When looking at:
        // [6 3 5 1 2 9], how are we going to know what group 6 is a part of, to know that we need to be
        // replacing it with the smallest element of that group? Well, here's what we can do:
        // As we add them to groups, we can keep a running counter to identify which group we are currently
        // constructing. This way, we will have some way to identify each group number. Now that we have
        // the value of the current element we are adding to a group, AND we have the group number, we know
        // that we can simply construct a map, where the key is the element value itself and the value
        // is the group number of that element, signaling to pop from that group/queue when going through
        // the original array. That way, we can collect this information in O(1) time, and we will know
        // exactly what we need to replace the element with. We will add to this map as we iterate through
        // the sorted array to construct the groups

        unordered_map<int, int> groupId;
        int groupCnt = 0; // Tells us what group # we are on
        vector<queue<int>> groups; // Stores the sorted order for each group
        queue<int> currGroup;
        currGroup.push(numsSorted[0]);
        groupId[numsSorted[0]] = groupCnt;
        for(int i = 1; i < n; i++) {
            if(numsSorted[i] - numsSorted[i - 1] > limit) {
                groups.push_back(currGroup);
                currGroup = queue<int>(); // Clear the queue by reassigning it
                groupCnt++;
            } 
            currGroup.push(numsSorted[i]);
            groupId[numsSorted[i]] = groupCnt;
        }
        groups.push_back(currGroup); // Add the last group

        // At this point, we will have a vector of queues, where the index represents the group number
        // of the queue
        // We will also have a map that tells us what group each element in nums is a part of
        // This way, as we iterate back through nums to replace elements, we will easily be able to tell
        // what group an element is a part of, so we can replace the current element with whatever is at
        // the front of that element's group queue
        for(int i = 0; i < n; i++) {
            int groupNumber = groupId[nums[i]]; // Ex. 6 would be in group 1
            // Replace the current element in nums with the value at the front of the group's queue
            int newVal = groups[groupNumber].front();
            groups[groupNumber].pop();
            nums[i] = newVal;
        }

        return nums;
    }
};
