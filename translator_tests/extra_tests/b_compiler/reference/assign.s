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
		addiu	$sp, $sp, -20	# Move $sp to end of variable section before function call
		addiu	$t0, $fp, 0		# (unary) get address & in $t0
		sw	$t0, -4($fp)			# (assign) store var result in NORMAL variable "y"
		li	$t0, 64				# (int const)
		lw	$t3, -4($fp)		# (var: pointer) Assign - Reading from pointer "y"
		nop
		sw	$t0, 0($t3) 			# (var: pointer) Assign - store var result in full address of pointer variable "y"
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "x"
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop

f_end_0:
		addiu	$sp, $sp, 20	# Move $sp to end of function arg section after function call
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

end: