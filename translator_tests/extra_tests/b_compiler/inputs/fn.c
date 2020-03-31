int sub(int i, int j, int k);

int fmain() {
    return sub(3,2,1);
}

int sub(int i, int j, int k) {
    i -= j;
    i -= k;
    return i;
}