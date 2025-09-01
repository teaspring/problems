import java.util.*;

class StockExLoss {
    public int process1(List<Integer> prices) {
        int peak = 0, trough = 0, res = 0;
        int prev = -1;
        for (int i = 0; i < prices.size(); i++) {
            int v = prices.get(i);
            if (peak == -1 || (prev < v && peak < v)) {
                peak = v;
                trough = 0;
            } else if (prev > v && (trough == 0 || trough > v)) {
                trough = v;
                res = Math.max(res, peak - trough);
            }
            prev = v;
        }
        return -res;
    }
}