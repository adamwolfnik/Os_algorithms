#include <stdio.h>
int n;
struct process{
    int id, WT, AT, BT, TAT, PR, PT;
};
struct process a[10];

void swap(int *b, int *c){
    int tem;
    tem = *c;
    *c = *b;
    *b = tem;
}

void non_preemptive(){
    int check_ar = 0;
    int Cmp_time = 0;
    float Total_WT = 0, Total_TAT = 0, Avg_WT, Avg_TAT;
    
    for (int i=0; i<n; i++){
        scanf("%d", &a[i].AT);
        a[i].id = i+1;
        if(i==0)
            check_ar = a[i].AT;
        
        if (check_ar != a[i].AT)
            check_ar = 1;
    }
    
    for (int i=0; i<n; i++){
        scanf("%d", &a[i].PR);
        a[i].id = i+1;
    }
    
    for (int i=0; i<n; i++){
        scanf("%d", &a[i].BT);
        a[i].id = i+1;
    }
    
    if (check_ar != 0){
        for (int i=0; i<n; i++){
            for (int j=0; j<n-i-1; j++){
                if (a[j].AT > a[j+1].AT){
                    swap(&a[j].id, &a[j+1].id);
                    swap(&a[j].AT, &a[j+1].AT);
                    swap(&a[j].BT, &a[j+1].BT);
                    swap(&a[j].PR, &a[j+1].PR);
                }
            }
        }
    }
    
    if (check_ar != 0){
        a[0].WT = a[0].AT;
        a[0].TAT = a[0].BT - a[0].AT;
        Cmp_time = a[0].TAT;
        Total_WT = Total_WT + a[0].WT;
        Total_TAT = Total_TAT + a[0].TAT;
        
        for (int i=1; i<n; i++){
            int min = a[i].PR;
            for (int j=i+1; j<n; j++){
                if (min > a[j].PR && a[j].AT <= Cmp_time){
                    min = a[j].PR;
                    swap(&a[i].id, &a[j].id);
                    swap(&a[i].AT, &a[j].AT);
                    swap(&a[i].BT, &a[j].BT);
                    swap(&a[i].PR, &a[j].PR);
                }
            }
            a[i].WT = Cmp_time - a[i].AT;
            Total_WT = Total_WT + a[i].WT;
            Cmp_time = Cmp_time + a[i].BT;
            a[i].TAT = Cmp_time - a[i].AT;
            Total_TAT = Total_TAT + a[i].TAT; 
        }
    }
    
    else{
        for (int i=0; i<n; i++){
            int min = a[i].PR;
            for (int j=i+1; j<n; j++){
                if (min > a[j].PR && a[j].AT <= Cmp_time){
                    min = a[j].PR;
                    swap(&a[i].id, &a[j].id);
                    swap(&a[i].AT, &a[j].AT);
                    swap(&a[i].BT, &a[j].BT);
                    swap(&a[i].PR, &a[j].PR);
                    
                }
            }
            a[i].WT = Cmp_time - a[i].AT;
            Cmp_time = Cmp_time + a[i].BT;
            a[i].TAT = Cmp_time - a[i].BT;
            Total_WT = Total_WT + a[i].WT;
            Total_TAT = Total_TAT + a[i].TAT;
        }
    }
    
    Avg_WT = Total_WT / n;
    Avg_TAT = Total_TAT / n;
    printf("%0.1f %0.1f", Avg_WT, Avg_TAT);
}

void preemptive(){
    int temp[10], t, count=0, short_p;
    float total_WT=0, total_TAT=0, Avg_WT, Avg_TAT;
    for (int i=0; i<n; i++){
        scanf("%d", &a[i].AT);
    }
    
    for (int i=0; i<n; i++){
        scanf("%d", &a[i].PT);
    } 
    
    for (int i=0; i<n; i++){
        scanf("%d", &a[i].BT);
        temp[i] = a[i].BT;
    }
    a[9].PT = 10000;
    
    for (t=0; count!=n; t++){
        short_p = 9;
        for (int i=0; i<n; i++){
            if (a[short_p].PT>a[i].PT && a[i].AT <= t && a[i].BT>0){
                short_p = i;
            }
        }
        
        a[short_p].BT = a[short_p].BT - 1;
        if (a[short_p].BT == 0){
            count++;
            a[short_p].WT = t+1-a[short_p].AT - temp[short_p];
            a[short_p].TAT = t+1-a[short_p].AT;
            total_WT = total_WT + a[short_p].WT;
            total_TAT = total_TAT + a[short_p].TAT;
        }
    }
    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;
    printf("%0.1f %0.1f", Avg_WT, Avg_WT);
}

int main(){
    int ch;
    scanf("%d %d", &ch, &n);
    switch(ch){
        case 1: non_preemptive();
                break;
        case 2: preemptive();
                break;
    }
    return 0;
}