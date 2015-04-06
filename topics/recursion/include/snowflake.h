/*
 * *******************<DataStructure&AlgorithmInC++> chapter5 recursion*********************
 * non-tail recursion
 * von Koch snowflake, constructed via recursion idealy
 *
 * code not ready due to lack of "graphics.h" of Turbo C
 * */
#include <iostream>
#include <graphics.h>
#include <math>

class RecursiveCurve{
    public:
        RecursiveCurve();
        void readInitValues();
        void snowflake();
    private:
        double side, angle;
        int level;
        void right(double x){
            angle += x;
        }
        void left(double x){
            angle -= x;
        }
        void drawFourLines(double side, int level);
};

void RecursiveCurve::RecursiveCurve(){
    setcolor(WHITE);
    setbkcolor(BLUE);
    moveto(200,150);
    angle = 0.0;
    cout << "Enter side and level: ";
    cin >> side >> level;
}

void RecursiveCurve::drawFourLines(double side, int level){
    if(level == 0){
      linerel((cos(angle * M_PI/180) * side),
              (sin(angle * M_PI/180) * side));
    }else{
        drawFourLines(side/3.0, level-1);
        left(60);
        drawFourLines(side/3.0, level-1);

        right(120);
        drawFourLines(side/3.0, level-1);
        left(60);
        drawFourLines(side/3.0, level-1);
    }
}

void RecursiveCurve::snowflake(){
    for(int i=1; i<=3; i++){
        drawFourLines(side, level);
        right(120);
    }
}

static void runSnowFlake(){
    int grBoard = DETECT, grMode, grResult, grError;
    initgraph(&grBoard, &grMode, "~\\tmp\\bgi");
    grError = graphresult();
    if(grError != grOK){
        cerr << "error: " << grapherrormsg(grError) << endl;
        return;
    }
    RecursiveCurve curve;
    curve.snowflake();
}
