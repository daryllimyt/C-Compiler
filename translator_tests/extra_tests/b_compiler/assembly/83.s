.text
.globl f1

f1:
		.ent f1
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
		lw	$t0, 92($fp)		# (var: normal) Reading from variable "x"
		nop
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -8($fp) 		# (fn call params) store in virtual
		move	$t9, $fp 		# Store current fp in $f9
		jal	f2				# (fn call) enter fn def
		nop
		sw	$t0, -16($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 92($fp)		# (var: normal) Reading from variable "x"
		nop
		lw	$t1, -16($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	f1_end_0
		nop

f1_end_0:
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
		.end f1
.globl f2

f2:
		.ent f2
		.frame $sp, 124, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -124		# (fn def: frame start) Move sp to end of new frame
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
		sw	$t8, 116($fp)		# (fn args) Store fn call args from $t8 to new virtual

if_start_2:
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 0				# (int const)
		sw	$t0, -16($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 116($fp)		# (var: normal) Reading from variable "x"
		nop
		lw	$t1, -16($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		slt	$t0, $t1, $t0
		sltu	$t0, $t0, 1
		beq	$t0, $0, if_next_2
		nop
		li	$t0, 0				# (int const)
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	if_end_2
		nop
		j	if_end_2
		nop

if_next_2:
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 1				# (int const)
		sw	$t0, -16($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 116($fp)		# (var: normal) Reading from variable "x"
		nop
		lw	$t1, -16($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		sub	$t0, $t0, $t1 		# (add node) lhs - rhs
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -16($fp) 		# (fn call params) store in virtual
		move	$t9, $fp 		# Store current fp in $f9
		jal	f1				# (fn call) enter fn def
		nop
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	if_end_2
		nop

if_end_2:

f2_end_1:
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
		addiu	$sp, $sp, 124		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f2
.globl fmain

fmain:
		.ent fmain
		.frame $sp, 84, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -84		# (fn def: frame start) Move sp to end of new frame
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
		li	$t0, 5				# (int const)
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -24($fp) 		# (fn call params) store in virtual
		move	$t9, $fp 		# Store current fp in $f9
		jal	f1				# (fn call) enter fn def
		nop
		add	$v0, $t0, $0 		# (return node) put return val in $v0
		j	fmain_end_3
		nop

fmain_end_3:
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
		addiu	$sp, $sp, 84		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
