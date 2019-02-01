#include<stdio.h>

int L, N;
char sng[21][21], plr[21][21];

void readCase()
{
    int i;
    scanf("%d %d", &L, &N);
    for (i=0; i<L; i++)
         scanf("%s %s", sng[i], plr[i]);
}

int search(char word[]) 
{
    int i, j;
    for (i=0; i<L; i++) {
         for (j=0; word[j] && sng[i][j] && word[j]==sng[i][j]; j++);
         if (word[j]=='\0' && sng[i][j]=='\0')
             return i;
    }
    return -1;
}
 
int isCon(char ch) {
    switch (ch) {
         case 'a':
         case 'e':
         case 'i':
         case 'o':
         case 'u':
             return 0;
         default:
             return 1;
    }
}

void solveCase()
{
    int i, j, index;
    char word[21];
    while(N--) {
         scanf("%s", word);
         index = search(word);
         if (index >= 0)
             printf("%s\n", plr[index]);
		 else {
             for (i=0; word[i]; i++);
             if (i>=2 && isCon(word[i-2]) && word[i-1]=='y') {
                 for (j=0; j<i-1; j++)
                      printf("%c", word[j]);
                 printf("ies\n");
             }
             else if (i>=2 && word[i-1]=='h' && (word[i-2]=='c' || word[i-2]=='s'))
                 printf("%ses\n", word);
             else if (i>=1 && (word[i-1]=='o' || word[i-1]=='s' || word[i-1]=='x'))
                 printf("%ses\n", word);
             else
		         printf("%ss\n", word);
         }
    }
}

int main(){
    readCase();
    solveCase();
	return 0;
}
