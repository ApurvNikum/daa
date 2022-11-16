#include<bits/stdc++.h>
using namespace std;
struct Data{
int profit, weight;
};
bool compare(Data a, Data b){
return ((float)a.profit/(float)a.weight) > ((float)b.profit/(float)b.weight);
}
float fractionalKnapsack(Data d[], float maxWeight, int n){
float profit = 0; sort(d, d+n, compare); for(int
i=0;i<n;i++){ if(d[i].weight<=maxWeight){
maxWeight -= d[i].weight;
profit += d[i].profit;
}
else{
profit += d[i].profit*(maxWeight/d[i].weight);
break;
}
}
return profit;
}
int main(){ int n
= 3, W = 50;
Data d[n] = {{60,10},{80,20},{100,40}};
cout<<"Maximum Profit is: "<<fractionalKnapsack(d, W, n);
return 0;
}
