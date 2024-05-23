class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        PriorityQueue<Pair<Integer, Integer>> maxHeap = new PriorityQueue<>((a, b) ->
        a.getValue() - b.getValue());
        int[] anw = new int[k];

        for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);

        for (Map.Entry<Integer, Integer> it : map.entrySet()) {
            maxHeap.add(new Pair<>(it.getKey(), it.getValue()));
            if (maxHeap.size() > k) maxHeap.poll();
        }

        for (int i = 0; i < k; i++) {
            anw[i] = (maxHeap.poll().getKey());
        }
        return anw;
    }
}