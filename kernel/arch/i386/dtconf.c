#include <kernel/dtconf.h>

// EXTERN ASSEMBLY FUNCTIONS

/* These function are destined to be the interrupt handlers. All of them push
   the interrupt number they represent on the stack. They also push an error
   code equal to zero if the cpu has not done it, to complete the interrupt
   information structure.
   Then they call a shared piece of code. The later push the registers and
   call the master interrupt handler, written in C.
 */
extern void interrupt_isr_wrapper_entry_point_0(void);
extern void interrupt_isr_wrapper_entry_point_1(void);
extern void interrupt_isr_wrapper_entry_point_2(void);
extern void interrupt_isr_wrapper_entry_point_3(void);
extern void interrupt_isr_wrapper_entry_point_4(void);
extern void interrupt_isr_wrapper_entry_point_5(void);
extern void interrupt_isr_wrapper_entry_point_6(void);
extern void interrupt_isr_wrapper_entry_point_7(void);
extern void interrupt_isr_wrapper_entry_point_8(void);
extern void interrupt_isr_wrapper_entry_point_9(void);
extern void interrupt_isr_wrapper_entry_point_10(void);
extern void interrupt_isr_wrapper_entry_point_11(void);
extern void interrupt_isr_wrapper_entry_point_12(void);
extern void interrupt_isr_wrapper_entry_point_13(void);
extern void interrupt_isr_wrapper_entry_point_14(void);
extern void interrupt_isr_wrapper_entry_point_15(void);
extern void interrupt_isr_wrapper_entry_point_16(void);
extern void interrupt_isr_wrapper_entry_point_17(void);
extern void interrupt_isr_wrapper_entry_point_18(void);
extern void interrupt_isr_wrapper_entry_point_19(void);
extern void interrupt_isr_wrapper_entry_point_20(void);
extern void interrupt_isr_wrapper_entry_point_21(void);
extern void interrupt_isr_wrapper_entry_point_22(void);
extern void interrupt_isr_wrapper_entry_point_23(void);
extern void interrupt_isr_wrapper_entry_point_24(void);
extern void interrupt_isr_wrapper_entry_point_25(void);
extern void interrupt_isr_wrapper_entry_point_26(void);
extern void interrupt_isr_wrapper_entry_point_27(void);
extern void interrupt_isr_wrapper_entry_point_28(void);
extern void interrupt_isr_wrapper_entry_point_29(void);
extern void interrupt_isr_wrapper_entry_point_30(void);
extern void interrupt_isr_wrapper_entry_point_31(void);
extern void interrupt_isr_wrapper_entry_point_32(void);
extern void interrupt_isr_wrapper_entry_point_33(void);
extern void interrupt_isr_wrapper_entry_point_34(void);
extern void interrupt_isr_wrapper_entry_point_35(void);
extern void interrupt_isr_wrapper_entry_point_36(void);
extern void interrupt_isr_wrapper_entry_point_37(void);
extern void interrupt_isr_wrapper_entry_point_38(void);
extern void interrupt_isr_wrapper_entry_point_39(void);
extern void interrupt_isr_wrapper_entry_point_40(void);
extern void interrupt_isr_wrapper_entry_point_41(void);
extern void interrupt_isr_wrapper_entry_point_42(void);
extern void interrupt_isr_wrapper_entry_point_43(void);
extern void interrupt_isr_wrapper_entry_point_44(void);
extern void interrupt_isr_wrapper_entry_point_45(void);
extern void interrupt_isr_wrapper_entry_point_46(void);
extern void interrupt_isr_wrapper_entry_point_47(void);
extern void interrupt_isr_wrapper_entry_point_48(void);
extern void interrupt_isr_wrapper_entry_point_49(void);
extern void interrupt_isr_wrapper_entry_point_50(void);
extern void interrupt_isr_wrapper_entry_point_51(void);
extern void interrupt_isr_wrapper_entry_point_52(void);
extern void interrupt_isr_wrapper_entry_point_53(void);
extern void interrupt_isr_wrapper_entry_point_54(void);
extern void interrupt_isr_wrapper_entry_point_55(void);
extern void interrupt_isr_wrapper_entry_point_56(void);
extern void interrupt_isr_wrapper_entry_point_57(void);
extern void interrupt_isr_wrapper_entry_point_58(void);
extern void interrupt_isr_wrapper_entry_point_59(void);
extern void interrupt_isr_wrapper_entry_point_60(void);
extern void interrupt_isr_wrapper_entry_point_61(void);
extern void interrupt_isr_wrapper_entry_point_62(void);
extern void interrupt_isr_wrapper_entry_point_63(void);
extern void interrupt_isr_wrapper_entry_point_64(void);
extern void interrupt_isr_wrapper_entry_point_65(void);
extern void interrupt_isr_wrapper_entry_point_66(void);
extern void interrupt_isr_wrapper_entry_point_67(void);
extern void interrupt_isr_wrapper_entry_point_68(void);
extern void interrupt_isr_wrapper_entry_point_69(void);
extern void interrupt_isr_wrapper_entry_point_70(void);
extern void interrupt_isr_wrapper_entry_point_71(void);
extern void interrupt_isr_wrapper_entry_point_72(void);
extern void interrupt_isr_wrapper_entry_point_73(void);
extern void interrupt_isr_wrapper_entry_point_74(void);
extern void interrupt_isr_wrapper_entry_point_75(void);
extern void interrupt_isr_wrapper_entry_point_76(void);
extern void interrupt_isr_wrapper_entry_point_77(void);
extern void interrupt_isr_wrapper_entry_point_78(void);
extern void interrupt_isr_wrapper_entry_point_79(void);
extern void interrupt_isr_wrapper_entry_point_80(void);
extern void interrupt_isr_wrapper_entry_point_81(void);
extern void interrupt_isr_wrapper_entry_point_82(void);
extern void interrupt_isr_wrapper_entry_point_83(void);
extern void interrupt_isr_wrapper_entry_point_84(void);
extern void interrupt_isr_wrapper_entry_point_85(void);
extern void interrupt_isr_wrapper_entry_point_86(void);
extern void interrupt_isr_wrapper_entry_point_87(void);
extern void interrupt_isr_wrapper_entry_point_88(void);
extern void interrupt_isr_wrapper_entry_point_89(void);
extern void interrupt_isr_wrapper_entry_point_90(void);
extern void interrupt_isr_wrapper_entry_point_91(void);
extern void interrupt_isr_wrapper_entry_point_92(void);
extern void interrupt_isr_wrapper_entry_point_93(void);
extern void interrupt_isr_wrapper_entry_point_94(void);
extern void interrupt_isr_wrapper_entry_point_95(void);
extern void interrupt_isr_wrapper_entry_point_96(void);
extern void interrupt_isr_wrapper_entry_point_97(void);
extern void interrupt_isr_wrapper_entry_point_98(void);
extern void interrupt_isr_wrapper_entry_point_99(void);
extern void interrupt_isr_wrapper_entry_point_100(void);
extern void interrupt_isr_wrapper_entry_point_101(void);
extern void interrupt_isr_wrapper_entry_point_102(void);
extern void interrupt_isr_wrapper_entry_point_103(void);
extern void interrupt_isr_wrapper_entry_point_104(void);
extern void interrupt_isr_wrapper_entry_point_105(void);
extern void interrupt_isr_wrapper_entry_point_106(void);
extern void interrupt_isr_wrapper_entry_point_107(void);
extern void interrupt_isr_wrapper_entry_point_108(void);
extern void interrupt_isr_wrapper_entry_point_109(void);
extern void interrupt_isr_wrapper_entry_point_110(void);
extern void interrupt_isr_wrapper_entry_point_111(void);
extern void interrupt_isr_wrapper_entry_point_112(void);
extern void interrupt_isr_wrapper_entry_point_113(void);
extern void interrupt_isr_wrapper_entry_point_114(void);
extern void interrupt_isr_wrapper_entry_point_115(void);
extern void interrupt_isr_wrapper_entry_point_116(void);
extern void interrupt_isr_wrapper_entry_point_117(void);
extern void interrupt_isr_wrapper_entry_point_118(void);
extern void interrupt_isr_wrapper_entry_point_119(void);
extern void interrupt_isr_wrapper_entry_point_120(void);
extern void interrupt_isr_wrapper_entry_point_121(void);
extern void interrupt_isr_wrapper_entry_point_122(void);
extern void interrupt_isr_wrapper_entry_point_123(void);
extern void interrupt_isr_wrapper_entry_point_124(void);
extern void interrupt_isr_wrapper_entry_point_125(void);
extern void interrupt_isr_wrapper_entry_point_126(void);
extern void interrupt_isr_wrapper_entry_point_127(void);
extern void interrupt_isr_wrapper_entry_point_128(void);
extern void interrupt_isr_wrapper_entry_point_129(void);
extern void interrupt_isr_wrapper_entry_point_130(void);
extern void interrupt_isr_wrapper_entry_point_131(void);
extern void interrupt_isr_wrapper_entry_point_132(void);
extern void interrupt_isr_wrapper_entry_point_133(void);
extern void interrupt_isr_wrapper_entry_point_134(void);
extern void interrupt_isr_wrapper_entry_point_135(void);
extern void interrupt_isr_wrapper_entry_point_136(void);
extern void interrupt_isr_wrapper_entry_point_137(void);
extern void interrupt_isr_wrapper_entry_point_138(void);
extern void interrupt_isr_wrapper_entry_point_139(void);
extern void interrupt_isr_wrapper_entry_point_140(void);
extern void interrupt_isr_wrapper_entry_point_141(void);
extern void interrupt_isr_wrapper_entry_point_142(void);
extern void interrupt_isr_wrapper_entry_point_143(void);
extern void interrupt_isr_wrapper_entry_point_144(void);
extern void interrupt_isr_wrapper_entry_point_145(void);
extern void interrupt_isr_wrapper_entry_point_146(void);
extern void interrupt_isr_wrapper_entry_point_147(void);
extern void interrupt_isr_wrapper_entry_point_148(void);
extern void interrupt_isr_wrapper_entry_point_149(void);
extern void interrupt_isr_wrapper_entry_point_150(void);
extern void interrupt_isr_wrapper_entry_point_151(void);
extern void interrupt_isr_wrapper_entry_point_152(void);
extern void interrupt_isr_wrapper_entry_point_153(void);
extern void interrupt_isr_wrapper_entry_point_154(void);
extern void interrupt_isr_wrapper_entry_point_155(void);
extern void interrupt_isr_wrapper_entry_point_156(void);
extern void interrupt_isr_wrapper_entry_point_157(void);
extern void interrupt_isr_wrapper_entry_point_158(void);
extern void interrupt_isr_wrapper_entry_point_159(void);
extern void interrupt_isr_wrapper_entry_point_160(void);
extern void interrupt_isr_wrapper_entry_point_161(void);
extern void interrupt_isr_wrapper_entry_point_162(void);
extern void interrupt_isr_wrapper_entry_point_163(void);
extern void interrupt_isr_wrapper_entry_point_164(void);
extern void interrupt_isr_wrapper_entry_point_165(void);
extern void interrupt_isr_wrapper_entry_point_166(void);
extern void interrupt_isr_wrapper_entry_point_167(void);
extern void interrupt_isr_wrapper_entry_point_168(void);
extern void interrupt_isr_wrapper_entry_point_169(void);
extern void interrupt_isr_wrapper_entry_point_170(void);
extern void interrupt_isr_wrapper_entry_point_171(void);
extern void interrupt_isr_wrapper_entry_point_172(void);
extern void interrupt_isr_wrapper_entry_point_173(void);
extern void interrupt_isr_wrapper_entry_point_174(void);
extern void interrupt_isr_wrapper_entry_point_175(void);
extern void interrupt_isr_wrapper_entry_point_176(void);
extern void interrupt_isr_wrapper_entry_point_177(void);
extern void interrupt_isr_wrapper_entry_point_178(void);
extern void interrupt_isr_wrapper_entry_point_179(void);
extern void interrupt_isr_wrapper_entry_point_180(void);
extern void interrupt_isr_wrapper_entry_point_181(void);
extern void interrupt_isr_wrapper_entry_point_182(void);
extern void interrupt_isr_wrapper_entry_point_183(void);
extern void interrupt_isr_wrapper_entry_point_184(void);
extern void interrupt_isr_wrapper_entry_point_185(void);
extern void interrupt_isr_wrapper_entry_point_186(void);
extern void interrupt_isr_wrapper_entry_point_187(void);
extern void interrupt_isr_wrapper_entry_point_188(void);
extern void interrupt_isr_wrapper_entry_point_189(void);
extern void interrupt_isr_wrapper_entry_point_190(void);
extern void interrupt_isr_wrapper_entry_point_191(void);
extern void interrupt_isr_wrapper_entry_point_192(void);
extern void interrupt_isr_wrapper_entry_point_193(void);
extern void interrupt_isr_wrapper_entry_point_194(void);
extern void interrupt_isr_wrapper_entry_point_195(void);
extern void interrupt_isr_wrapper_entry_point_196(void);
extern void interrupt_isr_wrapper_entry_point_197(void);
extern void interrupt_isr_wrapper_entry_point_198(void);
extern void interrupt_isr_wrapper_entry_point_199(void);
extern void interrupt_isr_wrapper_entry_point_200(void);
extern void interrupt_isr_wrapper_entry_point_201(void);
extern void interrupt_isr_wrapper_entry_point_202(void);
extern void interrupt_isr_wrapper_entry_point_203(void);
extern void interrupt_isr_wrapper_entry_point_204(void);
extern void interrupt_isr_wrapper_entry_point_205(void);
extern void interrupt_isr_wrapper_entry_point_206(void);
extern void interrupt_isr_wrapper_entry_point_207(void);
extern void interrupt_isr_wrapper_entry_point_208(void);
extern void interrupt_isr_wrapper_entry_point_209(void);
extern void interrupt_isr_wrapper_entry_point_210(void);
extern void interrupt_isr_wrapper_entry_point_211(void);
extern void interrupt_isr_wrapper_entry_point_212(void);
extern void interrupt_isr_wrapper_entry_point_213(void);
extern void interrupt_isr_wrapper_entry_point_214(void);
extern void interrupt_isr_wrapper_entry_point_215(void);
extern void interrupt_isr_wrapper_entry_point_216(void);
extern void interrupt_isr_wrapper_entry_point_217(void);
extern void interrupt_isr_wrapper_entry_point_218(void);
extern void interrupt_isr_wrapper_entry_point_219(void);
extern void interrupt_isr_wrapper_entry_point_220(void);
extern void interrupt_isr_wrapper_entry_point_221(void);
extern void interrupt_isr_wrapper_entry_point_222(void);
extern void interrupt_isr_wrapper_entry_point_223(void);
extern void interrupt_isr_wrapper_entry_point_224(void);
extern void interrupt_isr_wrapper_entry_point_225(void);
extern void interrupt_isr_wrapper_entry_point_226(void);
extern void interrupt_isr_wrapper_entry_point_227(void);
extern void interrupt_isr_wrapper_entry_point_228(void);
extern void interrupt_isr_wrapper_entry_point_229(void);
extern void interrupt_isr_wrapper_entry_point_230(void);
extern void interrupt_isr_wrapper_entry_point_231(void);
extern void interrupt_isr_wrapper_entry_point_232(void);
extern void interrupt_isr_wrapper_entry_point_233(void);
extern void interrupt_isr_wrapper_entry_point_234(void);
extern void interrupt_isr_wrapper_entry_point_235(void);
extern void interrupt_isr_wrapper_entry_point_236(void);
extern void interrupt_isr_wrapper_entry_point_237(void);
extern void interrupt_isr_wrapper_entry_point_238(void);
extern void interrupt_isr_wrapper_entry_point_239(void);
extern void interrupt_isr_wrapper_entry_point_240(void);
extern void interrupt_isr_wrapper_entry_point_241(void);
extern void interrupt_isr_wrapper_entry_point_242(void);
extern void interrupt_isr_wrapper_entry_point_243(void);
extern void interrupt_isr_wrapper_entry_point_244(void);
extern void interrupt_isr_wrapper_entry_point_245(void);
extern void interrupt_isr_wrapper_entry_point_246(void);
extern void interrupt_isr_wrapper_entry_point_247(void);
extern void interrupt_isr_wrapper_entry_point_248(void);
extern void interrupt_isr_wrapper_entry_point_249(void);
extern void interrupt_isr_wrapper_entry_point_250(void);
extern void interrupt_isr_wrapper_entry_point_251(void);
extern void interrupt_isr_wrapper_entry_point_252(void);
extern void interrupt_isr_wrapper_entry_point_253(void);
extern void interrupt_isr_wrapper_entry_point_254(void);
extern void interrupt_isr_wrapper_entry_point_255(void);

