#include<stdio.h>

int main(){
	int n,AT[10],BT[10];
	int temp;
	int k=1,btime=0;
	int sum=0,ta=0;
	int TAT[10],WT[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&AT[i]);
		scanf("%d",&BT[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]<a[j]){
				temp=AT[i];
				AT[i]=AT[j];
				AT[j]=temp;
				temp=BT[i];
				BT[i]=BT[j];
				BT[j]=temp;
			}
		}
	}
	for(int j=0;j<n;j++){
		btime=btime+BT[i];
		min=BT[k];
		for(int i=k;i<n;i++){
			if(btime>AT[i] && BT[i]<min){
				temp=BT[i];
				BT[i]=BT[j];
				BT[j]=temp;
				temp=AT[i];
				AT[i]=AT[j];
				AT[j]=AT[i];
			}
		}
		k++;
	}
	for(int i=0;i<n;i++){
		printf("Arrival Time:%d \t Burst Time:%d",AT[i],BT[i]);
	}
}