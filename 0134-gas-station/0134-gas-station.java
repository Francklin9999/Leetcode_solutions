class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int index = 0;
        int _cost = 0;
        int total = 0;

        for (int i = 0; i < cost.length; i++) {
            _cost += gas[i] - cost[i];
            total += (gas[i] - cost[i]);
            if (total < 0) {
                total = 0;
                index = i + 1;
            }
        }
        return (_cost >= 0) ? index : -1;
    }
}