// VARIABLES

struct gdt_entry gdt_conf[GDT_SIZE] = {
  {},
  {.base  = 0x00000000,
   .limit = 0xFFFFFFFF,
   .prs   = true,
   .privl = 0x00,
   .ex    = true,
   .dc    = true,
   .rw    = true,
   .gr    = true,
   .sz    = true
  },
  {.base  = 0x00000000,
   .limit = 0xFFFFFFFF,
   .prs   = true,
   .privl = 0x00,
   .ex    = false,
   .dc    = false,
   .rw    = true,
   .gr    = true,
   .sz    = true
  },
  {.base  = 0x00000000,
   .limit = 0xFFFFFFFF,
   .prs   = true,
   .privl = 0x00,
   .ex    = true,
   .dc    = true,
   .rw    = true,
   .gr    = true,
   .sz    = true
  },
  {.base  = 0x00000000,
   .limit = 0xFFFFFFFF,
   .prs   = true,
   .privl = 0x00,
   .ex    = false,
   .dc    = false,
   .rw    = true,
   .gr    = true,
   .sz    = true
  }
};

struct idt_entry idt_conf[IDT_SIZE] = {
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_0,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_1,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_2,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_3,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_4,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_5,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_6,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_7,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_8,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_9,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_10,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_11,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_12,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_13,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_14,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_15,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_16,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_17,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_18,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_19,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_20,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_21,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_22,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_23,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_24,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_25,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_26,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_27,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_28,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_29,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_30,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_31,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_32,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_33,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_34,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_35,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_36,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_37,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_38,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_39,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_40,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_41,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_42,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_43,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_44,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_45,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_46,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_47,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_48,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_49,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_50,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_51,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_52,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_53,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_54,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_55,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_56,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_57,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_58,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_59,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_60,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_61,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_62,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_63,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_64,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_65,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_66,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_67,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_68,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_69,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_70,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_71,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_72,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_73,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_74,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_75,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_76,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_77,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_78,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_79,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_80,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_81,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_82,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_83,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_84,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_85,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_86,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_87,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_88,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_89,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_90,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_91,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_92,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_93,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_94,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_95,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_96,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_97,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_98,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_99,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_100,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_101,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_102,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_103,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_104,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_105,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_106,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_107,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_108,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_109,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_110,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_111,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_112,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_113,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_114,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_115,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_116,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_117,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_118,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_119,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_120,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_121,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_122,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_123,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_124,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_125,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_126,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_127,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_128,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_129,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_130,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_131,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_132,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_133,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_134,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_135,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_136,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_137,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_138,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_139,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_140,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_141,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_142,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_143,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_144,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_145,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_146,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_147,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_148,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_149,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_150,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_151,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_152,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_153,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_154,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_155,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_156,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_157,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_158,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_159,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_160,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_161,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_162,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_163,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_164,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_165,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_166,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_167,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_168,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_169,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_170,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_171,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_172,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_173,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_174,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_175,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_176,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_177,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_178,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_179,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_180,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_181,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_182,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_183,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_184,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_185,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_186,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_187,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_188,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_189,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_190,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_191,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_192,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_193,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_194,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_195,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_196,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_197,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_198,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_199,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_200,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_201,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_202,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_203,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_204,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_205,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_206,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_207,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_208,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_209,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_210,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_211,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_212,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_213,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_214,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_215,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_216,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_217,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_218,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_219,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_220,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_221,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_222,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_223,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_224,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_225,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_226,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_227,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_228,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_229,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_230,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_231,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_232,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_233,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_234,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_235,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_236,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_237,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_238,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_239,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_240,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_241,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_242,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_243,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_244,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_245,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_246,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_247,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_248,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_249,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_250,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_251,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_252,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_253,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_254,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
  {
    .selector = 0x0008,
    .offset = (uint32_t) interrupt_isr_wrapper_entry_point_255,
    .type = IDT_GATE_TYPE_INTERRUPT,
    .dpl = 0,
    .prs = true,
  },
};
