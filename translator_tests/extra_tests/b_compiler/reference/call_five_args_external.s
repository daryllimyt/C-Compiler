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
		addiu	$sp, $sp, -8	# Move $sp to end of variable section before function call
		addiu	$sp, $sp, -20	# (fn call) Expand stack for fn "g" arg slots
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		li	$t0, 2				# (int const)
		sw	$t0, 4($sp) 		# (fn call params) store in arg slot
		li	$t0, 3				# (int const)
		sw	$t0, 8($sp) 		# (fn call params) store in arg slot
		li	$t0, 4				# (int const)
		sw	$t0, 12($sp) 		# (fn call params) store in arg slot
		li	$t0, 5				# (int const)
		sw	$t0, 16($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		lw	$a1, 4($sp) 		# Load arguments into $a0-$a3
		lw	$a2, 8($sp) 		# Load arguments into $a0-$a3
		lw	$a3, 12($sp) 		# Load arguments into $a0-$a3
		jal	g				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 20	# (fn call) Shrink stack for fn "g" arg slots
		j	f_end_0
		nop

f_end_0:
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
