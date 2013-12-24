/*
* from leetcode
* a pile of N kg of nuts in an Oasis, and the town is 'D' km away far from the oasis.
* use a horse to transport the nuts to town. the capacity of horse is C, and it eats F nuts per km for food. calculate the maximum amount of nuts that
* can be transported to town
*/
#include "../header/preliminary.h"

int getMaxNuts(int N, int D, int C, int F){
    if(N<=C){        //base case
        int nutsAtDestination = N - D*F;
        return (nutsAtDestination >= 0) ?
                nutsAtDestination :
                0;    //out of fuel!
    }

    int numTrips = 2*(N/C - 1) + 1;     //trip count
    int costPerKm = numTrips * F;       //really cool variable
    int remainingNuts = C*(N/C - 1);    // 1.ensure remain is multiplies of D; 2. till next stop, the consumption equals to C
    int traveled = (N - remainingNuts)/costPerKm;

    if(traveled >= D)
      return N - D*costPerKm;
    return getMaxNuts(remainingNuts, D - traveled, C, F);
}

int main(int, char**){
    string str;
    while(1){
        printf("please input N, D, C, F:\n");
        if(getline(cin, str)==0 || str.empty())
            break;
        int *arr = new int[str.size()]();
        splitStr2IntArray(str, arr);
        printf("the maximum amounts that transported to town is %d\n", getMaxNuts(arr[0], arr[1], arr[2], arr[3]));

        delete[] arr;
        arr = 0;
    }
    return 0;
}
