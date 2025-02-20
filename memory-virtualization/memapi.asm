
memapi:     file format elf64-x86-64


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

00000000000010a0 <free@plt>:
    10a0:	f3 0f 1e fa          	endbr64
    10a4:	ff 25 fe 2e 00 00    	jmp    *0x2efe(%rip)        # 3fa8 <free@GLIBC_2.2.5>
    10aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010b0 <malloc@plt>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	ff 25 f6 2e 00 00    	jmp    *0x2ef6(%rip)        # 3fb0 <malloc@GLIBC_2.2.5>
    10ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010c0 <realloc@plt>:
    10c0:	f3 0f 1e fa          	endbr64
    10c4:	ff 25 ee 2e 00 00    	jmp    *0x2eee(%rip)        # 3fb8 <realloc@GLIBC_2.2.5>
    10ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010d0 <__printf_chk@plt>:
    10d0:	f3 0f 1e fa          	endbr64
    10d4:	ff 25 e6 2e 00 00    	jmp    *0x2ee6(%rip)        # 3fc0 <__printf_chk@GLIBC_2.3.4>
    10da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010e0 <exit@plt>:
    10e0:	f3 0f 1e fa          	endbr64
    10e4:	ff 25 de 2e 00 00    	jmp    *0x2ede(%rip)        # 3fc8 <exit@GLIBC_2.2.5>
    10ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000010f0 <fwrite@plt>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	ff 25 d6 2e 00 00    	jmp    *0x2ed6(%rip)        # 3fd0 <fwrite@GLIBC_2.2.5>
    10fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001100 <main>:
    1100:	f3 0f 1e fa          	endbr64
    1104:	41 56                	push   %r14
    1106:	bf a0 01 00 00       	mov    $0x1a0,%edi
    110b:	41 55                	push   %r13
    110d:	41 54                	push   %r12
    110f:	55                   	push   %rbp
    1110:	53                   	push   %rbx
    1111:	e8 9a ff ff ff       	call   10b0 <malloc@plt>
    1116:	48 85 c0             	test   %rax,%rax
    1119:	0f 84 ec 00 00 00    	je     120b <main+0x10b>
    111f:	66 0f 6f 05 59 0f 00 	movdqa 0xf59(%rip),%xmm0        # 2080 <_IO_stdin_used+0x80>
    1126:	00 
    1127:	49 89 c4             	mov    %rax,%r12
    112a:	31 db                	xor    %ebx,%ebx
    112c:	31 ed                	xor    %ebp,%ebp
    112e:	41 be 64 00 00 00    	mov    $0x64,%r14d
    1134:	0f 11 00             	movups %xmm0,(%rax)
    1137:	eb 22                	jmp    115b <main+0x5b>
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1140:	45 89 6c 9c 10       	mov    %r13d,0x10(%r12,%rbx,4)
    1145:	48 83 c5 01          	add    $0x1,%rbp
    1149:	48 83 c3 01          	add    $0x1,%rbx
    114d:	49 89 5c 24 08       	mov    %rbx,0x8(%r12)
    1152:	48 81 fd 80 8d 5b 00 	cmp    $0x5b8d80,%rbp
    1159:	74 32                	je     118d <main+0x8d>
    115b:	41 89 ed             	mov    %ebp,%r13d
    115e:	4c 39 f3             	cmp    %r14,%rbx
    1161:	75 dd                	jne    1140 <main+0x40>
    1163:	4c 89 e7             	mov    %r12,%rdi
    1166:	48 8d 34 dd 10 00 00 	lea    0x10(,%rbx,8),%rsi
    116d:	00 
    116e:	e8 4d ff ff ff       	call   10c0 <realloc@plt>
    1173:	49 89 c4             	mov    %rax,%r12
    1176:	48 85 c0             	test   %rax,%rax
    1179:	74 69                	je     11e4 <main+0xe4>
    117b:	48 8b 00             	mov    (%rax),%rax
    117e:	49 8b 5c 24 08       	mov    0x8(%r12),%rbx
    1183:	4c 8d 34 00          	lea    (%rax,%rax,1),%r14
    1187:	4d 89 34 24          	mov    %r14,(%r12)
    118b:	eb b3                	jmp    1140 <main+0x40>
    118d:	ba 10 00 00 00       	mov    $0x10,%edx
    1192:	48 8d 35 a5 0e 00 00 	lea    0xea5(%rip),%rsi        # 203e <_IO_stdin_used+0x3e>
    1199:	bf 02 00 00 00       	mov    $0x2,%edi
    119e:	31 c0                	xor    %eax,%eax
    11a0:	e8 2b ff ff ff       	call   10d0 <__printf_chk@plt>
    11a5:	48 89 da             	mov    %rbx,%rdx
    11a8:	bf 02 00 00 00       	mov    $0x2,%edi
    11ad:	31 c0                	xor    %eax,%eax
    11af:	48 8d 35 9a 0e 00 00 	lea    0xe9a(%rip),%rsi        # 2050 <_IO_stdin_used+0x50>
    11b6:	e8 15 ff ff ff       	call   10d0 <__printf_chk@plt>
    11bb:	4c 89 f2             	mov    %r14,%rdx
    11be:	bf 02 00 00 00       	mov    $0x2,%edi
    11c3:	31 c0                	xor    %eax,%eax
    11c5:	48 8d 35 95 0e 00 00 	lea    0xe95(%rip),%rsi        # 2061 <_IO_stdin_used+0x61>
    11cc:	e8 ff fe ff ff       	call   10d0 <__printf_chk@plt>
    11d1:	4c 89 e7             	mov    %r12,%rdi
    11d4:	e8 c7 fe ff ff       	call   10a0 <free@plt>
    11d9:	5b                   	pop    %rbx
    11da:	31 c0                	xor    %eax,%eax
    11dc:	5d                   	pop    %rbp
    11dd:	41 5c                	pop    %r12
    11df:	41 5d                	pop    %r13
    11e1:	41 5e                	pop    %r14
    11e3:	c3                   	ret
    11e4:	48 8b 0d 35 2e 00 00 	mov    0x2e35(%rip),%rcx        # 4020 <stderr@GLIBC_2.2.5>
    11eb:	ba 10 00 00 00       	mov    $0x10,%edx
    11f0:	be 01 00 00 00       	mov    $0x1,%esi
    11f5:	48 8d 3d 31 0e 00 00 	lea    0xe31(%rip),%rdi        # 202d <_IO_stdin_used+0x2d>
    11fc:	e8 ef fe ff ff       	call   10f0 <fwrite@plt>
    1201:	bf 01 00 00 00       	mov    $0x1,%edi
    1206:	e8 d5 fe ff ff       	call   10e0 <exit@plt>
    120b:	48 8b 0d 0e 2e 00 00 	mov    0x2e0e(%rip),%rcx        # 4020 <stderr@GLIBC_2.2.5>
    1212:	ba 24 00 00 00       	mov    $0x24,%edx
    1217:	be 01 00 00 00       	mov    $0x1,%esi
    121c:	48 8d 3d e5 0d 00 00 	lea    0xde5(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    1223:	e8 c8 fe ff ff       	call   10f0 <fwrite@plt>
    1228:	bf 01 00 00 00       	mov    $0x1,%edi
    122d:	e8 ae fe ff ff       	call   10e0 <exit@plt>
    1232:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    1239:	00 00 00 
    123c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001240 <_start>:
    1240:	f3 0f 1e fa          	endbr64
    1244:	31 ed                	xor    %ebp,%ebp
    1246:	49 89 d1             	mov    %rdx,%r9
    1249:	5e                   	pop    %rsi
    124a:	48 89 e2             	mov    %rsp,%rdx
    124d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1251:	50                   	push   %rax
    1252:	54                   	push   %rsp
    1253:	45 31 c0             	xor    %r8d,%r8d
    1256:	31 c9                	xor    %ecx,%ecx
    1258:	48 8d 3d a1 fe ff ff 	lea    -0x15f(%rip),%rdi        # 1100 <main>
    125f:	ff 15 73 2d 00 00    	call   *0x2d73(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1265:	f4                   	hlt
    1266:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    126d:	00 00 00 

0000000000001270 <deregister_tm_clones>:
    1270:	48 8d 3d 99 2d 00 00 	lea    0x2d99(%rip),%rdi        # 4010 <__TMC_END__>
    1277:	48 8d 05 92 2d 00 00 	lea    0x2d92(%rip),%rax        # 4010 <__TMC_END__>
    127e:	48 39 f8             	cmp    %rdi,%rax
    1281:	74 15                	je     1298 <deregister_tm_clones+0x28>
    1283:	48 8b 05 56 2d 00 00 	mov    0x2d56(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    128a:	48 85 c0             	test   %rax,%rax
    128d:	74 09                	je     1298 <deregister_tm_clones+0x28>
    128f:	ff e0                	jmp    *%rax
    1291:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1298:	c3                   	ret
    1299:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012a0 <register_tm_clones>:
    12a0:	48 8d 3d 69 2d 00 00 	lea    0x2d69(%rip),%rdi        # 4010 <__TMC_END__>
    12a7:	48 8d 35 62 2d 00 00 	lea    0x2d62(%rip),%rsi        # 4010 <__TMC_END__>
    12ae:	48 29 fe             	sub    %rdi,%rsi
    12b1:	48 89 f0             	mov    %rsi,%rax
    12b4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    12b8:	48 c1 f8 03          	sar    $0x3,%rax
    12bc:	48 01 c6             	add    %rax,%rsi
    12bf:	48 d1 fe             	sar    $1,%rsi
    12c2:	74 14                	je     12d8 <register_tm_clones+0x38>
    12c4:	48 8b 05 25 2d 00 00 	mov    0x2d25(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    12cb:	48 85 c0             	test   %rax,%rax
    12ce:	74 08                	je     12d8 <register_tm_clones+0x38>
    12d0:	ff e0                	jmp    *%rax
    12d2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    12d8:	c3                   	ret
    12d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012e0 <__do_global_dtors_aux>:
    12e0:	f3 0f 1e fa          	endbr64
    12e4:	80 3d 3d 2d 00 00 00 	cmpb   $0x0,0x2d3d(%rip)        # 4028 <completed.0>
    12eb:	75 2b                	jne    1318 <__do_global_dtors_aux+0x38>
    12ed:	55                   	push   %rbp
    12ee:	48 83 3d 02 2d 00 00 	cmpq   $0x0,0x2d02(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    12f5:	00 
    12f6:	48 89 e5             	mov    %rsp,%rbp
    12f9:	74 0c                	je     1307 <__do_global_dtors_aux+0x27>
    12fb:	48 8b 3d 06 2d 00 00 	mov    0x2d06(%rip),%rdi        # 4008 <__dso_handle>
    1302:	e8 89 fd ff ff       	call   1090 <__cxa_finalize@plt>
    1307:	e8 64 ff ff ff       	call   1270 <deregister_tm_clones>
    130c:	c6 05 15 2d 00 00 01 	movb   $0x1,0x2d15(%rip)        # 4028 <completed.0>
    1313:	5d                   	pop    %rbp
    1314:	c3                   	ret
    1315:	0f 1f 00             	nopl   (%rax)
    1318:	c3                   	ret
    1319:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001320 <frame_dummy>:
    1320:	f3 0f 1e fa          	endbr64
    1324:	e9 77 ff ff ff       	jmp    12a0 <register_tm_clones>

Disassembly of section .fini:

000000000000132c <_fini>:
    132c:	f3 0f 1e fa          	endbr64
    1330:	48 83 ec 08          	sub    $0x8,%rsp
    1334:	48 83 c4 08          	add    $0x8,%rsp
    1338:	c3                   	ret
