def main():
	x = 0
	y = 1
	z = x and x or y
	return z


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)