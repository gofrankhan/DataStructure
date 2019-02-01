#include<stdio.h>

#define SIZE1 51
#define SIZE2 101

int X, Y;
char Direction[3], D;
int Cx, Cy;
char Instruction[SIZE2];
int Robot[SIZE1][SIZE1];
int Valid;

void readCase()
{
    scanf("%s", Instruction);
}

void initRobot()
{
    int i, j;
    for (i=0; i<=X; i++) for (j=0; j<=Y; j++)
	Robot[i][j] = 0;
}

int isValidPosition()
{
    if (Cx < 0 || Cx > X || Cy < 0 || Cy > Y)
         return 0;
    return 1;
}

void moveForward()
{
    switch(D) {
         case 'N': Cy++; break;
         case 'E': Cx++; break;
         case 'W': Cx--; break;
         case 'S': Cy--; break;
    }
}

void moveBackward()
{
    switch(D) {
         case 'N': Cy--; break;
         case 'E': Cx--; break;
         case 'W': Cx++; break;
         case 'S': Cy++; break;
    }
}

void turnRight()
{
    switch(D) {
         case 'N': D = 'E'; break;
         case 'E': D = 'S'; break;
         case 'W': D = 'N'; break;
         case 'S': D = 'W'; break;
    }
}

void turnLeft()
{
    switch(D) {
         case 'N': D = 'W'; break;
         case 'E': D = 'N'; break;
         case 'W': D = 'S'; break;
         case 'S': D = 'E'; break;
    }
}

void solveCase()
{
    int i;
    D = Direction[0];
    Valid = 1;
    for (i=0; Instruction[i]; i++) {
         switch (Instruction[i]) {
             case 'R':
                 turnRight();
                 break;
             case 'L':
                 turnLeft();
				 break;
             case 'F':
                 moveForward();
                 break;
         }
         if (!isValidPosition()) {
             moveBackward();
             if (Robot[Cx][Cy])
                 continue;
             Valid = 0;
             Robot[Cx][Cy] = 1;
             break;
         }
    }
}

 

void printCase()
{
    printf("%d %d %c", Cx, Cy, D);
    if (!Valid)
         printf(" LOST");
    printf("\n");
}

int main()
{
    scanf("%d %d", &X, &Y);
	initRobot();
    while (3 == scanf("%d %d %s", &Cx, &Cy, Direction)) {
         readCase();
         solveCase();
         printCase();
    }
    return 0;
}
