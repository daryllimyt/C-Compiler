int y;
int z;
int g(int a) {
    return a+y;
}

int f(int x) {
    g(x);
    return x == y;
}