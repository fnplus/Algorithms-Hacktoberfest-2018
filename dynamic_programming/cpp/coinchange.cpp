//coin change
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int coins[]={1, 2, 3},total=4,n=3;

int coinc_mem(int i,int total)//  **has problem**     function to calc total possible combos of coins    gfg      
{
	if(total==0)
	return 1;
	if(total<0)
	return 0;
	if(total>0&&i>=n)
	return 0;
	return coinc_mem(i+1,total)+coinc_mem(i,total-coins[i]);
}

int coinc_tabl()//function to calc total possible combos of coins   gfg
{
	int dp[n][total+1],i=0,j=0;
	for(i=0;i<n;i++)dp[i][0]=0;
	for(i=1;i<=total;i++)dp[0][i]=1;
	for(i=1;i<n;i++)
	for(j=1;j<=total;j++)
	if(i<=j)
	dp[i][j]=j/coins[i]+dp[i-1][j];
	else
	dp[i][j]=dp[i-1][j];
//	for(i=0;i<n;i++)	{
//	for(j=0;j<=total;j++)
//	cout<<dp[i][j]<<" ";
//	cout<<endl;}
	cout<<dp[n-1][total];
}

int coinchange_tabl()//function to calc min no of coins req           tabulation          tushar roy
{
	int n=sizeof(coins)/sizeof(int),i=0,j=0;
	int dp[n][total+1];
	for(i=0;i<n;i++)dp[i][0]=0;
	for(i=1;i<=total;i++)dp[0][i]=i;
	for(i=1;i<n;i++)	
	for(j=1;j<=total;j++)
		dp[i][j]=min(j/coins[i]+dp[i-1][j%coins[i]],dp[i-1][j]);
//	for(i=0;i<n;i++)	{
//	for(j=0;j<=total;j++)
//	cout<<dp[i][j]<<" ";
//	cout<<endl;}
	cout<<dp[n-1][total];
	return 0;
}

int main()
{
	coinchange_tabl();
	cout<<endl<<coinc_mem(0,4);
	cout<<endl;
	coinc_tabl();
	return 0;
}
