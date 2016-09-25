#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while(a != -1){
        printf("%d %d 1\n", a + 1, b + 1);
        printf("%d %d 1\n", b + 1, a + 1);
        scanf("%d %d", &a, &b);
    }
    return 0;
}
