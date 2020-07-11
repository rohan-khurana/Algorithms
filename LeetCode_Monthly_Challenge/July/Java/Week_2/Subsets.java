/*
PROBLEM:
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/



class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> powerSet = new ArrayList<>();
		powerSet.add(new LinkedList<>());
	    for (int num : nums) {
            List<List<Integer>> set = new ArrayList<>();
            for (List<Integer> i : powerSet) {
				List<Integer> temp = new ArrayList<>(i);
				temp.add (num);
				set.add (temp);
			}
            for(List<Integer> i : set){
                powerSet.add(i);
            }
        }
		return powerSet;
    }
}
