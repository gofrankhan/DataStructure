#include<stdio.h>

int K, E;
char word[21][21], sent[21][71];
int freq[21], Case, max;

void readCase()
{
    int i;
    for (i=0; i<K; i++)
         scanf("%s", word[i]);
    getchar();
    for (i=0; i<E; i++)
         gets(sent[i]);
}

int wordComp(char st1[], char st2[]){
    int i;
    for (i=0; st1[i] && st2[i]; i++) {
         if (st1[i] != st2[i])
			return 0;
    }
    if (st1[i])
         return 0;
    if (st2[i])
         return 0;
    return 1;
}

int searchWord(char st[])
{
    int i;
    for (i=0; i<K; i++) {
         if (wordComp(word[i], st))
            return 1;
    }
    return 0;
}

void solveCase()
{
    int i, j, k, len;
    char temp[21];
    max = 0;
    for (i=0; i<E; i++){
         freq[i] = 0;
         for (len=0; sent[i][len]; len++) ;
         k = 0;
         for (j=0; j<=len; j++) {
             if (sent[i][j] >= 'a' && sent[i][j] <= 'z')
                 temp[k++] = sent[i][j];
			 else if (sent[i][j] >= 'A' && sent[i][j] <= 'Z')
                 temp[k++] = sent[i][j] + 32;
             else {
                 temp[k] = '\0';
                 if (searchWord(temp))
                      freq[i]++;
                 k = 0;
             }
         }
         if (freq[i] > max)
             max = freq[i];
    }
}

void printCase(){
    int i;
    printf("Excuse Set #%d\n", ++Case);
    for (i=0; i<E; i++) if (freq[i] == max)
         printf("%s\n", sent[i]);
    printf("\n");
}

int main()
{
    Case = 0;
    while(2 == scanf("%d %d", &K, &E)) {
         readCase();
         solveCase();
         printCase();
    }
    return 0;
}