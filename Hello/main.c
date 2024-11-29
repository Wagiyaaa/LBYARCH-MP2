#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


extern double imgCvtGrayIntToDouble(int pixel);

double imgCvtGrayIntToDoubleC(int pixel) {
	double answer = (double) pixel / 255.0;
	return answer;
}

int main() {
	int h, w;

	printf("Input the height and width of the image seperated by space: ");
	scanf_s("%d", &h);
	scanf_s("%d", &w);

	int* image = malloc((h * w) * sizeof(int));

	

	if (!image) {
		printf("Failed to Allocate Memory");
		return 0;
	}

	srand((unsigned int)time(NULL));

	printf("Randomly generated pixel values:\n");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			image[i * w + j] = rand() % 256; // Random value between 0 and 255
			printf("%d ", image[i * w + j]); 
		}
		printf("\n");
	}

	/* Commented out since random number generator is used for input
	for (int i = 0; i < h * w; i++)
		scanf_s("%d,", &image[i]);
	*/

	printf("Assembly Conversion: \n");
	clock_t start_time = clock();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			printf("%0.2lf ", imgCvtGrayIntToDouble(image[i * w + j]));
		printf("\n");
	}
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


	printf("C conversion for Checking: \n");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			printf("%0.2lf ", imgCvtGrayIntToDoubleC(image[i * w + j]));
		printf("\n");
	}

	// For Verifying
	int all_match = 1; 

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			double asm_result = imgCvtGrayIntToDouble(image[i * w + j]);
			double c_result = imgCvtGrayIntToDoubleC(image[i * w + j]);

			if ((asm_result - c_result) > 1e-6) { // Used > 1e-6 to ignore if there is a slight difference of 0.0000001
				all_match = 0; // Mismatch found
				break;
			}
		}
		if (!all_match) 
			break;
	}

	if (all_match) {
		printf("\nAll results match!\n");
	}
	else {
		printf("\nMismatch found in results.\n");
	}


	printf("Execution time of ASM function :%0.6lf seconds\n", elapsed_time);
	free(image);
	return 0;
}