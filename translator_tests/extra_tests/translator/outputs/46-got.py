e = 5
def f():
	global e
	return 5 + e

_f_ = 7
def f1(a, b):
	global _f_
	global e
	return e + a * b + _f_

_ = 23
def f2(A, B, C, D):
	global _
	global _f_
	global e
	return e + _f_ + A * B * C * D + _

_123 = 123
def main():
	global _123
	global _
	global _f_
	global e
	return e + _f_ + _ + f() + f1(2, 3) + f2(4, 5, 6, 7) + _123


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
