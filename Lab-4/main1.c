#include <stdio.h>

int steps = 1;

void Transfer(int n, char from, char to, char temp) {
   if (n == 0) {
      return;
   } else {
      Transfer(n-1, from, temp, to);
      printf("%d. move disk %d from %c to %c\n", steps, n, from, to);
      steps++;
      Transfer(n-1, temp, to, from);
   }
}

int main() {
   int n;
   printf("Enter number of disks: ");
   scanf("%d", &n);
   Transfer(n, 'A', 'C', 'B');
}

