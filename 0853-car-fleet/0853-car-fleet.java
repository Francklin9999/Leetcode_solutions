class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        if (position.length == 0) return 0;
        if (position.length == 0) return 1;
        HashMap<Integer, Float> map = new HashMap<>();
        float res;
        int counter = position.length;
        for (int i = 0; i < position.length; i++) {
            res = ((float)target - (float)position[i]) / (float)speed[i];
            map.put(position[i], res);
        }
        Arrays.sort(position);
        for (int i = position.length - 2; i >= 0; i--) {
            if (map.get(position[i]) <= map.get(position[i + 1])) {
                map.put(position[i], map.get(position[i + 1]));
                counter--;
            } 
        }
        return counter;
    }
}