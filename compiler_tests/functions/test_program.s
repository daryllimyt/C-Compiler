.text

.set noreorder
.text
.globl f1
f1:
		.ent f1
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 16($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 24($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		lw	$t0, 0($t9) 		# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, 0($fp)		# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 0($fp)		# (var: normal) Reading from variable "x"
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f1_end_0
		nop

f1_end_0:
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		addiu	$sp, $sp, 12		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f1

.set noreorder
.text
.globl f2
f2:
		.ent f2
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 16($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 24($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		lw	$t0, 0($t9) 		# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, 0($fp)		# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 8($t9) 		# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -8($fp)		# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 16($t9) 		# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -16($fp)		# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 24($t9) 		# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -24($fp)		# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 32($t9) 		# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -32($fp)		# (fn args) Store fn call args from $t0 to memory
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, -32($fp)		# (var: normal) Reading from variable "e"
		nop
		sw	$t0, -8($fp) 		# (eval expr) store RHS in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, -24($fp)		# (var: normal) Reading from variable "d"
		nop
		sw	$t0, -16($fp) 		# (eval expr) store RHS in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, -16($fp)		# (var: normal) Reading from variable "c"
		nop
		sw	$t0, -24($fp) 		# (eval expr) store RHS in virtual
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		lw	$t0, -8($fp)		# (var: normal) Reading from variable "b"
		nop
		sw	$t0, -32($fp) 		# (eval expr) store RHS in virtual
		lw	$t0, 0($fp)		# (var: normal) Reading from variable "a"
		nop
		lw	$t1, -32($fp) 		# (eval expr) load LHS from virtual to $t1, RHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, -24($fp) 		# (eval expr) load LHS from virtual to $t1, RHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, -16($fp) 		# (eval expr) load LHS from virtual to $t1, RHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, -8($fp) 		# (eval expr) load LHS from virtual to $t1, RHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f2_end_1
		nop

f2_end_1:
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		addiu	$sp, $sp, 12		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f2

.set noreorder
.text
.globl fmain
fmain:
		.ent fmain
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 16($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 24($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		li	$t0, 1				# (int const)
		sw	$t0, 0($fp)		# (assign) store var result in NORMAL variable "a"
		li	$t0, 2				# (int const)
		sw	$t0, -8($fp)		# (assign) store var result in NORMAL variable "b"
		li	$t0, 3				# (int const)
		sw	$t0, -16($fp)		# (assign) store var result in NORMAL variable "c"
		li	$t0, 4				# (int const)
		sw	$t0, -24($fp)		# (assign) store var result in NORMAL variable "d"
		li	$t0, 5				# (int const)
		sw	$t0, -32($fp)		# (assign) store var result in NORMAL variable "e"
		addiu	$sp, $sp, -80		# (fn call) Expand stack for fn "f2" arg slots
		addiu	$sp, $sp, -72		# (fn call) Expand stack for fn "f1" arg slots
		lw	$t0, 0($fp)		# (var: normal) Reading from variable "a"
		nop
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		jal	f1				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 72		# (fn call) Shrink stack for fn "f1" arg slots
		sw	$v0, 0($sp) 		# (fn call params) store in arg slot
		lw	$t0, -8($fp)		# (var: normal) Reading from variable "b"
		nop
		sw	$t0, 8($sp) 		# (fn call params) store in arg slot
		lw	$t0, -16($fp)		# (var: normal) Reading from variable "c"
		nop
		sw	$t0, 16($sp) 		# (fn call params) store in arg slot
		lw	$t0, -24($fp)		# (var: normal) Reading from variable "d"
		nop
		sw	$t0, 24($sp) 		# (fn call params) store in arg slot
		lw	$t0, -32($fp)		# (var: normal) Reading from variable "e"
		nop
		sw	$t0, 32($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		lw	$a1, 8($sp) 		# Load arguments into $a0-$a3
		lw	$a2, 16($sp) 		# Load arguments into $a0-$a3
		lw	$a3, 24($sp) 		# Load arguments into $a0-$a3
		jal	f2				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 80		# (fn call) Shrink stack for fn "f2" arg slots
		j	fmain_end_2
		nop

fmain_end_2:
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		addiu	$sp, $sp, 12		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f

end:
