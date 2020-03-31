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
		addiu	$sp, $sp, -48		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		sw	$gp, 12($sp) 		# (fn def) Store value of $gp on stack
		sw	$s0, 16($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		sw	$s1, 20($sp)
		sw	$s2, 24($sp)
		sw	$s3, 28($sp)
		sw	$s4, 32($sp)
		sw	$s5, 36($sp)
		sw	$s6, 40($sp)
		sw	$s7, 44($sp)
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -4		# Move $sp to end of function arg section for local variables
		lw	$t0, 0($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, 0($fp)			# (fn args) Store fn call args from $t0 to memory
		addiu	$sp, $sp, -20	# Move $sp to end of variable section before function call

if_start_1:
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		slt	$t0, $t1, $t0
		beq	$t0, $0, if_next_1
		nop
		addiu	$sp, $sp, -16	# (fn call) Expand stack for fn "f" arg slots
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		sub	$t0, $t0, $t1 		# (add node) LHS - RHS
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		jal	f				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 16	# (fn call) Shrink stack for fn "f" arg slots
		j	f_end_0
		nop
		j	if_end_1
		nop

if_next_1:
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop

if_end_1:

f_end_0:
		addiu	$sp, $sp, 24	# Move $sp to end of function arg section after function call
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		lw	$gp, 12($sp) 		# (fn def) Store value of $gp on stack
		lw	$s0, 16($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		lw	$s1, 20($sp)
		lw	$s2, 24($sp)
		lw	$s3, 28($sp)
		lw	$s4, 32($sp)
		lw	$s5, 36($sp)
		lw	$s6, 40($sp)
		lw	$s7, 44($sp)
		addiu	$sp, $sp, 48		# (fn def: frame end) Shrink stack back to previous frame
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
		addiu	$sp, $sp, -48		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		sw	$gp, 12($sp) 		# (fn def) Store value of $gp on stack
		sw	$s0, 16($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		sw	$s1, 20($sp)
		sw	$s2, 24($sp)
		sw	$s3, 28($sp)
		sw	$s4, 32($sp)
		sw	$s5, 36($sp)
		sw	$s6, 40($sp)
		sw	$s7, 44($sp)
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -4	# Move $sp to end of variable section before function call

if_start_3:
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		addiu	$sp, $sp, -16	# (fn call) Expand stack for fn "f" arg slots
		li	$t0, 2				# (int const)
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		jal	f				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 16	# (fn call) Shrink stack for fn "f" arg slots
		move	$t0, $v0 		# (eval expr) LHS from fn call
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		slt	$v0, $t0, $t1
		slt	$v1, $t1, $t0
		xor	$t0, $v0, $v1
		sltiu	$t0, $t0, 1
		beq	$t0, $0, if_next_3
		nop
		li	$t0, 2				# (int const)
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	fmain_end_2
		nop
		j	if_end_3
		nop

if_next_3:

if_end_3:
		li	$t0, 1				# (int const)
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	fmain_end_2
		nop

fmain_end_2:
		addiu	$sp, $sp, 4	# Move $sp to end of function arg section after function call
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		lw	$gp, 12($sp) 		# (fn def) Store value of $gp on stack
		lw	$s0, 16($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		lw	$s1, 20($sp)
		lw	$s2, 24($sp)
		lw	$s3, 28($sp)
		lw	$s4, 32($sp)
		lw	$s5, 36($sp)
		lw	$s6, 40($sp)
		lw	$s7, 44($sp)
		addiu	$sp, $sp, 48		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end fmain

end:
