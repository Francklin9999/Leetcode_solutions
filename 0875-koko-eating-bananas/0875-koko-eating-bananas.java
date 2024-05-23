class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int r = 0;

        for (int num : piles) r = Math.max(r, num);

        int l = 0;
        int mid;

        while (l < r) {
            mid = l + (r - l) / 2;
            if (helper(mid, h, piles)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }

    private boolean helper(int rate, int h, int[] piles) {
        for (int i = 0; i < piles.length; i++) {
            h -= Math.ceil((double) piles[i] / (double) rate);
            if (h < 0) return false;
        }
        return true;
    }
}