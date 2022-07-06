#include<bits/stdc++.h>
using namespace std;
int w[9]={0,1,11,21,23,33,43,45,55};
int p[9]={0,11,21,31,33,43,53,55,65};
int y[9],x[9],fp=-1,fw;
int m=110;
int n=8;
void show()
{
float s=0.0;
cout<<"\n\tItem\tWeight\tCost\tSelected";
for(int i=1;i<9;i++)
printf("\n\t%d\t%d\t%d\t%d",i+1,w[i],p[i],x[i]);
printf("\n\n The Sack holds these items : ");
for(int i=1;i<9;i++){
if(x[i]==1)
{
cout<<i+1<<"     ";
s += (float) p[i] * (float) x[i];
}
}
printf("\n Maximum Profit: %f ",s);
}
/* compute profit and weight  */
float bound(float cp,float cw,int k)
{
float b = cp;
float c = cw;
for(int i=k+1;i<=n;i++)
{
c = c+w[i];
if( c < m)
b = b +p[i];
else
return (b+(1-(c-m)/ (float)w[i])*p[i]);
}
return b;
}
// start for choosing items
void knapsack(int k,float cp,float cw)
{
if(cw+w[k] <= m)
{
y[k] = 1;
if(k < n)
knapsack(k+1,cp+p[k],cw+w[k]);
if(((cp+p[k]) > fp) && ( k == n))
{
fp = cp+p[k];
fw = cw+w[k];
for(int j=1;j<=k;j++)
x[j] = y[j];
}
}
if(bound(cp,cw,k) >= fp)
{
y[k] = 0;
if( k < n)
knapsack(k+1,cp,cw);
if((cp > fp) && (k == n))
{
fp = cp;
fw = cw;
for(int j=1;j<=k;j++)
x[j] = y[j];
}
}
}
int main()
{
knapsack(1,0.0,0.0);
show();
return 0;
}
