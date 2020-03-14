def foo():
	global foo
	x = 2
	y = 3
	z = x + y


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
