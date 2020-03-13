def main():
	a = 1
	b = 2
	if(a):
		return 3

	if(3):
		return a
	else:
		return 3



if __name__ == "__main__":
	import sys
	ret = main()
	sys.exit(ret)
