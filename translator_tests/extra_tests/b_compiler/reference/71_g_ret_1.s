.text

.globl f
f:
		.ent f
		.frame $sp, 180, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -180		# (fn def: frame start) Move sp to end of new frame
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
		lw	$t8, 48($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 172($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 40($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 164($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 32($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 156($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 24($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 148($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 16($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 140($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 8($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 132($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 0($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 124($fp)		# (fn args) Store fn call args from $t8 to memory
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 124($fp)		# (var: normal) Reading from variable "y"
		nop
		sw	$t0, -8($fp) 		# (eval expr) store lhs in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 132($fp)		# (var: normal) Reading from variable "x"
		nop
		sw	$t0, -16($fp) 		# (eval expr) store lhs in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "e"
		nop
		sw	$t0, -24($fp) 		# (eval expr) store lhs in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 148($fp)		# (var: normal) Reading from variable "d"
		nop
		sw	$t0, -32($fp) 		# (eval expr) store lhs in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 156($fp)		# (var: normal) Reading from variable "c"
		nop
		sw	$t0, -40($fp) 		# (eval expr) store lhs in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 164($fp)		# (var: normal) Reading from variable "b"
		nop
		sw	$t0, -48($fp) 		# (eval expr) store lhs in virtual
		lw	$t0, 172($fp)		# (var: normal) Reading from variable "a"
		nop
		lw	$t1, -48($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		lw	$t1, -40($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		lw	$t1, -32($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		lw	$t1, -24($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		lw	$t1, -16($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		lw	$t1, -8($fp) 		# (eval expr) load lhs from virtual to $t1, rhs in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) lhs + rhs
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
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
		addiu	$sp, $sp, 180		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f

.globl g
g:
		.ent g
		.frame $sp, 76, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -76		# (fn def: frame start) Move sp to end of new frame
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
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	g_end_1
		nop

g_end_1:
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
		addiu	$sp, $sp, 76		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end g

.globl fmain
fmain:
		.ent fmain
		.frame $sp, 180, $ra
		.set noreorder
		.cpload $t4
		.set reorder
		addiu	$sp, $sp, -180		# (fn def: frame start) Move sp to end of new frame
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
		sw	$t0, 172($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 2				# (int const)
		sw	$t0, 164($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 3				# (int const)
		sw	$t0, 156($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 4				# (int const)
		sw	$t0, 148($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 5				# (int const)
		sw	$t0, 140($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 6				# (int const)
		sw	$t0, 132($fp)		# (assign) store var result in NORMAL variable
		li	$t0, 7				# (int const)
		sw	$t0, 124($fp)		# (assign) store var result in NORMAL variable
		
		# g() = 1
		move	$a0, $sp 		# Store current sp in $a0
		jal	g				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, -8		# Erasing virtual register for g
		sw	$v0, 0($sp) 		# (fn call params) fn call result stored in virtual reg
		
		# 2nd var
		lw	$t0, 164($fp)		# (var: normal) Reading from variable "b"
		nop
		addiu	$sp, $sp, -8 		# (fn call params) Expanding stack
		sw	$t0, 0($sp) 		# (fn call params) store in virtual register
		lw	$t0, 156($fp)		# (var: normal) Reading from variable "c"
		nop
		addiu	$sp, $sp, -8 		# (fn call params) Expanding stack
		sw	$t0, 0($sp) 		# (fn call params) store in virtual register
		lw	$t0, 148($fp)		# (var: normal) Reading from variable "d"
		nop
		addiu	$sp, $sp, -8 		# (fn call params) Expanding stack
		sw	$t0, 0($sp) 		# (fn call params) store in virtual register
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "e"
		nop
		addiu	$sp, $sp, -8 		# (fn call params) Expanding stack
		sw	$t0, 0($sp) 		# (fn call params) store in virtual register
		lw	$t0, 132($fp)		# (var: normal) Reading from variable "x"
		nop
		addiu	$sp, $sp, -8 		# (fn call params) Expanding stack
		sw	$t0, 0($sp) 		# (fn call params) store in virtual register
		lw	$t0, 124($fp)		# (var: normal) Reading from variable "y"
		nop
		addiu	$sp, $sp, -8 		# (fn call params) Expanding stack
		sw	$t0, 0($sp) 		# (fn call params) store in virtual register
		move	$a0, $sp 		# Store current sp in $a0
		jal	f				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 48		# Erasing virtual register for f
		j	fmain_end_2
		nop

fmain_end_2:
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
		addiu	$sp, $sp, 180		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
