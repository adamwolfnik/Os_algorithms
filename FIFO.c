#include <stdio.h>
#include <stdlib.h>

int main(){
	int pages,frame,i,j,s,pageFault;
	scanf("%d",&pages);
	scanf("%d",&frame);
	int seq[pages];
	int temp[frame];
	for(i=0;i<pages;i++){
		scanf("%d",&seq[i]);
	}
	for(i=0;i<frame;i++){
		temp[i]=-1;
	}

	for(i=0;i<pages;i++){
		s=0;
		for(j=0;j<frame;j++){
			if(seq[i]==temp[j]){
				s++;
				pageFault--;
			}
		}
		pageFault++;
		if((pageFault<=frame)&(s==0)){
			temp[m]=seq[m];
		}
		else if(s==0){
			temp[(pageFault-1)%frame]=seq[i];
		}
	}
}