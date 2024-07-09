class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int makingTime = customers[0][0] + customers[0][1];
        long totalWaitingTime = customers[0][1];  // first customer's waiting time is equal to its making time

        for (int i = 1; i < n; i++) {
            if (customers[i][0] > makingTime) {
                makingTime = customers[i][0];
            }
            makingTime += customers[i][1];
            totalWaitingTime += makingTime - customers[i][0];
        }

        return (double) totalWaitingTime / n;
    }
};