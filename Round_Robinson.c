#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
struct process_struct
{
    int pid,AT,BT,CT,WT,TAT,RT,ST,BT_REM;
}Process[100];
    int find_Max(int m,int n){
        return m>n ? m:n;
    }
    int comp_AT(const void*a,const void *b){
        int x=((struct process_struct*)a)->AT;
        int y=((struct process_struct*)b)->AT;
        if(x<y)
        return -1;
        else if(x>=y)
        return 1;
     }
    int comp_PID(const void *a,const void *b){
        int x=((struct process_struct*)a)->pid;
        int y=((struct process_struct*)b)->pid;
        if(x<y)
        return -1;
        else if(x>=y)
        return 1;
    }
int main(){
    int n,index;
    int cpu_util;
    bool visit[100]={false},first_process=true;
    int curr_time=0,maxcom_time;
    int c=0,TQ,ID=0,cycle;
    scanf("%d",&n);
    int queue[100],front= -1,rear= -1;
    float sum_tat=0,sum_wt=0,sum_rt=0;
    scanf("%d",&TQ);
    for(int i=0;i<n;i++){
        scanf("%d",&Process[i].AT);
        Process[i].pid=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&Process[i].BT);
        Process[i].BT_REM=Process[i].BT;
    }
    qsort((void*)Process,n,sizeof(struct process_struct),comp_AT);
    front=rear=0;
    queue[rear]=0;
    visit[0]=true;
    while(c!=n){
        index=queue[front];
        front++;
        if(Process[index].BT_REM==Process[index].BT){
        Process[index].ST=find_Max(curr_time,Process[index].AT);
        ID+=(first_process==true)?0:Process[index].ST-curr_time;
        curr_time=Process[index].ST;
        first_process=false;
        }
        if(Process[index].BT_REM-TQ>0){
            Process[index].BT_REM-=TQ;
            curr_time+=TQ;
        }
        else{
            curr_time+=Process[index].BT_REM;
            Process[index].BT_REM=0;
            c++;
            Process[index].CT=curr_time;
            Process[index].TAT=Process[index].CT-Process[index].AT;
            Process[index].WT=Process[index].TAT-Process[index].BT;
            Process[index].RT=Process[index].ST-Process[index].AT;
            sum_tat+=Process[index].TAT;
            sum_wt+=Process[index].WT;
            sum_rt+=Process[index].RT;
        }
        for(int i=1;i<n;i++){
            if(Process[i].BT_REM>0 && Process[i].AT<=curr_time && visit[i]==false){
                queue[++rear]=i;
                visit[i]=true;
            }
        }
        if(Process[index].BT_REM>0){
            queue[++rear]=index;
        }
        if(front>rear){
            for(int i=1;i<n;i++){
                if(Process[i].BT_REM>0){
                    queue[rear++]=i;
                    visit[i]=true;
                    break;
                }
            }
        }
    }
    maxcom_time=INT_MIN;
    for(int i=0;i<n;i++){
        qsort((void*)Process,n,sizeof(struct process_struct),comp_PID);
        printf("%d ",Process[i].WT);
    }
    printf("%.2f %.2f",(float)sum_wt/n,(float)sum_tat/n);
    return 0;
}