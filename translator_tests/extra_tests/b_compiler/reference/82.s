.text

.set noreorder
.text
.globl f
f:
		.ent f
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 4($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 12($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -4		# Move $sp to end of function arg section for local variables
		lw	$t0, 0($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, 0($fp)			# (fn args) Store fn call args from $t0 to memory
		addiu	$sp, $sp, -20	# Move $sp to end of variable section before function call

if_start_1:
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 0				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "n"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		slt	$t0, $t1, $t0
		sltiu	$t0, $t0, 1
		beq	$t0, $0, if_next_1
		nop
		li	$t0, 0				# (int const)
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop
		j	if_end_1
		nop

if_next_1:
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		addiu	$sp, $sp, -16	# (fn call) Expand stack for fn "f" arg slots
		addiu	$sp, $sp, -8 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "n"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		sub	$t0, $t0, $t1 		# (add node) LHS - RHS
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		jal	f				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 16	# (fn call) Shrink stack for fn "f" arg slots
		sw	$v0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "n"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop

if_end_1:

f_end_0:
		addiu	$sp, $sp, 24	# Move $sp to end of function arg section after function call
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		addiu	$sp, $sp, 12		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f

.set noreorder
.text
.globl fmain
fmain:
		.ent fmain
		sw	$a0, 0($sp) 		# (fn def) Store arg regs in memory
		sw	$a1, 4($sp) 		# (fn def) Store arg regs in memory
		sw	$a2, 8($sp) 		# (fn def) Store arg regs in memory
		sw	$a3, 12($sp) 		# (fn def) Store arg regs in memory
		move	$t9, $sp 		# (fn def) Store caller $sp in $t9 for argument calling
		addiu	$sp, $sp, -12		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -4	# Move $sp to end of variable section before function call
		addiu	$sp, $sp, -16	# (fn call) Expand stack for fn "f" arg slots
		li	$t0, 5				# (int const)
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		jal	f				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 16	# (fn call) Shrink stack for fn "f" arg slots
		j	fmain_end_2
		nop

fmain_end_2:
		addiu	$sp, $sp, 4	# Move $sp to end of function arg section after function call
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		addiu	$sp, $sp, 12		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
