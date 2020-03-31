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
		addiu	$sp, $sp, -68	# Move $sp to end of variable section before function call
		li	$t0, 0				# (int const)
		sw	$t0, 0($fp)			# (assign) store var result in NORMAL variable "i"

for_start_1:
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 8				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		slt	$t0, $t0, $t1
		beq	$t0, $0, for_end_1
		nop
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		sll	$t2, $t0, 2		# (var: array) assignment - scale array index offset to multiplier, save to $t2
		move	 $t8, $fp		# (var: array) read - use $t8 as refreg to access array so $fp/$gp stays
		addiu	$t8, $t8, -4		# (var: array) Move refreg to array base address
		subu	$t8, $t8, $t2		# (var: array) Move refreg to index offset from array base
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		sw	$t0, 0($t8) 		# (var: array) Storing into array "x" at base offset -4

for_continue_1:
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		lw	$t0, 0($fp)		# (postfix) store var result in NORMAL variable "i"
		nop
		move	$t1, $t0
		addi	$t0, $t0, 1
		sw	$t0, 0($fp)
		move	$t0, $t1
		j	for_start_1
		nop

for_end_1:
		li	$t0, 4				# (int const)
		sll	$t2, $t0, 2		# (var: array) read - scale array index offset to multiplier, save to $t2
		move	 $t8, $fp		# (var: array) read - use $t8 as refreg to access array so $fp/$gp stays
		addiu	$t8, $t8, -4		# (var: array) Move refreg to array base address
		subu	$t8, $t8, $t2		# (var: array) Move refreg to index offset from array base
		lw	$t0, 0($t8) 		# (var: array) Reading from array "x" at base offset -4
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop

f_end_0:
		addiu	$sp, $sp, 68	# Move $sp to end of function arg section after function call
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
