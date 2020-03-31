.text

.set noreorder
.text
.globl g
g:
		.ent g
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
		addiu	$sp, $sp, -44	# Move $sp to end of variable section before function call
		li	$t0, 0				# (int const)
		sw	$t0, -4($fp)			# (assign) store var result in NORMAL variable "x"

switch_start_1:
		li	$s1, 1
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "t"
		nop
		move	$s0, $t0		# (switch) Storing the switch expression in $s0

case_start_2:
		li	$t0, 0				# (int const)
		slt	$t1, $t0, $s0
		slt	$t2, $s0, $t0
		or	$t0, $t1, $t2
		and	$t0, $t0, $s1
		bgtz	$t0, case_end_2		# (case) branching past case if expr not same
		nop
		move	$s1, $0
		li	$t0, 1				# (int const)
		sw	$t0, -4($fp)			# (assign) store var result in NORMAL variable "x"
		j	switch_end_1
		nop

case_end_2:

case_start_3:
		li	$t0, 2				# (int const)
		slt	$t1, $t0, $s0
		slt	$t2, $s0, $t0
		or	$t0, $t1, $t2
		and	$t0, $t0, $s1
		bgtz	$t0, case_end_3		# (case) branching past case if expr not same
		nop
		move	$s1, $0
		li	$t0, 2				# (int const)
		sw	$t0, -4($fp)			# (assign) store var result in NORMAL variable "x"

case_end_3:

case_start_4:
		li	$t0, 1				# (int const)
		slt	$t1, $t0, $s0
		slt	$t2, $s0, $t0
		or	$t0, $t1, $t2
		and	$t0, $t0, $s1
		bgtz	$t0, case_end_4		# (case) branching past case if expr not same
		nop
		move	$s1, $0
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, -4($fp)			# (var: normal) Reading from variable "x"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		sw	$t0, -4($fp)			# (assign) store var result in NORMAL variable "x"
		j	switch_end_1
		nop

case_end_4:
		j default_end_5
		nop

default_start_5:
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "t"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		sw	$t0, -4($fp)			# (assign) store var result in NORMAL variable "x"
		j	switch_end_1
		nop

default_end_5:
		j	default_start_5

switch_end_1:
		lw	$t0, -4($fp)			# (var: normal) Reading from variable "x"
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	g_end_0
		nop

g_end_0:
		addiu	$sp, $sp, 48	# Move $sp to end of function arg section after function call
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
		.end g

end:
