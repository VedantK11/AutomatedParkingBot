/* --- Generated the 14/4/2024 at 17:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. feb. 9 16:14:54 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__determineDirection_out {
  long direction;
} Line_follower__determineDirection_out;

void Line_follower__determineDirection_step(long s[5],
                                            Line_follower__determineDirection_out* _out);

typedef struct Line_follower__specialdetermineDirection_out {
  long direction;
} Line_follower__specialdetermineDirection_out;

void Line_follower__specialdetermineDirection_step(long s[5],
                                                   Line_follower__specialdetermineDirection_out* _out);

typedef struct Line_follower__blackleftdetermineDirection_out {
  long direction;
} Line_follower__blackleftdetermineDirection_out;

void Line_follower__blackleftdetermineDirection_step(long s[5],
                                                     Line_follower__blackleftdetermineDirection_out* _out);

typedef struct Line_follower__blackrightdetermineDirection_out {
  long direction;
} Line_follower__blackrightdetermineDirection_out;

void Line_follower__blackrightdetermineDirection_step(long s[5],
                                                      Line_follower__blackrightdetermineDirection_out* _out);

typedef struct Line_follower__calculatePID_mem {
  long v_44;
  long v_43;
  long v_41;
  long v;
} Line_follower__calculatePID_mem;

typedef struct Line_follower__calculatePID_out {
  long pid;
} Line_follower__calculatePID_out;

void Line_follower__calculatePID_reset(Line_follower__calculatePID_mem* self);

void Line_follower__calculatePID_step(long sensor1, long sensor2,
                                      Line_follower__calculatePID_out* _out,
                                      Line_follower__calculatePID_mem* self);

typedef struct Line_follower__calculatePIDBLack_mem {
  long v_55;
  long v_54;
  long v_52;
  long v;
} Line_follower__calculatePIDBLack_mem;

typedef struct Line_follower__calculatePIDBLack_out {
  long pid;
} Line_follower__calculatePIDBLack_out;

void Line_follower__calculatePIDBLack_reset(Line_follower__calculatePIDBLack_mem* self);

void Line_follower__calculatePIDBLack_step(long sensor1, long sensor2,
                                           Line_follower__calculatePIDBLack_out* _out,
                                           Line_follower__calculatePIDBLack_mem* self);

typedef struct Line_follower__max_out {
  long max;
} Line_follower__max_out;

void Line_follower__max_step(long a, long b, Line_follower__max_out* _out);

typedef struct Line_follower__min_out {
  long min;
} Line_follower__min_out;

void Line_follower__min_step(long a, long b, Line_follower__min_out* _out);

typedef struct Line_follower__blackMain_mem {
  Line_follower__calculatePIDBLack_mem calculatePIDBLack;
  Line_follower__calculatePIDBLack_mem calculatePIDBLack_1;
} Line_follower__blackMain_mem;

typedef struct Line_follower__blackMain_out {
  long v_ll;
  long v_rr;
} Line_follower__blackMain_out;

void Line_follower__blackMain_reset(Line_follower__blackMain_mem* self);

void Line_follower__blackMain_step(long sen0, long sen1, long sen2, long sen3,
                                   long sen4, long nodeCount,
                                   Line_follower__blackMain_out* _out,
                                   Line_follower__blackMain_mem* self);

typedef struct Line_follower__whitemain_mem {
  Line_follower__calculatePID_mem calculatePID;
  Line_follower__calculatePID_mem calculatePID_1;
} Line_follower__whitemain_mem;

typedef struct Line_follower__whitemain_out {
  long v_ll;
  long v_rr;
  long dir;
} Line_follower__whitemain_out;

void Line_follower__whitemain_reset(Line_follower__whitemain_mem* self);

void Line_follower__whitemain_step(long sen0, long sen1, long sen2, long sen3,
                                   long sen4, long cond,
                                   Line_follower__whitemain_out* _out,
                                   Line_follower__whitemain_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st_1 ck;
  Line_follower__st v_259;
  long v_263;
  long v_260;
  long v_267;
  long v_264;
  long v_269;
  long v_291;
  long v_289;
  long v_286;
  long v_284;
  long pnr_1;
  long insideNodeFlag_1;
  long parkingFlag_1;
  long nodeCount_4;
  long whitecond_1;
  Line_follower__blackMain_mem blackMain;
  Line_follower__blackMain_mem blackMain_1;
  Line_follower__blackMain_mem blackMain_2;
  Line_follower__whitemain_mem whitemain;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
  long nc;
  long inf;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
