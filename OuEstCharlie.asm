.data:00000000 2f                               das                         ;del of all comment ;)
.data:00000001 2a 2a                            sub    ch,BYTE PTR [edx]
.data:00000003 0d 0a 20 2a 20                   or     eax,0x202a200a
.data:00000008 40                               inc    eax
.data:00000009 70 61                            jo     0x0000006c
.data:0000000b 63 6b 61                         arpl   WORD PTR [ebx+0x61],bp
.data:0000000e 67 65 20 6e 75                   and    BYTE PTR gs:[bp+0x75],ch
.data:00000013 6c                               ins    BYTE PTR es:[edi],dx
.data:00000014 6c                               ins    BYTE PTR es:[edi],dx
.data:00000015 0d 0a 20 2a 20                   or     eax,0x202a200a
.data:0000001a 40                               inc    eax
.data:0000001b 73 75                            jae    0x00000092
.data:0000001d 62 70 61                         bound  esi,QWORD PTR [eax+0x61]
.data:00000020 63 6b 61                         arpl   WORD PTR [ebx+0x61],bp
.data:00000023 67 65 20 6e 75                   and    BYTE PTR gs:[bp+0x75],ch
.data:00000028 6c                               ins    BYTE PTR es:[edi],dx
.data:00000029 6c                               ins    BYTE PTR es:[edi],dx
.data:0000002a 0d 0a 20 2a 20                   or     eax,0x202a200a
.data:0000002f 40                               inc    eax
.data:00000030 73 69                            jae    0x0000009b
.data:00000032 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000033 63 65 20                         arpl   WORD PTR [ebp+0x20],sp
.data:00000036 56                               push   esi
.data:00000037 65 72 69                         gs jb  0x000000a3
.data:0000003a 66 69 65 72 59 61                imul   sp,WORD PTR [ebp+0x72],0x6159
.data:00000040 70 69                            jo     0x000000ab
.data:00000042 78 20                            js     0x00000064
.data:00000044 30 2e                            xor    BYTE PTR [esi],ch
.data:00000046 30 2e                            xor    BYTE PTR [esi],ch
.data:00000048 31 0d 0a 20 2a 20                xor    DWORD PTR ds:0x202a200a,ecx
.data:0000004e 40                               inc    eax
.data:0000004f 41                               inc    ecx
.data:00000050 75 74                            jne    0x000000c6
.data:00000052 68 6f 72 20 59                   push   0x5920726f
.data:00000057 61                               popa   
.data:00000058 70 69                            jo     0x000000c3
.data:0000005a 78 20                            js     0x0000007c
.data:0000005c 5b                               pop    ebx
.data:0000005d 44                               inc    esp
.data:0000005e 45                               inc    ebp
.data:0000005f 56                               push   esi
.data:00000060 2d 4d 41 53 54                   sub    eax,0x5453414d
.data:00000065 45                               inc    ebp
.data:00000066 52                               push   edx
.data:00000067 20 26                            and    BYTE PTR [esi],ah
.data:00000069 26 20 43 52                      and    BYTE PTR es:[ebx+0x52],al
.data:0000006d 45                               inc    ebp
.data:0000006e 41                               inc    ecx
.data:0000006f 54                               push   esp
.data:00000070 4f                               dec    edi
.data:00000071 52                               push   edx
.data:00000072 5d                               pop    ebp
.data:00000073 0d 0a 20 2a 20                   or     eax,0x202a200a
.data:00000078 40                               inc    eax
.data:00000079 41                               inc    ecx
.data:0000007a 6c                               ins    BYTE PTR es:[edi],dx
.data:0000007b 74 65                            je     0x000000e2
.data:0000007d 73 56                            jae    0x000000d5
.data:0000007f 65 72 73                         gs jb  0x000000f5
.data:00000082 69 6f 6e 20 41 6c 70             imul   ebp,DWORD PTR [edi+0x6e],0x706c4120
.data:00000089 68 61 20 30 2e                   push   0x2e302061
.data:0000008e 30 30                            xor    BYTE PTR [eax],dh
.data:00000090 30 2e                            xor    BYTE PTR [esi],ch
.data:00000092 30 30                            xor    BYTE PTR [eax],dh
.data:00000094 31 0d 0a 20 2a 20                xor    DWORD PTR ds:0x202a200a,ecx
.data:0000009a 40                               inc    eax
.data:0000009b 41                               inc    ecx
.data:0000009c 70 69                            jo     0x00000107
.data:0000009e 56                               push   esi
.data:0000009f 65 72 73                         gs jb  0x00000115
.data:000000a2 69 6f 6e 20 42 65 74             imul   ebp,DWORD PTR [edi+0x6e],0x74654220
.data:000000a9 61                               popa   
.data:000000aa 20 30                            and    BYTE PTR [eax],dh
.data:000000ac 2e 30 2e                         xor    BYTE PTR cs:[esi],ch
.data:000000af 31 0d 0a 20 2a 20                xor    DWORD PTR ds:0x202a200a,ecx
.data:000000b5 40                               inc    eax
.data:000000b6 55                               push   ebp
.data:000000b7 73 65                            jae    0x0000011e
.data:000000b9 72 4e                            jb     0x00000109
.data:000000bb 61                               popa   
.data:000000bc 6d                               ins    DWORD PTR es:[edi],dx
.data:000000bd 65 20 35 38 35 30 2d             and    BYTE PTR gs:0x2d303538,dh
.data:000000c4 64 66 37                         fs data16 aaa 
.data:000000c7 61                               popa   
.data:000000c8 2d 62 32 35 66                   sub    eax,0x66353262
.data:000000cd 2d 34 37 65 36                   sub    eax,0x36653734
.data:000000d2 2d 39 66 63 32                   sub    eax,0x32636639
.data:000000d7 2d 36 36 33 30                   sub    eax,0x30333636
.data:000000dc 2d 66 35 31 33                   sub    eax,0x33313566
.data:000000e1 2d 38 31 66 32                   sub    eax,0x32663138
.data:000000e6 0d 0a 20 2a 20                   or     eax,0x202a200a
.data:000000eb 40                               inc    eax
.data:000000ec 44                               inc    esp
.data:000000ed 65 73 63                         gs jae 0x00000153
.data:000000f0 72 69                            jb     0x0000015b
.data:000000f2 70 74                            jo     0x00000168
.data:000000f4 69 6f 6e 20 3b 29 0d             imul   ebp,DWORD PTR [edi+0x6e],0xd293b20
.data:000000fb 0a 20                            or     ah,BYTE PTR [eax]
.data:000000fd 2a 20                            sub    ah,BYTE PTR [eax]
.data:000000ff 40                               inc    eax
.data:00000100 44                               inc    esp
.data:00000101 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000102 63 52 65                         arpl   WORD PTR [edx+0x65],dx
.data:00000105 70 65                            jo     0x0000016c
.data:00000107 72 74                            jb     0x0000017d
.data:00000109 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000010a 72 79                            jb     0x00000185
.data:0000010c 20 4e 0d                         and    BYTE PTR [esi+0xd],cl
.data:0000010f 0a 20                            or     ah,BYTE PTR [eax]
.data:00000111 2a 20                            sub    ah,BYTE PTR [eax]
.data:00000113 40                               inc    eax
.data:00000114 41                               inc    ecx
.data:00000115 6c                               ins    BYTE PTR es:[edi],dx
.data:00000116 67 41                            addr16 inc ecx
.data:00000118 6c                               ins    BYTE PTR es:[edi],dx
.data:00000119 74 65                            je     0x00000180
.data:0000011b 73 20                            jae    0x0000013d
.data:0000011d 59                               pop    ecx
.data:0000011e 0d 0a 20 2a 20                   or     eax,0x202a200a
.data:00000123 40                               inc    eax
.data:00000124 41                               inc    ecx
.data:00000125 75 74                            jne    0x0000019b
.data:00000127 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000128 49                               dec    ecx
.data:00000129 6d                               ins    DWORD PTR es:[edi],dx
.data:0000012a 70 6f                            jo     0x0000019b
.data:0000012c 72 74                            jb     0x000001a2
.data:0000012e 20 4e 0d                         and    BYTE PTR [esi+0xd],cl
.data:00000131 0a 20                            or     ah,BYTE PTR [eax]
.data:00000133 2a 2f                            sub    ch,BYTE PTR [edi]
.data:00000135 0d 0a 0d 0a 2f                   or     eax,0x2f0a0d0a
.data:0000013a 2f                               das    
.data:0000013b 54                               push   esp
.data:0000013c 68 65 20 67 6f                   push   0x6f672065
.data:00000141 61                               popa   
.data:00000142 6c                               ins    BYTE PTR es:[edi],dx
.data:00000143 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000146 20 74 68 69                      and    BYTE PTR [eax+ebp*2+0x69],dh
.data:0000014a 73 20                            jae    0x0000016c
.data:0000014c 70 72                            jo     0x000001c0
.data:0000014e 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000014f 67 72 61                         addr16 jb 0x000001b3
.data:00000152 6d                               ins    DWORD PTR es:[edi],dx
.data:00000153 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000156 20 73 69                         and    BYTE PTR [ebx+0x69],dh
.data:00000159 6d                               ins    DWORD PTR es:[edi],dx
.data:0000015a 70 6c                            jo     0x000001c8
.data:0000015c 79 20                            jns    0x0000017e
.data:0000015e 61                               popa   
.data:0000015f 64 64 20 31                      fs and BYTE PTR fs:[ecx],dh
.data:00000163 20 74 6f 20                      and    BYTE PTR [edi+ebp*2+0x20],dh
.data:00000167 74 68                            je     0x000001d1
.data:00000169 65 20 76 61                      and    BYTE PTR gs:[esi+0x61],dh
.data:0000016d 6c                               ins    BYTE PTR es:[edi],dx
.data:0000016e 75 65                            jne    0x000001d5
.data:00000170 20 6f 62                         and    BYTE PTR [edi+0x62],ch
.data:00000173 74 61                            je     0x000001d6
.data:00000175 69 6e 65 64 20 21 0d             imul   ebp,DWORD PTR [esi+0x65],0xd212064
.data:0000017c 0a 0d 0a 41 6c 67                or     cl,BYTE PTR ds:0x676c410a
.data:00000182 41                               inc    ecx
.data:00000183 6c                               ins    BYTE PTR es:[edi],dx
.data:00000184 74 65                            je     0x000001eb
.data:00000186 73 0d                            jae    0x00000195
.data:00000188 0a 0d 0a 2f 2a 0d                or     cl,BYTE PTR ds:0xd2a2f0a
.data:0000018e 0a 09                            or     cl,BYTE PTR [ecx]
.data:00000190 41                               inc    ecx
.data:00000191 6c                               ins    BYTE PTR es:[edi],dx
.data:00000192 67 41                            addr16 inc ecx
.data:00000194 6c                               ins    BYTE PTR es:[edi],dx
.data:00000195 74 65                            je     0x000001fc
.data:00000197 73 20                            jae    0x000001b9
.data:00000199 69 73 20 74 68 65 20             imul   esi,DWORD PTR [ebx+0x20],0x20656874
.data:000001a0 70 72                            jo     0x00000214
.data:000001a2 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000001a3 63 65 73                         arpl   WORD PTR [ebp+0x73],sp
.data:000001a6 73 20                            jae    0x000001c8
.data:000001a8 69 6e 63 6c 75 64 65             imul   ebp,DWORD PTR [esi+0x63],0x6564756c
.data:000001af 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:000001b2 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:000001b6 20 41 6c                         and    BYTE PTR [ecx+0x6c],al
.data:000001b9 74 65                            je     0x00000220
.data:000001bb 73 2d                            jae    0x000001ea
.data:000001bd 4c                               dec    esp
.data:000001be 61                               popa   
.data:000001bf 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000001c0 67 20 66 6f                      and    BYTE PTR [bp+0x6f],ah
.data:000001c4 72 20                            jb     0x000001e6
.data:000001c6 6d                               ins    DWORD PTR es:[edi],dx
.data:000001c7 61                               popa   
.data:000001c8 6b 65 20 77                      imul   esp,DWORD PTR [ebp+0x20],0x77
.data:000001cc 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000001cd 72 6b                            jb     0x0000023a
.data:000001cf 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:000001d3 20 6c 61 6e                      and    BYTE PTR [ecx+eiz*2+0x6e],ch
.data:000001d7 67 75 61                         addr16 jne 0x0000023b
.data:000001da 67 65 2e 20 54 68                gs and BYTE PTR cs:[si+0x68],dl
.data:000001e0 69 73 20 69 73 20 6e             imul   esi,DWORD PTR [ebx+0x20],0x6e207369
.data:000001e7 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000001e8 74 20                            je     0x0000020a
.data:000001ea 63 6f 6d                         arpl   WORD PTR [edi+0x6d],bp
.data:000001ed 70 75                            jo     0x00000264
.data:000001ef 6c                               ins    BYTE PTR es:[edi],dx
.data:000001f0 73 6f                            jae    0x00000261
.data:000001f2 72 79                            jb     0x0000026d
.data:000001f4 20 74 6f 20                      and    BYTE PTR [edi+ebp*2+0x20],dh
.data:000001f8 64 6f                            outs   dx,DWORD PTR fs:[esi]
.data:000001fa 20 77 69                         and    BYTE PTR [edi+0x69],dh
.data:000001fd 74 68                            je     0x00000267
.data:000001ff 20 68 61                         and    BYTE PTR [eax+0x61],ch
.data:00000202 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000203 64 20 21                         and    BYTE PTR fs:[ecx],ah
.data:00000206 0d 0a 09 53 6f                   or     eax,0x6f53090a
.data:0000020b 6d                               ins    DWORD PTR es:[edi],dx
.data:0000020c 65 74 69                         gs je  0x00000278
.data:0000020f 6d                               ins    DWORD PTR es:[edi],dx
.data:00000210 65 73 20                         gs jae 0x00000233
.data:00000213 69 74 20 69 73 20 65 76          imul   esi,DWORD PTR [eax+eiz*1+0x69],0x76652073
.data:0000021b 65 6e                            outs   dx,BYTE PTR gs:[esi]
.data:0000021d 20 61 64                         and    BYTE PTR [ecx+0x64],ah
.data:00000220 76 69                            jbe    0x0000028b
.data:00000222 73 61                            jae    0x00000285
.data:00000224 62 6c 65 20                      bound  ebp,QWORD PTR [ebp+eiz*2+0x20]
.data:00000228 21 20                            and    DWORD PTR [eax],esp
.data:0000022a 50                               push   eax
.data:0000022b 61                               popa   
.data:0000022c 79 20                            jns    0x0000024e
.data:0000022e 61                               popa   
.data:0000022f 74 74                            je     0x000002a5
.data:00000231 65 6e                            outs   dx,BYTE PTR gs:[esi]
.data:00000233 74 69                            je     0x0000029e
.data:00000235 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000236 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000237 20 77 69                         and    BYTE PTR [edi+0x69],dh
.data:0000023a 74 68                            je     0x000002a4
.data:0000023c 20 74 68 69                      and    BYTE PTR [eax+ebp*2+0x69],dh
.data:00000240 73 20                            jae    0x00000262
.data:00000242 21 20                            and    DWORD PTR [eax],esp
.data:00000244 54                               push   esp
.data:00000245 68 65 20 63 6f                   push   0x6f632065
.data:0000024a 6d                               ins    DWORD PTR es:[edi],dx
.data:0000024b 70 69                            jo     0x000002b6
.data:0000024d 6c                               ins    BYTE PTR es:[edi],dx
.data:0000024e 65 72 20                         gs jb  0x00000271
.data:00000251 63 61 6e                         arpl   WORD PTR [ecx+0x6e],sp
.data:00000254 20 64 6f 20                      and    BYTE PTR [edi+ebp*2+0x20],ah
.data:00000258 69 74 20 61 6c 6f 6e 65          imul   esi,DWORD PTR [eax+eiz*1+0x61],0x656e6f6c
.data:00000260 20 21                            and    BYTE PTR [ecx],ah
.data:00000262 20 3b                            and    BYTE PTR [ebx],bh
.data:00000264 29 20                            sub    DWORD PTR [eax],esp
.data:00000266 44                               inc    esp
.data:00000267 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000268 63 75 6d                         arpl   WORD PTR [ebp+0x6d],si
.data:0000026b 65 6e                            outs   dx,BYTE PTR gs:[esi]
.data:0000026d 74 61                            je     0x000002d0
.data:0000026f 74 69                            je     0x000002da
.data:00000271 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000272 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000273 20 66 6f                         and    BYTE PTR [esi+0x6f],ah
.data:00000276 72 20                            jb     0x00000298
.data:00000278 74 68                            je     0x000002e2
.data:0000027a 69 73 20 69 73 20 6f             imul   esi,DWORD PTR [ebx+0x20],0x6f207369
.data:00000281 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000282 6c                               ins    BYTE PTR es:[edi],dx
.data:00000283 69 6e 65 20 21 0d 0a             imul   ebp,DWORD PTR [esi+0x65],0xa0d2120
.data:0000028a 09 09                            or     DWORD PTR [ecx],ecx
.data:0000028c 09 09                            or     DWORD PTR [ecx],ecx
.data:0000028e 09 09                            or     DWORD PTR [ecx],ecx
.data:00000290 09 5b 57                         or     DWORD PTR [ebx+0x57],ebx
.data:00000293 61                               popa   
.data:00000294 72 6e                            jb     0x00000304
.data:00000296 69 6e 67 20 74 68 65             imul   ebp,DWORD PTR [esi+0x67],0x65687420
.data:0000029d 72 65                            jb     0x00000304
.data:0000029f 20 6d 69                         and    BYTE PTR [ebp+0x69],ch
.data:000002a2 67 68 74 20 62 65                addr16 push 0x65622074
.data:000002a8 20 70 72                         and    BYTE PTR [eax+0x72],dh
.data:000002ab 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000002ac 62 6c 65 6d                      bound  ebp,QWORD PTR [ebp+eiz*2+0x6d]
.data:000002b0 73 20                            jae    0x000002d2
.data:000002b2 77 68                            ja     0x0000031c
.data:000002b4 65 6e                            outs   dx,BYTE PTR gs:[esi]
.data:000002b6 20 63 6f                         and    BYTE PTR [ebx+0x6f],ah
.data:000002b9 6d                               ins    DWORD PTR es:[edi],dx
.data:000002ba 70 69                            jo     0x00000325
.data:000002bc 6c                               ins    BYTE PTR es:[edi],dx
.data:000002bd 69 6e 67 20 21 5d 0d             imul   ebp,DWORD PTR [esi+0x67],0xd5d2120
.data:000002c4 0a 2a                            or     ch,BYTE PTR [edx]
.data:000002c6 2f                               das    
.data:000002c7 0d 0a 0d 0a 7b                   or     eax,0x7b0a0d0a
.data:000002cc 20 2f                            and    BYTE PTR [edi],ch
.data:000002ce 2f                               das    
.data:000002cf 4f                               dec    edi
.data:000002d0 70 65                            jo     0x00000337
.data:000002d2 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000002d3 0d 0a 09 44 45                   or     eax,0x4544090a
.data:000002d8 46                               inc    esi
.data:000002d9 49                               dec    ecx
.data:000002da 4e                               dec    esi
.data:000002db 45                               inc    ebp
.data:000002dc 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:000002df 63 6c 75 64                      arpl   WORD PTR [ebp+esi*2+0x64],bp
.data:000002e3 65 64 28 73 6f                   gs sub BYTE PTR fs:[ebx+0x6f],dh
.data:000002e8 75 72                            jne    0x0000035c
.data:000002ea 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:000002ed 61                               popa   
.data:000002ee 74 68                            je     0x00000358
.data:000002f0 3a 3a                            cmp    bh,BYTE PTR [edx]
.data:000002f2 66 69 6c 65 5b 66 69             imul   bp,WORD PTR [ebp+eiz*2+0x5b],0x6966
.data:000002f9 6c                               ins    BYTE PTR es:[edi],dx
.data:000002fa 65 28 29                         sub    BYTE PTR gs:[ecx],ch
.data:000002fd 20 3c 3c                         and    BYTE PTR [esp+edi*1],bh
.data:00000300 20 5b 67                         and    BYTE PTR [ebx+0x67],bl
.data:00000303 65 74 46                         gs je  0x0000034c
.data:00000306 69 6c 65 4e 61 6d 65 28          imul   ebp,DWORD PTR [ebp+eiz*2+0x4e],0x28656d61
.data:0000030e 29 5d 2c                         sub    DWORD PTR [ebp+0x2c],ebx
.data:00000311 20 73 64                         and    BYTE PTR [ebx+0x64],dh
.data:00000314 6b 46 69 6c                      imul   eax,DWORD PTR [esi+0x69],0x6c
.data:00000318 65 28 29                         sub    BYTE PTR gs:[ecx],ch
.data:0000031b 5d                               pop    ebp
.data:0000031c 29 3b                            sub    DWORD PTR [ebx],edi
.data:0000031e 09 2f                            or     DWORD PTR [edi],ebp
.data:00000320 2f                               das    
.data:00000321 22 69 6e                         and    ch,BYTE PTR [ecx+0x6e]
.data:00000324 63 6c 75 64                      arpl   WORD PTR [ebp+esi*2+0x64],bp
.data:00000328 65 64 22 20                      gs and ah,BYTE PTR fs:[eax]
.data:0000032c 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000032d 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000330 63 74 20 69                      arpl   WORD PTR [eax+eiz*1+0x69],si
.data:00000334 73 20                            jae    0x00000356
.data:00000336 75 73                            jne    0x000003ab
.data:00000338 65 64 20 74 6f 20                gs and BYTE PTR fs:[edi+ebp*2+0x20],dh
.data:0000033e 75 73                            jne    0x000003b3
.data:00000340 65 20 74 68 65                   and    BYTE PTR gs:[eax+ebp*2+0x65],dh
.data:00000345 20 22                            and    BYTE PTR [edx],ah
.data:00000347 23 69 6e                         and    ebp,DWORD PTR [ecx+0x6e]
.data:0000034a 63 6c 75 64                      arpl   WORD PTR [ebp+esi*2+0x64],bp
.data:0000034e 65 22 20                         and    ah,BYTE PTR gs:[eax]
.data:00000351 6b 65 79 77                      imul   esp,DWORD PTR [ebp+0x79],0x77
.data:00000355 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000356 72 64                            jb     0x000003bc
.data:00000358 20 21                            and    BYTE PTR [ecx],ah
.data:0000035a 0d 0a 09 09 2f                   or     eax,0x2f09090a
.data:0000035f 2f                               das    
.data:00000360 49                               dec    ecx
.data:00000361 66 20 22                         data16 and BYTE PTR [edx],ah
.data:00000364 69 6e 63 6c 75 64 65             imul   ebp,DWORD PTR [esi+0x63],0x6564756c
.data:0000036b 64 22 20                         and    ah,BYTE PTR fs:[eax]
.data:0000036e 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:00000370 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000371 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000375 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000376 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000379 20 6e 6f                         and    BYTE PTR [esi+0x6f],ch
.data:0000037c 74 20                            je     0x0000039e
.data:0000037e 64 65 66 69 6e 65 64 20          fs imul bp,WORD PTR gs:[esi+0x65],0x2064
.data:00000386 74 68                            je     0x000003f0
.data:00000388 65 20 6b 65                      and    BYTE PTR gs:[ebx+0x65],ch
.data:0000038c 79 77                            jns    0x00000405
.data:0000038e 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000038f 72 64                            jb     0x000003f5
.data:00000391 73 20                            jae    0x000003b3
.data:00000393 22 23                            and    ah,BYTE PTR [ebx]
.data:00000395 69 6e 63 6c 75 64 65             imul   ebp,DWORD PTR [esi+0x63],0x6564756c
.data:0000039c 22 20                            and    ah,BYTE PTR [eax]
.data:0000039e 69 73 20 6e 6f 20 75             imul   esi,DWORD PTR [ebx+0x20],0x75206f6e
.data:000003a5 73 65                            jae    0x0000040c
.data:000003a7 20 21                            and    BYTE PTR [ecx],ah
.data:000003a9 09 0d 0a 09 09 64                or     DWORD PTR ds:0x6409090a,ecx
.data:000003af 65 66 20 28                      data16 and BYTE PTR gs:[eax],ch
.data:000003b3 69 6e 63 6c 75 64 65             imul   ebp,DWORD PTR [esi+0x63],0x6564756c
.data:000003ba 64 29 3a                         sub    DWORD PTR fs:[edx],edi
.data:000003bd 20 09                            and    BYTE PTR [ecx],cl
.data:000003bf 2f                               das    
.data:000003c0 2f                               das    
.data:000003c1 44                               inc    esp
.data:000003c2 65 66 69 6e 69 74 69             imul   bp,WORD PTR gs:[esi+0x69],0x6974
.data:000003c9 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000003ca 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000003cb 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:000003ce 20 22                            and    BYTE PTR [edx],ah
.data:000003d0 69 6e 63 6c 75 64 65             imul   ebp,DWORD PTR [esi+0x63],0x6564756c
.data:000003d7 64 22 20                         and    ah,BYTE PTR fs:[eax]
.data:000003da 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000003db 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:000003de 63 74 20 21                      arpl   WORD PTR [eax+eiz*1+0x21],si
.data:000003e2 0d 0a 09 09 09                   or     eax,0x909090a
.data:000003e7 2f                               das    
.data:000003e8 2f                               das    
.data:000003e9 54                               push   esp
.data:000003ea 68 65 20 22 64                   push   0x64222065
.data:000003ef 65 66 22 20                      data16 and ah,BYTE PTR gs:[eax]
.data:000003f3 6b 65 79 77                      imul   esp,DWORD PTR [ebp+0x79],0x77
.data:000003f7 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000003f8 72 64                            jb     0x0000045e
.data:000003fa 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:000003fd 20 63 6f                         and    BYTE PTR [ebx+0x6f],ah
.data:00000400 6d                               ins    DWORD PTR es:[edi],dx
.data:00000401 70 75                            jo     0x00000478
.data:00000403 6c                               ins    BYTE PTR es:[edi],dx
.data:00000404 73 6f                            jae    0x00000475
.data:00000406 72 79                            jb     0x00000481
.data:00000408 20 21                            and    BYTE PTR [ecx],ah
.data:0000040a 0d 0a 09 09 09                   or     eax,0x909090a
.data:0000040f 73 63                            jae    0x00000474
.data:00000411 20 73 6f                         and    BYTE PTR [ebx+0x6f],dh
.data:00000414 75 72                            jne    0x00000488
.data:00000416 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:00000419 61                               popa   
.data:0000041a 74 68                            je     0x00000484
.data:0000041c 28 29                            sub    BYTE PTR [ecx],ch
.data:0000041e 3b 20                            cmp    esp,DWORD PTR [eax]
.data:00000420 20 20                            and    BYTE PTR [eax],ah
.data:00000422 20 2f                            and    BYTE PTR [edi],ch
.data:00000424 2f                               das    
.data:00000425 22 73 63                         and    dh,BYTE PTR [ebx+0x63]
.data:00000428 22 20                            and    ah,BYTE PTR [eax]
.data:0000042a 65 71 75                         gs jno 0x000004a2
.data:0000042d 61                               popa   
.data:0000042e 6c                               ins    BYTE PTR es:[edi],dx
.data:0000042f 73 20                            jae    0x00000451
.data:00000431 53                               push   ebx
.data:00000432 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000433 75 72                            jne    0x000004a7
.data:00000435 63 65 20                         arpl   WORD PTR [ebp+0x20],sp
.data:00000438 43                               inc    ebx
.data:00000439 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000043a 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000043b 74 72                            je     0x000004af
.data:0000043d 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000043e 6c                               ins    BYTE PTR es:[edi],dx
.data:0000043f 2c 20                            sub    al,0x20
.data:00000441 64 65 66 69 6e 69 74 69          fs imul bp,WORD PTR gs:[esi+0x69],0x6974
.data:00000449 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000044a 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000044b 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:0000044e 20 22                            and    BYTE PTR [edx],ah
.data:00000450 73 6f                            jae    0x000004c1
.data:00000452 75 72                            jne    0x000004c6
.data:00000454 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:00000457 61                               popa   
.data:00000458 74 68                            je     0x000004c2
.data:0000045a 22 20                            and    ah,BYTE PTR [eax]
.data:0000045c 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:0000045e 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000045f 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000463 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000464 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000467 64 20 6f 62                      and    BYTE PTR fs:[edi+0x62],ch
.data:0000046b 6a 65                            push   0x65
.data:0000046d 63 74 20 28                      arpl   WORD PTR [eax+eiz*1+0x28],si
.data:00000471 62 75 74                         bound  esi,QWORD PTR [ebp+0x74]
.data:00000474 20 61 6c                         and    BYTE PTR [ecx+0x6c],ah
.data:00000477 6c                               ins    BYTE PTR es:[edi],dx
.data:00000478 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:0000047b 20 6f 62                         and    BYTE PTR [edi+0x62],ch
.data:0000047e 6a 65                            push   0x65
.data:00000480 63 74 20 69                      arpl   WORD PTR [eax+eiz*1+0x69],si
.data:00000484 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000485 20 41 6c                         and    BYTE PTR [ecx+0x6c],al
.data:00000488 74 65                            je     0x000004ef
.data:0000048a 73 29                            jae    0x000004b5
.data:0000048c 21 0d 0a 09 09 09                and    DWORD PTR ds:0x909090a,ecx
.data:00000492 09 2f                            or     DWORD PTR [edi],ebp
.data:00000494 2f                               das    
.data:00000495 54                               push   esp
.data:00000496 68 65 20 22 73                   push   0x73222065
.data:0000049b 63 22                            arpl   WORD PTR [edx],sp
.data:0000049d 20 6f 62                         and    BYTE PTR [edi+0x62],ch
.data:000004a0 6a 65                            push   0x65
.data:000004a2 63 74 20 69                      arpl   WORD PTR [eax+eiz*1+0x69],si
.data:000004a6 73 20                            jae    0x000004c8
.data:000004a8 62 65 66                         bound  esp,QWORD PTR [ebp+0x66]
.data:000004ab 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000004ac 72 65                            jb     0x00000513
.data:000004ae 68 61 6e 64 20                   push   0x20646e61
.data:000004b3 64 65 66 69 6e 65 2c 20          fs imul bp,WORD PTR gs:[esi+0x65],0x202c
.data:000004bb 74 68                            je     0x00000525
.data:000004bd 69 73 20 69 73 20 69             imul   esi,DWORD PTR [ebx+0x20],0x69207369
.data:000004c4 6d                               ins    DWORD PTR es:[edi],dx
.data:000004c5 70 6f                            jo     0x00000536
.data:000004c7 73 73                            jae    0x0000053c
.data:000004c9 69 62 6c 65 20 74 6f             imul   esp,DWORD PTR [edx+0x6c],0x6f742065
.data:000004d0 20 72 65                         and    BYTE PTR [edx+0x65],dh
.data:000004d3 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:000004d6 61                               popa   
.data:000004d7 74 65                            je     0x0000053e
.data:000004d9 20 74 68 69                      and    BYTE PTR [eax+ebp*2+0x69],dh
.data:000004dd 73 20                            jae    0x000004ff
.data:000004df 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000004e0 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:000004e3 63 74 20 6f                      arpl   WORD PTR [eax+eiz*1+0x6f],si
.data:000004e7 72 20                            jb     0x00000509
.data:000004e9 6d                               ins    DWORD PTR es:[edi],dx
.data:000004ea 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000004eb 64 69 66 79 20 74 68 69          imul   esp,DWORD PTR fs:[esi+0x79],0x69687420
.data:000004f3 73 20                            jae    0x00000515
.data:000004f5 21 0d 0a 09 09 09                and    DWORD PTR ds:0x909090a,ecx
.data:000004fb 09 73 6f                         or     DWORD PTR [ebx+0x6f],esi
.data:000004fe 75 72                            jne    0x00000572
.data:00000500 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:00000503 61                               popa   
.data:00000504 74 68                            je     0x0000056e
.data:00000506 20 66 69                         and    BYTE PTR [esi+0x69],ah
.data:00000509 6c                               ins    BYTE PTR es:[edi],dx
.data:0000050a 65 28 29                         sub    BYTE PTR gs:[ecx],ch
.data:0000050d 3b 20                            cmp    esp,DWORD PTR [eax]
.data:0000050f 20 20                            and    BYTE PTR [eax],ah
.data:00000511 20 2f                            and    BYTE PTR [edi],ch
.data:00000513 2f                               das    
.data:00000514 55                               push   ebp
.data:00000515 74 69                            je     0x00000580
.data:00000517 6c                               ins    BYTE PTR es:[edi],dx
.data:00000518 69 7a 61 74 69 6f 6e             imul   edi,DWORD PTR [edx+0x61],0x6e6f6974
.data:0000051f 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000522 20 22                            and    BYTE PTR [edx],ah
.data:00000524 73 6f                            jae    0x00000595
.data:00000526 75 72                            jne    0x0000059a
.data:00000528 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:0000052b 61                               popa   
.data:0000052c 74 68                            je     0x00000596
.data:0000052e 22 20                            and    ah,BYTE PTR [eax]
.data:00000530 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000531 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000534 63 74 20 66                      arpl   WORD PTR [eax+eiz*1+0x66],si
.data:00000538 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000539 72 20                            jb     0x0000055b
.data:0000053b 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:0000053e 61                               popa   
.data:0000053f 74 65                            je     0x000005a6
.data:00000541 20 22                            and    BYTE PTR [edx],ah
.data:00000543 66 69 6c 65 22 20 66             imul   bp,WORD PTR [ebp+eiz*2+0x22],0x6620
.data:0000054a 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000054b 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000054c 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000550 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000551 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000554 64 20 6f 62                      and    BYTE PTR fs:[edi+0x62],ch
.data:00000558 6a 65                            push   0x65
.data:0000055a 63 74 20 21                      arpl   WORD PTR [eax+eiz*1+0x21],si
.data:0000055e 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000563 09 09                            or     DWORD PTR [ecx],ecx
.data:00000565 2f                               das    
.data:00000566 2f                               das    
.data:00000567 22 73 6f                         and    dh,BYTE PTR [ebx+0x6f]
.data:0000056a 75 72                            jne    0x000005de
.data:0000056c 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:0000056f 61                               popa   
.data:00000570 74 68                            je     0x000005da
.data:00000572 22 20                            and    ah,BYTE PTR [eax]
.data:00000574 62 65 66                         bound  esp,QWORD PTR [ebp+0x66]
.data:00000577 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000578 72 65                            jb     0x000005df
.data:0000057a 20 22                            and    BYTE PTR [edx],ah
.data:0000057c 66 69 6c 65 28 29 22             imul   bp,WORD PTR [ebp+eiz*2+0x28],0x2229
.data:00000583 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000586 20 63 6f                         and    BYTE PTR [ebx+0x6f],ah
.data:00000589 6d                               ins    DWORD PTR es:[edi],dx
.data:0000058a 70 75                            jo     0x00000601
.data:0000058c 6c                               ins    BYTE PTR es:[edi],dx
.data:0000058d 73 6f                            jae    0x000005fe
.data:0000058f 72 79                            jb     0x0000060a
.data:00000591 20 21                            and    BYTE PTR [ecx],ah
.data:00000593 20 57 69                         and    BYTE PTR [edi+0x69],dl
.data:00000596 74 68                            je     0x00000600
.data:00000598 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:0000059c 20 75 74                         and    BYTE PTR [ebp+0x74],dh
.data:0000059f 69 6c 69 7a 61 74 69 6f          imul   ebp,DWORD PTR [ecx+ebp*2+0x7a],0x6f697461
.data:000005a7 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000005a8 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:000005ab 20 22                            and    BYTE PTR [edx],ah
.data:000005ad 73 6f                            jae    0x0000061e
.data:000005af 75 72                            jne    0x00000623
.data:000005b1 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:000005b4 61                               popa   
.data:000005b5 74 68                            je     0x0000061f
.data:000005b7 22 20                            and    ah,BYTE PTR [eax]
.data:000005b9 74 68                            je     0x00000623
.data:000005bb 65 20 22                         and    BYTE PTR gs:[edx],ah
.data:000005be 66 69 6c 65 22 20 6f             imul   bp,WORD PTR [ebp+eiz*2+0x22],0x6f20
.data:000005c5 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:000005c8 63 74 20 61                      arpl   WORD PTR [eax+eiz*1+0x61],si
.data:000005cc 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000005cd 64 20 66 6f                      and    BYTE PTR fs:[esi+0x6f],ah
.data:000005d1 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000005d2 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:000005d6 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000005d7 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:000005da 20 63 72                         and    BYTE PTR [ebx+0x72],ah
.data:000005dd 65 61                            gs popa 
.data:000005df 74 65                            je     0x00000646
.data:000005e1 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:000005e4 64 20 69 74                      and    BYTE PTR fs:[ecx+0x74],ch
.data:000005e8 20 73 65                         and    BYTE PTR [ebx+0x65],dh
.data:000005eb 72 76                            jb     0x00000663
.data:000005ed 65 73 20                         gs jae 0x00000610
.data:000005f0 21 0d 0a 09 09 09                and    DWORD PTR ds:0x909090a,ecx
.data:000005f6 09 09                            or     DWORD PTR [ecx],ecx
.data:000005f8 66 69 6c 65 20 67 65             imul   bp,WORD PTR [ebp+eiz*2+0x20],0x6567
.data:000005ff 74 46                            je     0x00000647
.data:00000601 69 6c 65 4e 61 6d 65 28          imul   ebp,DWORD PTR [ebp+eiz*2+0x4e],0x28656d61
.data:00000609 29 3b                            sub    DWORD PTR [ebx],edi
.data:0000060b 20 20                            and    BYTE PTR [eax],ah
.data:0000060d 20 20                            and    BYTE PTR [eax],ah
.data:0000060f 2f                               das    
.data:00000610 2f                               das    
.data:00000611 55                               push   ebp
.data:00000612 74 6c                            je     0x00000680
.data:00000614 69 7a 61 74 69 6f 6e             imul   edi,DWORD PTR [edx+0x61],0x6e6f6974
.data:0000061b 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:0000061e 20 22                            and    BYTE PTR [edx],ah
.data:00000620 66 69 6c 65 22 20 6f             imul   bp,WORD PTR [ebp+eiz*2+0x22],0x6f20
.data:00000627 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:0000062a 63 74 20 66                      arpl   WORD PTR [eax+eiz*1+0x66],si
.data:0000062e 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000062f 72 20                            jb     0x00000651
.data:00000631 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:00000634 61                               popa   
.data:00000635 74 65                            je     0x0000069c
.data:00000637 20 22                            and    BYTE PTR [edx],ah
.data:00000639 67 65 74 46                      addr16 gs je 0x00000683
.data:0000063d 69 6c 65 4e 61 6d 65 22          imul   ebp,DWORD PTR [ebp+eiz*2+0x4e],0x22656d61
.data:00000645 20 66 6f                         and    BYTE PTR [esi+0x6f],ah
.data:00000648 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000649 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:0000064d 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000064e 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000651 64 20 6f 62                      and    BYTE PTR fs:[edi+0x62],ch
.data:00000655 6a 65                            push   0x65
.data:00000657 63 74 20 21                      arpl   WORD PTR [eax+eiz*1+0x21],si
.data:0000065b 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000660 09 09                            or     DWORD PTR [ecx],ecx
.data:00000662 09 2f                            or     DWORD PTR [edi],ebp
.data:00000664 2f                               das    
.data:00000665 22 66 69                         and    ah,BYTE PTR [esi+0x69]
.data:00000668 6c                               ins    BYTE PTR es:[edi],dx
.data:00000669 65 22 20                         and    ah,BYTE PTR gs:[eax]
.data:0000066c 62 65 66                         bound  esp,QWORD PTR [ebp+0x66]
.data:0000066f 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000670 72 65                            jb     0x000006d7
.data:00000672 20 22                            and    BYTE PTR [edx],ah
.data:00000674 67 65 74 46                      addr16 gs je 0x000006be
.data:00000678 69 6c 65 4e 61 6d 65 28          imul   ebp,DWORD PTR [ebp+eiz*2+0x4e],0x28656d61
.data:00000680 29 22                            sub    DWORD PTR [edx],esp
.data:00000682 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000685 20 63 6f                         and    BYTE PTR [ebx+0x6f],ah
.data:00000688 6d                               ins    DWORD PTR es:[edi],dx
.data:00000689 70 75                            jo     0x00000700
.data:0000068b 6c                               ins    BYTE PTR es:[edi],dx
.data:0000068c 73 6f                            jae    0x000006fd
.data:0000068e 72 79                            jb     0x00000709
.data:00000690 20 21                            and    BYTE PTR [ecx],ah
.data:00000692 20 57 49                         and    BYTE PTR [edi+0x49],dl
.data:00000695 74 68                            je     0x000006ff
.data:00000697 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:0000069b 20 75 74                         and    BYTE PTR [ebp+0x74],dh
.data:0000069e 69 6c 69 7a 61 74 69 6f          imul   ebp,DWORD PTR [ecx+ebp*2+0x7a],0x6f697461
.data:000006a6 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000006a7 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:000006aa 20 22                            and    BYTE PTR [edx],ah
.data:000006ac 66 69 6c 65 22 20 74             imul   bp,WORD PTR [ebp+eiz*2+0x22],0x7420
.data:000006b3 68 65 20 22 67                   push   0x67222065
.data:000006b8 65 74 46                         gs je  0x00000701
.data:000006bb 69 6c 65 4e 61 6d 65 22          imul   ebp,DWORD PTR [ebp+eiz*2+0x4e],0x22656d61
.data:000006c3 20 6f 62                         and    BYTE PTR [edi+0x62],ch
.data:000006c6 6a 65                            push   0x65
.data:000006c8 63 74 20 61                      arpl   WORD PTR [eax+eiz*1+0x61],si
.data:000006cc 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000006cd 64 20 66 6f                      and    BYTE PTR fs:[esi+0x6f],ah
.data:000006d1 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000006d2 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:000006d6 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000006d7 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:000006da 20 63 72                         and    BYTE PTR [ebx+0x72],ah
.data:000006dd 65 61                            gs popa 
.data:000006df 74 65                            je     0x00000746
.data:000006e1 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:000006e4 64 20 69 74                      and    BYTE PTR fs:[ecx+0x74],ch
.data:000006e8 20 73 65                         and    BYTE PTR [ebx+0x65],dh
.data:000006eb 72 76                            jb     0x00000763
.data:000006ed 65 73 20                         gs jae 0x00000710
.data:000006f0 21 20                            and    DWORD PTR [eax],esp
.data:000006f2 09 09                            or     DWORD PTR [ecx],ecx
.data:000006f4 0d 0a 09 09 09                   or     eax,0x909090a
.data:000006f9 09 73 6f                         or     DWORD PTR [ebx+0x6f],esi
.data:000006fc 75 72                            jne    0x00000770
.data:000006fe 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:00000701 61                               popa   
.data:00000702 74 68                            je     0x0000076c
.data:00000704 20 73 64                         and    BYTE PTR [ebx+0x64],dh
.data:00000707 6b 46 69 6c                      imul   eax,DWORD PTR [esi+0x69],0x6c
.data:0000070b 65 28 29                         sub    BYTE PTR gs:[ecx],ch
.data:0000070e 3b 20                            cmp    esp,DWORD PTR [eax]
.data:00000710 20 20                            and    BYTE PTR [eax],ah
.data:00000712 20 2f                            and    BYTE PTR [edi],ch
.data:00000714 2f                               das    
.data:00000715 55                               push   ebp
.data:00000716 74 69                            je     0x00000781
.data:00000718 6c                               ins    BYTE PTR es:[edi],dx
.data:00000719 69 7a 61 74 69 6f 6e             imul   edi,DWORD PTR [edx+0x61],0x6e6f6974
.data:00000720 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000723 20 22                            and    BYTE PTR [edx],ah
.data:00000725 73 6f                            jae    0x00000796
.data:00000727 75 72                            jne    0x0000079b
.data:00000729 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:0000072c 61                               popa   
.data:0000072d 74 68                            je     0x00000797
.data:0000072f 22 20                            and    ah,BYTE PTR [eax]
.data:00000731 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000732 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000735 63 74 20 66                      arpl   WORD PTR [eax+eiz*1+0x66],si
.data:00000739 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000073a 72 20                            jb     0x0000075c
.data:0000073c 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:0000073f 61                               popa   
.data:00000740 74 65                            je     0x000007a7
.data:00000742 20 22                            and    BYTE PTR [edx],ah
.data:00000744 73 64                            jae    0x000007aa
.data:00000746 6b 46 69 6c                      imul   eax,DWORD PTR [esi+0x69],0x6c
.data:0000074a 65 22 20                         and    ah,BYTE PTR gs:[eax]
.data:0000074d 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:0000074f 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000750 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000754 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000755 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000758 64 20 6f 62                      and    BYTE PTR fs:[edi+0x62],ch
.data:0000075c 6a 65                            push   0x65
.data:0000075e 63 74 20 21                      arpl   WORD PTR [eax+eiz*1+0x21],si
.data:00000762 20 0d 0a 09 09 09                and    BYTE PTR ds:0x909090a,cl
.data:00000768 09 09                            or     DWORD PTR [ecx],ecx
.data:0000076a 2f                               das    
.data:0000076b 2f                               das    
.data:0000076c 22 73 6f                         and    dh,BYTE PTR [ebx+0x6f]
.data:0000076f 75 72                            jne    0x000007e3
.data:00000771 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:00000774 61                               popa   
.data:00000775 74 68                            je     0x000007df
.data:00000777 22 20                            and    ah,BYTE PTR [eax]
.data:00000779 62 65 66                         bound  esp,QWORD PTR [ebp+0x66]
.data:0000077c 6f                               outs   dx,DWORD PTR ds:[esi]
.data:0000077d 69 72 65 20 22 73 64             imul   esi,DWORD PTR [edx+0x65],0x64732220
.data:00000784 6b 46 69 6c                      imul   eax,DWORD PTR [esi+0x69],0x6c
.data:00000788 65 28 29                         sub    BYTE PTR gs:[ecx],ch
.data:0000078b 22 20                            and    ah,BYTE PTR [eax]
.data:0000078d 69 73 20 63 6f 6d 70             imul   esi,DWORD PTR [ebx+0x20],0x706d6f63
.data:00000794 75 6c                            jne    0x00000802
.data:00000796 73 6f                            jae    0x00000807
.data:00000798 72 79                            jb     0x00000813
.data:0000079a 20 21                            and    BYTE PTR [ecx],ah
.data:0000079c 20 57 69                         and    BYTE PTR [edi+0x69],dl
.data:0000079f 74 68                            je     0x00000809
.data:000007a1 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:000007a5 20 75 74                         and    BYTE PTR [ebp+0x74],dh
.data:000007a8 69 6c 69 7a 61 74 69 6f          imul   ebp,DWORD PTR [ecx+ebp*2+0x7a],0x6f697461
.data:000007b0 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000007b1 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:000007b4 20 22                            and    BYTE PTR [edx],ah
.data:000007b6 73 6f                            jae    0x00000827
.data:000007b8 75 72                            jne    0x0000082c
.data:000007ba 63 65 50                         arpl   WORD PTR [ebp+0x50],sp
.data:000007bd 61                               popa   
.data:000007be 68 74 22 20 74                   push   0x74202274
.data:000007c3 68 65 20 22 73                   push   0x73222065
.data:000007c8 64 6b 46 69 6c                   imul   eax,DWORD PTR fs:[esi+0x69],0x6c
.data:000007cd 65 22 20                         and    ah,BYTE PTR gs:[eax]
.data:000007d0 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000007d1 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:000007d4 63 74 20 61                      arpl   WORD PTR [eax+eiz*1+0x61],si
.data:000007d8 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000007d9 64 20 66 6f                      and    BYTE PTR fs:[esi+0x6f],ah
.data:000007dd 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000007de 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:000007e2 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000007e3 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:000007e6 20 63 72                         and    BYTE PTR [ebx+0x72],ah
.data:000007e9 65 61                            gs popa 
.data:000007eb 74 65                            je     0x00000852
.data:000007ed 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:000007f0 64 20 69 74                      and    BYTE PTR fs:[ecx+0x74],ch
.data:000007f4 20 73 65                         and    BYTE PTR [ebx+0x65],dh
.data:000007f7 72 76                            jb     0x0000086f
.data:000007f9 65 73 20                         gs jae 0x0000081c
.data:000007fc 21 0d 0a 23 69 6e                and    DWORD PTR ds:0x6e69230a,ecx
.data:00000802 63 6c 75 64                      arpl   WORD PTR [ebp+esi*2+0x64],bp
.data:00000806 65 20 63 6c                      and    BYTE PTR gs:[ebx+0x6c],ah
.data:0000080a 69 65 6e 74 3a 73 79             imul   esp,DWORD PTR [ebp+0x6e],0x79733a74
.data:00000811 73 74                            jae    0x00000887
.data:00000813 65 6d                            gs ins DWORD PTR es:[edi],dx
.data:00000815 3a 6f 62                         cmp    ch,BYTE PTR [edi+0x62]
.data:00000818 6a 65                            push   0x65
.data:0000081a 63 74 3a 6d                      arpl   WORD PTR [edx+edi*1+0x6d],si
.data:0000081e 61                               popa   
.data:0000081f 74 68                            je     0x00000889
.data:00000821 3a 70 6f                         cmp    dh,BYTE PTR [eax+0x6f]
.data:00000824 77 3a                            ja     0x00000860
.data:00000826 2a 3b                            sub    bh,BYTE PTR [ebx]
.data:00000828 09 2f                            or     DWORD PTR [edi],ebp
.data:0000082a 2f                               das    
.data:0000082b 54                               push   esp
.data:0000082c 68 65 20 72 65                   push   0x65722065
.data:00000831 70 6f                            jo     0x000008a2
.data:00000833 73 69                            jae    0x0000089e
.data:00000835 74 6f                            je     0x000008a6
.data:00000837 72 79                            jb     0x000008b2
.data:00000839 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:0000083c 20 22                            and    BYTE PTR [edx],ah
.data:0000083e 70 6f                            jo     0x000008af
.data:00000840 77 22                            ja     0x00000864
.data:00000842 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000845 20 75 73                         and    BYTE PTR [ebp+0x73],dh
.data:00000848 65 64 20 74 6f 20                gs and BYTE PTR fs:[edi+ebp*2+0x20],dh
.data:0000084e 6d                               ins    DWORD PTR es:[edi],dx
.data:0000084f 61                               popa   
.data:00000850 74 68                            je     0x000008ba
.data:00000852 20 66 6f                         and    BYTE PTR [esi+0x6f],ah
.data:00000855 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000856 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:0000085a 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000085b 20 70 6f                         and    BYTE PTR [eax+0x6f],dh
.data:0000085e 77 65                            ja     0x000008c5
.data:00000860 72 20                            jb     0x00000882
.data:00000862 28 78 2c                         sub    BYTE PTR [eax+0x2c],bh
.data:00000865 20 79 29                         and    BYTE PTR [ecx+0x29],bh
.data:00000868 20 21                            and    BYTE PTR [ecx],ah
.data:0000086a 0d 0a 09 2f 2f                   or     eax,0x2f2f090a
.data:0000086f 57                               push   edi
.data:00000870 69 74 68 6f 75 74 20 22          imul   esi,DWORD PTR [eax+ebp*2+0x6f],0x22207475
.data:00000878 69 6e 63 6c 75 64 65             imul   ebp,DWORD PTR [esi+0x63],0x6564756c
.data:0000087f 64 22 20                         and    ah,BYTE PTR fs:[eax]
.data:00000882 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:00000884 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000885 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000889 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000088a 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:0000088d 64 20 6f 62                      and    BYTE PTR fs:[edi+0x62],ch
.data:00000891 6a 65                            push   0x65
.data:00000893 63 74 20 74                      arpl   WORD PTR [eax+eiz*1+0x74],si
.data:00000897 68 69 73 20 6c                   push   0x6c207369
.data:0000089c 69 6e 65 20 69 73 20             imul   ebp,DWORD PTR [esi+0x65],0x20736920
.data:000008a3 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000008a4 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000008a5 20 75 73                         and    BYTE PTR [ebp+0x73],dh
.data:000008a8 65 20 21                         and    BYTE PTR gs:[ecx],ah
.data:000008ab 20 49 6e                         and    BYTE PTR [ecx+0x6e],cl
.data:000008ae 63 6c 75 64                      arpl   WORD PTR [ebp+esi*2+0x64],bp
.data:000008b2 65 20 6f 66                      and    BYTE PTR gs:[edi+0x66],ch
.data:000008b6 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:000008ba 20 66 6f                         and    BYTE PTR [esi+0x6f],ah
.data:000008bd 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000008be 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:000008c2 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000008c3 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:000008c6 20 70 6f                         and    BYTE PTR [eax+0x6f],dh
.data:000008c9 77 20                            ja     0x000008eb
.data:000008cb 69 6e 20 73 63 2f 63             imul   ebp,DWORD PTR [esi+0x20],0x632f6373
.data:000008d2 6c                               ins    BYTE PTR es:[edi],dx
.data:000008d3 69 65 6e 74 2f 73 79             imul   esp,DWORD PTR [ebp+0x6e],0x79732f74
.data:000008da 73 74                            jae    0x00000950
.data:000008dc 65 6d                            gs ins DWORD PTR es:[edi],dx
.data:000008de 2f                               das    
.data:000008df 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000008e0 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:000008e3 63 74 2f 6d                      arpl   WORD PTR [edi+ebp*1+0x6d],si
.data:000008e7 61                               popa   
.data:000008e8 74 68                            je     0x00000952
.data:000008ea 2f                               das    
.data:000008eb 70 6f                            jo     0x0000095c
.data:000008ed 77 2f                            ja     0x0000091e
.data:000008ef 2a 0d 0a 09 44 45                sub    cl,BYTE PTR ds:0x4544090a
.data:000008f5 46                               inc    esi
.data:000008f6 49                               dec    ecx
.data:000008f7 4e                               dec    esi
.data:000008f8 45                               inc    ebp
.data:000008f9 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:000008fc 74 28                            je     0x00000926
.data:000008fe 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000008ff 75 6d                            jne    0x0000096e
.data:00000901 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000904 2e 62 65 74                      bound  esp,QWORD PTR cs:[ebp+0x74]
.data:00000908 77 65                            ja     0x0000096f
.data:0000090a 65 6e                            outs   dx,BYTE PTR gs:[esi]
.data:0000090c 5b                               pop    ebx
.data:0000090d 69 6e 74 2e 5b 67 65             imul   ebp,DWORD PTR [esi+0x74],0x65675b2e
.data:00000914 74 4d                            je     0x00000963
.data:00000916 69 6e 56 61 6c 75 65             imul   ebp,DWORD PTR [esi+0x56],0x65756c61
.data:0000091d 28 2d 6e 29 5d 20                sub    BYTE PTR ds:0x205d296e,ch
.data:00000923 26 26 20 5b 67                   es and BYTE PTR es:[ebx+0x67],bl
.data:00000928 65 74 4d                         gs je  0x00000978
.data:0000092b 61                               popa   
.data:0000092c 78 56                            js     0x00000984
.data:0000092e 61                               popa   
.data:0000092f 6c                               ins    BYTE PTR es:[edi],dx
.data:00000930 75 65                            jne    0x00000997
.data:00000932 28 6e 29                         sub    BYTE PTR [esi+0x29],ch
.data:00000935 5d                               pop    ebp
.data:00000936 5d                               pop    ebp
.data:00000937 29 3b                            sub    DWORD PTR [ebx],edi
.data:00000939 20 20                            and    BYTE PTR [eax],ah
.data:0000093b 20 20                            and    BYTE PTR [eax],ah
.data:0000093d 2f                               das    
.data:0000093e 2f                               das    
.data:0000093f 22 69 6e                         and    ch,BYTE PTR [ecx+0x6e]
.data:00000942 74 22                            je     0x00000966
.data:00000944 20 6f 62                         and    BYTE PTR [edi+0x62],ch
.data:00000947 6a 65                            push   0x65
.data:00000949 63 74 20 69                      arpl   WORD PTR [eax+eiz*1+0x69],si
.data:0000094d 73 20                            jae    0x0000096f
.data:0000094f 75 73                            jne    0x000009c4
.data:00000951 65 64 20 74 6f 20                gs and BYTE PTR fs:[edi+ebp*2+0x20],dh
.data:00000957 64 65 66 69 6e 65 20 61          fs imul bp,WORD PTR gs:[esi+0x65],0x6120
.data:0000095f 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000960 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:00000963 74 65                            je     0x000009ca
.data:00000965 67 65 72 20                      addr16 gs jb 0x00000989
.data:00000969 6e                               outs   dx,BYTE PTR ds:[esi]
.data:0000096a 75 6d                            jne    0x000009d9
.data:0000096c 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:0000096f 20 62 65                         and    BYTE PTR [edx+0x65],ah
.data:00000972 74 77                            je     0x000009eb
.data:00000974 65 65 6e                         gs outs dx,BYTE PTR gs:[esi]
.data:00000977 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:0000097b 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:0000097e 74 65                            je     0x000009e5
.data:00000980 67 65 72 20                      addr16 gs jb 0x000009a4
.data:00000984 6d                               ins    DWORD PTR es:[edi],dx
.data:00000985 61                               popa   
.data:00000986 78 69                            js     0x000009f1
.data:00000988 6d                               ins    DWORD PTR es:[edi],dx
.data:00000989 75 6d                            jne    0x000009f8
.data:0000098b 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:0000098e 64 20 6d 69                      and    BYTE PTR fs:[ebp+0x69],ch
.data:00000992 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000993 69 6d 75 6d 20 21 0d             imul   ebp,DWORD PTR [ebp+0x75],0xd21206d
.data:0000099a 0a 09                            or     cl,BYTE PTR [ecx]
.data:0000099c 09 2f                            or     DWORD PTR [edi],ebp
.data:0000099e 2f                               das    
.data:0000099f 49                               dec    ecx
.data:000009a0 66 20 22                         data16 and BYTE PTR [edx],ah
.data:000009a3 69 6e 74 22 20 66 6f             imul   ebp,DWORD PTR [esi+0x74],0x6f662022
.data:000009aa 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000009ab 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:000009af 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000009b0 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:000009b3 20 6e 6f                         and    BYTE PTR [esi+0x6f],ch
.data:000009b6 74 20                            je     0x000009d8
.data:000009b8 64 65 66 69 6e 65 64 20          fs imul bp,WORD PTR gs:[esi+0x65],0x2064
.data:000009c0 74 68                            je     0x00000a2a
.data:000009c2 65 20 6c 65 66                   and    BYTE PTR gs:[ebp+eiz*2+0x66],ch
.data:000009c7 74 2d                            je     0x000009f6
.data:000009c9 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000009ca 76 65                            jbe    0x00000a31
.data:000009cc 72 20                            jb     0x000009ee
.data:000009ce 77 69                            ja     0x00000a39
.data:000009d0 6c                               ins    BYTE PTR es:[edi],dx
.data:000009d1 6c                               ins    BYTE PTR es:[edi],dx
.data:000009d2 20 6e 6f                         and    BYTE PTR [esi+0x6f],ch
.data:000009d5 74 20                            je     0x000009f7
.data:000009d7 77 6f                            ja     0x00000a48
.data:000009d9 72 6b                            jb     0x00000a46
.data:000009db 20 21                            and    BYTE PTR [ecx],ah
.data:000009dd 0d 0a 09 09 64                   or     eax,0x6409090a
.data:000009e2 65 66 20 28                      data16 and BYTE PTR gs:[eax],ch
.data:000009e6 69 6e 74 29 3a 20 20             imul   ebp,DWORD PTR [esi+0x74],0x20203a29
.data:000009ed 20 20                            and    BYTE PTR [eax],ah
.data:000009ef 2f                               das    
.data:000009f0 2f                               das    
.data:000009f1 44                               inc    esp
.data:000009f2 65 66 69 6e 69 74 69             imul   bp,WORD PTR gs:[esi+0x69],0x6974
.data:000009f9 6f                               outs   dx,DWORD PTR ds:[esi]
.data:000009fa 6e                               outs   dx,BYTE PTR ds:[esi]
.data:000009fb 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:000009fe 20 22                            and    BYTE PTR [edx],ah
.data:00000a00 69 6e 74 22 20 6f 62             imul   ebp,DWORD PTR [esi+0x74],0x626f2022
.data:00000a07 6a 65                            push   0x65
.data:00000a09 63 74 20 21                      arpl   WORD PTR [eax+eiz*1+0x21],si
.data:00000a0d 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000a12 2f                               das    
.data:00000a13 2f                               das    
.data:00000a14 54                               push   esp
.data:00000a15 68 65 20 22 64                   push   0x64222065
.data:00000a1a 65 66 22 20                      data16 and ah,BYTE PTR gs:[eax]
.data:00000a1e 6b 65 79 77                      imul   esp,DWORD PTR [ebp+0x79],0x77
.data:00000a22 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000a23 72 64                            jb     0x00000a89
.data:00000a25 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000a28 20 63 6f                         and    BYTE PTR [ebx+0x6f],ah
.data:00000a2b 6d                               ins    DWORD PTR es:[edi],dx
.data:00000a2c 70 75                            jo     0x00000aa3
.data:00000a2e 6c                               ins    BYTE PTR es:[edi],dx
.data:00000a2f 73 6f                            jae    0x00000aa0
.data:00000a31 72 79                            jb     0x00000aac
.data:00000a33 20 21                            and    BYTE PTR [ecx],ah
.data:00000a35 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000a3a 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a3b 62 20                            bound  esp,QWORD PTR [eax]
.data:00000a3d 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a3e 75 6d                            jne    0x00000aad
.data:00000a40 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000a43 28 6e 29                         sub    BYTE PTR [esi+0x29],ch
.data:00000a46 3b 20                            cmp    esp,DWORD PTR [eax]
.data:00000a48 20 20                            and    BYTE PTR [eax],ah
.data:00000a4a 20 2f                            and    BYTE PTR [edi],ch
.data:00000a4c 2f                               das    
.data:00000a4d 22 6e 62                         and    ch,BYTE PTR [esi+0x62]
.data:00000a50 22 20                            and    ah,BYTE PTR [eax]
.data:00000a52 65 71 75                         gs jno 0x00000aca
.data:00000a55 61                               popa   
.data:00000a56 6c                               ins    BYTE PTR es:[edi],dx
.data:00000a57 73 20                            jae    0x00000a79
.data:00000a59 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a5a 75 6d                            jne    0x00000ac9
.data:00000a5c 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000a5f 2c 20                            sub    al,0x20
.data:00000a61 64 65 66 69 6e 69 74 69          fs imul bp,WORD PTR gs:[esi+0x69],0x6974
.data:00000a69 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000a6a 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a6b 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000a6e 20 22                            and    BYTE PTR [edx],ah
.data:00000a70 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a71 75 6d                            jne    0x00000ae0
.data:00000a73 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000a76 2d 3e 6e 22 20                   sub    eax,0x20226e3e
.data:00000a7b 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000a7c 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000a7f 63 74 20 61                      arpl   WORD PTR [eax+eiz*1+0x61],si
.data:00000a83 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a84 64 20 66 6f                      and    BYTE PTR fs:[esi+0x6f],ah
.data:00000a88 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a89 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000a8d 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000a8e 20 21                            and    BYTE PTR [ecx],ah
.data:00000a90 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000a95 09 2f                            or     DWORD PTR [edi],ebp
.data:00000a97 2f                               das    
.data:00000a98 54                               push   esp
.data:00000a99 68 65 20 22 6e                   push   0x6e222065
.data:00000a9e 62 22                            bound  esp,QWORD PTR [edx]
.data:00000aa0 20 6f 62                         and    BYTE PTR [edi+0x62],ch
.data:00000aa3 6a 65                            push   0x65
.data:00000aa5 63 74 20 69                      arpl   WORD PTR [eax+eiz*1+0x69],si
.data:00000aa9 73 20                            jae    0x00000acb
.data:00000aab 62 65 66                         bound  esp,QWORD PTR [ebp+0x66]
.data:00000aae 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000aaf 72 65                            jb     0x00000b16
.data:00000ab1 68 61 6e 64 20                   push   0x20646e61
.data:00000ab6 64 65 66 69 6e 65 2c 20          fs imul bp,WORD PTR gs:[esi+0x65],0x202c
.data:00000abe 74 68                            je     0x00000b28
.data:00000ac0 69 73 20 69 73 20 69             imul   esi,DWORD PTR [ebx+0x20],0x69207369
.data:00000ac7 6d                               ins    DWORD PTR es:[edi],dx
.data:00000ac8 70 6f                            jo     0x00000b39
.data:00000aca 73 73                            jae    0x00000b3f
.data:00000acc 69 62 6c 65 20 74 6f             imul   esp,DWORD PTR [edx+0x6c],0x6f742065
.data:00000ad3 20 72 65                         and    BYTE PTR [edx+0x65],dh
.data:00000ad6 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:00000ad9 61                               popa   
.data:00000ada 74 65                            je     0x00000b41
.data:00000adc 20 74 68 69                      and    BYTE PTR [eax+ebp*2+0x69],dh
.data:00000ae0 73 20                            jae    0x00000b02
.data:00000ae2 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000ae3 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000ae6 63 74 20 6f                      arpl   WORD PTR [eax+eiz*1+0x6f],si
.data:00000aea 72 20                            jb     0x00000b0c
.data:00000aec 6d                               ins    DWORD PTR es:[edi],dx
.data:00000aed 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000aee 64 69 66 79 20 74 68 69          imul   esp,DWORD PTR fs:[esi+0x79],0x69687420
.data:00000af6 73 20                            jae    0x00000b18
.data:00000af8 21 0d 0a 09 09 09                and    DWORD PTR ds:0x909090a,ecx
.data:00000afe 09 6e 75                         or     DWORD PTR [esi+0x75],ebp
.data:00000b01 6d                               ins    DWORD PTR es:[edi],dx
.data:00000b02 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000b05 20 6e 28                         and    BYTE PTR [esi+0x28],ch
.data:00000b08 29 3b                            sub    DWORD PTR [ebx],edi
.data:00000b0a 20 20                            and    BYTE PTR [eax],ah
.data:00000b0c 20 20                            and    BYTE PTR [eax],ah
.data:00000b0e 2f                               das    
.data:00000b0f 2f                               das    
.data:00000b10 4e                               dec    esi
.data:00000b11 61                               popa   
.data:00000b12 74 75                            je     0x00000b89
.data:00000b14 72 61                            jb     0x00000b77
.data:00000b16 6c                               ins    BYTE PTR es:[edi],dx
.data:00000b17 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:00000b1a 74 65                            je     0x00000b81
.data:00000b1c 67 65 72 0d                      addr16 gs jb 0x00000b2d
.data:00000b20 0a 09                            or     cl,BYTE PTR [ecx]
.data:00000b22 09 09                            or     DWORD PTR [ecx],ecx
.data:00000b24 09 09                            or     DWORD PTR [ecx],ecx
.data:00000b26 2f                               das    
.data:00000b27 2f                               das    
.data:00000b28 55                               push   ebp
.data:00000b29 74 69                            je     0x00000b94
.data:00000b2b 6c                               ins    BYTE PTR es:[edi],dx
.data:00000b2c 69 7a 61 74 69 6f 6e             imul   edi,DWORD PTR [edx+0x61],0x6e6f6974
.data:00000b33 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000b36 20 22                            and    BYTE PTR [edx],ah
.data:00000b38 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000b39 75 6d                            jne    0x00000ba8
.data:00000b3b 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000b3e 22 20                            and    ah,BYTE PTR [eax]
.data:00000b40 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000b41 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000b44 63 74 20 66                      arpl   WORD PTR [eax+eiz*1+0x66],si
.data:00000b48 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000b49 72 20                            jb     0x00000b6b
.data:00000b4b 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:00000b4e 61                               popa   
.data:00000b4f 74 65                            je     0x00000bb6
.data:00000b51 20 22                            and    BYTE PTR [edx],ah
.data:00000b53 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000b54 28 29                            sub    BYTE PTR [ecx],ch
.data:00000b56 22 20                            and    ah,BYTE PTR [eax]
.data:00000b58 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000b59 75 6d                            jne    0x00000bc8
.data:00000b5b 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000b5e 20 21                            and    BYTE PTR [ecx],ah
.data:00000b60 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000b65 09 6e 75                         or     DWORD PTR [esi+0x75],ebp
.data:00000b68 6d                               ins    DWORD PTR es:[edi],dx
.data:00000b69 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000b6c 20 62 65                         and    BYTE PTR [edx+0x65],ah
.data:00000b6f 74 77                            je     0x00000be8
.data:00000b71 65 65 6e                         gs outs dx,BYTE PTR gs:[esi]
.data:00000b74 28 2d 6e 20 3c 2d                sub    BYTE PTR ds:0x2d3c206e,ch
.data:00000b7a 3e 20 6e 29                      and    BYTE PTR ds:[esi+0x29],ch
.data:00000b7e 3b 09                            cmp    ecx,DWORD PTR [ecx]
.data:00000b80 2f                               das    
.data:00000b81 2f                               das    
.data:00000b82 55                               push   ebp
.data:00000b83 74 69                            je     0x00000bee
.data:00000b85 6c                               ins    BYTE PTR es:[edi],dx
.data:00000b86 69 7a 61 74 69 6f 6e             imul   edi,DWORD PTR [edx+0x61],0x6e6f6974
.data:00000b8d 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000b90 20 22                            and    BYTE PTR [edx],ah
.data:00000b92 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000b93 75 6d                            jne    0x00000c02
.data:00000b95 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000b98 22 20                            and    ah,BYTE PTR [eax]
.data:00000b9a 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000b9b 62 6a 65                         bound  ebp,QWORD PTR [edx+0x65]
.data:00000b9e 63 74 20 66                      arpl   WORD PTR [eax+eiz*1+0x66],si
.data:00000ba2 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000ba3 72 20                            jb     0x00000bc5
.data:00000ba5 63 72 65                         arpl   WORD PTR [edx+0x65],si
.data:00000ba8 61                               popa   
.data:00000ba9 74 65                            je     0x00000c10
.data:00000bab 20 22                            and    BYTE PTR [edx],ah
.data:00000bad 62 65 74                         bound  esp,QWORD PTR [ebp+0x74]
.data:00000bb0 77 65                            ja     0x00000c17
.data:00000bb2 65 6e                            outs   dx,BYTE PTR gs:[esi]
.data:00000bb4 22 20                            and    ah,BYTE PTR [eax]
.data:00000bb6 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:00000bb8 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000bb9 63 74 69 6f                      arpl   WORD PTR [ecx+ebp*2+0x6f],si
.data:00000bbd 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000bbe 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000bc1 64 20 6f 62                      and    BYTE PTR fs:[edi+0x62],ch
.data:00000bc5 6a 65                            push   0x65
.data:00000bc7 63 74 20 21                      arpl   WORD PTR [eax+eiz*1+0x21],si
.data:00000bcb 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000bd0 09 09                            or     DWORD PTR [ecx],ecx
.data:00000bd2 2f                               das    
.data:00000bd3 2f                               das    
.data:00000bd4 54                               push   esp
.data:00000bd5 68 69 73 20 69                   push   0x69207369
.data:00000bda 73 20                            jae    0x00000bfc
.data:00000bdc 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:00000bde 72 20                            jb     0x00000c00
.data:00000be0 74 68                            je     0x00000c4a
.data:00000be2 65 20 64 65 66                   and    BYTE PTR gs:[ebp+eiz*2+0x66],ah
.data:00000be7 66 65 72 65                      data16 gs jb 0x00000c50
.data:00000beb 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000bec 63 65 20                         arpl   WORD PTR [ebp+0x20],sp
.data:00000bef 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000bf0 66 20 6e 61                      data16 and BYTE PTR [esi+0x61],ch
.data:00000bf4 74 75                            je     0x00000c6b
.data:00000bf6 72 61                            jb     0x00000c59
.data:00000bf8 6c                               ins    BYTE PTR es:[edi],dx
.data:00000bf9 20 6d 61                         and    BYTE PTR [ebp+0x61],ch
.data:00000bfc 78 20                            js     0x00000c1e
.data:00000bfe 61                               popa   
.data:00000bff 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000c00 64 20 6d 69                      and    BYTE PTR fs:[ebp+0x69],ch
.data:00000c04 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000c05 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:00000c08 74 65                            je     0x00000c6f
.data:00000c0a 67 65 72 20                      addr16 gs jb 0x00000c2e
.data:00000c0e 76 61                            jbe    0x00000c71
.data:00000c10 6c                               ins    BYTE PTR es:[edi],dx
.data:00000c11 75 65                            jne    0x00000c78
.data:00000c13 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000c18 09 09                            or     DWORD PTR [ecx],ecx
.data:00000c1a 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000c1b 75 6d                            jne    0x00000c8a
.data:00000c1d 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000c20 20 67 65                         and    BYTE PTR [edi+0x65],ah
.data:00000c23 74 4d                            je     0x00000c72
.data:00000c25 69 6e 56 61 6c 75 65             imul   ebp,DWORD PTR [esi+0x56],0x65756c61
.data:00000c2c 28 67 65                         sub    BYTE PTR [edi+0x65],ah
.data:00000c2f 74 4d                            je     0x00000c7e
.data:00000c31 61                               popa   
.data:00000c32 78 56                            js     0x00000c8a
.data:00000c34 61                               popa   
.data:00000c35 6c                               ins    BYTE PTR es:[edi],dx
.data:00000c36 75 65                            jne    0x00000c9d
.data:00000c38 28 29                            sub    BYTE PTR [ecx],ch
.data:00000c3a 20 2d 20 28 70 6f                and    BYTE PTR ds:0x6f702820,ch
.data:00000c40 77 28                            ja     0x00000c6a
.data:00000c42 67 65 74 4d                      addr16 gs je 0x00000c93
.data:00000c46 61                               popa   
.data:00000c47 78 56                            js     0x00000c9f
.data:00000c49 61                               popa   
.data:00000c4a 6c                               ins    BYTE PTR es:[edi],dx
.data:00000c4b 75 65                            jne    0x00000cb2
.data:00000c4d 2c 20                            sub    al,0x20
.data:00000c4f 67 65 74 4d                      addr16 gs je 0x00000ca0
.data:00000c53 61                               popa   
.data:00000c54 78 56                            js     0x00000cac
.data:00000c56 61                               popa   
.data:00000c57 6c                               ins    BYTE PTR es:[edi],dx
.data:00000c58 75 65                            jne    0x00000cbf
.data:00000c5a 29 20                            sub    DWORD PTR [eax],esp
.data:00000c5c 2d 20 31 29 29                   sub    eax,0x29293120
.data:00000c61 3b 20                            cmp    esp,DWORD PTR [eax]
.data:00000c63 20 20                            and    BYTE PTR [eax],ah
.data:00000c65 20 2f                            and    BYTE PTR [edi],ch
.data:00000c67 2f                               das    
.data:00000c68 54                               push   esp
.data:00000c69 68 69 73 20 69                   push   0x69207369
.data:00000c6e 73 20                            jae    0x00000c90
.data:00000c70 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:00000c72 72 20                            jb     0x00000c94
.data:00000c74 64 65 66 69 6e 65 20 6d          fs imul bp,WORD PTR gs:[esi+0x65],0x6d20
.data:00000c7c 69 6e 20 76 61 6c 75             imul   ebp,DWORD PTR [esi+0x20],0x756c6176
.data:00000c83 65 20 6f 66                      and    BYTE PTR gs:[edi+0x66],ch
.data:00000c87 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000c8a 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:00000c8d 74 65                            je     0x00000cf4
.data:00000c8f 67 65 72 20                      addr16 gs jb 0x00000cb3
.data:00000c93 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000c94 75 6d                            jne    0x00000d03
.data:00000c96 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000c99 20 21                            and    BYTE PTR [ecx],ah
.data:00000c9b 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000ca0 09 09                            or     DWORD PTR [ecx],ecx
.data:00000ca2 09 2f                            or     DWORD PTR [edi],ebp
.data:00000ca4 2f                               das    
.data:00000ca5 32 20                            xor    ah,BYTE PTR [eax]
.data:00000ca7 31 34 37                         xor    DWORD PTR [edi+esi*1],esi
.data:00000caa 20 34 38                         and    BYTE PTR [eax+edi*1],dh
.data:00000cad 33 20                            xor    esp,DWORD PTR [eax]
.data:00000caf 36 34 37                         ss xor al,0x37
.data:00000cb2 20 2d 20 28 32 20                and    BYTE PTR ds:0x20322820,ch
.data:00000cb8 31 34 37                         xor    DWORD PTR [edi+esi*1],esi
.data:00000cbb 20 34 38                         and    BYTE PTR [eax+edi*1],dh
.data:00000cbe 33 20                            xor    esp,DWORD PTR [eax]
.data:00000cc0 36 34 37                         ss xor al,0x37
.data:00000cc3 20 2a                            and    BYTE PTR [edx],ch
.data:00000cc5 20 32                            and    BYTE PTR [edx],dh
.data:00000cc7 20 31                            and    BYTE PTR [ecx],dh
.data:00000cc9 34 37                            xor    al,0x37
.data:00000ccb 20 34 38                         and    BYTE PTR [eax+edi*1],dh
.data:00000cce 33 20                            xor    esp,DWORD PTR [eax]
.data:00000cd0 36 34 37                         ss xor al,0x37
.data:00000cd3 29 20                            sub    DWORD PTR [eax],esp
.data:00000cd5 2d 20 31 0d 0a                   sub    eax,0xa0d3120
.data:00000cda 09 09                            or     DWORD PTR [ecx],ecx
.data:00000cdc 09 09                            or     DWORD PTR [ecx],ecx
.data:00000cde 09 6e 75                         or     DWORD PTR [esi+0x75],ebp
.data:00000ce1 6d                               ins    DWORD PTR es:[edi],dx
.data:00000ce2 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000ce5 20 67 65                         and    BYTE PTR [edi+0x65],ah
.data:00000ce8 74 4d                            je     0x00000d37
.data:00000cea 61                               popa   
.data:00000ceb 78 56                            js     0x00000d43
.data:00000ced 61                               popa   
.data:00000cee 6c                               ins    BYTE PTR es:[edi],dx
.data:00000cef 75 65                            jne    0x00000d56
.data:00000cf1 28 67 65                         sub    BYTE PTR [edi+0x65],ah
.data:00000cf4 74 4d                            je     0x00000d43
.data:00000cf6 69 6e 56 61 6c 75 65             imul   ebp,DWORD PTR [esi+0x56],0x65756c61
.data:00000cfd 28 29                            sub    BYTE PTR [ecx],ch
.data:00000cff 20 2b                            and    BYTE PTR [ebx],ch
.data:00000d01 20 28                            and    BYTE PTR [eax],ch
.data:00000d03 70 6f                            jo     0x00000d74
.data:00000d05 77 28                            ja     0x00000d2f
.data:00000d07 67 65 74 4d                      addr16 gs je 0x00000d58
.data:00000d0b 69 6e 56 61 6c 75 65             imul   ebp,DWORD PTR [esi+0x56],0x65756c61
.data:00000d12 2c 20                            sub    al,0x20
.data:00000d14 67 65 74 4d                      addr16 gs je 0x00000d65
.data:00000d18 69 6e 56 61 6c 75 65             imul   ebp,DWORD PTR [esi+0x56],0x65756c61
.data:00000d1f 29 20                            sub    DWORD PTR [eax],esp
.data:00000d21 2b 20                            sub    esp,DWORD PTR [eax]
.data:00000d23 31 29                            xor    DWORD PTR [ecx],ebp
.data:00000d25 29 3b                            sub    DWORD PTR [ebx],edi
.data:00000d27 20 20                            and    BYTE PTR [eax],ah
.data:00000d29 20 20                            and    BYTE PTR [eax],ah
.data:00000d2b 2f                               das    
.data:00000d2c 2f                               das    
.data:00000d2d 54                               push   esp
.data:00000d2e 68 69 73 20 69                   push   0x69207369
.data:00000d33 73 20                            jae    0x00000d55
.data:00000d35 66 6f                            outs   dx,WORD PTR ds:[esi]
.data:00000d37 72 20                            jb     0x00000d59
.data:00000d39 64 65 66 69 6e 65 20 6d          fs imul bp,WORD PTR gs:[esi+0x65],0x6d20
.data:00000d41 61                               popa   
.data:00000d42 78 20                            js     0x00000d64
.data:00000d44 76 61                            jbe    0x00000da7
.data:00000d46 6c                               ins    BYTE PTR es:[edi],dx
.data:00000d47 75 65                            jne    0x00000dae
.data:00000d49 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000d4c 20 61 6e                         and    BYTE PTR [ecx+0x6e],ah
.data:00000d4f 20 69 6e                         and    BYTE PTR [ecx+0x6e],ch
.data:00000d52 74 65                            je     0x00000db9
.data:00000d54 67 65 72 20                      addr16 gs jb 0x00000d78
.data:00000d58 6e                               outs   dx,BYTE PTR ds:[esi]
.data:00000d59 75 6d                            jne    0x00000dc8
.data:00000d5b 62 65 72                         bound  esp,QWORD PTR [ebp+0x72]
.data:00000d5e 20 21                            and    BYTE PTR [ecx],ah
.data:00000d60 0d 0a 09 09 09                   or     eax,0x909090a
.data:00000d65 09 09                            or     DWORD PTR [ecx],ecx
.data:00000d67 09 2f                            or     DWORD PTR [edi],ebp
.data:00000d69 2f                               das    
.data:00000d6a 32 20                            xor    ah,BYTE PTR [eax]
.data:00000d6c 31 34 37                         xor    DWORD PTR [edi+esi*1],esi
.data:00000d6f 20 34 38                         and    BYTE PTR [eax+edi*1],dh
.data:00000d72 33 20                            xor    esp,DWORD PTR [eax]
.data:00000d74 36 34 37                         ss xor al,0x37
.data:00000d77 20 2b                            and    BYTE PTR [ebx],ch
.data:00000d79 20 28                            and    BYTE PTR [eax],ch
.data:00000d7b 32 20                            xor    ah,BYTE PTR [eax]
.data:00000d7d 31 34 37                         xor    DWORD PTR [edi+esi*1],esi
.data:00000d80 20 34 38                         and    BYTE PTR [eax+edi*1],dh
.data:00000d83 33 20                            xor    esp,DWORD PTR [eax]
.data:00000d85 36 34 37                         ss xor al,0x37
.data:00000d88 20 2a                            and    BYTE PTR [edx],ch
.data:00000d8a 20 32                            and    BYTE PTR [edx],dh
.data:00000d8c 20 31                            and    BYTE PTR [ecx],dh
.data:00000d8e 34 37                            xor    al,0x37
.data:00000d90 20 34 38                         and    BYTE PTR [eax+edi*1],dh
.data:00000d93 33 20                            xor    esp,DWORD PTR [eax]
.data:00000d95 36 34 37                         ss xor al,0x37
.data:00000d98 29 20                            sub    DWORD PTR [eax],esp
.data:00000d9a 2b 20                            sub    esp,DWORD PTR [eax]
.data:00000d9c 31 0d 0a 0d 0a 7d                xor    DWORD PTR ds:0x7d0a0d0a,ecx
.data:00000da2 20 2f                            and    BYTE PTR [edi],ch
.data:00000da4 2f                               das    
.data:00000da5 43                               inc    ebx
.data:00000da6 6c                               ins    BYTE PTR es:[edi],dx
.data:00000da7 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000da8 73 65                            jae    0x00000e0f
.data:00000daa 0d 0a 0d 0a 23                   or     eax,0x230a0d0a
.data:00000daf 69 6d 70 6f 72 74 20             imul   ebp,DWORD PTR [ebp+0x70],0x2074726f
.data:00000db6 41                               inc    ecx
.data:00000db7 6c                               ins    BYTE PTR es:[edi],dx
.data:00000db8 74 65                            je     0x00000e1f
.data:00000dba 73 3a                            jae    0x00000df6
.data:00000dbc 42                               inc    edx
.data:00000dbd 69 6e 4c 69 62 46 69             imul   ebp,DWORD PTR [esi+0x4c],0x69466269
.data:00000dc4 6c                               ins    BYTE PTR es:[edi],dx
.data:00000dc5 65 3a 61 6c                      cmp    ah,BYTE PTR gs:[ecx+0x6c]
.data:00000dc9 74 64                            je     0x00000e2f
.data:00000dcb 69 6f 2e 62 69 6e 20             imul   ebp,DWORD PTR [edi+0x2e],0x206e6962
.data:00000dd2 09 2f                            or     DWORD PTR [edi],ebp
.data:00000dd4 2f                               das    
.data:00000dd5 41                               inc    ecx
.data:00000dd6 6c                               ins    BYTE PTR es:[edi],dx
.data:00000dd7 74 64                            je     0x00000e3d
.data:00000dd9 69 6f 2e 62 69 6e 20             imul   ebp,DWORD PTR [edi+0x2e],0x206e6962
.data:00000de0 69 73 20 74 68 65 20             imul   esi,DWORD PTR [ebx+0x20],0x20656874
.data:00000de7 73 6f                            jae    0x00000e58
.data:00000de9 75 72                            jne    0x00000e5d
.data:00000deb 63 65 20                         arpl   WORD PTR [ebp+0x20],sp
.data:00000dee 63 6f 6e                         arpl   WORD PTR [edi+0x6e],bp
.data:00000df1 74 72                            je     0x00000e65
.data:00000df3 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000df4 6c                               ins    BYTE PTR es:[edi],dx
.data:00000df5 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000df8 20 41 6c                         and    BYTE PTR [ecx+0x6c],al
.data:00000dfb 74 65                            je     0x00000e62
.data:00000dfd 73 0d                            jae    0x00000e0c
.data:00000dff 0a 23                            or     ah,BYTE PTR [ebx]
.data:00000e01 69 6d 70 6f 72 74 20             imul   ebp,DWORD PTR [ebp+0x70],0x2074726f
.data:00000e08 41                               inc    ecx
.data:00000e09 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e0a 74 65                            je     0x00000e71
.data:00000e0c 73 3a                            jae    0x00000e48
.data:00000e0e 43                               inc    ebx
.data:00000e0f 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000e10 6d                               ins    DWORD PTR es:[edi],dx
.data:00000e11 70 69                            jo     0x00000e7c
.data:00000e13 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e14 65 72 3a                         gs jb  0x00000e51
.data:00000e17 61                               popa   
.data:00000e18 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e19 74 63                            je     0x00000e7e
.data:00000e1b 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000e1c 6d                               ins    DWORD PTR es:[edi],dx
.data:00000e1d 70 69                            jo     0x00000e88
.data:00000e1f 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e20 2e 62 69 6e                      bound  ebp,QWORD PTR cs:[ecx+0x6e]
.data:00000e24 20 09                            and    BYTE PTR [ecx],cl
.data:00000e26 2f                               das    
.data:00000e27 2f                               das    
.data:00000e28 41                               inc    ecx
.data:00000e29 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e2a 74 63                            je     0x00000e8f
.data:00000e2c 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000e2d 6d                               ins    DWORD PTR es:[edi],dx
.data:00000e2e 70 69                            jo     0x00000e99
.data:00000e30 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e31 2e 62 69 6e                      bound  ebp,QWORD PTR cs:[ecx+0x6e]
.data:00000e35 20 69 73                         and    BYTE PTR [ecx+0x73],ch
.data:00000e38 20 74 68 65                      and    BYTE PTR [eax+ebp*2+0x65],dh
.data:00000e3c 20 63 6f                         and    BYTE PTR [ebx+0x6f],ah
.data:00000e3f 6d                               ins    DWORD PTR es:[edi],dx
.data:00000e40 70 69                            jo     0x00000eab
.data:00000e42 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e43 65 72 20                         gs jb  0x00000e66
.data:00000e46 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000e47 66 20 74 68 65                   data16 and BYTE PTR [eax+ebp*2+0x65],dh
.data:00000e4c 20 73 6f                         and    BYTE PTR [ebx+0x6f],dh
.data:00000e4f 75 72                            jne    0x00000ec3
.data:00000e51 63 65 20                         arpl   WORD PTR [ebp+0x20],sp
.data:00000e54 63 6f 6e                         arpl   WORD PTR [edi+0x6e],bp
.data:00000e57 74 72                            je     0x00000ecb
.data:00000e59 6f                               outs   dx,DWORD PTR ds:[esi]
.data:00000e5a 6c                               ins    BYTE PTR es:[edi],dx
.data:00000e5b 20 6f 66                         and    BYTE PTR [edi+0x66],ch
.data:00000e5e 20 41 6c                         and    BYTE PTR [ecx+0x6c],al
.data:00000e61 74 65                            je     0x00000ec8
.data:00000e63 73               
