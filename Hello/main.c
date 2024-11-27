#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double imgCvtGrayIntToDouble(int pixel);

double imgCvtGrayIntToDoubleC(int pixel) {
	double answer = (double) pixel / 255.0;
	return answer;
}
int main() {
	int h, w;
	scanf_s("%d", &h);
	scanf_s("%d", &w);

	int* image = malloc((h * w) * sizeof(int));

	for (int i = 0; i < h * w; i++)
		scanf_s("%d", &image[i]);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			printf("%0.2lf ", imgCvtGrayIntToDouble(image[i * w + j]));
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			printf("%0.2lf ", imgCvtGrayIntToDoubleC(image[i * w + j]));
		printf("\n");
	}

	free(image);
	return 0;
}