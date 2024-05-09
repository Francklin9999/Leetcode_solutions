class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxheap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int stone : stones) maxheap.add(stone);
        int y;
        int x;
        while (maxheap.size() > 1) {
            y = maxheap.poll();
            x = maxheap.poll();
            if (x == y) continue;
            y = y - x;
            maxheap.offer(y);
        }
        if (maxheap.size() == 0) return 0;
        return maxheap.poll();
    }
}