class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> maxheap = new PriorityQueue<>(Comparator.reverseOrder());
        long anw = 0;
        for (int i = 0; i < happiness.length; i++) {
            maxheap.add(happiness[i]);
        }
        for (int i = 0; i < k; i++) {
            int temp = maxheap.poll() - i;
            if (temp > 0) anw += temp;
        }
        return anw;
    }
}