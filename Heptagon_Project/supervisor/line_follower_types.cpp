/* --- Generated the 14/4/2024 at 17:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. feb. 9 16:14:54 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st_1 Line_follower__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_WhiteLine")==0)) {
    return Line_follower__St_1_WhiteLine;
  };
  if ((strcmp(s, "St_1_BlackLine")==0)) {
    return Line_follower__St_1_BlackLine;
  };
}

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf) {
  switch (x) {
    case Line_follower__St_1_WhiteLine:
      strcpy(buf, "St_1_WhiteLine");
      break;
    case Line_follower__St_1_BlackLine:
      strcpy(buf, "St_1_BlackLine");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_OutsideNode")==0)) {
    return Line_follower__St_OutsideNode;
  };
  if ((strcmp(s, "St_InsideNode")==0)) {
    return Line_follower__St_InsideNode;
  };
  if ((strcmp(s, "St_EnteredNode")==0)) {
    return Line_follower__St_EnteredNode;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_OutsideNode:
      strcpy(buf, "St_OutsideNode");
      break;
    case Line_follower__St_InsideNode:
      strcpy(buf, "St_InsideNode");
      break;
    case Line_follower__St_EnteredNode:
      strcpy(buf, "St_EnteredNode");
      break;
    default:
      break;
  };
  return buf;
}

