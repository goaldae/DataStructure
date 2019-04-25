#include<stdio.h>


int main(){
	int n;
	if(scanf("%d", &n)){};
	
	int k=0;
	int l=0;
	int max=0;
	int arr[n][n];
	
	for(int i = 0; i <n; i++){
		for(int j = 0; j <n; j++){
			if(scanf("%d", &arr[i][j])){};
		}	
	}
	
	
	while(k != (n)){
		if(arr[k][l] == 1){
			l++;			
			max = k;
			if(l>n-1){
				break;
			}
		}else{
			k++;
		}
	}
	
	
	printf("%d\n", max);
	return 0;
}
