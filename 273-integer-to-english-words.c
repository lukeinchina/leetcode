#include <stdio.h>
#include <stdlib.h>

int count_digit(int n) {
    int count = 0;
    while (0 != n) {
        count++;
        n /= 10;
    }
    return count;
}

int cell_to_words(int n, char *dst, int size) {
    static const char *singles[] = {"ERROR", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    static const char *tens[]    = {"ERROR", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    static const char *teens[]   = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    int offset = 0;

    while (n > 0) {
        if (offset > 0) {
            dst[offset++] = ' ';
        }

        if (n >= 100) {
            offset = snprintf(dst, size, "%s Hundred", singles[n / 100]);
            n %= 100;
        } else if (n >= 20) {
            offset += snprintf(dst+offset, size - offset, "%s", tens[n / 10]);
            n %= 10;
        } else if (n >= 10) {
            offset += snprintf(dst+offset, size - offset, "%s", teens[n - 10]);
            break;
        } else {
            offset += snprintf(dst+offset, size - offset, "%s", singles[n]);
            break;
        }
    }
    return offset;
}

char * numberToWords(int num){
    int ndigit, size, offset = 0;
    char *dst = NULL;
    size = 256;
    dst = (char *)malloc(size);

    while (num > 0) {
        if (offset > 0) {
            dst[offset++] = ' ';
        }
        ndigit = count_digit(num);
        if (ndigit > 9) {
            offset += cell_to_words(num / 1000000000, dst + offset, size - offset);
            offset += snprintf(dst + offset, size - offset, " Billion");
            num %= 1000000000;
        } else if (ndigit > 6) {
            offset += cell_to_words(num / 1000000, dst + offset, size - offset);
            offset += snprintf(dst + offset, size - offset, " Million");
            num %= 1000000;
        } else if (ndigit > 3) {
            offset += cell_to_words(num / 1000, dst + offset, size - offset);
            offset += snprintf(dst + offset, size - offset, " Thousand");
            num %= 1000;
        } else {
            offset += cell_to_words(num, dst + offset, size - offset);
            break;
        }
    }

    if (0 == offset && 0 == num) {
        snprintf(dst, size, "Zero");
    }

    return dst;
}

int
main(int argc, char *argv[]) {
    int n = 0;
    char *str = NULL;
    if (argc < 2) {
        printf("suage:%s n\n", argv[0]);
        return -1;
    }
    n = atoi(argv[1]);
    str = numberToWords(n);
    printf("%s\n", str);
    return 0;
}
