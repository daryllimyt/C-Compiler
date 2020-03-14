int globalvar;

void foo() {
    globalvar = 2;
    int y = 3;
    int z = globalvar + y;
}

int main() {
    return 0;
}

