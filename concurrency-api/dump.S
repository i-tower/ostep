
scratch:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 72 2f 00 00    	push   0x2f72(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 74 2f 00 00    	jmp    *0x2f74(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)
    1030:	f3 0f 1e fa          	endbr64
    1034:	68 00 00 00 00       	push   $0x0
    1039:	e9 e2 ff ff ff       	jmp    1020 <_init+0x20>
    103e:	66 90                	xchg   %ax,%ax
    1040:	f3 0f 1e fa          	endbr64
    1044:	68 01 00 00 00       	push   $0x1
    1049:	e9 d2 ff ff ff       	jmp    1020 <_init+0x20>
    104e:	66 90                	xchg   %ax,%ax
    1050:	f3 0f 1e fa          	endbr64
    1054:	68 02 00 00 00       	push   $0x2
    1059:	e9 c2 ff ff ff       	jmp    1020 <_init+0x20>
    105e:	66 90                	xchg   %ax,%ax
    1060:	f3 0f 1e fa          	endbr64
    1064:	68 03 00 00 00       	push   $0x3
    1069:	e9 b2 ff ff ff       	jmp    1020 <_init+0x20>
    106e:	66 90                	xchg   %ax,%ax
    1070:	f3 0f 1e fa          	endbr64
    1074:	68 04 00 00 00       	push   $0x4
    1079:	e9 a2 ff ff ff       	jmp    1020 <_init+0x20>
    107e:	66 90                	xchg   %ax,%ax
    1080:	f3 0f 1e fa          	endbr64
    1084:	68 05 00 00 00       	push   $0x5
    1089:	e9 92 ff ff ff       	jmp    1020 <_init+0x20>
    108e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.got:

0000000000001090 <__cxa_finalize@plt>:
    1090:	f3 0f 1e fa          	endbr64
    1094:	ff 25 5e 2f 00 00    	jmp    *0x2f5e(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    109a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

00000000000010a0 <puts@plt>:
    10a0:	f3 0f 1e fa          	endbr64
    10a4:	ff 25 fe 2e 00 00    	jmp    *0x2efe(%rip)        # 3fa8 <puts@GLIBC_2.2.5>
    10aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010b0 <__stack_chk_fail@plt>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	ff 25 f6 2e 00 00    	jmp    *0x2ef6(%rip)        # 3fb0 <__stack_chk_fail@GLIBC_2.4>
    10ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010c0 <errx@plt>:
    10c0:	f3 0f 1e fa          	endbr64
    10c4:	ff 25 ee 2e 00 00    	jmp    *0x2eee(%rip)        # 3fb8 <errx@GLIBC_2.2.5>
    10ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010d0 <printf@plt>:
    10d0:	f3 0f 1e fa          	endbr64
    10d4:	ff 25 e6 2e 00 00    	jmp    *0x2ee6(%rip)        # 3fc0 <printf@GLIBC_2.2.5>
    10da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010e0 <pthread_create@plt>:
    10e0:	f3 0f 1e fa          	endbr64
    10e4:	ff 25 de 2e 00 00    	jmp    *0x2ede(%rip)        # 3fc8 <pthread_create@GLIBC_2.34>
    10ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010f0 <pthread_join@plt>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	ff 25 d6 2e 00 00    	jmp    *0x2ed6(%rip)        # 3fd0 <pthread_join@GLIBC_2.34>
    10fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001100 <_start>:
    1100:	f3 0f 1e fa          	endbr64
    1104:	31 ed                	xor    %ebp,%ebp
    1106:	49 89 d1             	mov    %rdx,%r9
    1109:	5e                   	pop    %rsi
    110a:	48 89 e2             	mov    %rsp,%rdx
    110d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1111:	50                   	push   %rax
    1112:	54                   	push   %rsp
    1113:	45 31 c0             	xor    %r8d,%r8d
    1116:	31 c9                	xor    %ecx,%ecx
    1118:	48 8d 3d fc 00 00 00 	lea    0xfc(%rip),%rdi        # 121b <main>
    111f:	ff 15 b3 2e 00 00    	call   *0x2eb3(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1125:	f4                   	hlt
    1126:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    112d:	00 00 00 

0000000000001130 <deregister_tm_clones>:
    1130:	48 8d 3d d9 2e 00 00 	lea    0x2ed9(%rip),%rdi        # 4010 <__TMC_END__>
    1137:	48 8d 05 d2 2e 00 00 	lea    0x2ed2(%rip),%rax        # 4010 <__TMC_END__>
    113e:	48 39 f8             	cmp    %rdi,%rax
    1141:	74 15                	je     1158 <deregister_tm_clones+0x28>
    1143:	48 8b 05 96 2e 00 00 	mov    0x2e96(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    114a:	48 85 c0             	test   %rax,%rax
    114d:	74 09                	je     1158 <deregister_tm_clones+0x28>
    114f:	ff e0                	jmp    *%rax
    1151:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1158:	c3                   	ret
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <register_tm_clones>:
    1160:	48 8d 3d a9 2e 00 00 	lea    0x2ea9(%rip),%rdi        # 4010 <__TMC_END__>
    1167:	48 8d 35 a2 2e 00 00 	lea    0x2ea2(%rip),%rsi        # 4010 <__TMC_END__>
    116e:	48 29 fe             	sub    %rdi,%rsi
    1171:	48 89 f0             	mov    %rsi,%rax
    1174:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1178:	48 c1 f8 03          	sar    $0x3,%rax
    117c:	48 01 c6             	add    %rax,%rsi
    117f:	48 d1 fe             	sar    $1,%rsi
    1182:	74 14                	je     1198 <register_tm_clones+0x38>
    1184:	48 8b 05 65 2e 00 00 	mov    0x2e65(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    118b:	48 85 c0             	test   %rax,%rax
    118e:	74 08                	je     1198 <register_tm_clones+0x38>
    1190:	ff e0                	jmp    *%rax
    1192:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1198:	c3                   	ret
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <__do_global_dtors_aux>:
    11a0:	f3 0f 1e fa          	endbr64
    11a4:	80 3d 65 2e 00 00 00 	cmpb   $0x0,0x2e65(%rip)        # 4010 <__TMC_END__>
    11ab:	75 2b                	jne    11d8 <__do_global_dtors_aux+0x38>
    11ad:	55                   	push   %rbp
    11ae:	48 83 3d 42 2e 00 00 	cmpq   $0x0,0x2e42(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    11b5:	00 
    11b6:	48 89 e5             	mov    %rsp,%rbp
    11b9:	74 0c                	je     11c7 <__do_global_dtors_aux+0x27>
    11bb:	48 8b 3d 46 2e 00 00 	mov    0x2e46(%rip),%rdi        # 4008 <__dso_handle>
    11c2:	e8 c9 fe ff ff       	call   1090 <__cxa_finalize@plt>
    11c7:	e8 64 ff ff ff       	call   1130 <deregister_tm_clones>
    11cc:	c6 05 3d 2e 00 00 01 	movb   $0x1,0x2e3d(%rip)        # 4010 <__TMC_END__>
    11d3:	5d                   	pop    %rbp
    11d4:	c3                   	ret
    11d5:	0f 1f 00             	nopl   (%rax)
    11d8:	c3                   	ret
    11d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011e0 <frame_dummy>:
    11e0:	f3 0f 1e fa          	endbr64
    11e4:	e9 77 ff ff ff       	jmp    1160 <register_tm_clones>

00000000000011e9 <work>:
    11e9:	f3 0f 1e fa          	endbr64
    11ed:	55                   	push   %rbp
    11ee:	48 89 e5             	mov    %rsp,%rbp
    11f1:	48 83 ec 10          	sub    $0x10,%rsp
    11f5:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    11f9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11fd:	48 89 c6             	mov    %rax,%rsi
    1200:	48 8d 05 fd 0d 00 00 	lea    0xdfd(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    1207:	48 89 c7             	mov    %rax,%rdi
    120a:	b8 00 00 00 00       	mov    $0x0,%eax
    120f:	e8 bc fe ff ff       	call   10d0 <printf@plt>
    1214:	b8 00 00 00 00       	mov    $0x0,%eax
    1219:	c9                   	leave
    121a:	c3                   	ret

000000000000121b <main>:
    121b:	f3 0f 1e fa          	endbr64
    121f:	55                   	push   %rbp
    1220:	48 89 e5             	mov    %rsp,%rbp
    1223:	48 83 ec 30          	sub    $0x30,%rsp
    1227:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    122e:	00 00 
    1230:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1234:	31 c0                	xor    %eax,%eax
    1236:	48 8d 05 d6 0d 00 00 	lea    0xdd6(%rip),%rax        # 2013 <_IO_stdin_used+0x13>
    123d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1241:	48 8d 05 cd 0d 00 00 	lea    0xdcd(%rip),%rax        # 2015 <_IO_stdin_used+0x15>
    1248:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    124c:	48 8d 05 c4 0d 00 00 	lea    0xdc4(%rip),%rax        # 2017 <_IO_stdin_used+0x17>
    1253:	48 89 c7             	mov    %rax,%rdi
    1256:	e8 45 fe ff ff       	call   10a0 <puts@plt>
    125b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    125f:	48 8d 45 d8          	lea    -0x28(%rbp),%rax
    1263:	48 89 d1             	mov    %rdx,%rcx
    1266:	48 8d 15 7c ff ff ff 	lea    -0x84(%rip),%rdx        # 11e9 <work>
    126d:	be 00 00 00 00       	mov    $0x0,%esi
    1272:	48 89 c7             	mov    %rax,%rdi
    1275:	e8 66 fe ff ff       	call   10e0 <pthread_create@plt>
    127a:	85 c0                	test   %eax,%eax
    127c:	79 19                	jns    1297 <main+0x7c>
    127e:	48 8d 05 9c 0d 00 00 	lea    0xd9c(%rip),%rax        # 2021 <_IO_stdin_used+0x21>
    1285:	48 89 c6             	mov    %rax,%rsi
    1288:	bf 01 00 00 00       	mov    $0x1,%edi
    128d:	b8 00 00 00 00       	mov    $0x0,%eax
    1292:	e8 29 fe ff ff       	call   10c0 <errx@plt>
    1297:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    129b:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    129f:	48 89 d1             	mov    %rdx,%rcx
    12a2:	48 8d 15 40 ff ff ff 	lea    -0xc0(%rip),%rdx        # 11e9 <work>
    12a9:	be 00 00 00 00       	mov    $0x0,%esi
    12ae:	48 89 c7             	mov    %rax,%rdi
    12b1:	e8 2a fe ff ff       	call   10e0 <pthread_create@plt>
    12b6:	85 c0                	test   %eax,%eax
    12b8:	79 19                	jns    12d3 <main+0xb8>
    12ba:	48 8d 05 60 0d 00 00 	lea    0xd60(%rip),%rax        # 2021 <_IO_stdin_used+0x21>
    12c1:	48 89 c6             	mov    %rax,%rsi
    12c4:	bf 01 00 00 00       	mov    $0x1,%edi
    12c9:	b8 00 00 00 00       	mov    $0x0,%eax
    12ce:	e8 ed fd ff ff       	call   10c0 <errx@plt>
    12d3:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    12d7:	be 00 00 00 00       	mov    $0x0,%esi
    12dc:	48 89 c7             	mov    %rax,%rdi
    12df:	e8 0c fe ff ff       	call   10f0 <pthread_join@plt>
    12e4:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    12e8:	be 00 00 00 00       	mov    $0x0,%esi
    12ed:	48 89 c7             	mov    %rax,%rdi
    12f0:	e8 fb fd ff ff       	call   10f0 <pthread_join@plt>
    12f5:	48 8d 05 35 0d 00 00 	lea    0xd35(%rip),%rax        # 2031 <_IO_stdin_used+0x31>
    12fc:	48 89 c7             	mov    %rax,%rdi
    12ff:	e8 9c fd ff ff       	call   10a0 <puts@plt>
    1304:	b8 00 00 00 00       	mov    $0x0,%eax
    1309:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    130d:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    1314:	00 00 
    1316:	74 05                	je     131d <main+0x102>
    1318:	e8 93 fd ff ff       	call   10b0 <__stack_chk_fail@plt>
    131d:	c9                   	leave
    131e:	c3                   	ret

Disassembly of section .fini:

0000000000001320 <_fini>:
    1320:	f3 0f 1e fa          	endbr64
    1324:	48 83 ec 08          	sub    $0x8,%rsp
    1328:	48 83 c4 08          	add    $0x8,%rsp
    132c:	c3                   	ret
Contents of the .eh_frame section (loaded from scratch):


00000000 0000000000000014 00000000 CIE
  Version:               1
  Augmentation:          "zR"
  Code alignment factor: 1
  Data alignment factor: -8
  Return address column: 16
  Augmentation data:     1b
  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_offset: r16 (rip) at cfa-8
  DW_CFA_nop
  DW_CFA_nop

00000018 0000000000000014 0000001c FDE cie=00000000 pc=0000000000001100..0000000000001126
  DW_CFA_advance_loc: 4 to 0000000000001104
  DW_CFA_undefined: r16 (rip)
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_noprip001030
  DW_CFA_def_cfa_expression (DW_OP_breg7 (rsp): 8; DW_OP_breg16 (rip): 0; DW_OP_lit15; DW_OP_and; DW_OP_lit9; DW_OP_ge; DW_OP_lit3; DW_OP_shl; DW_OP_plus)
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000058 0000000000000014 0000005c FDE cie=00000000 pc=0000000000001090..00000000000010a0
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000070 0000000000000014 00000074 FDE cie=00000000 pc=00000000000010a0..0000000000001100
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000088 000000000000001c 0000008c FDE cie=00000000 pc=00000000000011e9..000000000000121b
  DW_CFA_advance_loc: 5 to 00000000000011ee
  DW_CFA_def_cfa_offset: 16
  DW_CFA_offset: r6 (rbp) at cfa-16
  DW_CFA_advance_loc: 3 to 00000000000011f1
  DW_CFA_def_cfa_register: r6 (rbp)
  DW_CFA_advance_loc: 41 to 000000000000121a
  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

000000a8 000000000000001c 000000ac FDE cie=00000000 pc=000000000000121b..000000000000131f
  DW_CFA_advance_loc: 5 to 0000000000001220
  DW_CFA_def_cfa_offset: 16
  DW_CFA_offset: r6 (rbp) at cfa-16
  DW_CFA_advance_loc: 3 to 0000000000001223
  DW_CFA_def_cfa_register: r6 (rbp)
  DW_CFA_advance_loc1: 251 to 000000000000131e
  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_nop
  DW_CFA_nop

000000c8 ZERO terminator


Contents of the .debug_aranges section (loaded from scratch):

  Length:                   44
  Version:                  2
  Offset into .debug_info:  0
  Pointer Size:             8
  Segment Size:             0

    Address            Length
    00000000000011e9 0000000000000136
    0000000000000000 0000000000000000

Contents of the .debug_info section (loaded from scratch):

  Compilation Unit @ offset 0:
   Length:        0x20a (32-bit)
   Version:       5
   Unit Type:     DW_UT_compile (1)
   Abbrev Offset: 0
   Pointer Size:  8
 <0><c>: Abbrev Number: 12 (DW_TAG_compile_unit)
    <d>   DW_AT_producer    : (indirect string, offset: 0xa5): GNU C23 14.2.0 -mtune=generic -march=x86-64 -ggdb -O0 -std=c23 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
    <11>   DW_AT_language    : 29	(C11)
    <12>   DW_AT_name        : (indirect line string, offset: 0x29): scratch.c
    <16>   DW_AT_comp_dir    : (indirect line string, offset: 0): /home/ian/Projects/ostep/concurrency-api
    <1a>   DW_AT_low_pc      : 0x11e9
    <22>   DW_AT_high_pc     : 0x136
    <2a>   DW_AT_stmt_list   : 0
 <1><2e>: Abbrev Number: 2 (DW_TAG_base_type)
    <2f>   DW_AT_byte_size   : 8
    <30>   DW_AT_encoding    : 7	(unsigned)
    <31>   DW_AT_name        : (indirect string, offset: 0x44): long unsigned int
 <1><35>: Abbrev Number: 2 (DW_TAG_base_type)
    <36>   DW_AT_byte_size   : 4
    <37>   DW_AT_encoding    : 7	(unsigned)
    <38>   DW_AT_name        : (indirect string, offset: 0x49): unsigned int
 <1><3c>: Abbrev Number: 13 (DW_TAG_pointer_type)
    <3d>   DW_AT_byte_size   : 8
 <1><3e>: Abbrev Number: 5 (DW_TAG_restrict_type)
    <3f>   DW_AT_type        : <0x3c>
 <1><43>: Abbrev Number: 2 (DW_TAG_base_type)
    <44>   DW_AT_byte_size   : 1
    <45>   DW_AT_encoding    : 8	(unsigned char)
    <46>   DW_AT_name        : (indirect string, offset: 0x18): unsigned char
 <1><4a>: Abbrev Number: 2 (DW_TAG_base_type)
    <4b>   DW_AT_byte_size   : 2
    <4c>   DW_AT_encoding    : 7	(unsigned)
    <4d>   DW_AT_name        : (indirect string, offset: 0x81): short unsigned int
 <1><51>: Abbrev Number: 2 (DW_TAG_base_type)
    <52>   DW_AT_byte_size   : 1
    <53>   DW_AT_encoding    : 6	(signed char)
    <54>   DW_AT_name        : (indirect string, offset: 0x1a): signed char
 <1><58>: Abbrev Number: 2 (DW_TAG_base_type)
    <59>   DW_AT_byte_size   : 2
    <5a>   DW_AT_encoding    : 5	(signed)
    <5b>   DW_AT_name        : (indirect string, offset: 0x9b): short int
 <1><5f>: Abbrev Number: 14 (DW_TAG_base_type)
    <60>   DW_AT_byte_size   : 4
    <61>   DW_AT_encoding    : 5	(signed)
    <62>   DW_AT_name        : int
 <1><66>: Abbrev Number: 2 (DW_TAG_base_type)
    <67>   DW_AT_byte_size   : 8
    <68>   DW_AT_encoding    : 5	(signed)
    <69>   DW_AT_name        : (indirect string, offset: 0x5): long int
 <1><6d>: Abbrev Number: 3 (DW_TAG_pointer_type)
    <6e>   DW_AT_byte_size   : 8
    <6e>   DW_AT_type        : <0x72>
 <1><72>: Abbrev Number: 2 (DW_TAG_base_type)
    <73>   DW_AT_byte_size   : 1
    <74>   DW_AT_encoding    : 6	(signed char)
    <75>   DW_AT_name        : (indirect string, offset: 0x21): char
 <1><79>: Abbrev Number: 6 (DW_TAG_const_type)
    <7a>   DW_AT_type        : <0x72>
 <1><7e>: Abbrev Number: 3 (DW_TAG_pointer_type)
    <7f>   DW_AT_byte_size   : 8
    <7f>   DW_AT_type        : <0x79>
 <1><83>: Abbrev Number: 2 (DW_TAG_base_type)
    <84>   DW_AT_byte_size   : 8
    <85>   DW_AT_encoding    : 7	(unsigned)
    <86>   DW_AT_name        : (indirect string, offset: 0x3f): long long unsigned int
 <1><8a>: Abbrev Number: 7 (DW_TAG_typedef)
    <8b>   DW_AT_name        : (indirect string, offset: 0x143): pthread_t
    <8f>   DW_AT_decl_file   : 2
    <8f>   DW_AT_decl_line   : 27
    <90>   DW_AT_decl_column : 27
    <91>   DW_AT_type        : <0x2e>
 <1><95>: Abbrev Number: 15 (DW_TAG_union_type)
    <96>   DW_AT_name        : (indirect string, offset: 0x2b): pthread_attr_t
    <9a>   DW_AT_byte_size   : 56
    <9b>   DW_AT_decl_file   : 2
    <9c>   DW_AT_decl_line   : 56
    <9d>   DW_AT_decl_column : 7
    <9e>   DW_AT_sibling     : <0xb9>
 <2><a2>: Abbrev Number: 8 (DW_TAG_member)
    <a3>   DW_AT_name        : (indirect string, offset: 0x7a): __size
    <a7>   DW_AT_decl_file   : 2
    <a7>   DW_AT_decl_line   : 58
    <a8>   DW_AT_decl_column : 8
    <a9>   DW_AT_type        : <0xb9>
 <2><ad>: Abbrev Number: 8 (DW_TAG_member)
    <ae>   DW_AT_name        : (indirect string, offset: 0x65): __align
    <b2>   DW_AT_decl_file   : 2
    <b2>   DW_AT_decl_line   : 59
    <b3>   DW_AT_decl_column : 12
    <b4>   DW_AT_type        : <0x66>
 <2><b8>: Abbrev Number: 0
 <1><b9>: Abbrev Number: 16 (DW_TAG_array_type)
    <ba>   DW_AT_type        : <0x72>
    <be>   DW_AT_sibling     : <0xc9>
 <2><c2>: Abbrev Number: 17 (DW_TAG_subrange_type)
    <c3>   DW_AT_type        : <0x2e>
    <c7>   DW_AT_upper_bound : 55
 <2><c8>: Abbrev Number: 0
 <1><c9>: Abbrev Number: 7 (DW_TAG_typedef)
    <ca>   DW_AT_name        : (indirect string, offset: 0x2b): pthread_attr_t
    <ce>   DW_AT_decl_file   : 2
    <ce>   DW_AT_decl_line   : 62
    <cf>   DW_AT_decl_column : 30
    <d0>   DW_AT_type        : <0x95>
 <1><d4>: Abbrev Number: 6 (DW_TAG_const_type)
    <d5>   DW_AT_type        : <0xc9>
 <1><d9>: Abbrev Number: 2 (DW_TAG_base_type)
    <da>   DW_AT_byte_size   : 8
    <db>   DW_AT_encoding    : 5	(signed)
    <dc>   DW_AT_name        : (indirect string, offset: 0): long long int
 <1><e0>: Abbrev Number: 9 (DW_TAG_subprogram)
    <e1>   DW_AT_external    : 1
    <e1>   DW_AT_name        : (indirect string, offset: 0x6d): pthread_join
    <e5>   DW_AT_decl_file   : 3
    <e5>   DW_AT_decl_line   : 219
    <e6>   DW_AT_decl_column : 12
    <e6>   DW_AT_prototyped  : 1
    <e6>   DW_AT_type        : <0x5f>
    <ea>   DW_AT_declaration : 1
    <ea>   DW_AT_sibling     : <0xf9>
 <2><ee>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <ef>   DW_AT_type        : <0x8a>
 <2><f3>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <f4>   DW_AT_type        : <0xf9>
 <2><f8>: Abbrev Number: 0
 <1><f9>: Abbrev Number: 3 (DW_TAG_pointer_type)
    <fa>   DW_AT_byte_size   : 8
    <fa>   DW_AT_type        : <0x3c>
 <1><fe>: Abbrev Number: 18 (DW_TAG_subprogram)
    <ff>   DW_AT_external    : 1
    <ff>   DW_AT_name        : (indirect string, offset: 0x3a): errx
    <103>   DW_AT_decl_file   : 4
    <104>   DW_AT_decl_line   : 50
    <105>   DW_AT_decl_column : 13
    <106>   DW_AT_prototyped  : 1
    <106>   DW_AT_noreturn    : 1
    <106>   DW_AT_declaration : 1
    <106>   DW_AT_sibling     : <0x116>
 <2><10a>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <10b>   DW_AT_type        : <0x5f>
 <2><10f>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <110>   DW_AT_type        : <0x7e>
 <2><114>: Abbrev Number: 10 (DW_TAG_unspecified_parameters)
 <2><115>: Abbrev Number: 0
 <1><116>: Abbrev Number: 9 (DW_TAG_subprogram)
    <117>   DW_AT_external    : 1
    <117>   DW_AT_name        : (indirect string, offset: 0x56): pthread_create
    <11b>   DW_AT_decl_file   : 3
    <11b>   DW_AT_decl_line   : 202
    <11c>   DW_AT_decl_column : 12
    <11c>   DW_AT_prototyped  : 1
    <11c>   DW_AT_type        : <0x5f>
    <120>   DW_AT_declaration : 1
    <120>   DW_AT_sibling     : <0x139>
 <2><124>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <125>   DW_AT_type        : <0x13e>
 <2><129>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <12a>   DW_AT_type        : <0x148>
 <2><12e>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <12f>   DW_AT_type        : <0x14d>
 <2><133>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <134>   DW_AT_type        : <0x3e>
 <2><138>: Abbrev Number: 0
 <1><139>: Abbrev Number: 3 (DW_TAG_pointer_type)
    <13a>   DW_AT_byte_size   : 8
    <13a>   DW_AT_type        : <0x8a>
 <1><13e>: Abbrev Number: 5 (DW_TAG_restrict_type)
    <13f>   DW_AT_type        : <0x139>
 <1><143>: Abbrev Number: 3 (DW_TAG_pointer_type)
    <144>   DW_AT_byte_size   : 8
    <144>   DW_AT_type        : <0xd4>
 <1><148>: Abbrev Number: 5 (DW_TAG_restrict_type)
    <149>   DW_AT_type        : <0x143>
 <1><14d>: Abbrev Number: 3 (DW_TAG_pointer_type)
    <14e>   DW_AT_byte_size   : 8
    <14e>   DW_AT_type        : <0x152>
 <1><152>: Abbrev Number: 19 (DW_TAG_subroutine_type)
    <153>   DW_AT_prototyped  : 1
    <153>   DW_AT_type        : <0x3c>
    <157>   DW_AT_sibling     : <0x161>
 <2><15b>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <15c>   DW_AT_type        : <0x3c>
 <2><160>: Abbrev Number: 0
 <1><161>: Abbrev Number: 11 (DW_TAG_subprogram)
    <162>   DW_AT_external    : 1
    <162>   DW_AT_name        : (indirect string, offset: 0x13): puts
    <166>   DW_AT_decl_file   : 5
    <166>   DW_AT_decl_line   : 724
    <168>   DW_AT_decl_column : 12
    <168>   DW_AT_prototyped  : 1
    <168>   DW_AT_type        : <0x5f>
    <16c>   DW_AT_declaration : 1
    <16c>   DW_AT_sibling     : <0x176>
 <2><170>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <171>   DW_AT_type        : <0x7e>
 <2><175>: Abbrev Number: 0
 <1><176>: Abbrev Number: 11 (DW_TAG_subprogram)
    <177>   DW_AT_external    : 1
    <177>   DW_AT_name        : (indirect string, offset: 0x94): printf
    <17b>   DW_AT_decl_file   : 5
    <17b>   DW_AT_decl_line   : 363
    <17d>   DW_AT_decl_column : 12
    <17d>   DW_AT_prototyped  : 1
    <17d>   DW_AT_type        : <0x5f>
    <181>   DW_AT_declaration : 1
    <181>   DW_AT_sibling     : <0x18c>
 <2><185>: Abbrev Number: 1 (DW_TAG_formal_parameter)
    <186>   DW_AT_type        : <0x7e>
 <2><18a>: Abbrev Number: 10 (DW_TAG_unspecified_parameters)
 <2><18b>: Abbrev Number: 0
 <1><18c>: Abbrev Number: 20 (DW_TAG_subprogram)
    <18d>   DW_AT_external    : 1
    <18d>   DW_AT_name        : (indirect string, offset: 0x26): main
    <191>   DW_AT_decl_file   : 1
    <192>   DW_AT_decl_line   : 11
    <193>   DW_AT_decl_column : 5
    <194>   DW_AT_prototyped  : 1
    <194>   DW_AT_type        : <0x5f>
    <198>   DW_AT_low_pc      : 0x121b
    <1a0>   DW_AT_high_pc     : 0x104
    <1a8>   DW_AT_frame_base  : 1 byte block: 9c 	(DW_OP_call_frame_cfa)
    <1aa>   DW_AT_call_all_tail_calls: 1
    <1aa>   DW_AT_sibling     : <0x1e1>
 <2><1ae>: Abbrev Number: 4 (DW_TAG_variable)
    <1af>   DW_AT_name        : p1
    <1b2>   DW_AT_decl_file   : 1
    <1b2>   DW_AT_decl_line   : 13
    <1b3>   DW_AT_decl_column : 15
    <1b4>   DW_AT_type        : <0x8a>
    <1b8>   DW_AT_location    : 2 byte block: 91 48 	(DW_OP_fbreg: -56)
 <2><1bb>: Abbrev Number: 4 (DW_TAG_variable)
    <1bc>   DW_AT_name        : p2
    <1bf>   DW_AT_decl_file   : 1
    <1bf>   DW_AT_decl_line   : 14
    <1c0>   DW_AT_decl_column : 15
    <1c1>   DW_AT_type        : <0x8a>
    <1c5>   DW_AT_location    : 2 byte block: 91 50 	(DW_OP_fbreg: -48)
 <2><1c8>: Abbrev Number: 4 (DW_TAG_variable)
    <1c9>   DW_AT_name        : a
    <1cb>   DW_AT_decl_file   : 1
    <1cb>   DW_AT_decl_line   : 15
    <1cc>   DW_AT_decl_column : 11
    <1cd>   DW_AT_type        : <0x6d>
    <1d1>   DW_AT_location    : 2 byte block: 91 58 	(DW_OP_fbreg: -40)
 <2><1d4>: Abbrev Number: 4 (DW_TAG_variable)
    <1d5>   DW_AT_name        : n
    <1d7>   DW_AT_decl_file   : 1
    <1d7>   DW_AT_decl_line   : 16
    <1d8>   DW_AT_decl_column : 11
    <1d9>   DW_AT_type        : <0x6d>
    <1dd>   DW_AT_location    : 2 byte block: 91 60 	(DW_OP_fbreg: -32)
 <2><1e0>: Abbrev Number: 0
 <1><1e1>: Abbrev Number: 21 (DW_TAG_subprogram)
    <1e2>   DW_AT_external    : 1
    <1e2>   DW_AT_name        : (indirect string, offset: 0xe): work
    <1e6>   DW_AT_decl_file   : 1
    <1e7>   DW_AT_decl_line   : 5
    <1e8>   DW_AT_decl_column : 7
    <1e9>   DW_AT_prototyped  : 1
    <1e9>   DW_AT_type        : <0x3c>
    <1ed>   DW_AT_low_pc      : 0x11e9
    <1f5>   DW_AT_high_pc     : 0x32
    <1fd>   DW_AT_frame_base  : 1 byte block: 9c 	(DW_OP_call_frame_cfa)
    <1ff>   DW_AT_call_all_tail_calls: 1
 <2><1ff>: Abbrev Number: 22 (DW_TAG_formal_parameter)
    <200>   DW_AT_name        : c
    <202>   DW_AT_decl_file   : 1
    <203>   DW_AT_decl_line   : 5
    <204>   DW_AT_decl_column : 18
    <205>   DW_AT_type        : <0x3c>
    <209>   DW_AT_location    : 2 byte block: 91 68 	(DW_OP_fbreg: -24)
 <2><20c>: Abbrev Number: 0
 <1><20d>: Abbrev Number: 0

Contents of the .debug_abbrev section (loaded from scratch):

  Number TAG (0)
   1      DW_TAG_formal_parameter    [no children]
    DW_AT_type         DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   2      DW_TAG_base_type    [no children]
    DW_AT_byte_size    DW_FORM_data1
    DW_AT_encoding     DW_FORM_data1
    DW_AT_name         DW_FORM_strp
    DW_AT value: 0     DW_FORM value: 0
   3      DW_TAG_pointer_type    [no children]
    DW_AT_byte_size    DW_FORM_implicit_const: 8
    DW_AT_type         DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   4      DW_TAG_variable    [no children]
    DW_AT_name         DW_FORM_string
    DW_AT_decl_file    DW_FORM_implicit_const: 1
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_type         DW_FORM_ref4
    DW_AT_location     DW_FORM_exprloc
    DW_AT value: 0     DW_FORM value: 0
   5      DW_TAG_restrict_type    [no children]
    DW_AT_type         DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   6      DW_TAG_const_type    [no children]
    DW_AT_type         DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   7      DW_TAG_typedef    [no children]
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_implicit_const: 2
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_type         DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   8      DW_TAG_member    [no children]
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_implicit_const: 2
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_type         DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   9      DW_TAG_subprogram    [has children]
    DW_AT_external     DW_FORM_flag_present
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_implicit_const: 3
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_implicit_const: 12
    DW_AT_prototyped   DW_FORM_flag_present
    DW_AT_type         DW_FORM_ref4
    DW_AT_declaration  DW_FORM_flag_present
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   10      DW_TAG_unspecified_parameters    [no children]
    DW_AT value: 0     DW_FORM value: 0
   11      DW_TAG_subprogram    [has children]
    DW_AT_external     DW_FORM_flag_present
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_implicit_const: 5
    DW_AT_decl_line    DW_FORM_data2
    DW_AT_decl_column  DW_FORM_implicit_const: 12
    DW_AT_prototyped   DW_FORM_flag_present
    DW_AT_type         DW_FORM_ref4
    DW_AT_declaration  DW_FORM_flag_present
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   12      DW_TAG_compile_unit    [has children]
    DW_AT_producer     DW_FORM_strp
    DW_AT_language     DW_FORM_data1
    DW_AT_name         DW_FORM_line_strp
    DW_AT_comp_dir     DW_FORM_line_strp
    DW_AT_low_pc       DW_FORM_addr
    DW_AT_high_pc      DW_FORM_data8
    DW_AT_stmt_list    DW_FORM_sec_offset
    DW_AT value: 0     DW_FORM value: 0
   13      DW_TAG_pointer_type    [no children]
    DW_AT_byte_size    DW_FORM_data1
    DW_AT value: 0     DW_FORM value: 0
   14      DW_TAG_base_type    [no children]
    DW_AT_byte_size    DW_FORM_data1
    DW_AT_encoding     DW_FORM_data1
    DW_AT_name         DW_FORM_string
    DW_AT value: 0     DW_FORM value: 0
   15      DW_TAG_union_type    [has children]
    DW_AT_name         DW_FORM_strp
    DW_AT_byte_size    DW_FORM_data1
    DW_AT_decl_file    DW_FORM_data1
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   16      DW_TAG_array_type    [has children]
    DW_AT_type         DW_FORM_ref4
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   17      DW_TAG_subrange_type    [no children]
    DW_AT_type         DW_FORM_ref4
    DW_AT_upper_bound  DW_FORM_data1
    DW_AT value: 0     DW_FORM value: 0
   18      DW_TAG_subprogram    [has children]
    DW_AT_external     DW_FORM_flag_present
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_data1
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_prototyped   DW_FORM_flag_present
    DW_AT_noreturn     DW_FORM_flag_present
    DW_AT_declaration  DW_FORM_flag_present
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   19      DW_TAG_subroutine_type    [has children]
    DW_AT_prototyped   DW_FORM_flag_present
    DW_AT_type         DW_FORM_ref4
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   20      DW_TAG_subprogram    [has children]
    DW_AT_external     DW_FORM_flag_present
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_data1
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_prototyped   DW_FORM_flag_present
    DW_AT_type         DW_FORM_ref4
    DW_AT_low_pc       DW_FORM_addr
    DW_AT_high_pc      DW_FORM_data8
    DW_AT_frame_base   DW_FORM_exprloc
    DW_AT_call_all_tail_calls DW_FORM_flag_present
    DW_AT_sibling      DW_FORM_ref4
    DW_AT value: 0     DW_FORM value: 0
   21      DW_TAG_subprogram    [has children]
    DW_AT_external     DW_FORM_flag_present
    DW_AT_name         DW_FORM_strp
    DW_AT_decl_file    DW_FORM_data1
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_prototyped   DW_FORM_flag_present
    DW_AT_type         DW_FORM_ref4
    DW_AT_low_pc       DW_FORM_addr
    DW_AT_high_pc      DW_FORM_data8
    DW_AT_frame_base   DW_FORM_exprloc
    DW_AT_call_all_tail_calls DW_FORM_flag_present
    DW_AT value: 0     DW_FORM value: 0
   22      DW_TAG_formal_parameter    [no children]
    DW_AT_name         DW_FORM_string
    DW_AT_decl_file    DW_FORM_data1
    DW_AT_decl_line    DW_FORM_data1
    DW_AT_decl_column  DW_FORM_data1
    DW_AT_type         DW_FORM_ref4
    DW_AT_location     DW_FORM_exprloc
    DW_AT value: 0     DW_FORM value: 0

Raw dump of debug contents of section .debug_line (loaded from scratch):

  Offset:                      0
  Length:                      167
  DWARF Version:               5
  Address size (bytes):        8
  Segment selector (bytes):    0
  Prologue Length:             70
  Minimum Instruction Length:  1
  Maximum Ops per Instruction: 1
  Initial value of 'is_stmt':  1
  Line Base:                   -5
  Line Range:                  14
  Opcode Base:                 13

 Opcodes:
  Opcode 1 has 0 args
  Opcode 2 has 1 arg
  Opcode 3 has 1 arg
  Opcode 4 has 1 arg
  Opcode 5 has 1 arg
  Opcode 6 has 0 args
  Opcode 7 has 0 args
  Opcode 8 has 0 args
  Opcode 9 has 1 arg
  Opcode 10 has 0 args
  Opcode 11 has 0 args
  Opcode 12 has 1 arg

 The Directory Table (offset 0x22, lines 3, columns 1):
  Entry	Name
  0	(indirect line string, offset: 0): /home/ian/Projects/ostep/concurrency-api
  1	(indirect line string, offset: 0x33): /usr/include/x86_64-linux-gnu/bits
  2	(indirect line string, offset: 0x56): /usr/include

 The File Name Table (offset 0x34, lines 6, columns 2):
  Entry	Dir	Name
  0	0	(indirect line string, offset: 0x29): scratch.c
  1	0	(indirect line string, offset: 0x29): scratch.c
  2	1	(indirect line string, offset: 0x63): pthreadtypes.h
  3	2	(indirect line string, offset: 0x72): pthread.h
  4	2	(indirect line string, offset: 0x7c): err.h
  5	2	(indirect line string, offset: 0x82): stdio.h

 Line Number Statements:
  [0x00000052]  Set column to 1
  [0x00000054]  Extended opcode 2: set Address to 0x11e9
  [0x0000005f]  Special opcode 10: advance Address by 0 to 0x11e9 and Line by 5 to 6
  [0x00000060]  Set column to 5
  [0x00000062]  Special opcode 230: advance Address by 16 to 0x11f9 and Line by 1 to 7
  [0x00000063]  Set column to 12
  [0x00000065]  Advance PC by constant 17 to 0x120a
  [0x00000066]  Special opcode 146: advance Address by 10 to 0x1214 and Line by 1 to 8
  [0x00000067]  Set column to 1
  [0x00000069]  Special opcode 76: advance Address by 5 to 0x1219 and Line by 1 to 9
  [0x0000006a]  Special opcode 36: advance Address by 2 to 0x121b and Line by 3 to 12
  [0x0000006b]  Special opcode 173: advance Address by 12 to 0x1227 and Line by 0 to 12
  [0x0000006c]  Set column to 11
  [0x0000006e]  Special opcode 218: advance Address by 15 to 0x1236 and Line by 3 to 15
  [0x0000006f]  Special opcode 160: advance Address by 11 to 0x1241 and Line by 1 to 16
  [0x00000070]  Set column to 5
  [0x00000072]  Special opcode 161: advance Address by 11 to 0x124c and Line by 2 to 18
  [0x00000073]  Set column to 9
  [0x00000075]  Special opcode 217: advance Address by 15 to 0x125b and Line by 2 to 20
  [0x00000076]  Set column to 8
  [0x00000078]  Extended opcode 4: set Discriminator to 1
  [0x0000007c]  Advance PC by constant 17 to 0x126c
  [0x0000007d]  Special opcode 201: advance Address by 14 to 0x127a and Line by 0 to 20
  [0x0000007e]  Set column to 49
  [0x00000080]  Extended opcode 4: set Discriminator to 1
  [0x00000084]  Special opcode 61: advance Address by 4 to 0x127e and Line by 0 to 20
  [0x00000085]  Set column to 9
  [0x00000087]  Advance PC by constant 17 to 0x128f
  [0x00000088]  Special opcode 118: advance Address by 8 to 0x1297 and Line by 1 to 21
  [0x00000089]  Set column to 8
  [0x0000008b]  Extended opcode 4: set Discriminator to 1
  [0x0000008f]  Advance PC by constant 17 to 0x12a8
  [0x00000090]  Special opcode 201: advance Address by 14 to 0x12b6 and Line by 0 to 21
  [0x00000091]  Set column to 49
  [0x00000093]  Extended opcode 4: set Discriminator to 1
  [0x00000097]  Special opcode 61: advance Address by 4 to 0x12ba and Line by 0 to 21
  [0x00000098]  Set column to 5
  [0x0000009a]  Advance PC by constant 17 to 0x12cb
  [0x0000009b]  Special opcode 119: advance Address by 8 to 0x12d3 and Line by 2 to 23
  [0x0000009c]  Advance PC by constant 17 to 0x12e4
  [0x0000009d]  Special opcode 6: advance Address by 0 to 0x12e4 and Line by 1 to 24
  [0x0000009e]  Advance PC by constant 17 to 0x12f5
  [0x0000009f]  Special opcode 7: advance Address by 0 to 0x12f5 and Line by 2 to 26
  [0x000000a0]  Set column to 12
  [0x000000a2]  Special opcode 217: advance Address by 15 to 0x1304 and Line by 2 to 28
  [0x000000a3]  Set column to 1
  [0x000000a5]  Special opcode 77: advance Address by 5 to 0x1309 and Line by 2 to 30
  [0x000000a6]  Advance PC by 22 to 0x131f
  [0x000000a8]  Extended opcode 1: End of Sequence


Contents of the .debug_str section (loaded from scratch):

  0x00000000 6c6f6e67 206c6f6e 6720696e 7400776f long long int.wo
  0x00000010 726b0070 75747300 756e7369 676e6564 rk.puts.unsigned
  0x00000020 20636861 72006d61 696e0070 74687265  char.main.pthre
  0x00000030 61645f61 7474725f 74006572 7278006c ad_attr_t.errx.l
  0x00000040 6f6e6720 6c6f6e67 20756e73 69676e65 ong long unsigne
  0x00000050 6420696e 74007074 68726561 645f6372 d int.pthread_cr
  0x00000060 65617465 005f5f61 6c69676e 00707468 eate.__align.pth
  0x00000070 72656164 5f6a6f69 6e005f5f 73697a65 read_join.__size
  0x00000080 0073686f 72742075 6e736967 6e656420 .short unsigned 
  0x00000090 696e7400 7072696e 74660073 686f7274 int.printf.short
  0x000000a0 20696e74 00474e55 20433233 2031342e  int.GNU C23 14.
  0x000000b0 322e3020 2d6d7475 6e653d67 656e6572 2.0 -mtune=gener
  0x000000c0 6963202d 6d617263 683d7838 362d3634 ic -march=x86-64
  0x000000d0 202d6767 6462202d 4f30202d 7374643d  -ggdb -O0 -std=
  0x000000e0 63323320 2d666173 796e6368 726f6e6f c23 -fasynchrono
  0x000000f0 75732d75 6e77696e 642d7461 626c6573 us-unwind-tables
  0x00000100 202d6673 7461636b 2d70726f 74656374  -fstack-protect
  0x00000110 6f722d73 74726f6e 67202d66 73746163 or-strong -fstac
  0x00000120 6b2d636c 6173682d 70726f74 65637469 k-clash-protecti
  0x00000130 6f6e202d 6663662d 70726f74 65637469 on -fcf-protecti
  0x00000140 6f6e0070 74687265 61645f74 00       on.pthread_t.

Contents of the .debug_line_str section (loaded from scratch):

  0x00000000 2f686f6d 652f6961 6e2f5072 6f6a6563 /home/ian/Projec
  0x00000010 74732f6f 73746570 2f636f6e 63757272 ts/ostep/concurr
  0x00000020 656e6379 2d617069 00736372 61746368 ency-api.scratch
  0x00000030 2e63002f 7573722f 696e636c 7564652f .c./usr/include/
  0x00000040 7838365f 36342d6c 696e7578 2d676e75 x86_64-linux-gnu
  0x00000050 2f626974 73002f75 73722f69 6e636c75 /bits./usr/inclu
  0x00000060 64650070 74687265 61647479 7065732e de.pthreadtypes.
  0x00000070 68007074 68726561 642e6800 6572722e h.pthread.h.err.
  0x00000080 68007374 64696f2e 6800              h.stdio.h.

