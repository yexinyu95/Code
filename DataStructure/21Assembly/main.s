	.file	"main.c"
	.intel_syntax noprefix
 # GNU C17 (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) version 8.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 8.1.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.18-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -imultilib 32
 # -iprefix C:/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/
 # -D_REENTRANT main.c -m32 -masm=intel -mtune=generic -march=i686
 # -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
 # -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
 # -fpeephole -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fshrink-wrap-separate
 # -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
 # -m96bit-long-double -maccumulate-outgoing-args -malign-double
 # -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mstv -mvzeroupper

	.text
	.section .rdata,"dr"
LC0:
	.ascii "i=%d\12\0"
	.text
	.globl	_assign
	.def	_assign;	.scl	2;	.type	32;	.endef
_assign:
	push	ebp	 #
	mov	ebp, esp	 #,
	sub	esp, 56	 #,
 # main.c:8:     int arr[3]={1,2,3};
	mov	DWORD PTR [ebp-32], 1	 # arr,
	mov	DWORD PTR [ebp-28], 2	 # arr,
	mov	DWORD PTR [ebp-24], 3	 # arr,
 # main.c:10:     int i=5;
	mov	DWORD PTR [ebp-12], 5	 # i,
 # main.c:11:     int j=10;
	mov	DWORD PTR [ebp-16], 10	 # j,
 # main.c:12:     i=arr[2];
	mov	eax, DWORD PTR [ebp-24]	 # tmp87, arr
	mov	DWORD PTR [ebp-12], eax	 # i, tmp87
 # main.c:13:     p=arr;
	lea	eax, [ebp-32]	 # tmp88,
	mov	DWORD PTR [ebp-20], eax	 # p, tmp88
 # main.c:14:     printf("i=%d\n", i);
	mov	eax, DWORD PTR [ebp-12]	 # tmp89, i
	mov	DWORD PTR [esp+4], eax	 #, tmp89
	mov	DWORD PTR [esp], OFFSET FLAT:LC0	 #,
	call	_printf	 #
 # main.c:15: }
	nop	
	leave	
	ret	
	.section .rdata,"dr"
LC1:
	.ascii "i is small\0"
LC2:
	.ascii "This is loop\0"
	.text
	.globl	_control
	.def	_control;	.scl	2;	.type	32;	.endef
_control:
	push	ebp	 #
	mov	ebp, esp	 #,
	sub	esp, 40	 #,
 # main.c:18:     int i=5;
	mov	DWORD PTR [ebp-16], 5	 # i,
 # main.c:19:     int j=10;
	mov	DWORD PTR [ebp-20], 10	 # j,
 # main.c:20:     if(i<j){
	mov	eax, DWORD PTR [ebp-16]	 # tmp87, i
	cmp	eax, DWORD PTR [ebp-20]	 # tmp87, j
	jge	L3	 #,
 # main.c:21:         printf("i is small\n");
	mov	DWORD PTR [esp], OFFSET FLAT:LC1	 #,
	call	_puts	 #
L3:
 # main.c:24:     for (int k = 0; k < 5; ++k) {
	mov	DWORD PTR [ebp-12], 0	 # k,
 # main.c:24:     for (int k = 0; k < 5; ++k) {
	jmp	L4	 #
L5:
 # main.c:25:         printf("This is loop\n");
	mov	DWORD PTR [esp], OFFSET FLAT:LC2	 #,
	call	_puts	 #
 # main.c:24:     for (int k = 0; k < 5; ++k) {
	add	DWORD PTR [ebp-12], 1	 # k,
L4:
 # main.c:24:     for (int k = 0; k < 5; ++k) {
	cmp	DWORD PTR [ebp-12], 4	 # k,
	jle	L5	 #,
 # main.c:27: }
	nop	
	leave	
	ret	
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
	push	ebp	 #
	mov	ebp, esp	 #,
	sub	esp, 16	 #,
 # main.c:31:     ret=a+b;
	mov	edx, DWORD PTR [ebp+8]	 # tmp93, a
	mov	eax, DWORD PTR [ebp+12]	 # tmp94, b
	add	eax, edx	 # tmp92, tmp93
	mov	DWORD PTR [ebp-4], eax	 # ret, tmp92
 # main.c:32:     return ret;
	mov	eax, DWORD PTR [ebp-4]	 # _4, ret
 # main.c:33: }
	leave	
	ret	
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC3:
	.ascii "add result = \12.\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp	 #
	mov	ebp, esp	 #,
	and	esp, -16	 #,
	sub	esp, 32	 #,
 # main.c:35: int main() {
	call	___main	 #
 # main.c:38:     a=5;
	mov	DWORD PTR [esp+16], 5	 # a,
 # main.c:39:     p=&a;
	lea	eax, [esp+16]	 # tmp91,
	mov	DWORD PTR [esp+28], eax	 # p, tmp91
 # main.c:40:     b=*p+2;
	mov	eax, DWORD PTR [esp+28]	 # tmp92, p
	mov	eax, DWORD PTR [eax]	 # _1, *p_5
 # main.c:40:     b=*p+2;
	add	eax, 2	 # tmp93,
	mov	DWORD PTR [esp+24], eax	 # b, tmp93
 # main.c:41:     ret=add(a,b);
	mov	eax, DWORD PTR [esp+16]	 # a.0_2, a
	mov	edx, DWORD PTR [esp+24]	 # tmp94, b
	mov	DWORD PTR [esp+4], edx	 #, tmp94
	mov	DWORD PTR [esp], eax	 #, a.0_2
	call	_add	 #
	mov	DWORD PTR [esp+20], eax	 # ret, tmp95
 # main.c:42:     printf("add result = \n.", ret);
	mov	eax, DWORD PTR [esp+20]	 # tmp96, ret
	mov	DWORD PTR [esp+4], eax	 #, tmp96
	mov	DWORD PTR [esp], OFFSET FLAT:LC3	 #,
	call	_printf	 #
 # main.c:44:     return 0;
	mov	eax, 0	 # _10,
 # main.c:45: }
	leave	
	ret	
	.ident	"GCC: (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
