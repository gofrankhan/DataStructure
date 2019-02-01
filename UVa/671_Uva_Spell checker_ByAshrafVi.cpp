#include<stdio.h>

char dict[10001][16], ch;
int T, N;
 
int search(char word[]){
    int i, j;
    for (i=0; i<N; i++) {
         for (j=0; word[j] && dict[i][j] && word[j]==dict[i][j]; j++);
         if (word[j]=='\0' && dict[i][j]=='\0')
             return 1;
    }
    return 0;
}

int match(int n, char word[]){
    int i, j;
    i = 0;
    while(word[i] && dict[n][i] && word[i]==dict[n][i]) i++;
    j = i;
	while(word[j+1] && dict[n][j] && word[j+1]==dict[n][j]) j++;
    if (word[j+1]=='\0' && dict[n][j]=='\0')
         return 1;
    j = i + 1;
    while(word[j] && dict[n][j] && word[j]==dict[n][j]) j++;
    if (word[j]=='\0' && dict[n][j]=='\0')
         return 1;
    j = i;
    while(word[j] && dict[n][j+1] && word[j]==dict[n][j+1]) j++;
    if (word[j]=='\0' && dict[n][j+1]=='\0')
         return 1;
    return 0;
}

 

int main(){
    char word[16];
    int i;
    scanf("%d", &T);
	while(T--){
         N = 0;
		 ch = getchar();
         while (1==scanf("%s", dict[N]) && dict[N][0]!='#') N++;
         while (1==scanf("%s", word) && word[0]!='#') {
             printf("%s", word);
             if (search(word))
                 printf(" is correct\n");
             else {
                 printf(":");
                 for (i=0; i<N; i++) if (match(i, word))
                      printf(" %s", dict[i]);
                 printf("\n");
             }
         }
		 if (T)
			 printf("\n");
	}
    return 0;
}
