/************************************************/
/* Constants and functions for the WATCH module */
/************************************************/

#ifndef WATCH_LOADED
#include "watch.h"
#endif

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_10MN 10
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define PM_VALUE 12
#define DAYS_PER_WEEK 7
#define MONTHS_PER_YEAR 12

static short monthlength [] = {31,28,31,30,31,30,31,31,30,31,30,31};
static char *day_names [7] = {"SU","MO","TU","WE","TH","FR","SA"};


/***** The INITIAL_WATCH_TIME constant *****

The INITIAL_WATCH_TIME constant is declared here and
initialized in the main program, using the function GET_INITIAL_WATCH_TIME,
unless in SIMUL mode where it is initialized here.
*/


WATCH_TIME_TYPE INITIAL_WATCH_TIME;

WATCH_TIME_TYPE GET_INITIAL_WATCH_TIME () //Can change to use <Time.h> arduino librarie
{
   WATCH_TIME_TYPE wt;
   wt.day_in_week = 1;
   wt.month = 1;
   wt.day = 1;
   wt.hours = 0;
   wt.minutes = 0;
   wt.seconds = 0;
   wt.mode12h = 0;
   return(wt);
}


/***** The INCREMENT_WATCH_TIME function} *****/

WATCH_TIME_TYPE INCREMENT_WATCH_TIME (WATCH_TIME_TYPE wt)
{
   wt.seconds ++;
   if (wt.seconds == SECONDS_PER_MINUTE) {
      wt.seconds = 0;
      wt.minutes ++;
      if (wt.minutes == MINUTES_PER_HOUR) {
         wt.minutes = 0;
         wt.hours ++;
         if (wt.hours == HOURS_PER_DAY) {
            wt.hours = 0;
            wt.day ++;
            wt.day_in_week = (wt.day_in_week+1) % DAYS_PER_WEEK;
            if (wt.day > monthlength[wt.month]) {
               wt.day = 1;
               wt.month = (wt.month+1) % MONTHS_PER_YEAR;
            }
         }
      }
   }
   return wt;
}

char* WATCH_TIME_TYPE_to_text (WATCH_TIME_TYPE wt)
{
	static char res[22];
	sprintf (res, "%s %d-%d %d:%d:%d%s",
                 day_names[wt.day_in_week],
                 wt.month+1,
                 wt.day,
                 (wt.mode12h ? ((wt.hours % PM_VALUE ==0) ?
                                    PM_VALUE :
                                    wt.hours % PM_VALUE)
                             : wt.hours),
                 wt.minutes,
                 wt.seconds,
                (wt.mode12h
                         ? ((wt.hours>=PM_VALUE) ? " PM" : " AM") 
                         : " 24H"));
   return res;
}

