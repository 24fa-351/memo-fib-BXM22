#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long long memo[10000];

void fib_memo() {
    for (int i = 0; i < 1000; i++) {memo[i] = -1;}
}
unsigned long long recursive_fib(unsigned long long n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = recursive_fib(n - 1) + recursive_fib(n - 2);
    return memo[n];
}
unsigned long long iterative_fib(unsigned long long int n) {
    if (n == 1) return 0; //shifts the n back by 1
    if (n == 2) return 1;
    int a = 0, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char *argv[]) { 
   fib_memo(); //initialize memo
   if (argc != 3) {  
      printf("Usage: %s <integer> <r|i>\n", argv[0]); 
      return 1;
   }
   //Get the arguments
   unsigned int long long num1 = atoi(argv[1]);
   char mode = argv[2][0];
   
   unsigned long long int fib = num1;

   //determine modes
   if (mode == 'r') {
      fib = recursive_fib(fib);
   } else if (mode == 'i') {
      fib = iterative_fib(fib);
   } else {
      printf("Error: Invalid mode\n");
      return 1;
   }
   printf("%llu", fib); //Result
   return 0;
}