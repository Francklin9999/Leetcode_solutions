class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> anw = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
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
            List<Integer> copy = new ArrayList<>(list);
            anw.add(copy);
            return;
        }
        if (start >= candidates.length || sum > target) return;
        list.add(candidates[start]);
        helper(start, sum + candidates[start], target, candidates, anw, list);
        list.remove(list.size() - 1);
        helper(start + 1, sum, target, candidates, anw, list);
    }
}