#include<stdio.h>

char in[300], out[300], c;
int len, ch;

int main(){
	int index;
	while(c = getchar())
	{ 
		if(c == EOF)
			break;
		len = 0;
		in[len++] = c;
		while(c != '\n'){
			c = getchar();
			in[len++] = c;
		}
		len--;
		index = 0;
		if(in[len-1] <= 57 && in[len-1] >= 48)
		{
			while(len){
				ch = in[--len] - 48;
				ch = ch*10 + in[--len] - 48;
				if(ch < 23)
					ch = ch*10 + in[--len] - 48;
				out[index++] = ch;
			}
			out[index] = '\0';
		}
		else{
			while(len){
				ch = in[--len];
				while(ch){
					out[index++] = ch%10 + 48;
					ch = ch/10;
				}
			}
			out[index] = '\0';
		}
		printf("%s\n",out);
	}
	return 0;
}