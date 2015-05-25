#ifndef __WDT_H__
#define __WDT_H__
      #define   WDTO_15MS 1
      #define   WDTO_30MS  1
      #define   WDTO_60MS   1
      #define   WDTO_120MS  1
      #define   WDTO_250MS  1
      #define   WDTO_500MS  1
      #define   WDTO_1S     1
      #define   WDTO_2S     1
      #define   WDTO_4S     1
      #define   WDTO_8S     1

void wdt_reset();
void wdt_enable(int );
void wdt_disable();

#endif
