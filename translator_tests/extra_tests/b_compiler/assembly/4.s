.text
.globl fmain

fmain:
		.ent fmain
		.frame $sp, 108, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -108		# (fn def: frame start) Move sp to end of new frame
		sw	$fp, 0($sp) 		# (fn def) Store addr of old fp on stack
		add	$fp, $sp, $0 		# (fn def) Move fp to new sp
		sw	$ra, 4($sp) 		# (fn def) Store ra on stack
		sw	$s0, 8($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp) 		# (fn def) Store prev fn args $a0-$a3 on stack
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp) 		# Store value of $gp on stack
		.cprestore 60
		nop
		li	$t0, 4				# (int const)
		sw	$t0, 100($fp)		# (assign) store var result in NORMAL variable
		lw	$t0, 100($fp)		# (var: normal) Reading from variable "x"
		nop
		sw	$t0, 92($fp)		# (assign) store recursive assign
		lw	$t0, 92($fp)		# (var: normal) Reading from variable "y"
		nop
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	fmain_end_0
		nop

fmain_end_0:
		lw	$s0, 8($fp) 		# (fn def) Load saved regs into $s0-$s7
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp) 		# (fn def) Load prev fn args into $a0-$a3
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp) 		# (fn def) Load return address into $ra
		lw	$fp, 0($fp) 		# (fn def) Load prev fp into $fp
		nop
		addiu	$sp, $sp, 108		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
