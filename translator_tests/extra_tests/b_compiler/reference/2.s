.text

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
		addiu	$sp, $sp, -8	# Move $sp to end of variable section before function call
		li	$t0, 3				# (int const)
		sw	$t0, 0($fp)			# (assign) store var result in NORMAL variable "x"
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "x"
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	fmain_end_0
		nop

fmain_end_0:
		addiu	$sp, $sp, 8	# Move $sp to end of function arg section after function call
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