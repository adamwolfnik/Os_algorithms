#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,j;
	scanf("%d",&n);
	int AT[n],BT[n],WT[n],TAT[n],cmpl_t[n],burst=0;
	for(int i=0;i<n;i++){
		scanf("%d",&AT[i]);
	}
	for(int i=0;i<n;i++){
	scanf("%d",&BT[i]);
	}
	for(int i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(AT[i]>AT[j]){
				int temp;
				temp=AT[i];
				AT[i]=AT[j];
				AT[j]=temp;
				temp=BT[i];
				BT[i]=BT[j];
				BT[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(AT[i]>burst)
			burst++;
		if(i==0){
			WT[i]=AT[i];
		}
		else{
			WT[i]=burst-AT[i];
		}
		burst+=BT[i];
		cmpl_t[i]=BT[i];
	}
	for(int i=0;i<n;i++){	
		TAT[i]=cmpl_t[i]-AT[i];
	}
}