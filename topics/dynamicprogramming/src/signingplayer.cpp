/*
 * <IntroductionToAlgorithm> chapter15 dynamic programming, exercise 15-12, signing free-agent baseball players
 * as a manager for a baseball team, you need to sign some free-agent player. you have X dollars in hand
 * N: positions to consider.
 * P: players available for each position
 * VORP(value over replacement player): integer value of each player.
 * each player has a number of salary amount
 * Q: devise an algorithm that maximize the total VORP of the players you sign with no more than X dollars. output total VORP, total amount of salary, and a list of signed players
 *
 * in my mind, its prototype is 0-1 knapsack, but added with one more dimension
 *
 * open qustion: 
 * how to solve case of no signment for particular position?
 * */
#include "../header/preliminary.h"

/*
 * substructure: 
 * w[i][j][t] = max{w[i-1][k][t-s[i][j]], k=1...P} + v[i][j]
 * result = max{w[N-1][j][X], j=1...P}
 * @param:
 *        N: positions to consider
 *        P: players available for each position
 *        X: total budget
 *        s: total cost of all signed players
 *        return: total VORP of all signed players
 * */
int signingplayers(int** vorp, int ** salary, int N, int P, int X, int& s){
    int*** dp = new int**[N];        //dp[i][j][t] means with budget t, max total VORP if player[i][j] is signed, while i-1 psotions ready 
    for(int i=0;i<N;++i){
        dp[i] = new int*[P];
        for(int j=0;j<P;++j){
            dp[i][j] = new int[X+1]();
        }
    }
    int*** prev = new int**[N];     //prev[i][j][t] means for signed play j of position i with budget t, the optimal signed player of
    for(int i=0;i<N;++i){           //position i-1
        prev[i] = new int*[P];
        for(int j=0;j<P;++j){
            prev[i][j] = new int[X+1]();
        }
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<P;++j){
            for(int t=X;t >= salary[i][j];--t){
                if(t < salary[i][j])
                  break;
                dp[i][j][t] += vorp[i][j];
                if(j>0){
                    int bgt = t - salary[i][j];
                    if(bgt > 0){
                        int tmp = dp[i-1][0][bgt];
                        int tmpk = 0;
                        for(int k=1;k<P;++k){        //dp[i][j][t] += max{dp[i-1][k][t-s[i][j], k=1...P}
                            if(tmp < dp[i-1][k][bgt]){
                                tmp = dp[i-1][k][bgt];
                                tmpk = k;
                            }
                        }
                        dp[i][j][t] += tmp;
                        prev[i][j][t] = tmpk;
                    }else{
                        prev[i][j][t] = -1;
                    }
                }
            }
        }
    }

    int sum = dp[N-1][0][X];            //total VORP of all signed players
    int t = 0;                          //signed player of position N 
    for(int j=0;j<P;++j){
        if(sum < dp[N-1][j][X]){
            sum = dp[N-1][j][X];
            t = j;
        }
    }
    int cost = salary[N-1][t];
    int V = X;
    printf("for position %d, the signed play is %d\n", N, t+1);
    for(int i=N-1;i>0;--i){
        t = prev[i][t][V];
        if(t == -1){        //no signement for previous position 
            printf("for position %d, no player is signed\n", i);
            break;
        }
        cost += salary[i-1][t];
        V -= salary[i-1][t];
        printf("for position %d, the signed play is %d\n", i, t+1);
    }
    s = cost;
    
    for(int i=0;i<N;++i){                //release allocated structure
        for(int j=0;j<P;++j){
            delete[] dp[i][j];
            dp[i][j]=0;
            delete[] prev[i][j];
            prev[i][j]=0;
        }
        delete[] dp[i];
        dp[i] = 0;
        delete[] prev[i];
        prev[i] = 0;
    }
    delete[] dp;
    dp=0;
    delete[] prev;
    prev=0;

    return sum;
}

void test_01(){  //not test yet
    return;
}

int main(int, char**){
    return 0;
}

