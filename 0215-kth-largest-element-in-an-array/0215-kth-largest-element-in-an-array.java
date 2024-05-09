class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minheap = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            if (minheap.size() < k) {
                minheap.add(nums[i]);
            } else if (minheap.peek() < nums[i]) {
                minheap.poll();
                minheap.add(nums[i]);
            }
        }
        return minheap.poll();
    }
}