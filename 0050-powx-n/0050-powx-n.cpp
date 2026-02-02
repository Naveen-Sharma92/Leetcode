class Solution {
public:
    double myPow(double x, int n) {

        long long N = n; // prevent overflow
        
        if(N < 0){
            x = 1/x;
            N = -N;
        }

        double result = 1;

        while(N > 0){

            if(N % 2 == 1){   // odd
                result *= x;
            }

            x *= x;  // square  x not result
            N /= 2;  // halve power
        }

        return result;
    }
};
