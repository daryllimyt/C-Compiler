.text

.globl f
f:
		.ent f
		.frame $sp, 100, $ra
		.set noreorder
		.set reorder
		addiu	$sp, $sp, -100		# (fn def: frame start) Move sp to end of new frame
		sw	$fp, 0($sp) 		# (fn def) Store addr of old fp on stack
		add	$fp, $sp, $0 		# (fn def) Move fp to new sp
		sw	$ra, 4($sp) 		# (fn def) Store ra on stack
		sw	$s0, 8($sp) 		# (fn def) Store save regs $s0-$s7 on stack
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp) 		# (fn def) Store prev fn args $a0-$a3 on stack
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp) 		# Store value of $gp on stack
		nop

if_start_1:
		addiu	$sp, $sp, -8 		# (eval expr) move sp for virtual regs
		li	$t0, 1				# (int const)
		sw	$t0, 0($sp) 		# (eval expr) store RHS in virtual register
		li	$t0, 0				# (int const)
		lw	$t1, 0($sp) 		# (eval expr) load RHS from virtual to $t1, LHS in $t0
		nop
		addiu	$sp, $sp, 8 		# (eval expr) clearing virtual
		sltu	$t0, $0, $t0
		sltu	$t1, $0, $t1
		and	$t0, $t0, $t1
		andi	$t0, $t0, 1
		sltu	$t0, $0, $t0
		xori	$t0, $t0, 1
		andi	$t0, $t0, 1
		beq	$t0, $0, if_next_1
		nop
		li	$t0, 1				# (int const)
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop
		j	if_end_1
		nop

if_next_1:

if_end_1:
		li	$t0, 0				# (int const)
		move	$v0, $t0 		# (return node) load $t0 to $v0 if not function call
		j	f_end_0
		nop

f_end_0:
		lw	$s0, 8($fp) 		# (fn def) Load saved regs into $s0-$s7
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp) 		# (fn def) Load prev fn args into $a0-$a3
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp) 		# (fn def) Load return address into $ra
		lw	$fp, 0($fp) 		# (fn def) Load prev fp into $fp
		nop
		addiu	$sp, $sp, 100		# (fn def: frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop
		.end f

end:
