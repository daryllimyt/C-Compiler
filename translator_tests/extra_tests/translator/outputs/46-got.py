e = 0
 = 5def f():
	global e
	return 5+e

_f_ = 0
 = 7def f1(a, b):
	global _f_
	global e
	return e+a*b+_f_

_ = 0
 = 23def f2(A, B, C, D):
	global _
	global _f_
	global e
	return e+_f_+A*B*C*D+_

_123 = 0
 = 123def main():
	global _123
	global _
	global _f_
	global e
	return e+_f_+_+f()+f1(2, 3)+f2(4, 5, 6, 7)+_123


if __name__ == "__main__":
	import sys
	ret=main()
	sys.exit(ret)
