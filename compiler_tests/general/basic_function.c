int y;
int z = 1;

int g(int a, int b) {
    return a+y;
}

int f(int x) {
    int y = x+3;
    int a;
    g(x, y);
    return x == y;
}