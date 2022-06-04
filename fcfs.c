#include<stdio.h>
#include<conio.h>
 int main(){
	 int AT[10],BT[10],CT[10],WT[10],TAT[10];
	 int temp,n,burst=0;
	 int awt,atat;
	 scanf("%d",&n);
	 for(int i=0;i<n;i++){
		 scanf("%d",&AT[i]);
	 }
	 for(int i=0;i<n;i++){
		 scanf("%d",&BT[i]);
	 }
	 for(int i=0;i<n;i++){
		 for(int j=i+1;j<n;j++){
		 if(a[i]>a[j]){
			 temp=a[i];
			 a[i]=a[j];
			 a[j]=temp;
			 temp=b[i];
			 b[i]=b[j];
			 b[j]=temp;
			}
		 }
	 }
	 for(int i=0;i<n;i++){
	 if(burst<A[i]){
		 burst++;
	 }
	 if(i==0){
		 WT[i]=AT[i];
	 }
	 else{
		 WT[i]=burst-AT[i];
	 }
	 burst+=BT[i];
	 CT[i]=burst;
	 }
	 for(int i=0;i<n;i++){
		 TAT[i]=CT[i]-BT[i];
	 }
 }
