/*
* from leetcode
* a pile of 'N' kg of nuts is in an Oasis, and the town is 'D' km away far from the oasis.
* use a horse to transport the nuts to town. the capacity of horse is C, and it eats F nuts per km for food.
*
* calculate the maximum amount of nuts that can be transported to town
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

static const double dust = 1e-1;

class Solution{

public:
    /*
     * I used to think this solution is right but it is not finally.
     * its error is ignore the additional nuts while N % C > 0 while it should be able to contribute
     * */
    double getMaxNuts_2(double N, double D, double C, double F){
        if(N <= C){  // final journey
            return max(N - D * F, 0.0);    // 0.0 for out of feed
        }

        int floorTrips = floor(N / C); // aligned floor trips that horse can transport in full load
        int ceilTrips = ceil(N / C);  // aligned ceil trips

        double f = C * floorTrips; // f = N - N % C

        int numTrips = 2 * floorTrips - 1; // total trip count

        double costPerKm = numTrips * F; // important concept, feed per km to move ahead

        /*
        * horse transport is full load (C) definitely.
        * after first transport, the remaining must be aligned to multiplies of D
        * */
        double remainingNuts = f - C;

        double traveled = (f - remainingNuts) / costPerKm;  // option one of traveled

        if(N - f > dust){
            double numTrips2 = 2 * ceilTrips - 1 ; // equals to numTrip + 2, it means with one more round trip to load the rest nuts
            double costPerKm2 = numTrips2 * F;
            double traveled2 = (N - remainingNuts) / costPerKm2;  //check it whether worth to load
            traveled = max(traveled, traveled2); // option two of traveled
        }

        if(traveled >= D)    return N - D * costPerKm;

        /* just for debug
        printf("solution2: begin %fkg nuts, distance %fkm from town, after traveled %fkm, remaining %fkg nuts at next stop\n",
                    N, D, traveled, remainingNuts);
        */

        return getMaxNuts_2(remainingNuts, D - traveled, C, F);
    }

    /*
     * solution of author, test prove it correct !
     * */
    double getMaxNuts_1(double N, double D, double C, double F){
        if(N <= C){
            return max(N - D * F, 0.0); // 0.0 for out of feed
        }

        int numTrips = 2 * ceil(N / C) - 1; // it uses ceil !

        double costPerKm = numTrips * F;

        double remainingNuts = C * (ceil(N / C) - 1.0);

        double traveled = (N - remainingNuts) / costPerKm;

        if(traveled >= D)    return N - D * costPerKm;

        /* just for debug
        printf("solution1: begin %fkg nuts, distance %fkm from town, after traveled %fkm, remaining %fkg nuts at next stop\n",
                    N, D, traveled, remainingNuts);
        */
        return getMaxNuts_1(remainingNuts, D - traveled, C, F);
    }
};

/* unit test is in ../unittest/nutsInOasis_unittest */

/*
int main(int, char**){
    Solution s;
    double result = s.getMaxNuts_2(3200, 1000, 1000, 1);
    printf("for soluton 2, finally the rest %f kg nuts in destination\n", result);
    cout << "--------------------" << endl;
    result = s.getMaxNuts_1(3200, 1000, 1000, 1);
    printf("for soluton 1, finally the rest %f kg nuts in destination\n", result);

    return 0;
}
*/
