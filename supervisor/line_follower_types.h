/* --- Generated the 14/4/2024 at 17:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. feb. 9 16:14:54 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
// #include "pervasives.h"
typedef enum {
  Line_follower__St_1_WhiteLine,
  Line_follower__St_1_BlackLine
} Line_follower__st_1;

Line_follower__st_1 Line_follower__st_1_of_string(char* s);

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf);

typedef enum {
  Line_follower__St_OutsideNode,
  Line_follower__St_InsideNode,
  Line_follower__St_EnteredNode
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const long Line_follower__kp = 1;

static const long Line_follower__ki = 0;

static const long Line_follower__kd = 1;

static const long Line_follower__base_speed = 43;

static const long Line_follower__max_speed = 200;

static const long Line_follower__base_speed_black = 65;

static const long Line_follower__max_speed_black = 170;

static const long Line_follower__min_speed = 0;

static const long Line_follower__junction = 250;

static const long Line_follower__blackcond = 3800;

static const long Line_follower__thresholdNode = 350;

static const long Line_follower__thresholdNode1 = 600;

#endif // LINE_FOLLOWER_TYPES_H
