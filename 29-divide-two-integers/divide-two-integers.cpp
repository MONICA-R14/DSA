
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // Handle zero divisor
        if (divisor == 0)
            return INT_MAX;  // or throw error
        
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long res = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            res += multiple;
        }

        // Determine the sign
        if ((dividend > 0) != (divisor > 0))
            res = -res;

        return (int)res;
    }
};
