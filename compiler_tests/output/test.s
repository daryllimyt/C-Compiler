
main:
		addiu	$sp, $sp, -116 		# (frame start) Move sp to end of new frame
		sw	$fp, 0($sp) 		# Store addr of old fp on stack
		add	$fp, $sp, $0 		# Move fp to new sp
		sw	$ra, 4($sp) 		# Store ra on stack
		addiu	$t9, $ra, 0 		# Store ra in $t9
		sw	$s0, 8($sp) 		# Store save regs $s0-$s7 on stack
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp) 		# Store prev fn args $a0-$a3 on stack
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp) 		# Store value of $gp on stack
		nop
		li	$t0, 1
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -8($fp) 		# (fn call params) store in virtual
		li	$t0, 2
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -16($fp) 		# (fn call params) store in virtual
		li	$t0, 3
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -24($fp) 		# (fn call params) store in virtual
		move	$t9, $fp
		jal	add				# (fn call) enter fn def
		nop
		lw	$t0, 108($fp)
		nop
		add	$v0, $t0, $0 		# return value
		j	main_end_0

main_end_0:
		lw	$s0, 8($fp) 		# Load saved regs into $s0-$s7
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp) 		# Load prev fn args into $a0-$a3
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp) 		# Load return address into $ra
		lw	$fp, 0($fp) 		# Load prev fp into $fp
		nop
		addiu	$sp, $sp, 116 		# (frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

add:
		addiu	$sp, $sp, -116 		# (frame start) Move sp to end of new frame
		sw	$fp, 0($sp) 		# Store addr of old fp on stack
		add	$fp, $sp, $0 		# Move fp to new sp
		sw	$ra, 4($sp) 		# Store ra on stack
		addiu	$t9, $ra, 0 		# Store ra in $t9
		sw	$s0, 8($sp) 		# Store save regs $s0-$s7 on stack
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp) 		# Store prev fn args $a0-$a3 on stack
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp) 		# Store value of $gp on stack
		nop
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -32($fp) 		# (arg) store in virtual
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -40($fp) 		# (arg) store in virtual
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -48($fp) 		# (arg) store in virtual
		lw	$a0, -8($t9) 		# (fn args) Load fn call args from virtual to $aX
		lw	$a1, -16($t9) 		# (fn args) Load fn call args from virtual to $aX
		lw	$a2, -24($t9) 		# (fn args) Load fn call args from virtual to $aX
		lw	$a3, -32($t9) 		# (fn args) Load fn call args from virtual to $aX
		lw	$t8, -40($t9) 		# (fn args) Load fn call args from old virtual to $t8
		sw	$t8, -8($fp) 		# (fn args) Store fn call args from $t8 to new virtual
		lw	$t8, -48($t9) 		# (fn args) Load fn call args from old virtual to $t8
		sw	$t8, -16($fp) 		# (fn args) Store fn call args from $t8 to new virtual
		addiu	$sp, $sp, -8
		addiu	$sp, $sp, -8
		lw	$t0, 108($fp)
		nop
		sw	$t0, -24($fp)
		lw	$t0, 100($fp)
		nop
		lw	$t1, -24($fp)
		nop
		addiu	$sp, $sp, 8
		add	$t0, $t0, $t1
		sw	$t0, -24($fp)
		lw	$t0, 92($fp)
		nop
		lw	$t1, -24($fp)
		nop
		addiu	$sp, $sp, 8
		add	$t0, $t0, $t1
		add	$v0, $t0, $0 		# return value
		j	add_end_1

add_end_1:
		lw	$s0, 8($fp) 		# Load saved regs into $s0-$s7
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp) 		# Load prev fn args into $a0-$a3
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp) 		# Load return address into $ra
		lw	$fp, 0($fp) 		# Load prev fp into $fp
		nop
		addiu	$sp, $sp, 116 		# (frame end) Move sp to end of previous frame
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

end:
