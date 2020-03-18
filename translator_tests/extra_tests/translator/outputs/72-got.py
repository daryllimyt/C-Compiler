def main():
	x = 0
	y = 1
	z = (y and x and x)
	return z


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
