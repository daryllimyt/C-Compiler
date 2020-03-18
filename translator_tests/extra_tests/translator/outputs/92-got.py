def f(a, b, c, d):
	if(a):
		return 1
	elif(b):
		return 15
	elif(c):
		return 22
	elif(d):
		return 50


def main():
	return f(1, 2, 3, 4)


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
