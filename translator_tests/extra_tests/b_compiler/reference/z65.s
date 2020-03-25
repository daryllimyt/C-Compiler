.text
.globl f
f:
.ent f
    addiu $t5, $gp, 0
    .frame $sp, 64, $ra
    .set noreorder
    .cpload $t8
    .set reorder
    addiu $sp, $sp, -64
    sw $fp, 0($sp)
    add $fp, $sp, $0
    sw $ra, 4($sp)
    addiu $t9, $ra, 0
    sw $s0, 8($sp)
    sw $s1, 12($sp)
    sw $s2, 16($sp)
    sw $s3, 20($sp)
    sw $s4, 24($sp)
    sw $s5, 28($sp)
    sw $s6, 32($sp)
    sw $s7, 36($sp)
    sw $gp, 40($gp)
    .cprestore 44
    addiu $gp, $t5, 0
    addiu $t0, $a0, 0
    sw $t0, 56($fp)
    addiu $t0, $0, 0
    addiu $t1, $0, 0
    addiu $t2, $0, 0
    addiu $t3, $0, 0
    addiu $t4, $0, 0
    addiu $t5, $0, 0
    addiu $t6, $0, 0
    addiu $t7, $0, 0
    addiu $t8, $0, 0
    addiu $s0, $0, 0
    addiu $s1, $0, 0
    addiu $s2, $0, 0
    addiu $s3, $0, 0
    addiu $s4, $0, 0
    addiu $s5, $0, 0
    addiu $s6, $0, 0
    addiu $s7, $0, 0
    addiu $v0, $0, 0
    addiu $v1, $0, 0
    lw $t0, 56($fp)
    add $v0, $t0, $0
    j label_1
label_1:
    addiu $t0, $0, 0
    addiu $t1, $0, 0
    addiu $t2, $0, 0
    addiu $t3, $0, 0
    addiu $t4, $0, 0
    addiu $t5, $0, 0
    addiu $t6, $0, 0
    addiu $t7, $0, 0
    addiu $t8, $0, 0
    addiu $s0, $0, 0
    addiu $s1, $0, 0
    addiu $s2, $0, 0
    addiu $s3, $0, 0
    addiu $s4, $0, 0
    addiu $s5, $0, 0
    addiu $s6, $0, 0
    addiu $s7, $0, 0
    addiu $a0, $0, 0
    addiu $a1, $0, 0
    addiu $a2, $0, 0
    addiu $a3, $0, 0
    lw $s0, 8($fp)
    lw $s1, 12($fp)
    lw $s2, 16($fp)
    lw $s3, 20($fp)
    lw $s4, 24($fp)
    lw $s5, 28($fp)
    lw $s6, 32($fp)
    lw $s7, 36($fp)
    lw $ra, 4($fp)
    lw $fp, 0($fp)
    addiu $sp, $sp, 64
    beq $ra, $0, label_0
    jr $ra
    .end f
.globl fmain
fmain:
.ent fmain
    addiu $t5, $gp, 0
    .frame $sp, 80, $ra
    .set noreorder
    .cpload $t8
    .set reorder
    addiu $sp, $sp, -80
    sw $fp, 0($sp)
    add $fp, $sp, $0
    sw $ra, 4($sp)
    addiu $t9, $ra, 0
    sw $s0, 8($sp)
    sw $s1, 12($sp)
    sw $s2, 16($sp)
    sw $s3, 20($sp)
    sw $s4, 24($sp)
    sw $s5, 28($sp)
    sw $s6, 32($sp)
    sw $s7, 36($sp)
    sw $gp, 40($gp)
    .cprestore 44
    addiu $gp, $t5, 0
    addiu $t0, $0, 0
    addiu $t1, $0, 0
    addiu $t2, $0, 0
    addiu $t3, $0, 0
    addiu $t4, $0, 0
    addiu $t5, $0, 0
    addiu $t6, $0, 0
    addiu $t7, $0, 0
    addiu $t8, $0, 0
    addiu $s0, $0, 0
    addiu $s1, $0, 0
    addiu $s2, $0, 0
    addiu $s3, $0, 0
    addiu $s4, $0, 0
    addiu $s5, $0, 0
    addiu $s6, $0, 0
    addiu $s7, $0, 0
    addiu $v0, $0, 0
    addiu $v1, $0, 0
    lui $t0, 0
    addi $t0, $t0, 1
    sw $t0, 72($fp)
    lw $t0, 72($fp)
    sw $t0, 44($fp)
    addiu $t4, $fp, 44
    addiu $t3, $sp, 0
    lw $t0, 0($t4)
    addiu $a0, $t0, 0
    jal f
    add $t0, $v0, $0
    add $v0, $t0, $0
    j label_2
    label_2:
    addiu $t0, $0, 0
    addiu $t1, $0, 0
    addiu $t2, $0, 0
    addiu $t3, $0, 0
    addiu $t4, $0, 0
    addiu $t5, $0, 0
    addiu $t6, $0, 0
    addiu $t7, $0, 0
    addiu $t8, $0, 0
    addiu $s0, $0, 0
    addiu $s1, $0, 0
    addiu $s2, $0, 0
    addiu $s3, $0, 0
    addiu $s4, $0, 0
    addiu $s5, $0, 0
    addiu $s6, $0, 0
    addiu $s7, $0, 0
    addiu $a0, $0, 0
    addiu $a1, $0, 0
    addiu $a2, $0, 0
    addiu $a3, $0, 0
    lw $s0, 8($fp)
    lw $s1, 12($fp)
    lw $s2, 16($fp)
    lw $s3, 20($fp)
    lw $s4, 24($fp)
    lw $s5, 28($fp)
    lw $s6, 32($fp)
    lw $s7, 36($fp)
    lw $ra, 4($fp)
    lw $fp, 0($fp)
    addiu $sp, $sp, 80
    beq $ra, $0, label_0
    jr $ra
    .end fmain
label_0:
sll $0, $0, 0
sll $0, $0, 0
sll $0, $0, 0
sll $0, $0, 0
sll $0, $0, 0