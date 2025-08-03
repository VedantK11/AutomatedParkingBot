/* --- Generated the 14/4/2024 at 17:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. feb. 9 16:14:54 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__determineDirection_step(long s[5],
                                            Line_follower__determineDirection_out* _out) {
  
  long v_10;
  long v_9;
  long v_8;
  long v_7;
  long v_6;
  long v_5;
  long v_4;
  long v_3;
  long v_2;
  long v_1;
  long v;
  v_7 = s[4];
  v_8 = (v_7>500);
  v_5 = s[3];
  v_6 = (v_5>500);
  v_9 = (v_6||v_8);
  if (v_9) {
    v_10 = 3;
  } else {
    v_10 = 1;
  };
  v_2 = s[0];
  v = s[1];
  v_3 = (v_2>500);
  v_1 = (v>500);
  v_4 = (v_1||v_3);
  if (v_4) {
    _out->direction = 2;
  } else {
    _out->direction = v_10;
  };;
}

void Line_follower__specialdetermineDirection_step(long s[5],
                                                   Line_follower__specialdetermineDirection_out* _out) {
  
  long v_20;
  long v_19;
  long v_18;
  long v_17;
  long v_16;
  long v_15;
  long v_14;
  long v_13;
  long v_12;
  long v_11;
  long v;
  v_17 = s[4];
  v_18 = (v_17>380);
  v_15 = s[3];
  v_16 = (v_15>380);
  v_19 = (v_16||v_18);
  if (v_19) {
    v_20 = 3;
  } else {
    v_20 = 1;
  };
  v_12 = s[0];
  v = s[1];
  v_13 = (v_12>400);
  v_11 = (v>400);
  v_14 = (v_11||v_13);
  if (v_14) {
    _out->direction = 2;
  } else {
    _out->direction = v_20;
  };;
}

void Line_follower__blackleftdetermineDirection_step(long s[5],
                                                     Line_follower__blackleftdetermineDirection_out* _out) {
  
  long v_30;
  long v_29;
  long v_28;
  long v_27;
  long v_26;
  long v_25;
  long v_24;
  long v_23;
  long v_22;
  long v_21;
  long v;
  v_27 = s[4];
  v_28 = (v_27<550);
  v_25 = s[3];
  v_26 = (v_25<550);
  v_29 = (v_26||v_28);
  if (v_29) {
    v_30 = 3;
  } else {
    v_30 = 1;
  };
  v_22 = s[0];
  v = s[1];
  v_23 = (v_22<550);
  v_21 = (v<550);
  v_24 = (v_21||v_23);
  if (v_24) {
    _out->direction = 2;
  } else {
    _out->direction = v_30;
  };;
}

void Line_follower__blackrightdetermineDirection_step(long s[5],
                                                      Line_follower__blackrightdetermineDirection_out* _out) {
  
  long v_40;
  long v_39;
  long v_38;
  long v_37;
  long v_36;
  long v_35;
  long v_34;
  long v_33;
  long v_32;
  long v_31;
  long v;
  v_37 = s[0];
  v_38 = (v_37<550);
  v_35 = s[1];
  v_36 = (v_35<550);
  v_39 = (v_36||v_38);
  if (v_39) {
    v_40 = 2;
  } else {
    v_40 = 1;
  };
  v_32 = s[4];
  v = s[3];
  v_33 = (v_32<550);
  v_31 = (v<550);
  v_34 = (v_31||v_33);
  if (v_34) {
    _out->direction = 3;
  } else {
    _out->direction = v_40;
  };;
}

void Line_follower__calculatePID_reset(Line_follower__calculatePID_mem* self) {
  self->v_43 = true;
  self->v = true;
}

void Line_follower__calculatePID_step(long sensor1, long sensor2,
                                      Line_follower__calculatePID_out* _out,
                                      Line_follower__calculatePID_mem* self) {
  
  long v_51;
  long v_50;
  long v_49;
  long v_48;
  long v_47;
  long v_46;
  long v_45;
  long v_42;
  long error;
  long longegral;
  long derivative;
  if (self->v_43) {
    v_45 = 0;
  } else {
    v_45 = self->v_44;
  };
  error = (sensor1+sensor2);
  v_46 = (Line_follower__kp*error);
  v_47 = (v_46/12);
  derivative = (error-v_45);
  v_50 = (Line_follower__kd*derivative);
  v_51 = (v_50/250);
  v_42 = (self->v_41+error);
  if (self->v) {
    longegral = 0;
  } else {
    longegral = v_42;
  };
  v_48 = (Line_follower__ki*longegral);
  v_49 = (v_47+v_48);
  _out->pid = (v_49+v_51);
  self->v_44 = error;
  self->v_43 = false;
  self->v_41 = longegral;
  self->v = false;;
}

void Line_follower__calculatePIDBLack_reset(Line_follower__calculatePIDBLack_mem* self) {
  self->v_54 = true;
  self->v = true;
}

void Line_follower__calculatePIDBLack_step(long sensor1, long sensor2,
                                           Line_follower__calculatePIDBLack_out* _out,
                                           Line_follower__calculatePIDBLack_mem* self) {
  
  long v_63;
  long v_62;
  long v_61;
  long v_60;
  long v_59;
  long v_58;
  long v_57;
  long v_56;
  long v_53;
  long error;
  long longegral;
  long derivative;
  if (self->v_54) {
    v_56 = 0;
  } else {
    v_56 = self->v_55;
  };
  error = (sensor1+sensor2);
  v_57 = (Line_follower__kp*error);
  v_58 = (v_57/40);
  derivative = (error-v_56);
  v_61 = (Line_follower__kd*derivative);
  v_62 = (v_61*9);
  v_63 = (v_62/11);
  v_53 = (self->v_52+error);
  if (self->v) {
    longegral = 0;
  } else {
    longegral = v_53;
  };
  v_59 = (Line_follower__ki*longegral);
  v_60 = (v_58+v_59);
  _out->pid = (v_60+v_63);
  self->v_55 = error;
  self->v_54 = false;
  self->v_52 = longegral;
  self->v = false;;
}

void Line_follower__max_step(long a, long b, Line_follower__max_out* _out) {
  
  long v;
  v = (a>=b);
  if (v) {
    _out->max = a;
  } else {
    _out->max = b;
  };;
}

void Line_follower__min_step(long a, long b, Line_follower__min_out* _out) {
  
  long v;
  v = (a<=b);
  if (v) {
    _out->min = a;
  } else {
    _out->min = b;
  };;
}

void Line_follower__blackMain_reset(Line_follower__blackMain_mem* self) {
  Line_follower__calculatePIDBLack_reset(&self->calculatePIDBLack_1);
  Line_follower__calculatePIDBLack_reset(&self->calculatePIDBLack);
}

void Line_follower__blackMain_step(long sen0, long sen1, long sen2, long sen3,
                                   long sen4, long nodeCount,
                                   Line_follower__blackMain_out* _out,
                                   Line_follower__blackMain_mem* self) {
  Line_follower__blackrightdetermineDirection_out Line_follower__blackrightdetermineDirection_out_st;
  Line_follower__calculatePIDBLack_out Line_follower__calculatePIDBLack_out_st;
  
  long v_79;
  long v_78;
  long v_77;
  long v_76;
  long v_75;
  long v_74;
  long v_73;
  long v_72;
  long v_71;
  long v_70;
  long v_69;
  long v_68;
  long v_67;
  long v_66;
  long v_65;
  long v_64;
  long v;
  long sen[5];
  long pidLeftTurn;
  long pidRightTurn;
  long leftWheelspeed_left_turn;
  long rightWheelspeed_left_turn;
  long leftWheelspeed_right_turn;
  long rightWheelspeed_right_turn;
  long v_l;
  long v_r;
  long dirr;
  v_66 = (833-sen1);
  v_65 = (762-sen0);
  Line_follower__calculatePIDBLack_step(v_65, v_66,
                                        &Line_follower__calculatePIDBLack_out_st,
                                        &self->calculatePIDBLack_1);
  pidRightTurn = Line_follower__calculatePIDBLack_out_st.pid;
  rightWheelspeed_right_turn = (Line_follower__base_speed_black-pidRightTurn);
  leftWheelspeed_right_turn = (Line_follower__base_speed_black+pidRightTurn);
  v_64 = (853-sen4);
  v = (802-sen3);
  Line_follower__calculatePIDBLack_step(v, v_64,
                                        &Line_follower__calculatePIDBLack_out_st,
                                        &self->calculatePIDBLack);
  pidLeftTurn = Line_follower__calculatePIDBLack_out_st.pid;
  rightWheelspeed_left_turn = (Line_follower__base_speed_black+pidLeftTurn);
  leftWheelspeed_left_turn = (Line_follower__base_speed_black-pidLeftTurn);
  sen[0] = sen0;
  sen[1] = sen1;
  sen[2] = sen2;
  sen[3] = sen3;
  sen[4] = sen4;
  Line_follower__blackrightdetermineDirection_step(sen,
                                                   &Line_follower__blackrightdetermineDirection_out_st);
  dirr = Line_follower__blackrightdetermineDirection_out_st.direction;
  v_75 = (dirr==3);
  if (v_75) {
    v_77 = rightWheelspeed_left_turn;
    v_76 = leftWheelspeed_left_turn;
  } else {
    v_77 = 65;
    v_76 = 65;
  };
  v_74 = (dirr==2);
  if (v_74) {
    v_79 = rightWheelspeed_right_turn;
    v_78 = leftWheelspeed_right_turn;
  } else {
    v_79 = v_77;
    v_78 = v_76;
  };
  v_73 = (dirr==0);
  if (v_73) {
    v_r = 0;
    v_l = 0;
  } else {
    v_r = v_79;
    v_l = v_78;
  };
  v_71 = (v_r<Line_follower__min_speed);
  if (v_71) {
    v_72 = 0;
  } else {
    v_72 = v_r;
  };
  v_70 = (v_r>Line_follower__max_speed_black);
  if (v_70) {
    _out->v_rr = 170;
  } else {
    _out->v_rr = v_72;
  };
  v_68 = (v_l<Line_follower__min_speed);
  if (v_68) {
    v_69 = 0;
  } else {
    v_69 = v_l;
  };
  v_67 = (v_l>Line_follower__max_speed_black);
  if (v_67) {
    _out->v_ll = 170;
  } else {
    _out->v_ll = v_69;
  };;
}

void Line_follower__whitemain_reset(Line_follower__whitemain_mem* self) {
  Line_follower__calculatePID_reset(&self->calculatePID_1);
  Line_follower__calculatePID_reset(&self->calculatePID);
}

void Line_follower__whitemain_step(long sen0, long sen1, long sen2, long sen3,
                                   long sen4, long cond,
                                   Line_follower__whitemain_out* _out,
                                   Line_follower__whitemain_mem* self) {
  Line_follower__determineDirection_out Line_follower__determineDirection_out_st;
  Line_follower__calculatePID_out Line_follower__calculatePID_out_st;
  
  long v_99;
  long v_98;
  long v_97;
  long v_96;
  long v_95;
  long v_94;
  long v_93;
  long v_92;
  long v_91;
  long v_90;
  long v_89;
  long v_88;
  long v_87;
  long v_86;
  long v_85;
  long v_84;
  long v_83;
  long v_82;
  long v_81;
  long v_80;
  long v;
  long sen[5];
  long pidLeftTurn;
  long pidRightTurn;
  long leftWheelspeed_left_turn;
  long rightWheelspeed_left_turn;
  long leftWheelspeed_right_turn;
  long rightWheelspeed_right_turn;
  long v_l;
  long v_r;
  v_86 = (sen1-343);
  v_83 = (sen0-302);
  v_84 = (v_83*5);
  v_85 = (v_84/2);
  Line_follower__calculatePID_step(v_85, v_86,
                                   &Line_follower__calculatePID_out_st,
                                   &self->calculatePID_1);
  pidRightTurn = Line_follower__calculatePID_out_st.pid;
  rightWheelspeed_right_turn = (Line_follower__base_speed-pidRightTurn);
  leftWheelspeed_right_turn = (Line_follower__base_speed+pidRightTurn);
  v_80 = (sen4-321);
  v_81 = (v_80*5);
  v_82 = (v_81/2);
  v = (sen3-295);
  Line_follower__calculatePID_step(v, v_82,
                                   &Line_follower__calculatePID_out_st,
                                   &self->calculatePID);
  pidLeftTurn = Line_follower__calculatePID_out_st.pid;
  rightWheelspeed_left_turn = (Line_follower__base_speed+pidLeftTurn);
  leftWheelspeed_left_turn = (Line_follower__base_speed-pidLeftTurn);
  sen[0] = sen0;
  sen[1] = sen1;
  sen[2] = sen2;
  sen[3] = sen3;
  sen[4] = sen4;
  Line_follower__determineDirection_step(sen,
                                         &Line_follower__determineDirection_out_st);
  _out->dir = Line_follower__determineDirection_out_st.direction;
  v_95 = (_out->dir==3);
  if (v_95) {
    v_97 = rightWheelspeed_left_turn;
    v_96 = leftWheelspeed_left_turn;
  } else {
    v_97 = 43;
    v_96 = 43;
  };
  v_94 = (_out->dir==2);
  if (v_94) {
    v_99 = rightWheelspeed_right_turn;
    v_98 = leftWheelspeed_right_turn;
  } else {
    v_99 = v_97;
    v_98 = v_96;
  };
  v_93 = (_out->dir==0);
  if (v_93) {
    v_r = 0;
    v_l = 0;
  } else {
    v_r = v_99;
    v_l = v_98;
  };
  v_91 = (v_r<Line_follower__min_speed);
  if (v_91) {
    v_92 = 0;
  } else {
    v_92 = v_r;
  };
  v_90 = (v_r>Line_follower__max_speed);
  if (v_90) {
    _out->v_rr = v_r;
  } else {
    _out->v_rr = v_92;
  };
  v_88 = (v_l<Line_follower__min_speed);
  if (v_88) {
    v_89 = 0;
  } else {
    v_89 = v_l;
  };
  v_87 = (v_l>Line_follower__max_speed);
  if (v_87) {
    _out->v_ll = v_l;
  } else {
    _out->v_ll = v_89;
  };;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__whitemain_reset(&self->whitemain);
  Line_follower__blackMain_reset(&self->blackMain_2);
  Line_follower__blackMain_reset(&self->blackMain_1);
  Line_follower__blackMain_reset(&self->blackMain);
  self->pnr_1 = false;
  self->ck = Line_follower__St_1_WhiteLine;
  self->v_289 = true;
  self->v_284 = true;
  self->v_269 = false;
  self->v_259 = Line_follower__St_OutsideNode;
  self->v_264 = true;
  self->v_260 = true;
}

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__blackMain_out Line_follower__blackMain_out_st;
  Line_follower__whitemain_out Line_follower__whitemain_out_st;
  
  long v_112;
  long v_111;
  long v_110;
  long v_109;
  long v_108;
  long v_107;
  long v_106;
  long v_105;
  long v_104;
  long v_103;
  long v_102;
  long v_101;
  long v_100;
  long v;
  long r_1_St_1_BlackLine;
  Line_follower__st_1 s_2_St_1_BlackLine;
  long r_1_St_1_WhiteLine;
  Line_follower__st_1 s_2_St_1_WhiteLine;
  long v_178;
  long v_177;
  long v_176;
  long v_175;
  long v_174;
  long v_173;
  long v_172;
  long v_171;
  long v_170;
  long v_169;
  long v_168;
  long v_167;
  long v_166;
  long v_165;
  long v_164;
  long v_163;
  long v_162;
  long v_161;
  long v_160;
  long v_159;
  long v_158;
  long v_157;
  long v_156;
  long v_155;
  long v_154;
  long v_153;
  long v_152;
  long v_151;
  long v_150;
  long v_149;
  long v_148;
  long v_147;
  long v_146;
  long v_145;
  long v_144;
  long v_143;
  long v_142;
  long v_141;
  long v_140;
  long v_139;
  long v_138;
  long v_137;
  long v_136;
  long v_135;
  long v_134;
  long v_133;
  long v_132;
  long v_131;
  long v_130;
  long v_129;
  long v_128;
  long v_127;
  long v_126;
  long v_125;
  long v_124;
  long v_123;
  long v_122;
  long v_121;
  long v_120;
  long v_119;
  long v_118;
  long v_117;
  long v_116;
  long v_115;
  long v_114;
  long v_113;
  long v_258;
  long v_257;
  long v_256;
  long v_255;
  long v_254;
  long v_253;
  long v_252;
  long v_251;
  long v_250;
  long v_249;
  long v_248;
  long v_247;
  long v_246;
  long v_245;
  long v_244;
  long v_243;
  long v_242;
  long v_241;
  long v_240;
  long v_239;
  long v_238;
  long v_237;
  long v_236;
  long v_235;
  long v_234;
  long v_233;
  long v_232;
  long v_231;
  long v_230;
  long v_229;
  long v_228;
  long v_227;
  long v_226;
  long v_225;
  long v_224;
  long v_223;
  long v_222;
  long v_221;
  long v_220;
  long v_219;
  long v_218;
  long v_217;
  long v_216;
  long v_215;
  long v_214;
  long v_213;
  long v_212;
  long v_211;
  long v_210;
  long v_209;
  long v_208;
  long v_207;
  long v_206;
  long v_205;
  long v_204;
  long v_203;
  long v_202;
  long v_201;
  long v_200;
  long v_199;
  long v_198;
  long v_197;
  long v_196;
  long v_195;
  long v_194;
  long v_193;
  long v_192;
  long v_191;
  long v_190;
  long v_189;
  long v_188;
  long v_187;
  long v_186;
  long v_185;
  long v_184;
  long v_183;
  long v_182;
  long v_181;
  long v_180;
  long v_179;
  long r_St_InsideNode;
  Line_follower__st s_1_St_InsideNode;
  long r_St_EnteredNode;
  Line_follower__st s_1_St_EnteredNode;
  long r_St_OutsideNode;
  Line_follower__st s_1_St_OutsideNode;
  Line_follower__st ck_2;
  long v_262;
  long v_261;
  long r_2;
  long v_268;
  long v_266;
  long v_265;
  long r_3;
  long r_4;
  long nr_St_InsideNode;
  Line_follower__st ns_St_InsideNode;
  long insideNodeFlag_St_1_BlackLine_St_InsideNode;
  long nodeCount_St_1_BlackLine_St_InsideNode;
  long v_r_St_1_BlackLine_St_InsideNode;
  long v_l_St_1_BlackLine_St_InsideNode;
  long nr_St_EnteredNode;
  Line_follower__st ns_St_EnteredNode;
  long insideNodeFlag_St_1_BlackLine_St_EnteredNode;
  long nodeCount_St_1_BlackLine_St_EnteredNode;
  long v_r_St_1_BlackLine_St_EnteredNode;
  long v_l_St_1_BlackLine_St_EnteredNode;
  long nr_St_OutsideNode;
  Line_follower__st ns_St_OutsideNode;
  long insideNodeFlag_St_1_BlackLine_St_OutsideNode;
  long nodeCount_St_1_BlackLine_St_OutsideNode;
  long v_r_St_1_BlackLine_St_OutsideNode;
  long v_l_St_1_BlackLine_St_OutsideNode;
  Line_follower__st ck_3;
  Line_follower__st s_1;
  Line_follower__st ns;
  long r;
  long nr;
  long pnr;
  long v_292;
  long v_290;
  long v_288;
  long v_287;
  long v_285;
  long v_283;
  long v_282;
  long v_281;
  long v_280;
  long v_279;
  long v_278;
  long v_277;
  long v_276;
  long v_275;
  long v_274;
  long v_273;
  long v_272;
  long v_271;
  long v_270;
  long r_5;
  long nr_1_St_1_BlackLine;
  Line_follower__st_1 ns_1_St_1_BlackLine;
  long insideNodeFlag_St_1_BlackLine;
  long parkingFlag_St_1_BlackLine;
  long nodeCount_St_1_BlackLine;
  long whitecond_St_1_BlackLine;
  long dir_St_1_BlackLine;
  long v_r_St_1_BlackLine;
  long v_l_St_1_BlackLine;
  long nr_1_St_1_WhiteLine;
  Line_follower__st_1 ns_1_St_1_WhiteLine;
  long insideNodeFlag_St_1_WhiteLine;
  long parkingFlag_St_1_WhiteLine;
  long nodeCount_St_1_WhiteLine;
  long whitecond_St_1_WhiteLine;
  long dir_St_1_WhiteLine;
  long v_r_St_1_WhiteLine;
  long v_l_St_1_WhiteLine;
  Line_follower__st_1 ck_1;
  Line_follower__st_1 s_2;
  Line_follower__st_1 ns_1;
  long r_1;
  long nr_1;
  long s[5];
  long whitecond;
  long nodeCount;
  long parkingFlag;
  long insideNodeFlag;
  switch (self->ck) {
    case Line_follower__St_1_BlackLine:
      if (false) {
        r_1_St_1_BlackLine = false;
      } else {
        r_1_St_1_BlackLine = self->pnr_1;
      };
      if (false) {
        s_2_St_1_BlackLine = Line_follower__St_1_WhiteLine;
      } else {
        s_2_St_1_BlackLine = Line_follower__St_1_BlackLine;
      };
      break;
    default:
      break;
  };
  s[0] = sen0;
  s[1] = sen1;
  s[2] = sen2;
  s[3] = sen3;
  s[4] = sen4;
  switch (self->ck) {
    case Line_follower__St_1_WhiteLine:
      v_110 = s[4];
      v_111 = (v_110>650);
      v_107 = s[3];
      v_108 = (v_107>650);
      v_104 = s[2];
      v_105 = (v_104>650);
      v_101 = s[1];
      v_102 = (v_101>650);
      v = s[0];
      v_100 = (v>550);
      v_103 = (v_100&&v_102);
      v_106 = (v_103&&v_105);
      v_109 = (v_106&&v_108);
      v_112 = (v_109&&v_111);
      if (v_112) {
        r_1_St_1_WhiteLine = false;
        s_2_St_1_WhiteLine = Line_follower__St_1_BlackLine;
      } else {
        r_1_St_1_WhiteLine = self->pnr_1;
        s_2_St_1_WhiteLine = Line_follower__St_1_WhiteLine;
      };
      s_2 = s_2_St_1_WhiteLine;
      r_1 = r_1_St_1_WhiteLine;
      break;
    case Line_follower__St_1_BlackLine:
      s_2 = s_2_St_1_BlackLine;
      r_1 = r_1_St_1_BlackLine;
      break;
    default:
      break;
  };
  ck_1 = s_2;
  switch (ck_1) {
    case Line_follower__St_1_WhiteLine:
      insideNodeFlag_St_1_WhiteLine = 0;
      nodeCount_St_1_WhiteLine = 0;
      parkingFlag_St_1_WhiteLine = 0;
      if (self->v_289) {
        v_290 = true;
      } else {
        v_290 = r_1;
      };
      if (v_290) {
        v_292 = 0;
      } else {
        v_292 = self->v_291;
      };
      v_287 = (self->v_286+1);
      if (self->v_284) {
        v_285 = true;
      } else {
        v_285 = r_1;
      };
      if (v_285) {
        v_288 = 0;
      } else {
        v_288 = v_287;
      };
      v_281 = s[4];
      v_282 = (v_281>300);
      v_278 = s[3];
      v_279 = (v_278>300);
      v_275 = s[2];
      v_276 = (v_275>300);
      v_272 = s[1];
      v_273 = (v_272>300);
      v_270 = s[0];
      v_271 = (v_270>300);
      v_274 = (v_271&&v_273);
      v_277 = (v_274&&v_276);
      v_280 = (v_277&&v_279);
      v_283 = (v_280&&v_282);
      if (v_283) {
        whitecond_St_1_WhiteLine = v_288;
      } else {
        whitecond_St_1_WhiteLine = v_292;
      };
      nr_1_St_1_WhiteLine = false;
      ns_1_St_1_WhiteLine = Line_follower__St_1_WhiteLine;
      r_5 = r_1;
      whitecond = whitecond_St_1_WhiteLine;
      if (r_5) {
        Line_follower__whitemain_reset(&self->whitemain);
      };
      Line_follower__whitemain_step(sen0, sen1, sen2, sen3, sen4, whitecond,
                                    &Line_follower__whitemain_out_st,
                                    &self->whitemain);
      v_l_St_1_WhiteLine = Line_follower__whitemain_out_st.v_ll;
      v_r_St_1_WhiteLine = Line_follower__whitemain_out_st.v_rr;
      dir_St_1_WhiteLine = Line_follower__whitemain_out_st.dir;
      _out->dir = dir_St_1_WhiteLine;
      parkingFlag = parkingFlag_St_1_WhiteLine;
      ns_1 = ns_1_St_1_WhiteLine;
      nr_1 = nr_1_St_1_WhiteLine;
      nodeCount = nodeCount_St_1_WhiteLine;
      insideNodeFlag = insideNodeFlag_St_1_WhiteLine;
      _out->v_l = v_l_St_1_WhiteLine;
      _out->v_r = v_r_St_1_WhiteLine;
      break;
    case Line_follower__St_1_BlackLine:
      parkingFlag_St_1_BlackLine = self->parkingFlag_1;
      whitecond_St_1_BlackLine = self->whitecond_1;
      if (r_1) {
        pnr = false;
        ck_2 = Line_follower__St_OutsideNode;
      } else {
        pnr = self->v_269;
        ck_2 = self->v_259;
      };
      dir_St_1_BlackLine = 7;
      nr_1_St_1_BlackLine = false;
      ns_1_St_1_BlackLine = Line_follower__St_1_BlackLine;
      whitecond = whitecond_St_1_BlackLine;
      _out->dir = dir_St_1_BlackLine;
      parkingFlag = parkingFlag_St_1_BlackLine;
      ns_1 = ns_1_St_1_BlackLine;
      nr_1 = nr_1_St_1_BlackLine;
      switch (ck_2) {
        case Line_follower__St_OutsideNode:
          v_255 = s[4];
          v_256 = (v_255>100);
          v_252 = s[3];
          v_253 = (v_252>100);
          v_249 = s[2];
          v_250 = (v_249>100);
          v_246 = s[1];
          v_247 = (v_246>100);
          v_244 = s[0];
          v_245 = (v_244>100);
          v_248 = (v_245&&v_247);
          v_251 = (v_248&&v_250);
          v_254 = (v_251&&v_253);
          v_257 = (v_254&&v_256);
          v_240 = s[4];
          v_241 = (v_240<Line_follower__thresholdNode);
          v_237 = s[3];
          v_238 = (v_237<Line_follower__thresholdNode);
          v_234 = s[2];
          v_235 = (v_234<Line_follower__thresholdNode);
          v_232 = s[1];
          v_233 = (v_232<Line_follower__thresholdNode);
          v_236 = (v_233&&v_235);
          v_239 = (v_236&&v_238);
          v_242 = (v_239&&v_241);
          v_228 = s[4];
          v_229 = (v_228<Line_follower__thresholdNode);
          v_225 = s[3];
          v_226 = (v_225<Line_follower__thresholdNode);
          v_223 = s[2];
          v_224 = (v_223<Line_follower__thresholdNode);
          v_227 = (v_224&&v_226);
          v_230 = (v_227&&v_229);
          v_219 = s[3];
          v_220 = (v_219<Line_follower__thresholdNode);
          v_216 = s[2];
          v_217 = (v_216<Line_follower__thresholdNode);
          v_214 = s[1];
          v_215 = (v_214<Line_follower__thresholdNode);
          v_218 = (v_215&&v_217);
          v_221 = (v_218&&v_220);
          v_210 = s[2];
          v_211 = (v_210<Line_follower__thresholdNode);
          v_207 = s[1];
          v_208 = (v_207<Line_follower__thresholdNode);
          v_205 = s[0];
          v_206 = (v_205<Line_follower__thresholdNode);
          v_209 = (v_206&&v_208);
          v_212 = (v_209&&v_211);
          v_201 = s[3];
          v_202 = (v_201<Line_follower__thresholdNode);
          v_198 = s[2];
          v_199 = (v_198<Line_follower__thresholdNode);
          v_195 = s[1];
          v_196 = (v_195<Line_follower__thresholdNode);
          v_193 = s[0];
          v_194 = (v_193<Line_follower__thresholdNode);
          v_197 = (v_194&&v_196);
          v_200 = (v_197&&v_199);
          v_203 = (v_200&&v_202);
          v_190 = s[4];
          v_191 = (v_190<Line_follower__thresholdNode);
          v_187 = s[3];
          v_188 = (v_187<Line_follower__thresholdNode);
          v_184 = s[2];
          v_185 = (v_184<Line_follower__thresholdNode);
          v_181 = s[1];
          v_182 = (v_181<Line_follower__thresholdNode);
          v_179 = s[0];
          v_180 = (v_179<Line_follower__thresholdNode);
          v_183 = (v_180&&v_182);
          v_186 = (v_183&&v_185);
          v_189 = (v_186&&v_188);
          v_192 = (v_189&&v_191);
          v_204 = (v_192||v_203);
          v_213 = (v_204||v_212);
          v_222 = (v_213||v_221);
          v_231 = (v_222||v_230);
          v_243 = (v_231||v_242);
          v_258 = (v_243&&v_257);
          if (v_258) {
            r_St_OutsideNode = false;
            s_1_St_OutsideNode = Line_follower__St_EnteredNode;
          } else {
            r_St_OutsideNode = pnr;
            s_1_St_OutsideNode = Line_follower__St_OutsideNode;
          };
          s_1 = s_1_St_OutsideNode;
          r = r_St_OutsideNode;
          break;
        case Line_follower__St_EnteredNode:
          r_St_EnteredNode = pnr;
          s_1_St_EnteredNode = Line_follower__St_EnteredNode;
          s_1 = s_1_St_EnteredNode;
          r = r_St_EnteredNode;
          break;
        case Line_follower__St_InsideNode:
          v_174 = s[4];
          v_175 = (v_174<Line_follower__thresholdNode1);
          v_171 = s[3];
          v_172 = (v_171<Line_follower__thresholdNode1);
          v_168 = s[2];
          v_169 = (v_168<Line_follower__thresholdNode1);
          v_166 = s[1];
          v_167 = (v_166<Line_follower__thresholdNode1);
          v_170 = (v_167&&v_169);
          v_173 = (v_170&&v_172);
          v_176 = (v_173&&v_175);
          v_162 = s[4];
          v_163 = (v_162<Line_follower__thresholdNode1);
          v_159 = s[3];
          v_160 = (v_159<Line_follower__thresholdNode1);
          v_157 = s[2];
          v_158 = (v_157<Line_follower__thresholdNode1);
          v_161 = (v_158&&v_160);
          v_164 = (v_161&&v_163);
          v_153 = s[3];
          v_154 = (v_153<Line_follower__thresholdNode1);
          v_150 = s[2];
          v_151 = (v_150<Line_follower__thresholdNode1);
          v_148 = s[1];
          v_149 = (v_148<Line_follower__thresholdNode1);
          v_152 = (v_149&&v_151);
          v_155 = (v_152&&v_154);
          v_144 = s[2];
          v_145 = (v_144<Line_follower__thresholdNode1);
          v_141 = s[1];
          v_142 = (v_141<Line_follower__thresholdNode1);
          v_139 = s[0];
          v_140 = (v_139<Line_follower__thresholdNode1);
          v_143 = (v_140&&v_142);
          v_146 = (v_143&&v_145);
          v_135 = s[3];
          v_136 = (v_135<Line_follower__thresholdNode1);
          v_132 = s[2];
          v_133 = (v_132<Line_follower__thresholdNode1);
          v_129 = s[1];
          v_130 = (v_129<Line_follower__thresholdNode1);
          v_127 = s[0];
          v_128 = (v_127<Line_follower__thresholdNode1);
          v_131 = (v_128&&v_130);
          v_134 = (v_131&&v_133);
          v_137 = (v_134&&v_136);
          v_124 = s[4];
          v_125 = (v_124<Line_follower__thresholdNode1);
          v_121 = s[3];
          v_122 = (v_121<Line_follower__thresholdNode1);
          v_118 = s[2];
          v_119 = (v_118<Line_follower__thresholdNode1);
          v_115 = s[1];
          v_113 = s[0];
          v_116 = (v_115<Line_follower__thresholdNode1);
          v_114 = (v_113<Line_follower__thresholdNode1);
          v_117 = (v_114&&v_116);
          v_120 = (v_117&&v_119);
          v_123 = (v_120&&v_122);
          v_126 = (v_123&&v_125);
          v_138 = (v_126||v_137);
          v_147 = (v_138||v_146);
          v_156 = (v_147||v_155);
          v_165 = (v_156||v_164);
          v_177 = (v_165||v_176);
          v_178 = !(v_177);
          if (v_178) {
            r_St_InsideNode = false;
            s_1_St_InsideNode = Line_follower__St_OutsideNode;
          } else {
            r_St_InsideNode = pnr;
            s_1_St_InsideNode = Line_follower__St_InsideNode;
          };
          s_1 = s_1_St_InsideNode;
          r = r_St_InsideNode;
          break;
        default:
          break;
      };
      ck_3 = s_1;
      switch (ck_3) {
        case Line_follower__St_OutsideNode:
          nodeCount_St_1_BlackLine_St_OutsideNode = self->nodeCount_4;
          insideNodeFlag_St_1_BlackLine_St_OutsideNode = 0;
          nr_St_OutsideNode = false;
          ns_St_OutsideNode = Line_follower__St_OutsideNode;
          r_4 = (r_1||r);
          nodeCount_St_1_BlackLine = nodeCount_St_1_BlackLine_St_OutsideNode;
          insideNodeFlag_St_1_BlackLine = insideNodeFlag_St_1_BlackLine_St_OutsideNode;
          ns = ns_St_OutsideNode;
          nr = nr_St_OutsideNode;
          break;
        case Line_follower__St_EnteredNode:
          insideNodeFlag_St_1_BlackLine_St_EnteredNode = 0;
          v_268 = (self->v_267+1);
          v_265 = (r_1||r);
          if (self->v_264) {
            v_266 = true;
          } else {
            v_266 = v_265;
          };
          if (v_266) {
            nodeCount_St_1_BlackLine_St_EnteredNode = 0;
          } else {
            nodeCount_St_1_BlackLine_St_EnteredNode = v_268;
          };
          if (true) {
            nr_St_EnteredNode = false;
          } else {
            nr_St_EnteredNode = false;
          };
          if (true) {
            ns_St_EnteredNode = Line_follower__St_InsideNode;
          } else {
            ns_St_EnteredNode = Line_follower__St_EnteredNode;
          };
          r_3 = (r_1||r);
          nodeCount_St_1_BlackLine = nodeCount_St_1_BlackLine_St_EnteredNode;
          insideNodeFlag_St_1_BlackLine = insideNodeFlag_St_1_BlackLine_St_EnteredNode;
          ns = ns_St_EnteredNode;
          nr = nr_St_EnteredNode;
          break;
        case Line_follower__St_InsideNode:
          insideNodeFlag_St_1_BlackLine_St_InsideNode = 1;
          v_261 = (r_1||r);
          if (self->v_260) {
            v_262 = true;
          } else {
            v_262 = v_261;
          };
          if (v_262) {
            nodeCount_St_1_BlackLine_St_InsideNode = 0;
          } else {
            nodeCount_St_1_BlackLine_St_InsideNode = self->v_263;
          };
          nr_St_InsideNode = false;
          ns_St_InsideNode = Line_follower__St_InsideNode;
          r_2 = (r_1||r);
          nodeCount_St_1_BlackLine = nodeCount_St_1_BlackLine_St_InsideNode;
          insideNodeFlag_St_1_BlackLine = insideNodeFlag_St_1_BlackLine_St_InsideNode;
          ns = ns_St_InsideNode;
          nr = nr_St_InsideNode;
          break;
        default:
          break;
      };
      nodeCount = nodeCount_St_1_BlackLine;
      insideNodeFlag = insideNodeFlag_St_1_BlackLine;
      switch (ck_3) {
        case Line_follower__St_OutsideNode:
          if (r_4) {
            Line_follower__blackMain_reset(&self->blackMain_2);
          };
          Line_follower__blackMain_step(sen0, sen1, sen2, sen3, sen4,
                                        nodeCount,
                                        &Line_follower__blackMain_out_st,
                                        &self->blackMain_2);
          v_l_St_1_BlackLine_St_OutsideNode = Line_follower__blackMain_out_st.v_ll;
          v_r_St_1_BlackLine_St_OutsideNode = Line_follower__blackMain_out_st.v_rr;
          v_l_St_1_BlackLine = v_l_St_1_BlackLine_St_OutsideNode;
          v_r_St_1_BlackLine = v_r_St_1_BlackLine_St_OutsideNode;
          break;
        case Line_follower__St_EnteredNode:
          if (r_3) {
            Line_follower__blackMain_reset(&self->blackMain_1);
          };
          Line_follower__blackMain_step(sen0, sen1, sen2, sen3, sen4,
                                        nodeCount,
                                        &Line_follower__blackMain_out_st,
                                        &self->blackMain_1);
          v_l_St_1_BlackLine_St_EnteredNode = Line_follower__blackMain_out_st.v_ll;
          v_r_St_1_BlackLine_St_EnteredNode = Line_follower__blackMain_out_st.v_rr;
          v_l_St_1_BlackLine = v_l_St_1_BlackLine_St_EnteredNode;
          v_r_St_1_BlackLine = v_r_St_1_BlackLine_St_EnteredNode;
          break;
        case Line_follower__St_InsideNode:
          if (r_2) {
            Line_follower__blackMain_reset(&self->blackMain);
          };
          Line_follower__blackMain_step(sen0, sen1, sen2, sen3, sen4,
                                        nodeCount,
                                        &Line_follower__blackMain_out_st,
                                        &self->blackMain);
          v_l_St_1_BlackLine_St_InsideNode = Line_follower__blackMain_out_st.v_ll;
          v_r_St_1_BlackLine_St_InsideNode = Line_follower__blackMain_out_st.v_rr;
          v_l_St_1_BlackLine = v_l_St_1_BlackLine_St_InsideNode;
          v_r_St_1_BlackLine = v_r_St_1_BlackLine_St_InsideNode;
          break;
        default:
          break;
      };
      _out->v_l = v_l_St_1_BlackLine;
      _out->v_r = v_r_St_1_BlackLine;
      break;
    default:
      break;
  };
  _out->inf = insideNodeFlag;
  _out->nc = nodeCount;
  self->insideNodeFlag_1 = insideNodeFlag;
  self->parkingFlag_1 = parkingFlag;
  self->nodeCount_4 = nodeCount;
  self->whitecond_1 = whitecond;
  self->pnr_1 = nr_1;
  self->ck = ns_1;
  switch (ck_1) {
    case Line_follower__St_1_WhiteLine:
      self->v_291 = whitecond;
      self->v_289 = false;
      self->v_286 = whitecond;
      self->v_284 = false;
      break;
    case Line_follower__St_1_BlackLine:
      self->v_269 = nr;
      self->v_259 = ns;
      switch (ck_3) {
        case Line_follower__St_EnteredNode:
          self->v_267 = nodeCount;
          self->v_264 = false;
          break;
        case Line_follower__St_InsideNode:
          self->v_263 = nodeCount;
          self->v_260 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

