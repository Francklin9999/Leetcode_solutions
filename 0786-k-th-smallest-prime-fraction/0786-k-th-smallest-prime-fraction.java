class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<int[]> maxheap = new PriorityQueue<>((a, b) -> Float.compare((float) b[0] / b[1], (float) a[0] / a[1]));

        int[] anw = new int[2];

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                int[] curr = new int[2];
                curr[0] = arr[i];
                curr[1] = arr[j];
                if (maxheap.size() == k) {
                    maxheap.offer(curr);
                    maxheap.poll();
                } else maxheap.offer(curr);
            }
        }
        anw = maxheap.poll();
        return anw;
    }
}