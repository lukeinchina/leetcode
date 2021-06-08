#include <stdio.h>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int x1, x2, y1, y2;
    int and_area = 0;
    x1 = (ax1 >= bx1 ? ax1 : bx1);
    x2 = (ax2 >= bx2 ? bx2 : ax2);
    y1 = (ay1 >= by1 ? ay1 : by1);
    y2 = (ay2 >= by2 ? by2 : ay2);
    if (x2 <= x1 || y2 <= y1) {
        and_area =  0;
    } else {
        and_area =  (x2 - x1) * (y2 - y1);
    }
    return (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1) - and_area;
}
