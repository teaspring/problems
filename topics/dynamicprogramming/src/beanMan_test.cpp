/*
 * test code for beanMan
 * */
void runBeanMan(int pool[Rows][Columns]){
    int Prev[Rows][Columns];
    memset(Prev, 0, sizeof(Prev));

    int destR = Rows-1;
    int destC = Columns -1;
    int srcR = 0;
    int srcC = 0;
    int har = beanMan(pool, Prev, srcR, srcC, destR, destC);
        
    cout << "The best path is: " <<endl; 
    trace(Prev, srcR, srcC, destR, destC);
    cout << endl;
    cout << "I can eat most beans of "<< har << endl<< "**************************"<< endl ;    
}

void test_01(){
    int BeanPool1[Rows][Columns] ={
        {1, 0, 1, 0, 0, 1}, 
        {1, 0, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 0}
    }; 
    
    int BeanPool2[Rows][Columns]={
        {0,1,0,0,0,0},
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,1,1,0},
        {0,0,0,0,1,0},
        {1,0,1,0,0,1}
    };

    int BeanPool3[Rows][Columns] ={
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 0, 0}
    }; 

    int BeanPool4[Rows][Columns] ={
        {0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0}
    }; 
     
    runBeanMan(BeanPool1);
    runBeanMan(BeanPool2);
    runBeanMan(BeanPool3);
    runBeanMan(BeanPool4);
}

void runBeanMan_02(int pool[Rows][Columns]){
    int prev[Rows][Columns];
    memset(prev, 0, sizeof(prev));
    
    int beginR = 0;
    int beginC = 0;
    int destR = Rows - 1;
    int destC = Columns -1;
    beanMan2(pool, prev, beginR, beginC, destR, destC);
}

void test_02(){
    int BeanPool1[Rows][Columns] ={
        {1, 0, 1, 0, 0, 1}, 
        {1, 0, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 0}
    }; 
        
    int BeanPool2[Rows][Columns]={
        {0,1,0,0,0,0},
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,1,1,0},
        {0,0,0,0,1,0},
        {1,0,1,0,0,1}
    };
    
    int BeanPool3[Rows][Columns]={
        {0,1,0,1,0,0},
        {1,1,0,0,1,0},
        {1,0,1,1,0,0},
        {0,0,1,1,0,0},
        {0,0,0,0,1,0},
        {0,0,1,1,0,0}
    };

    int BeanPool4[Rows][Columns]={
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,1,1},
        {0,0,0,1,0,1},
        {0,0,0,1,1,0}
    };
    
    runBeanMan_02(BeanPool1, dbmp);
    runBeanMan_02(BeanPool2, dbmp);
    runBeanMan_02(BeanPool3, dbmp);
    runBeanMan_02(BeanPool4, dbmp);
}

int main(int, char**){
    test_01();
    //test_02();
}

