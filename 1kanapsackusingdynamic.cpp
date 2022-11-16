#include <iostream>
using namespace std;
struct Data{
int profit, weight;
};
int zeroOneKnapsack(Data d[], int n, int maxWeight){
int k[n + 1][maxWeight + 1];
for(int i=0;i<=n;i++){
for(int j=0;j<=maxWeight;j++){
if(i==0||j==0){
k[i][j] = 0;
}
else if(d[i-1].weight<=j){
k[i][j] = max(d[i-1].profit + k[i-1][j-d[i-1].weight], k[i-1][j]);
}
else{
k[i][j] = k[i-1][j];
}
}
}
for(int i=0;i<=n;i++){
for(int j=0;j<=maxWeight;j++){
cout<<k[i][j]<<" ";
}
cout<<endl;
}
cout<<endl;
int i = n, j = maxWeight;
while (i>0 && j>=0){
if (k[i][j] == k[i-1][j]){
cout<<i<<" = 0"<<endl;
i--;
}
else{
cout<<i<<" = 1"<<endl;
i--;
j = j - d[i].weight;
}
}
cout<<endl;
return k[n][maxWeight];
}
int main(){
int n = 4;
Data d[4] = {{3,2},{4,3},{5,4},{6,5}};
int W = 5;
cout <<zeroOneKnapsack(d, n, W);
return 0;
}