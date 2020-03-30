
add:
.globl add
		addiu	$sp, $sp, -116
		sw	$fp, 0($sp)
		add	$fp, $sp, $0
		sw	$ra, 4($sp)
		addiu	$t9, $ra, 0
		sw	$s0, 8($sp)
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp)
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp)
		nop
		addiu	$sp, $sp, -8
		addiu	$sp, $sp, -8
		lw	$t0, 108($fp)
		nop
		sw	$t0, -8($fp)
		lw	$t0, 100($fp)
		nop
		lw	$t1, -8($fp)
		nop
		addiu	$sp, $sp, 8
		add	$t0, $t0, $t1
		sw	$t0, -8($fp)
		lw	$t0, 92($fp)
		nop
		lw	$t1, -8($fp)
		nop
		addiu	$sp, $sp, 8
		add	$t0, $t0, $t1
		add	$v0, $t0, $0 	# return value
		j	add_end_0

add_end_0:
		lw	$s0, 8($fp)
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp)
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp)
		lw	$fp, 0($fp)
		nop
		addiu	$sp, $sp, 116
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

main:
.globl main
		addiu	$sp, $sp, -116
		sw	$fp, 0($sp)
		add	$fp, $sp, $0
		sw	$ra, 4($sp)
		addiu	$t9, $ra, 0
		sw	$s0, 8($sp)
		sw	$s1, 12($sp)
		sw	$s2, 16($sp)
		sw	$s3, 20($sp)
		sw	$s4, 24($sp)
		sw	$s5, 28($sp)
		sw	$s6, 32($sp)
		sw	$s7, 36($sp)
		sw	$a0, 40($sp)
		sw	$a1, 44($sp)
		sw	$a2, 48($sp)
		sw	$a3, 52($sp)
		sw	$gp, 56($sp)
		nop
		li	$t0, 1
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -8($fp) 		# (arg) storing in virtual
		li	$t0, 2
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -16($fp) 		# (arg) storing in virtual
		li	$t0, 3
		addiu	$sp, $sp, -8 		# Expanding stack
		sw	$t0, -24($fp) 		# (arg) storing in virtual
		move	$t9, $fp
		jal	add	# (fn call) enter fn def
		nop
		sw	$v0, 108($fp)		# (assign) storing function result
		lw	$t0, 108($fp)
		nop
		add	$v0, $t0, $0 	# return value
		j	main_end_1

main_end_1:
		lw	$s0, 8($fp)
		lw	$s1, 12($fp)
		lw	$s2, 16($fp)
		lw	$s3, 20($fp)
		lw	$s4, 24($fp)
		lw	$s5, 28($fp)
		lw	$s6, 32($fp)
		lw	$s7, 36($fp)
		lw	$a0, 40($fp)
		lw	$a1, 44($fp)
		lw	$a2, 48($fp)
		lw	$a3, 52($fp)
		lw	$ra, 4($fp)
		lw	$fp, 0($fp)
		nop
		addiu	$sp, $sp, 116
		beq	$ra, $0, end
		nop
		jr	$ra
		nop

end:
