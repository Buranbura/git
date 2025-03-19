#include <stdio.h>
#include <stdlib.h>

int main() {
int i, j, blanknum, charnum;
for (i = 1; i <= 9; i++) {
if (i <= 5) {
blanknum = i - 1;
charnum = 11 - 2 * i;
}
else {
blanknum = 9 - i;
charnum = 2 * i - 9;
}
for (j = 1; j <= blanknum; j++)
putchar(' ');
for (j = 1; j <= charnum; j++)
putchar('*');
putchar('\n');
}
return 0;
}
