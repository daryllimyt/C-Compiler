.text

.globl f1
f1:
		.ent f1
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
		lw	$t8, 40($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 156($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 32($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 148($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 24($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 140($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 16($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 132($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 8($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 124($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 0($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 116($fp)		# (fn args) Store fn call args from $t8 to memory
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 116($fp)		# (var: normal) Reading from variable "f"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 124($fp)		# (var: normal) Reading from variable "e"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 132($fp)		# (var: normal) Reading from variable "d"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "c"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 148($fp)		# (var: normal) Reading from variable "b"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		lw	$t0, 156($fp)		# (var: normal) Reading from variable "a"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
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
		addiu	$sp, $sp, 164		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f1

.globl f2
f2:
		.ent f2
		.frame $sp, 148, $ra
		.set noreorder
		.set reorder
		addiu	$sp, $sp, -148		# (fn def: frame start) Move sp to end of new frame
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
		lw	$t8, 32($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 140($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 24($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 132($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 16($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 124($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 8($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 116($fp)		# (fn args) Store fn call args from $t8 to memory
		lw	$t8, 0($a0) 		# (fn args) Load fn call args from old virtual to $t8
		nop
		sw	$t8, 108($fp)		# (fn args) Store fn call args from $t8 to memory
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 108($fp)		# (var: normal) Reading from variable "e"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 116($fp)		# (var: normal) Reading from variable "d"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 124($fp)		# (var: normal) Reading from variable "c"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, 132($fp)		# (var: normal) Reading from variable "b"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		lw	$t0, 140($fp)		# (var: normal) Reading from variable "a"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f2_end_1
		nop

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
		addiu	$sp, $sp, 148		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f2

.globl fmain
fmain:
		.ent fmain
		.frame $sp, 196, $ra
		.set noreorder
		.set reorder
		addiu	$sp, $sp, -196		# (fn def: frame start) Move sp to end of new frame
		sw	$fp, 0($sp) 		# (fn def) Store addr of old fp on stack
		add	$fp, $sp, $0 		# (fn def) Move fp to new sp
		sw	$ra, 4($sp) 		# (fn def) Store ra on stack
		sw	$s0, 8($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
