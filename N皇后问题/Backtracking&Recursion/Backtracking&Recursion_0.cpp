//
//  main.c
//  Xcode_C_test
//
//  Created by 王译苑 on 2017/3/13.
//  Copyright © 2017年 王译苑. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <sys/timeb.h>

#define N 30

int board[N][N];
int queen[N][2];
int found = 0;
int validState (int row, int col, int currentQueen) {
    int q,currentQ[2];
    for (q=0; q<currentQueen; q++) {
        currentQ[0]=queen[q][0];
        currentQ[1]=queen[q][1];
        if (row==currentQ[0] || col==currentQ[1] || abs(currentQ[0]-row)==abs(currentQ[1]-col)) {
            return 0;
        }
    }
    return 1;
}

int nQ (int currentQueen, int currentCol) {
    if (currentQueen >=N ) {
        return 1;
    }
    
    int row=0;
    while ((row<N)&&(!found)) {
        if (validState (row, currentCol, currentQueen)) {
            queen[currentQueen][0]=row;
            queen[currentQueen][1]=currentCol;
            found=nQ(currentQueen+1, currentCol+1);
            if (found) {
                return 1;
            }
        }
        row++;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    struct timeb  start , end;
    int i;
    int timeuse;
    for (i=0;i<N;i++) {
        queen[i][0]=queen[i][1]=-1;
    }
    
    ftime( &start );
    
    nQ(0, 0);
    
    ftime( &end);
    printf("time: %d ms\n", (end.time-start.time)*1000 + (end.millitm - start.millitm));
    printf("(");
    for (i=0;i<N-1;i++) {
        printf("%d, ",queen[i][0]);
    }
    printf("%d)\n",queen[i][0]);
    return 0;
}







