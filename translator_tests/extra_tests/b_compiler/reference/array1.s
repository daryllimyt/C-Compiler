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
		addiu	$sp, $sp, -52	# Move $sp to end of variable section before function call
		li	$t0, 0				# (int const)
		sll	$s6, $t0, 2		# (var: array) assignment - scale array index offset to multiplier, save to $s6
		move	$s7, $fp		# (var: array) read - use $s7 as refreg to access array so $fp/$gp stays
		addi	$s7, $s7, -20		# (var: array) Move refreg to array base address
		addu	$s7, $s7, $s6		# (var: array) Move refreg to index offset from array base
		li	$t0, 100				# (int const)
		sw	$t0, 0($s7) 		# (var: array) assign - Storing to array "arr" at base offset -20
		li	$t0, 1				# (int const)
		sll	$s6, $t0, 2		# (var: array) assignment - scale array index offset to multiplier, save to $s6
		move	$s7, $fp		# (var: array) read - use $s7 as refreg to access array so $fp/$gp stays
		addi	$s7, $s7, -20		# (var: array) Move refreg to array base address
		addu	$s7, $s7, $s6		# (var: array) Move refreg to index offset from array base
		addiu	$sp, $sp, -16	# (fn call) Expand stack for fn "sub" arg slots
		li	$t0, 4				# (int const)
		sw	$t0, 0($sp) 		# (fn call params) store in arg slot
		li	$t0, 1				# (int const)
		sw	$t0, 4($sp) 		# (fn call params) store in arg slot
		li	$t0, 2				# (int const)
		sw	$t0, 8($sp) 		# (fn call params) store in arg slot
		lw	$a0, 0($sp) 		# Load arguments into $a0-$a3
		lw	$a1, 4($sp) 		# Load arguments into $a0-$a3
		lw	$a2, 8($sp) 		# Load arguments into $a0-$a3
		jal	sub				# (fn call) enter fn def
		nop
		addiu	$sp, $sp, 16	# (fn call) Shrink stack for fn "sub" arg slots
		sw	$t0, 0($s7) 		# (var: array) assign - Storing to array "arr" at base offset -20
		li	$t0, 3				# (int const)
		sll	$s6, $t0, 2		# (var: array) assignment - scale array index offset to multiplier, save to $s6
		move	$s7, $fp		# (var: array) read - use $s7 as refreg to access array so $fp/$gp stays
		addi	$s7, $s7, -20		# (var: array) Move refreg to array base address
		addu	$s7, $s7, $s6		# (var: array) Move refreg to index offset from array base
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		li	$t0, 20				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		li	$t0, 1				# (int const)
		sll	$s6, $t0, 2		# (var: array) read - scale array index offset to multiplier, save to $s6
		move	$s7, $fp		# (var: array) read - use $s7 as refreg to access array so $fp/$gp stays
		addi	$s7, $s7, -20		# (var: array) Move refreg to array base address
		addu	$s7, $s7, $s6		# (var: array) Move refreg to index offset from array base
		lw	$t0, 0($s7) 		# (var: array) Reading from array "arr" at base offset -20
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		add	$t0, $t0, $t1 		# (add node) LHS + RHS
		sw	$t0, 0($s7) 		# (var: array) assign - Storing to array "arr" at base offset -20
		li	$t0, 3				# (int const)
		sll	$s6, $t0, 2		# (var: array) read - scale array index offset to multiplier, save to $s6
		move	$s7, $fp		# (var: array) read - use $s7 as refreg to access array so $fp/$gp stays
		addi	$s7, $s7, -20		# (var: array) Move refreg to array base address
		addu	$s7, $s7, $s6		# (var: array) Move refreg to index offset from array base
		lw	$t0, 0($s7) 		# (var: array) Reading from array "arr" at base offset -20
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	fmain_end_0
		nop

fmain_end_0:
		addiu	$sp, $sp, 52	# Move $sp to end of function arg section after function call
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

.set noreorder
.text
.globl sub
sub:
		.ent sub
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
		addiu	$sp, $sp, -12		# Move $sp to end of function arg section for local variables
		lw	$t0, 0($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, 0($fp)			# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 4($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -4($fp)			# (fn args) Store fn call args from $t0 to memory
		lw	$t0, 8($t9) 			# (fn args) Load fn call args from arg slots to $t0
		nop
		sw	$t0, -8($fp)			# (fn args) Store fn call args from $t0 to memory
		addiu	$sp, $sp, -32	# Move $sp to end of variable section before function call
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		lw	$t0, -4($fp)			# (var: normal) Reading from variable "j"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		sub	$t0, $t0, $t1 			# (assign op node) LHS -= RHS
		sw	$t0, 0($fp)				# (assign expr) storing evaluated expression from $t0 to LHS variable in memory
		addiu	$sp, $sp, -4 		# (eval expr) Expand stack for expression evaluation
		lw	$t0, -8($fp)			# (var: normal) Reading from variable "k"
		nop
		sw	$t0, 0($sp) 		# (eval expr) store RHS in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		lw	$t1, 0($sp) 		# (eval expr) load RHS from memory to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 4 		# (eval expr) Shrinking stack after evaluation
		sub	$t0, $t0, $t1 			# (assign op node) LHS -= RHS
		sw	$t0, 0($fp)				# (assign expr) storing evaluated expression from $t0 to LHS variable in memory
		lw	$t0, 0($fp)			# (var: normal) Reading from variable "i"
		nop
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	sub_end_1
		nop

sub_end_1:
		addiu	$sp, $sp, 44	# Move $sp to end of function arg section after function call
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
		.end sub

end:
