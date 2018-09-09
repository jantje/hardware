#include "Arduino.h"
#include "gdb.h"
//The setup function is called once at startup of the sketch
void RAMFUNC setup()
{
#ifdef DEBUG
	uart_div_modify(0, UART_CLK_FREQ / 115200);
	Serial.begin(115200);
	gdbstub_init();
#endif
// Add your initialization code here
	pinMode(LED_BUILTIN, OUTPUT);
}

// The loop function is called in an endless loop
void RAMFUNC loop()
{
	digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);              // wait for a second
	digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);              // wait for a second
}
