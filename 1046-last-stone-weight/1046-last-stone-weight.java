class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxheap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int stone : stones) maxheap.add(stone);
        while (maxheap.size() > 1) {
            int y = maxheap.poll();
            int x = maxheap.poll();
            if (x == y) continue;
            maxheap.offer(y - x);
        }
        if (maxheap.size() == 0) return 0;
        return maxheap.poll();
    }
}