#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct all{
    int arrival_t;
    int burst_t;
    int completion_t;
    int waiting_t;
    int turn_at;
    int rt_t;
    int start_t;
} processes[50];

int main(){
    float bt_remaining[50];
    bool is_completed[50] = {false}, is_first_process = {true};
    int current_time = 0;
    int completed = 0;
    float sum_tat = 0, sum_wt = 0, prev = 0;
    
    int algorithm;
    int num_process;
    
    scanf("%d", &algorithm);
    scanf("%d", &num_process);
    
    switch(algorithm){
        case(1):
        {
            for (int i =0; i< num_process; i++)
            {
                scanf("%d" , &processes[i].arrival_t);
            }
            for (int i =0; i< num_process; i++)
            {
                scanf("%d" , &processes[i].burst_t);
                bt_remaining[i] = processes[i].burst_t;
            }
            
            // calculating waiting time
            for (int i =1;i < num_process; i++)
                processes[i].waiting_t = processes[i-1].burst_t + processes[i-1].waiting_t;
            
            // function to find turn around time for all processes
            for (int i=0; i< num_process; i++)
                processes[i].turn_at = processes[i].burst_t + processes[i].waiting_t;
                
            // calculate total waiting time and total turn around time
            for (int i = 0; i< num_process; i++){
                sum_wt = sum_wt + processes[i].waiting_t;
                sum_tat = sum_tat + processes[i].turn_at;
            }
            
            printf("%.2f ", sum_wt/num_process);
            printf("%.2f", sum_tat/num_process);
            
            break;
        }
        case(2):
        {
            for(int i =0; i<num_process ; i++)
            {
                scanf("%d" , &processes[i].arrival_t);
            }
            for(int i =0; i<num_process ; i++)
            {
                scanf("%d" , &processes[i].burst_t);
                bt_remaining[i] = processes[i].burst_t;
            }
            while(completed != num_process)
            {
                int min_index = -1;
                int minimum = INT_MAX;
                for(int i =0; i<num_process ; i++)
                {
                    if (processes[i].arrival_t <= current_time && is_completed[i] == false)
                    {
                        if(processes[i].burst_t < minimum)
                        {
                            minimum = processes[i].burst_t;
                            min_index = i;
                        }
                        if (processes[i].burst_t == minimum)
                        {
                            if (processes[i].arrival_t < processes[min_index].arrival_t)
                            {
                                minimum = processes[i].burst_t;
                                min_index = i;
                            }
                        }
                    }
                }if (min_index == -1)
                    current_time++;
                else
                {
                    processes[min_index].start_t = current_time;
                    processes[min_index].completion_t = processes[min_index].start_t + processes[min_index].burst_t;
                    processes[min_index].turn_at = processes[min_index].completion_t - processes[min_index].arrival_t;
                    processes[min_index].waiting_t = processes[min_index].turn_at - processes[min_index].burst_t;
                    
                    sum_tat += processes[min_index].turn_at;
                    sum_wt += processes[min_index].waiting_t;
                    completed++;
                    is_completed[min_index] = true;
                    current_time = processes[min_index].completion_t;
                    prev = current_time;
                    is_first_process = false;
                }
            }
            printf("%.2f " , sum_wt/num_process);
            printf("%.2f" , sum_tat/num_process);
            break;
        case(3):
        {
            for(int i = 0; i< num_process; i++)
            {
                scanf("%d" ,&processes[i].arrival_t);
            }
            for (int i =0; i< num_process; i++)
            {
                scanf("%d" , &processes[i].burst_t);
                bt_remaining[i] = processes[i].burst_t;
            }
            while (completed != num_process)
            {
                int min_index = -1;
                int minimum = INT_MAX;
                for (int i =0; i< num_process; i++)
                {
                    if (processes[i].arrival_t <= current_time && is_completed[i] == false)
                    {
                        if(bt_remaining[i] < minimum)
                        {
                            minimum = bt_remaining[i];
                            min_index = i;
                        }
                        if (bt_remaining[i] == minimum)
                        {
                            if (processes[i].arrival_t < processes[min_index].arrival_t)
                            {
                                minimum =bt_remaining[i];
                                min_index = i;
                            }
                        }
                    }
                }
                if (min_index == -1)
                    current_time++;
                else
                {
                    if(bt_remaining[min_index] == processes[min_index].burst_t)
                    {
                        processes[min_index].start_t = current_time;
                        is_first_process = false;
                    }
                    bt_remaining[min_index] -= 1;
                    current_time++;
                    prev = current_time;
                    if(bt_remaining[min_index] == 0)
                    {
                        processes[min_index].completion_t = current_time;
                        processes[min_index].turn_at = processes[min_index].completion_t - processes[min_index].arrival_t;
                        processes[min_index].waiting_t = processes[min_index].turn_at - processes[min_index].burst_t;
                        sum_wt += processes[min_index].waiting_t;
                        completed++;
                        is_completed[min_index] = true;
                    }
                }
            }   
        }
        printf("%.2f", sum_wt/num_process);
        break;
            
        }
    }
}