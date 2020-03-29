.text

.globl fmain
fmain:
		.ent fmain
		.frame $sp, 164, $ra
		.set noreorder
		.set reorder
		addiu	$sp, $sp, -164		# (fn def: frame start) Move sp to end of new frame
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
		nop
		li	$t0, 0				# (int const)
<<<<<<< HEAD
		sw	$t0, 156($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 10				# (int const)
		sw	$t0, 148($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 0				# (int const)
		sw	$t0, 140($fp)		# (assign) store var result in NORMAL variable

for_start_1:
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 5				# (int const)
		sw	$t0, -8($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "y"
		nop
		lw	$t1, -8($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		slt	$t0, $t0, $t1
		beq	$t0, $0, for_end_1
		nop
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 1				# (int const)
		sw	$t0, -8($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 156($fp)		# (var: normal) Reading from variable "x"
=======
		sw	$t0, 156($fp)		# (assign) store var result in NORMAL variable "x"
		li	$t0, 10				# (int const)
		sw	$t0, 148($fp)		# (assign) store var result in NORMAL variable "y"
		li	$t0, 0				# (int const)
		sw	$t0, 140($fp)		# (assign) store var result in NORMAL variable "y"

for_start_1:
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 5				# (int const)
		sw	$t0, -8($fp) 		# (eval expr) store RHS in virtual
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "y"
>>>>>>> scoping
		nop
		lw	$t1, -8($fp) 		# (eval expr) load LHS from virtual to $t1, RHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
<<<<<<< HEAD
		add	$t0, $t0, $t1 		# (assign op node) lhs += rhs
=======
		slt	$t0, $t0, $t1
		beq	$t0, $0, for_end_1
		nop
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 1				# (int const)
		sw	$t0, -8($fp) 		# (eval expr) store RHS in virtual
		lw	$t0, 156($fp)		# (var: normal) Reading from variable "x"
		nop
		lw	$t1, -8($fp) 		# (eval expr) load LHS from virtual to $t1, RHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (assign op node) LHS += RHS
>>>>>>> scoping
		sw	$t0, 156($fp)		# (assign expr) storing evaluated expression from $t0 to LHS variable in memory

for_continue_1:
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "y"
		nop
<<<<<<< HEAD
		lw	$t0, 140($fp)		# (postfix) store var result in NORMAL variable
=======
		lw	$t0, 140($fp)		# (postfix) store var result in NORMAL variable "y"
>>>>>>> scoping
		nop
		move	$t1, $t0
		addi	$t0, $t0, 1
		sw	$t0, 140($fp)
		move	$t0, $t1
		j	for_start_1
		nop

for_end_1:
<<<<<<< HEAD
		lw	$t0, 1($fp)		# (var: normal) Reading from variable "y"
=======
		lw	$t0, 148($fp)		# (var: normal) Reading from variable "y"
>>>>>>> scoping
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
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
		addiu	$sp, $sp, 164		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
