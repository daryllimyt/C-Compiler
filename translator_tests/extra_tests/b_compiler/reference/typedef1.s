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
		addiu	$sp, $sp, -16		# (fn def: frame start) Expand stack for saved registers
		sw	$fp, 4($sp) 		# (fn def)
		sw	$ra, 8($sp) 		# (fn def)
		sw	$gp, 12($sp) 		# (fn def) Store value of $gp on stack
		move	$fp, $sp 		# $fp is at the start of the variable section
		addiu	$sp, $sp, -8	# Move $sp to end of variable section before function call
		li	$t0, 13				# (int const)
		sw	$t0, 0($fp)			# (assign) store var result in NORMAL variable "x"
		li	$t0, 13				# (int const)
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	g_end_0
		nop

g_end_0:
		addiu	$sp, $sp, 8	# Move $sp to end of function arg section after function call
		move	$sp, $fp 		# Restore sp to start of variable section
		lw	$fp, 4($sp) 		# (fn def)
		lw	$ra, 8($sp) 		# (fn def)
		lw	$gp, 12($sp) 		# (fn def) Store value of $gp on stack
		addiu	$sp, $sp, 16		# (fn def: frame end) Shrink stack back to previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end g

end:
