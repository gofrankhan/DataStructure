#include<iostream>

using namespace std;

int Index, bin[1010], position, ans, TC;
int i, j;

void DeciToBin(int n)
{
    for (i=31; i>0 && ((n>>i)&1) == 0; i--);
    for(; i>=0;i--)
        bin[Index++]=((n>>i)&1);
    //cout<<n<<" "<<Index-1<<endl;
}

void solvCase()
{
    ans=0;
    for(i=0; i<5; i++)
        ans=(ans*2)+bin[position+i];
}

int main()
{
	Index=1;
	for(j=1; Index<=1010; j++)
        DeciToBin(j);
	for(TC=1; TC<=10; TC++)
    {
        cin>>position;
        cout<<"#"<<TC<<" ";
        solvCase();
        cout<<ans<<"\n";
    }
	return 0;
}
/*
1
#1 27
6
#2 18
37
#3 13
94
#4 12
95
#5 25
186
#6 19
356
#7 8
476
#8 21
999
#9 18
1000
#10 4

*/
