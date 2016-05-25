/**************************************************************/
/* C header for the WATCH module: types and defined constants */
/**************************************************************/

#define WATCH_LOADED

/***** The WATCH_TIME_TYPE type *****/

typedef struct {int day_in_week;
                int month;
                int day;
                int hours;
                int minutes;
                int seconds;
                int mode12h;} WATCH_TIME_TYPE;

/***** Copying is simply done by assignment *****/

#define _WATCH_TIME_TYPE(X,Y) (*(X)=(Y))

/***** The WATCH_TIME_POSITION type *****/

typedef int WATCH_TIME_POSITION;

/***** Copying is simply done by assignment *****/

#define _WATCH_TIME_POSITION(X,Y) (*(X)=(Y))

/***** The INITIAL_WATCH_TIME_POSITION constant *****/

#define INITIAL_WATCH_TIME_POSITION 0

/***** The WATCH_BEEP_VALUE constant *****
     This constant is defined only if the LOAD_BEEP flag is #defined
*/

#ifdef LOAD_BEEP

#ifndef BEEP_LOADED
#include "beep.h"
#endif

#define WATCH_BEEP_VALUE TWO_BEEPS

#endif


