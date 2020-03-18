def main():
	x = 0
	y = 1
	z = (x or x and y)
	return z


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
