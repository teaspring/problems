/*
* from leetcode
* a pile of 'N' kg of nuts is in an Oasis, and the town is 'D' km away far from the oasis.
* use a horse to transport the nuts to town. the capacity of horse is C, and it eats F nuts per km for food.
*
* calculate the maximum amount of nuts that can be transported to town
*/
#include "../include/preliminary.h"

double getMaxNuts_02(double N, double D, double C, double F){
    if(N <= C){  // base case
        double nutsAtDestination = N - D*F;
        return max(nutsAtDestination, 0.0);    //0.0 for out of fuel
    }

    double f = C * floor(N/C);
    int numTrips = 2*(floor(N/C) - 1) + 1;     //trip count
    double costPerKm = numTrips * F;
    double remainingNuts = f - C;    // 1.ensure remaining is multiplies of D; 2. till next stop, the consumption equals to C
    double traveled = (f - remainingNuts)/costPerKm;  //traveled option 1
    if((N - f) > 0.1){
        double numTrips2 = numTrips + 2;   //with one more round trip to load the rest nuts
        double costPerKm2 = numTrips2 * F;
        double traveled2 = (N - remainingNuts)/costPerKm2;  //check it whether worth to load
        traveled = max(traveled, traveled2);
    }

    if(traveled >= D)    return N - D*costPerKm;

    return getMaxNuts_02(remainingNuts, D - traveled, C, F);
}

/*
 * solution of author, which fails for N % C > 0 
 * */
double getMaxNuts_01(double N, double D, double C, double F){
    if(N <= C){
        double nutsAtDestination = N - D*F;
        return max(nutsAtDestination, 0.0); //0.0 for out of fuel!
    }

    int numTrips = 2*(ceil(N/C) - 1) + 1;
    double costPerKm = numTrips * F;
    double remainingNuts = C*(ceil(N/C) - 1.0);
    double traveled = (N - remainingNuts) / costPerKm;

    if(traveled >= D)    return N - D*costPerKm;

    return getMaxNuts_01(remainingNuts, D - traveled, C, F);
}

