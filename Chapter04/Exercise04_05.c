/*
 * Exercise04_05.c
 *
 *  Created on: Aug 1, 2019
 *      Author: andrew
 */
#include <stdio.h>

int main(void) {
	const float BITS_PER_BYTE = 8;
	float download_speed, file_size;
	printf("Enter the download speed in megabits per second (Mbs): ");
	fflush(stdout);
	scanf("%f", &download_speed);
	printf("Enter the size of a file in megabytes (MB): ");
	fflush(stdout);
	scanf("%f", &file_size);
	printf("At %0.2f megabits per second, a file of %0.2f megabytes downloads in %0.2f seconds.\n",
			download_speed, file_size, file_size * BITS_PER_BYTE / download_speed);
	return 0;
}
