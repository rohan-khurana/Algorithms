/*
PROBLEM:
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/



class Solution {
    public List<List<Integer>> threeSum(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0) continue;
            int j = i + 1, k = arr.length - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    result.add(Arrays.asList(arr[i], arr[j], arr[k]));
                    // Skip duplicate numbers of j
                    while (j+1 <= k && arr[j] == arr[j+1]) j++;
                    j++;
                    k--;
                }
            }
            // Skip duplicate numbers of i
            while (i + 1 < arr.length && arr[i + 1] == arr[i]) i++;
        }
        return result;
    }
}
