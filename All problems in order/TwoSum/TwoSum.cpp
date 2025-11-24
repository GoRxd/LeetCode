/*
===============================================================================
 My solution (Two Pointers + Sorting)
 Time Complexity: O(n log n)
 Space Complexity: O(n)

 Approach:
 1. Wrap each number with its original index in a struct.
 2. Sort by value.
 3. Use two pointers to find the target sum.
===============================================================================
*/

class Solution {
public:
    struct Element {
        int value;
        int index;

        Element(int value, int index)
            : value(value), index(index) {}

        bool operator<(const Element& other) const {
            return value < other.value;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<Element> betterNums;
        betterNums.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            betterNums.emplace_back(nums[i], i);
        }

        sort(betterNums.begin(), betterNums.end());

        int left = 0;
        int right = betterNums.size() - 1;

        while (left < right)
        {
            int sum = betterNums[left].value + betterNums[right].value;

            if (sum > target) 
            {
                right--;
            } 
            else if (sum < target) 
            {
                left++;
            } 
            else {
                result.push_back(betterNums[left].index);
                result.push_back(betterNums[right].index);        
                return result;
            }
        }

    }
};


/*
===============================================================================
 Optimal Solution (HashMap)
 Time Complexity: O(n)
 Space Complexity: O(n)
===============================================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }

            hash[nums[i]] = i;
        }

        return {};
    }
};
*/
