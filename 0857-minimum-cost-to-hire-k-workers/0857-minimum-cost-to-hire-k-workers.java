class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        PriorityQueue<Integer> maxheap = new PriorityQueue<>(Comparator.reverseOrder());
        List<Pair<Double, Integer>> list = new ArrayList<>();
        double sum = Double.POSITIVE_INFINITY;
        int totalquality = 0;
        double ratio = 0;

        for (int i = 0; i < quality.length; i++) {
            list.add(new Pair<>((double) wage[i] / quality[i], quality[i]));
        }
        list.sort(Comparator.comparingDouble(p -> p.getKey()));
        for (int j = 0; j < quality.length; j++) {
            ratio = list.get(j).getKey();
            totalquality += list.get(j).getValue();
            maxheap.add(list.get(j).getValue());
            if (maxheap.size() > k) {
                totalquality -= maxheap.poll();
            }
            if (maxheap.size() == k) {
                sum = Math.min(sum, totalquality * ratio);
            }
        }
        return sum;
    }
}