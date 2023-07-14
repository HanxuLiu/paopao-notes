/*================================================================
*  Author: liu-paopao
*  Date: 2023-07-10
*  Description: 
================================================================*/

#include <stdio.h>

#define DEBUG(fmt, ...) \
	printf("%s:%d, %s" "---->" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
	printf("File: %s\n", __FILE__); \
	printf("Line: %d\n", __LINE__); \
	printf("Func: %s\n", __func__)

int main() {
	int a = 1;
	DEBUG();
	DEBUG("error occurs!");
	DEBUG("a = %d", a);
	return 0;

}
