#include <stdio.h>
#include <math.h>

int bulbSwitch(int n){
    int i,j, m;
    int count, total = (n > 0 ? 1 : 0);
    for (i = 1; i <= n; i++) {
        m = (i >> 1);
        count = 0;
        for (j = 2; j <= m; j++) {
            if (i % j == 0) {
                count++;
            }
        }
        total += (count % 2);
    }
    return total;
}

int bulbSwitch2(int n){
    int i, sum = 0;
    int size = sqrt(n);
    for (i = 1; i <= size; i++) {
        if (i * i <= n) {
            sum += 1;
        }
    }
    return sum;
}


int
main(void) {
    int i = 0;
    for (i = 1; i <= 100; i++) {
        printf("%d\t%d\n", i, bulbSwitch(i));
        printf("%d\t%d\n", i, bulbSwitch2(i));
    }
    return 0;
}
