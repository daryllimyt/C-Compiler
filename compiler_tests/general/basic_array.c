int sub(int i, int j, int k);

int main() {
    int x = 3;
    int arr[3];
    arr[0] = 100;
    arr[1] = sub(4, 1, 2); // returns 1
    arr[0+x] = arr[1] + 20; // 21
    arr[x-1] = arr[3]--; // 20
    int a = arr[0] + arr[1]; // 101
    return a + arr[3] + arr[2]; // return 142
}

int sub(int i, int j, int k) {
    i -= j;
    i -= k;
    return i;
}