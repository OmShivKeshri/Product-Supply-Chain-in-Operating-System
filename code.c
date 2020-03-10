#include <stdio.h>


int current[100][100], maximum_claim[100][100], available[100],current2[100][100]; int allocation[100]; int maxres[100], running[100], safe = 0; int counter = 0, i, j, exec, resources, processes, k = 1; int flag=0,flag2=0; int temp,temp1; int ctr2=0,ctr3=0; void check_safe_state(); int executed_orders[100]; int executed_orders1[100]; int ctr3_temp; int temp3; int flag3=-1;

void output()
 

{
if(flag==0)
{
for(i=0;i<ctr3;i++)
{
printf("Order %d \n",executed_orders[i]);
}
printf("\nAll the orders can be executed in the above order economically without any money overflow.\n");
return;
}
else

{
counter=0; safe=0;	k=1;

for(i=0;i<processes;i++)
{
if(running[i]==1)
{
flag2=1; temp=i; break;
}
}


if(flag2==0)
{	printf("\n\n"); for(i=0;i<ctr3;i++)
{
for(j=0;j<temp3;j++)
 

{
for(k=0;k<resources;k++)
{
 



flag3=temp3; break;

}
if(flag3==-1)
{
 
if(current[i][k]!=current2[j][k])
{



}





printf("Order %d \n",j+1);
 
break;
}	flag3=-1;
}	}	printf("\n");	printf("\nOnly the orders in the above
sequence can be executed economically without any money overflow, rest of the orders must be aborted.\n");	return;
}
for(i=0;i<processes;i++)
{	if(i!=temp)
{
running[i]=1; counter++;
}
}


flag2=0;


for(i=0;i<resources;i++)
{
allocation[i]=0;
 

}


for(i=0;i<processes;i++)
{	if(i!=temp)
{
running[ctr2]=running[i];	ctr2++;
}
}
ctr2=0; for(i=0;i<processes;i++)
{	if(i!=temp)
{
for(j=0;j<resources;j++)
{
current[ctr2][j]=current[i][j];
}	ctr2++;
}
}
ctr2=0; for(i=0;i<processes;i++)
{	if(i!=temp)
{
for(j=0;j<resources;j++)
{
maximum_claim[ctr2][j]=maximum_claim[i][j];
}	ctr2++;
}	}
ctr2=0; ctr3=0; processes--;
 

for(i=0;i<processes; i++)
{
executed_orders[i]=0;
}
check_safe_state();




}
}


void check_safe_state() { for (i = 0; i < processes; i++)
{
for (j = 0; j < resources; j++)
{
allocation[j] += current[i][j];
}
}


for (i = 0; i < resources; i++)
{
available[i] = maxres[i] - allocation[i];
}


while (counter != 0)
{
safe = 0;	for (i = 0; i < processes; i++)
 

{	if
(running[i])
{
exec = 1;	for (j = 0; j
< resources; j++)
{
if (maximum_claim[i][j] - current[i][j] > available[j])
{
 


break;
 
exec = 0;


}
 
}	if
(exec)

{
executed_orders[ctr3]=i+1;
ctr3++; running[i] = 0;
counter--;	safe
= 1;


for (j = 0; j < resources; j++)
{
available[j] += current[i][j];
}
break;
}
}
 
}	if
(!safe)
 



{
flag=1;
 

break;
}
}
output(); }





int main()
{


printf("\nEnter number of orders: ");
scanf("%d", &processes);	temp3=processes;	for(i=0;i<resources;i++)
{
allocation[i]=0;
}


for (i = 0; i < processes; i++)
{
running[i] = 1; counter++;
}
printf("\nEnter number of types of resources: "); scanf("%d", &resources);

printf("\nEnter number of instances of each resource type :\n\n");


for (i = 0; i < resources; i++)
{
printf("\tResource %d : ",i+1);; scanf("%d", &maxres[i]);
}
 


printf("\nEnter number of resources allocated to each order initially :\n\n");	for (i
= 0; i < processes; i++)
{
printf("\tFor Order %d : \n\n",i+1); for(j = 0; j < resources; j++)
{
printf("\t\tResource %d : ",j+1); scanf("%d", &current[i][j]);
current2[i][j]=current[i][j];
}
printf("\n");
}


printf("\nEnter the maximum resources required by every order:\n\n"); for (i = 0; i < processes; i++)
{
printf("\tFor Order %d : \n\n",i+1); for(j = 0; j < resources; j++)
{
printf("\t\tResource %d : ",j+1); scanf("%d", &maximum_claim[i][j]);
}
printf("\n");
}


check_safe_state(); return 0;
}
