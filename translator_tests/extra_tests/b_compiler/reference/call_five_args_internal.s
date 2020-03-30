.text

.set noreorder
.text
.globl g
g:
		.ent g
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 16($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 24($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -40		# Move $sp to end of function arg section for local variables
		lw	$t0, 0($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, 0($fp)			# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 8($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -8($fp)			# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 16($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -16($fp)			# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 24($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -24($fp)			# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 32($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -32($fp)			# (fn args) Store fn call args from $t0 to memory
		addiu	$sp, $sp, -80	# Move $sp to end of variable section before function call
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		lw	$t0, -32($fp)			# (var: normal) Reading from variable "e"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		lw	$t0, -24($fp)			# (var: normal) Reading from variable "d"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		lw	$t0, -16($fp)			# (var: normal) Reading from variable "c"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		lw	$t0, -8($fp)			# (var: normal) Reading from variable "b"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "a"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	g_end_0
		nop

g_end_0:
		addiu	$sp, $sp, 120	# Move $sp to end of function arg section after function call
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		addiu	$sp, $sp, 12		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end g

.set noreorder
.text
.globl f
f:
		.ent f
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 16($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 24($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -8	# Move $sp to end of variable section before function call
		addiu	$sp, $sp, -40	# (fn call) Expand stack for fn "g" arg slots
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		li	$t0, 2				# (int const)
		sw	$t0, 8($sp) 		# (fn call params) store in arg slot
		li	$t0, 3				# (int const)
		sw	$t0, 16($sp) 		# (fn call params) store in arg slot
		li	$t0, 4				# (int const)
		sw	$t0, 24($sp) 		# (fn call params) store in arg slot
		li	$t0, 5				# (int const)
		sw	$t0, 32($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		lw	$a1, 8($sp) 		# Load arguments into $a0-$a3
		lw	$a2, 16($sp) 		# Load arguments into $a0-$a3
		lw	$a3, 24($sp) 		# Load arguments into $a0-$a3
		jal	g				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 40	# (fn call) Shrink stack for fn "g" arg slots
		j	f_end_1
		nop

f_end_1:
		addiu	$sp, $sp, 8	# Move $sp to end of function arg section after function call
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
