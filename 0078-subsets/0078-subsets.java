class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        subsetshelper(0, nums, list1, list2);
        return list1;
    }

    private void subsetshelper(int i, int[] nums, 
    List<List<Integer>> list1, List<Integer> list2) {     
        
        if (i >= nums.length) {
            List<Integer> copylist = new ArrayList<>(list2);
            list1.add(copylist);
            return;
        }
        list2.add(nums[i]);
        subsetshelper(i + 1, nums, list1, list2);
        list2.remove(list2.size() - 1);
        subsetshelper(i + 1, nums, list1, list2);
    }
}