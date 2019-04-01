#include<stdio.h> 
#include<conio.h>
int main() 
{    int i,j,n,time,remain,flag=0,ts; 
     int wait_sum=0,turnaround_sum=0,at[15],bt[15],rt[15]; 
     printf("Enter the no of processes: "); 
     scanf("%d",&n);      //Getting number of processes from user
     remain=n;   
     for(i=0;i<n;i++)
    { printf("Enter  arrival time  for Process P%d :",i+1);   
	  scanf("%d",&at[i]);                                     //Getting arrival time from user
	  printf("Enter  burst time  for Process P%d :",i+1);     
      scanf("%d",&bt[i]);  
	  printf("\n");                                    //getting burst time from user  
      rt[i]=bt[i];          
	  }  
   printf("Enter time slice");   
   scanf("%d",&ts);  
  // remain=ts; 
   printf("\n\nProcess\t|Turnaround time|waiting time\n\n");                          
   for(time=0,i=0;remain!=0;)   
       {     if(rt[i]<=ts && rt[i]>0)     
                 { time=time+rt[i];      
				   rt[i]=0;   
				   flag=1;}     
            else if(rt[i]>0)     
                     { rt[i]=rt[i]-ts;    
					   time=time+ts;}     
            if(rt[i]==0 && flag==1)     
             {  remain--;       
                printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);    
			    wait_sum=(wait_sum)+(time-at[i]-bt[i]);      
                turnaround_sum=(turnaround_sum)+(time-at[i]);       
                flag=0;}    
                if(i==n-1)       
                i=0;   
                else if(at[i+1]<=time)      
                i++;   
                else    
				i=0; }  
printf("\n Average waiting time = %f\n",(wait_sum*1.0)/(n));   
printf("Averag turnaround time = %f \n",(turnaround_sum*1.0)/(n));    
return 0; }

