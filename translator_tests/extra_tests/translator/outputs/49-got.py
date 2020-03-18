x = 0
 = 1def f0():
	global x
	if(x):
		return 


def main():
	global x
	f0()
	return 10


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
