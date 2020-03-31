
int f(int *p);

int main()
{
    int x[2];
    x[0]=5;
    x[1]=13;
    return (f(x)-13);
}
