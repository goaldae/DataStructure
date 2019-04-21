#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100][100];

int main(void) {
	int posX = 0;
	int posY = 0;
	int i, j;
	int m, n;
	int num = 1;

	scanf("%d %d", &m, &n);
	//윗부분
	while (1) {
		i = posY;
		j = posX;

		while (1) {
			arr[i][j] = num;
			num++;

			if (j <= 0) { //한줄 종료조건
				break;
			}
			j--;
			i++;
		}

		if (i >= m - 1) { //윗부분 전체 종료 조건
			break;
		}

		if (posX >= n - 1) { //x점 끝에 다다랐으면
			posY++; // y점을 내리기 시작
		}
		else {
			posX++; //아직 닿지 않았으면  x점 계속 내리기
		}
	}

	if (posX >= n - 1) { //x점 끝에 다다랐으면
		posY++; // y점을 내리기 시작
	}
	else {
		posX++; //아직 닿지 않았으면  x점 계속 내리기
	}
	//아랫부분
	while (1) {
		i = posY;
		j = posX;

		while (1) {
			arr[i][j] = num;
			num++;

			if (i >= m - 1) { //한줄 종료조건
				break;
			}
			j--;
			i++;
		}

		if (j >= n - 1) { //윗부분 전체 종료 조건
			break;
		}

		if (posX >= n - 1) { //x점 끝에 다다랐으면
			posY++; // y점을 내리기 시작
		}
		else {
			posX++; //아직 닿지 않았으면  x점 계속 내리기
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}