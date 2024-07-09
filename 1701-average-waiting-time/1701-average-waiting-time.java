class Solution {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;
        double waitingTime = 0;
        double totalTime = customers[0][0];

        for(int i = 0; i < n; i++) {
            if(totalTime < customers[i][0]) totalTime = customers[i][0];
            double distance = customers[i][1];
            if (customers[i][0] < totalTime) {
                distance += totalTime - customers[i][0];
            }
            waitingTime += distance;
            totalTime += customers[i][1]; 
        }

        return (waitingTime / n);
    }
}