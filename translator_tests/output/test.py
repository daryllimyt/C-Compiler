y=0
z=0
def g(a, b):
	global z
	global y
	return a+y

def f(x):
	global z
	global y
	y = x+3
	g(x, y)
	return x == y


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
