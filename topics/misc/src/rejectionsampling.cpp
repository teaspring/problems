/*
 * from leetcode. given a function which generates a random integer in range 1 to 7, write a function which generates 
 * a random integer in range 1 to 10 uniformly
 *
 * most valuable is the strategy to calculate the efficiency of different solution
 * */

int rand7(){
    return 1;        //pseudo function of rand7()
}

int rand10_01(){
    int row=0, col=0, idx=0;
    do{
        row = rand7();    //[1,7] uniformly
        col = rand7();    
        idx = col + (row-1)*7;  //[1,49] uniformly
    }while(idx > 40);    //break for [1,40]
    return 1 + (idx-1)%10;
}

/*
 * it seems wasteful to throw away the integers in tha range [41,49]. we can reuse them in the hope of minimizing the number
 * of calls to rand7()
 * */
int rand10_02(){
    int a=0, b=0, idx=0;
    while(1){
        a = rand7();
        b = rand7();
        idx = b + (a-1)*7;
        if(idx <= 40)
          return 1 + (idx-1)%10;
        a = idx-40;       //[1,9]
        b = rand7();   //[1,7]
        idx = b + (a-1)*7;    //[1,63] uniformly
        if(idx <= 60)
          return 1 + (idx-1)%10;
        a = idx-60;        //[1,3] uniformly
        b = rand7();    //[1,7]
        idx = b + (a-1)*7;    //[1,21] uniformly
        if(idx <= 20)    //get uniform range of [1,20]
          return 1 + (idx-1)%10;
    }
}

int main(int, char**){
    return 0;
}
