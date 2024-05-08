class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> anw = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums);
        helper(0, nums, anw, list);
        return anw;
    }

    private void helper(int start, int[] nums, List<List<Integer>> anw, List<Integer> list) {
        if (start == nums.length) {
            List<Integer> temp = new ArrayList<>(list);
            anw.add(temp);
            return;
        }
        list.add(nums[start]);
        helper(start + 1, nums, anw, list);
        list.remove(list.size() - 1);

        while (start < nums.length - 1 && nums[start] == nums[start + 1]) start++;
        helper(start + 1, nums, anw, list);
    }
}