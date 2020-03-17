int y;
int z;
int g(int a, int b) {
    return a+y;
}

int f(int x) {
    int y = x+3;
    g(x, y);
    return x == y;
}