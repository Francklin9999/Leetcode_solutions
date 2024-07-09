class Solution {
    public double averageWaitingTime(int[][] customers) {
        double waitingTime = 0;
        double totalTime = customers[0][0];

        for(int i = 0; i < customers.length; i++) {
            waitingTime += customers[i][1];
            if(totalTime <= customers[i][0]) totalTime = customers[i][0];
            else {
                waitingTime += totalTime - customers[i][0];
            }
            totalTime += customers[i][1]; 
        }

        return (waitingTime / customers.length);
    }
}