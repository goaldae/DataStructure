#include <stdio.h>

void move(char from, char to) {
	printf("%c %c\n", from, to);
}

void hanoi(int n, char from, char by, char to) {
	if (n == 1)
		move(from, to);
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void) {
	int i;

	if (scanf("%d", &i)) {};

	hanoi(i, 'A', 'B', 'C');

	return 0;
}
