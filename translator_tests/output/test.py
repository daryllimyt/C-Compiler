y=0
z=0
def g(a):
	global z
	global y
	return a+y

def f(x):
	global z
	global y
	g(x)

	return x == y


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
