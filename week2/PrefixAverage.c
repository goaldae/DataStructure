#include<stdio.h>
#include <math.h>

void prefix1(int n, int arr[]){
	float res = 0;
	int total = 0;
	for(int j = 0; j<n; j++){
		for(int i = 0; i<=j; i++){
			total += arr[i];
		}

		res = (float)total/(j+1);

		res = roundf(res);
		
		printf("%d ", (int)res);
 
		total = 0;
	}
	printf("\n");
}

void prefix2(int n, int arr[]){
	int total=0;
	float res=0;
	for(int j = 0; j<n; j++){
		total += arr[j];
		res = (float)total/(j+1);
		res = roundf(res);
		printf("%d ", (int)res);		
	}		
	printf("\n");
}


int main(){
	int n;
	if(scanf("%d", &n)){};
	int arr[n];
	
	for(int i = 0; i<n; i++){
		if(scanf("%d", &arr[i])){};
	}
		
	prefix1(n, arr);
	prefix2(n, arr);
		
	return 0;
}
