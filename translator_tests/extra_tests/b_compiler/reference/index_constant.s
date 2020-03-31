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
		addiu	$sp, $sp, -32	# Move $sp to end of variable section before function call
		li	$t0, 0				# (int const)
		sll	$t2, $t0, 2		# (var: array) assignment - scale array index offset to multiplier, save to $t2
		li	$t0, 23				# (int const)
		move	 $t8, $fp		# (var: array) read - use $t8 as refreg to access array so $fp/$gp stays
		addi	$t8, $t8, -36		# (var: array) Move refreg to array base address
		addu	$t8, $t8, $t2		# (var: array) Move refreg to index offset from array base
		sw	$t0, 0($t8) 		# (var: array) assign - Storing to array "x" at base offset -36
		li	$t0, 0				# (int const)
		sll	$t2, $t0, 2		# (var: array) read - scale array index offset to multiplier, save to $t2
		move	$t8, $fp		# (var: array) read - use $t8 as refreg to access array so $fp/$gp stays
		addi	$t8, $t8, -36		# (var: array) Move refreg to array base address
		addu	$t8, $t8, $t2		# (var: array) Move refreg to index offset from array base
		lw	$t0, 0($t8) 		# (var: array) Reading from array "x" at base offset -36
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop

f_end_0:
		addiu	$sp, $sp, 32	# Move $sp to end of function arg section after function call
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
