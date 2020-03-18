{
    int x;
}

int main() {
    {
        x = x + 2;
        int y;
        y = y+x;
        int z =2;
        {
            int a = 1;
        }
        {
            a = x;
        }
    }
    return y;
}