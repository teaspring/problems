/*
 * *************<DataStructureInC++> chapter4 stack & queue************
 * BankOne problem of coming guests and serving jerks *******
 * -----------------------------------------------------------------------------
 * Num of customers per min       Percentage of one-minute intervals    Range
 *            0                                    15                   1-15
 *            1                                    20                   16-35
 *            2                                    25                   36-60
 *            3                                    10                   61-70
 *            4                                    30                   71-100
 *-----------------------------------------------------------------------------
 * AmountOfTimeNeededForService(sec)  Percentage Of customers           Range
 *            0                                    0                    ---
 *            10                                   0                    ---
 *            20                                   0                    ---
 *            30                                   10                   1-10
 *            40                                   5                    11-15
 *            50                                   10                   16-25
 *            60                                   10                   26-35
 *            70                                   0                    ---
 *            80                                   15                   36-50
 *            90                                   25                   51-75
 *            100                                  10                   76-85
 *            110                                  15                   86-100
 *----------------------------------------------------------------------------
 */

#include "stdio.h"
#include <iostream>
#include "stdlib.h"
#include "math.h"
#include "genqueue.h"

using namespace std;

/*
 * get random num based on a known disperse distribution 0-100
 * */
int option(int percents[]){
    register int i=0, choice = rand() % 100 + 1, perc;
    for(perc = percents[0]; perc < choice; perc +=percents[i+1], i++);
    return i;
}

int main(int argc, char* argv[]){
    int arrivals[] = {15, 20, 25, 10, 30};
    int service[] = {0, 0, 0, 10, 5, 10, 10, 0, 15, 25, 10, 15};
    int clerks[] = {0, 0, 0, 0};
    int numOfClerks = sizeof(clerks)/sizeof(int);
    int customers, t, i, numOfMinutes = 100, x;
    double maxWait = 0.0, currWait = 0.0, thereIsLine = 0.0;
    Queue<int> simulQ;
    cout.precision(2);

    for(t = 1; t <= numOfMinutes;t++){        //after each minute subtract
        cout << " t = " << t;                //at most 60 seconds from time
        for(i = 0;i < numOfClerks;i++)        //left to service the current 
          if(clerks[i] < 60)                //customer by clerk i;
            clerks[i] = 0;
          else clerks[i] -= 60;
        customers = option(arrivals);
        for(i = 0; i<customers; i++){
            x = option(service) * 10;
            simulQ.enqueue(x);
            currWait += x;
        }
        //dequeue customers when clerks are available
        for(i = 0; i < numOfClerks && !simulQ.isEmpty();){
            if(clerks[i] < 60){                // assign more than one customer
                x = simulQ.dequeue();            // to a clerk if service time
                clerks[i] += x;                    // is still below 60 sec;
                currWait  -= x;
            }else{
                i++;
            }
        }
        if( !simulQ.isEmpty()){
            thereIsLine++;
            cout << " wait = " << currWait/60.0;
            if(maxWait < currWait)
              maxWait = currWait;
        }else{
            cout << " wait = 0;";
        }
        cout<<endl;
    }
    cout << "\nFor " << numOfClerks << " clerks, there was a line "
         << thereIsLine/numOfMinutes*100.0 << "% of the time; \n"
         << "maximum wait time was " << maxWait/60.0 << " min.";
    return 0;
}
