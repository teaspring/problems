/*
 * implement pow(x, n).
 * */

class Solution{

public:
    /*
     * better to use recursion
     * */
    double pow(double x, int n){
        if(n == 0)    return 1;

        if(x == 0)    return 0;

        if(x == 1)    return 1;

        if(x == -1)    return n % 2 ? -1 : 1;

        if(n < 0)    return (double)1 / pow(x, -n);

        if(n % 2){
            return pow(x*x, n/2)*x;
        }else{
            return pow(x*x, n/2);
        }
    }
};

/* unit test is in ../cpp_unittest/pow_unittest */
