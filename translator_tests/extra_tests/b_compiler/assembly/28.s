
fmain:
.globl fmain
		addiu	$sp, $sp, -116 		# (frame start) Move sp to end of new frame
		sw	$fp, 0($sp) 		# Store addr of old fp on stack
		add	$fp, $sp, $0 		# Move fp to new sp
		sw	$ra, 4($sp) 		# Store ra on stack
		sw	$s0, 8($sp) 		# Store save regs $s0-$s7 on stack
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp) 		# Store prev fn args $a0-$a3 on stack
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp) 		# Store value of $gp on stack
		nop
		li	$t0, 10
		sw	$t0, 108($fp)		# (assign) store var result
		li	$t0, 20
		sw	$t0, 100($fp)		# (assign) store var result
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 100($fp) 		# Reading from variable
		nop
		sw	$t0, -8($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 108($fp) 		# Reading from variable
		nop
		lw	$t1, -8($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		slt	$t0, $t0, $t1
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	fmain_end_0

fmain_end_0:
		lw	$s0, 8($fp) 		# Load saved regs into $s0-$s7
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp) 		# Load prev fn args into $a0-$a3
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp) 		# Load return address into $ra
		lw	$fp, 0($fp) 		# Load prev fp into $fp
		nop
		addiu	$sp, $sp, 116 		# (frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

end:
