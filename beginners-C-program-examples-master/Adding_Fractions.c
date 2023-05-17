#include <stdio.h>
int main()
{
	/* variable declaration */
	int numerator1, numerator2, denominator1, denominator2, num_result, denom_result;

	/* Read each fraction */
	printf("Please provide the first numerator:\n");
	scanf("%d", &numerator1);
	printf("Please provide the first denominator:\n");
	scanf("%d", &denominator1);
	printf("Please provide the second numerator:\n");
	scanf("%d", &numerator2);
	printf("Please provide the second denominator:\n");
	scanf("%d", &denominator2);

	/*compare the demonators*/
	if (denominator1 == denominator2)
	{
		num_result = numerator1 + numerator2;
		denom_result = denominator1; /*  or 2, they are equal */
	}
	else
	{
		num_result = (numerator1 * denominator2) + (numerator2 * denominator1);
		denom_result = denominator1 * denominator2;
	}
	printf("The result of %d / %d  + %d / %d  is: %d / %d \n", numerator1, denominator1, numerator2, denominator2, num_result, denom_result);
	return 0;
}

// #include <stdio.h>

// int main() {
//   /* Declare variables to store the numerators and denominators of the two fractions */
//   int numerator1, numerator2, denominator1, denominator2, num_result, denom_result;

//   /* Read the first fraction */
//   printf("Please provide the first numerator:\n");

//   /* Use scanf to read the numerator */
//   /* scanf returns the number of items successfully read, so we check if it's equal to 1 */
//   if (scanf("%d", &numerator1) != 1) {
//     /* If scanf returns a value other than 1, it means the input is invalid */
//     printf("Invalid input. Exiting program.\n");
//     return 1;
//   }

//   printf("Please provide the first denominator:\n");

//   /* Use scanf to read the denominator */
//   /* scanf returns the number of items successfully read, so we check if it's equal to 1 */
//   if (scanf("%d", &denominator1) != 1) {
//     /* If scanf returns a value other than 1, it means the input is invalid */
//     printf("Invalid input. Exiting program.\n");
//     return 1;
//   }

//   /* Check if the denominator is zero */
//   if (denominator1 == 0) {
//     /* If the denominator is zero, it's not possible to divide by it */
//     printf("Error: Cannot divide by zero. Exiting program.\n");
//     return 1;
//   }

//   /* Read the second fraction */
//   printf("Please provide the second numerator:\n");

//   /* Use scanf to read the numerator */
//   /* scanf returns the number of items successfully read, so we check if it's equal to 1 */
//   if (scanf("%d", &numerator2) != 1) {
//     /* If scanf returns a value other than 1, it means the input is invalid */
//     printf("Invalid input. Exiting program.\n");
//     return 1;
//   }

//   printf("Please provide the second denominator:\n");

//   /* Use scanf to read the denominator */
//   /* scanf returns the number of items successfully read, so we check if it's equal to 1 */
//   if (scanf("%d", &denominator2) != 1) {
//     /* If scanf returns a value other than 1, it means the input is invalid */
//     printf("Invalid input. Exiting program.\n");
//     return 1;
//   }

//   /* Check if the denominator is zero */
//   if (denominator2 == 0) {
//     /* If the denominator is zero, it's not possible to divide by it */
//     printf("Error: Cannot divide by zero. Exiting program.\n");
//     return 1;
//   }

//   /* Compare the denominators of the two fractions */
//   if (denominator1 == denominator2) {
//     /* If the denominators are equal, we can add the numerators directly */
//     num_result = numerator1 + numerator2;
//     denom_result = denominator1; /*  or 2, they are equal */
//   } else {
//     /* If the denominators are not equal, we need to cross
