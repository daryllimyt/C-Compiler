
int f(int *p);

int main()
{
    int *x;
    *x = 1;

    return (f(x)-2);
}
