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
	//���κ�
	while (1) {
		i = posY;
		j = posX;

		while (1) {
			arr[i][j] = num;
			num++;

			if (j <= 0) { //���� ��������
				break;
			}
			j--;
			i++;
		}

		if (i >= m - 1) { //���κ� ��ü ���� ����
			break;
		}

		if (posX >= n - 1) { //x�� ���� �ٴٶ�����
			posY++; // y���� ������ ����
		}
		else {
			posX++; //���� ���� �ʾ�����  x�� ��� ������
		}
	}

	if (posX >= n - 1) { //x�� ���� �ٴٶ�����
		posY++; // y���� ������ ����
	}
	else {
		posX++; //���� ���� �ʾ�����  x�� ��� ������
	}
	//�Ʒ��κ�
	while (1) {
		i = posY;
		j = posX;

		while (1) {
			arr[i][j] = num;
			num++;

			if (i >= m - 1) { //���� ��������
				break;
			}
			j--;
			i++;
		}

		if (j >= n - 1) { //���κ� ��ü ���� ����
			break;
		}

		if (posX >= n - 1) { //x�� ���� �ٴٶ�����
			posY++; // y���� ������ ����
		}
		else {
			posX++; //���� ���� �ʾ�����  x�� ��� ������
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