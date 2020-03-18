def f(a, b, c, d):
	if(a):
a = 1	elif(b):
a = 2	elif(c):
a = 3	elif(d):
a = 4
	return a

def main():
	return f(1, 2, 3, 4)


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
