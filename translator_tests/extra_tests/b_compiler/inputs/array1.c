// int sub(int i, int j, int k);

int sub(int i, int j, int k) {
    i -= j;
    i -= k;
    return i;
}

int fmain() {
    // int x = 3;
    int arr[3];
    // arr[0] = 100 + x - 3;
    arr[1] = sub(4, 1, 2); // returns 1
    // arr[3] = arr[1] + 20; // 21
    // arr[2] = arr[3]--; // 20
    // int a = arr[0] + arr[1]; // 101
    // return a + arr[3] + arr[2]; // return 142
    return 0;
}

