/* Name: Koichi Nakata  */
/* C Lab #2 - Bitwise 	*/
/* COMSC-142 Fall 2024	*/

#include <stdio.h>

// Prototypes
void xorAB(int, int);
void maxMinInt();
void andNotsAB(int, int);
void displayInBits(int);


int main() {
  int inputA, inputB; 
  printf("Enter two integers as specified in the test cases in the assignment on Canvas. \n");
  scanf("%i", &inputA);
  scanf("%i", &inputB);
  
  printf("You entered two numbers (Integer, Hexadecimal, or Octal) as your input: %1d  %1d \n\n",
         inputA, inputB);
  
  printf("Binary bit patterns of inputA and inputB are: \n");
  displayInBits(inputA);
  displayInBits(inputB);

  xorAB(inputA,inputB);

  andNotsAB(inputA, inputB);

  maxMinInt();
}


/**
 xorAB() demonstrates the ^ operator of two integers
 :param num1: int 
 :param num2: int
 :return: void
**/
void xorAB(int num1, int num2) {
  printf("\n\n>>>>>>>>>> ENTERING xorAB Function \n");
  // ^ operator returns true if the operands are different each other
  int xorResult = (num1 ^ num2); 
  printf("result of XOR bitwise operation (_ ^ _) is %d \n",
         xorResult);
  displayInBits(xorResult);
  printf("\n\n");

}

/**
 andNotAB() demonstrates the ^ operator only using ~ and & operators
 :param num1: int 
 :param num2: int
 :return: void
**/
void andNotsAB(int num1, int num2) {
  printf("\n>>>>>>>>>> ENTERING andNotsAB Function \n");
  // Use Benn diagram to understand this
  int andNotResult = ~(~(~num1 & num2) & ~(num1 & ~num2));

  printf("result of operation using bitwise ~ & is %d \n",
         andNotResult);
  displayInBits(andNotResult);
  printf("\n\n");
}

/**
 maxMinInt() shows the largest positive int and smallest negative int in 32-bit int
 :param void
 :return: void
**/
void maxMinInt() {
  printf(">>>>>>>>>> ENTERING maxMinInt Function \n");

  // we want to use 0u instead of 0 to ensure sign bit is 0
  unsigned int x = ~0u;
  printf("unsigned int x just after ~0u = %d \n", (int)x);
  displayInBits(x);

  unsigned int y = ~0u;
  printf("unsigned int y just after ~0u = %d \n", (int)y); 
  displayInBits(y);	

  // Shifting to the right by 1 will bring 0 to the MSB
  x >>= 1;
  printf("max int x = %d \n", (int)x);
  displayInBits(x);

  // y = ~x can also be used
  y <<= (sizeof(y) * 8) - 1; 
  printf("most negative (min) int y = %d \n", y);
  displayInBits(y);
  
  printf("\n");
}

/**
 displayInBits() displays an int in binary expression
 :param bits: int
 :return: void
**/
void displayInBits(int bits) {
  for (int i = (8 * sizeof(int)) - 1; i >= 0; i--) {
    // sizeof(int) returns 4 bytes in Replit. We want to convert bytes to bits by muptiplying 8
    putchar(bits & (1u << i) ? '1' : '0');
    // We want to use 1u instead of 1 to avoid signed int overflow
  }

  printf("\n");
}
