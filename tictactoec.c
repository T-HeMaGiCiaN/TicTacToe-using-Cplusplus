#include <stdio.h>

int checkdouble(int array[], int a) {
    int ff = 0;
    for (int i = 0; i < 9; i++) {
        if (a == array[i])
            ff = 1;
    }
    return ff;
}

void value(char s[4][4], int a, int t) {
    if (t == 1) {
        if (a == 1) {
            s[0][0] = 'X';
        }
        if (a == 2) {
            s[0][1] = 'X';
        }
        if (a == 3) {
            s[0][2] = 'X';
        }
        if (a == 4) {
            s[1][0] = 'X';
        }
        if (a == 5) {
            s[1][1] = 'X';
        }
        if (a == 6) {
            s[1][2] = 'X';
        }
        if (a == 7) {
            s[2][0] = 'X';
        }
        if (a == 8) {
            s[2][1] = 'X';
        }
        if (a == 9) {
            s[2][2] = 'X';
        }
    }
    if (t == 2) {
        if (a == 1) {
            s[0][0] = 'O';
        }
        if (a == 2) {
            s[0][1] = 'O';
        }
        if (a == 3) {
            s[0][2] = 'O';
        }
        if (a == 4) {
            s[1][0] = 'O';
        }
        if (a == 5) {
            s[1][1] = 'O';
        }
        if (a == 6) {
            s[1][2] = 'O';
        }
        if (a == 7) {
            s[2][0] = 'O';
        }
        if (a == 8) {
            s[2][1] = 'O';
        }
        if (a == 9) {
            s[2][2] = 'O';
        }
    }
}

int check(char s) {
    int x = 0;
    if (s == 'X') {
        printf("Player 1(X) WIN\n");
        x++;
    } else if (s == 'O') {
        printf("Player 2(O) WIN\n");
        x++;
    }
    return x;
}

int tic(char s[4][4]) {
    int c = 0, flag = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2]) {
            c = check(s[i][0]);
            if (c == 1) break;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && c == 0) {
            c = check(s[0][i]);
            if (c == 1) break;
        }
    }
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && c == 0) {
        c = check(s[0][0]);
    }
    if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && c == 0) {
        c = check(s[0][2]);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (s[i][j] == ' ') {
                flag = 1;
            }
        }
    }
    if (flag == 0 && c == 0) {
        printf("DRAW\n");
        c = 1;
    }
    return c;
}

void print(char s[4][4]) {
    for (int i = 0; i < 2; ++i) {
        printf("%c|%c|%c\n", s[i][0], s[i][1], s[i][2]);
        printf("------\n");
    }
    printf("%c|%c|%c\n", s[2][0], s[2][1], s[2][2]);
}
int main() {
    int array[9];
    for (int i = 0; i < 9; i++) {
        array[i] = 0;
    }
    int flag = 0;
    int x = 0;
    char s[4][4];
    s[0][0] = '1';
    s[0][1] = '2';
    s[0][2] = '3';
    s[1][0] = '4';
    s[1][1] = '5';
    s[1][2] = '6';
    s[2][0] = '7';
    s[2][1] = '8';
    s[2][2] = '9';
    printf("USE THE NUMBER MARKED ON BOX TO PUT X OR O ON IT\n");
    printf("Player 1 use X\n");
    printf("Player 2 use O\n");
    print(s);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            s[i][j] = ' ';
        }
    }
    int z = 0;
    while (flag == 0) {
        int t = 1;
        printf("Player 1(X) turn\n");
        printf("Enter the box value:");
        int a;
        scanf("%d", &a);
        while (checkdouble(array, a)) {
            printf("THIS PLACE IS ALREADY OCCUPIED\n");
            printf("ENTER THE UNOCCUPIED SPACE:");
            scanf("%d", &a);
        }
        array[z++] = a;
        printf("\n");
        value(s, a, t);
        print(s);
        flag = tic(s);
        if (flag == 1) {
            break;
        }
        t++;
        printf("Player 2(O) turn\n");
        printf("Enter the box value:");
        scanf("%d", &a);
        while (checkdouble(array, a)) {
            printf("THIS PLACE IS ALREADY OCCUPIED\n");
            printf("ENTER THE UNOCCUPIED SPACE:");
            scanf("%d", &a);
        }
        array[z++] = a;
        printf("\n");
        value(s, a, t);
        print(s);
        flag = tic(s);
    }
    return 0;
}

