#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,min,j,sum;
    scanf("%d",&n);
    int AT[n],BT[n],WT[n],TAT[n],CT[n],burst=0,k=1,ta;
    for(int i=0;i<n;i++){
        scanf("%d",&AT[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&BT[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
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
        burst+=BT[i];
        min=BT[k];
        for(j=k;j<n;j++){
            if(AT[i]<=burst && BT[i]<min){
                int temp;
                temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;
                int temp;
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
            }
        }
        k++;
        }
    WT[0]=0;
    for(int i=1;i<n;i++){
        sum+=BT[i-1];
        WT[i]=sum-AT[i];
    }
    for(int i=0;i<n;i++){
        ta=ta+BT[i];
        TAT[i]=ta-BT[i];
    }
}
