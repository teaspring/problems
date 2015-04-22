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
}

