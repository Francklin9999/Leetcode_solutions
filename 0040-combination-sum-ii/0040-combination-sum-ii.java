class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> anw = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        helper(0, 0, target, candidates, anw, list);
        return anw;
    }

    private void helper(int start, 
        int sum, 
        int target, 
        int[] candidates, 
        List<List<Integer>> anw, 
        List<Integer> list) {
        if (sum == target) {
            List<Integer> temp = new ArrayList<>(list);
            anw.add(temp);
            return;
        }
        if (start >= candidates.length || sum > target) return;

        list.add(candidates[start]);
        helper(start + 1, sum + candidates[start], target, candidates, anw, list);
        list.remove(list.size() - 1);

        while (start < candidates.length - 1 && candidates[start] == candidates[start + 1]) start++;
        helper(start + 1, sum, target, candidates, anw, list);
    }
}