#include <stdio.h>

int main(){
	int Max[10][10], Allocation[10][10], Need[10][10], Available[10], Work[10], Finish[10], SafeSeq[10];
	int p,r,i,j,found;
	int count = 0;
	
	printf("Enter Number of Processes : ");
	scanf("%d",&p);

	printf("Enter Number of Resources : ");
	scanf("%d",&r);

	printf("\nEnter Maximum Resource Matrix : \n");
	for(i=0; i<p; i++){
		printf("Process P%d : ",i+1);
		for(j=0; j<r; j++)
			scanf("%d",&Max[i][j]);
	}	
	
	printf("\nEnter Allocation Matrix : \n");
	for(i=0; i<p; i++){
		printf("Process P%d : ",i+1);
		for(j=0; j<r; j++)
			scanf("%d",&Allocation[i][j]);
	}

	for(i=0; i<p; i++)
		for(j=0; j<r; j++)
			Need[i][j] = Max[i][j] - Allocation[i][j];

	printf("\nEnter Available Resources : ");
	for(j=0; j<r; j++){
		scanf("%d", &Available[j]);
		Work[j] = Available[j];
	}

	for(i=0; i<p; i++)
		Finish[i] = 0;

	while(count < p){
		found = 0;
		for(i=0; i<p; i++){
			if(Finish[i] == 0){
				int possible = 1;
				for(j=0; j<r; j++){
					if(Need[i][j] > Work[j]){
						possible = 0;
						break;
					}
				}
				if(possible){
					printf("\nProcess P%d can execute.",i+1);
					for(j=0; j<r; j++)
						Work[j] = Work[j] + Allocation[i][j];
					SafeSeq[count] = i+1;
					count++;
					Finish[i] = 1;
					found = 1;
				}	
			}
		}
		if(found == 0)
			break;
	}

	if(count == p){
		printf("\n\nSystem is in a SAFE state.");
		printf("\nSafe Sequence : ");
		for(i=0; i<p; i++){
			printf("P%d",SafeSeq[i]);
			if(i != p-1)
				printf(" -> ");
		}
		printf("\n");
	}
	else
		printf("\n\nSystem is in an UNSAFE state.");
	return 0;
}
