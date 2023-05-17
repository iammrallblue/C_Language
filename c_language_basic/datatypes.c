#include <stdio.h> 
#include <stdbool.h> // include for boolean variable

int main(){

char a = 'C';// single character %с
char b[] = "Bro"; // array of characters %5

float c = 3.141592; // 4 bytes (32 bits of precision) 6 - 7 digits %f
double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15 - 16 digits %lf

//bool e = true; // 1 byte (true or false) %d

char f = 'z'; // 1 byte (-128 to +127) %d or %C
// z == 122 in ASCII table
//unsigned char g = 255; // 1 byte (0 to +255) %d or %C

//short int h = 32767;// 2 bytes (-32,768 to +32,767) %d
//unsigned short int i = 65535; // 2 bytes (0 to +65,535) %d

int j = 2147483647; // 4 bytes (-2,147,483, 648 to +2, 147,483, 647) %d
//unsigned int k = 4294967295L; // 4 bytes (0 to +4, 294, 967, 295) %u

//long long int 1 = 9223372036854775807; // 8 bytes (-9 quintillion to +9 quintillion) %1ld
//unsigned long long int m = 18446744073709551615U; // 8 bytes (0 to +18 quintillion) %llu

//printf("%c \n", a); // char 
// printf ("%s \n", b); // character array

printf("%0.3f\n", c); //float  "0.3" to keep 3 digits of decimal
printf("%lf\n", d); // double 

//printf("%d\n", e); // bool
printf("%d\n", f); // char as numeric value

//printf("%d\n", g); // unsigned char as numeric value
//printf (*%d\n", h); // short 

//printf("%d\n", ¡); // unsigned short
// printf("%d\n", i): // int

//printf("%u\n", k); // unsigned int
//printf("%lld\n", l); // long long int
//printf("%llu\n", m); // unsigned long long int

for (int i = 0; i < 256; i++) {
    printf("%d: %c\n", i, i);  // %d, %c print out numbers, and characters
} // print out ASCII table

return 0;
} // main