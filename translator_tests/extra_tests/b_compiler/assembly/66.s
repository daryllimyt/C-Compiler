.text
.globl f

f:
		.ent f
		.frame $sp, 100, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -100		# (fn def: frame start) Move sp to end of new frame
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
		lw	$t8, -8($t9) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 92($fp)		# (fn args) Store fn call args from $t8 to new virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 10				# (int const)
		sw	$t0, -8($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 92($fp)		# (var: normal) Reading from variable "x"
		nop
		lw	$t1, -8($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (assign op node) lhs += rhs
		sw	$t0, 92($fp)		# (assign expr) storing evaluated expression from $t0 to LHS variable in memory
		li	$t0, 10				# (int const)
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	f_end_0
		nop

f_end_0:
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
		addiu	$sp, $sp, 100		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f
.globl fmain

fmain:
		.ent fmain
		.frame $sp, 116, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -116		# (fn def: frame start) Move sp to end of new frame
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
		li	$t0, 1				# (int const)
		sw	$t0, 108($fp)		# (assign) store var result in NORMAL variable
		lw	$t0, 108($fp)		# (var: normal) Reading from variable "x"
		nop
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -8($fp) 		# (fn call params) store in virtual
		move	$t9, $fp 		# Store current fp in $f9
		jal	f				# (fn call) enter fn def
		nop
		sw	$v0, 100($fp)		# (assign) store fn result in NORMAL variable
		lw	$t0, 108($fp)		# (var: normal) Reading from variable "x"
		nop
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	fmain_end_1
		nop

fmain_end_1:
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
		addiu	$sp, $sp, 116		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
