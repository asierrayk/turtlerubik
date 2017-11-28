%module rubik

%{
#define SWIG_FILE_WITH_INIT
#include "src/rubik.h"
%}


%include "std_string.i"
%include "src/rubik.h"
