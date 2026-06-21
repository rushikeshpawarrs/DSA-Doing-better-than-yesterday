class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i < n; i++){
            int element = nums[i];
            int tempAns = target - nums[i];
            if(mp.get(tempAns) != null){
                int arr[] = {i, mp.get(tempAns)};
                return arr;
            }
            mp.put(element, i);
        }
        return null;
    }
}
