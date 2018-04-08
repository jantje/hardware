#define ARDUINO_MAIN
#include "Arduino.h"
#include <unistd.h>



size_t strlcat(char * dst, const char * src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;
	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;
	if (n == 0) return (dlen + strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src)); /* count does not include NUL */
}
;

#define INT_DIGITS 19		/* enough for 64 bit integer */

char * itoa(int i, char * buffer, size_t size)
{
	/* Room for INT_DIGITS digits, - and '\0' */
	static char buf[INT_DIGITS + 2];
	char *p = buf + INT_DIGITS + 1; /* points to terminating '\0' */
	if (i >= 0)
	{
		do
		{
			*--p = '0' + (i % 10);
			i /= 10;
		} while (i != 0);
		strlcat(buffer, p, size);
		return buffer + strlen(p);
	} else
	{ /* i < 0 */
		do
		{
			*--p = '0' - (i % 10);
			i /= 10;
		} while (i != 0);
		*--p = '-';
	}
	strlcat(buffer, p, size);
	return buffer + strlen(p);
}

size_t strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	/* Copy as many bytes as will fit */
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*d++ = *s++) == '\0') break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0)
	{
		if (siz != 0) *d = '\0'; /* NUL-terminate dst */
		while (*s++)
			;
	}

	return (s - src - 1); /* count does not include NUL */
}

#ifndef LOCAL_RUN
//Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (*func)()) { return 0; }
#endif

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

#ifndef UNITTEST
int main(void)
{
	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif

	setup();

	for (;;) {
		loop();
//		if (serialEventRun) serialEventRun();
	}

	return 0;
}
#endif

void pinMode(uint8_t, uint8_t)
{
	//no code needed
}
void digitalWrite(uint8_t, uint8_t)
{
	//No code needed
}
void analogReference(uint8_t mode)
{
	//no code needed
}
void attachInterrupt(uint8_t, void (*)(void), int mode)
{
	//No code needed
}
void analogWrite(uint8_t, int)
{
	//No code needed
}

static unsigned long theMillis=0;
void delay(unsigned long milliseconds) {
#ifdef __MINGW_H
	sleep(milliseconds/1000);
#else
	usleep(milliseconds * 1000); // takes microseconds
#endif
	theMillis += milliseconds;
}
void delayMicroseconds(unsigned int us) {
#ifdef __MINGW_H
	sleep(us/1000);
#else
	usleep(us); // takes microseconds
#endif
	theMillis += us;
}
unsigned long millis(void)
{

	return ++theMillis;
}
int digitalRead(uint8_t pin)
{
	int ret=0;
	static std::fstream  myInfile[255];
	if (!myInfile[pin].is_open())
	{
		char Filename[255];
		sprintf(Filename,"digitalRead_%i.txt",(int)pin);
		myInfile[pin].open(Filename,  std::ios::in );
	}
	if (myInfile[pin].is_open())
	{
		char LineContent[30];
		myInfile[pin] >> LineContent;
		ret= atoi(LineContent);
	}
	if (myInfile[pin].eof())
	{
		myInfile[pin].close();
	}
	return ret;
}
unsigned long micros(void)
{
	static unsigned long theMicros=0;
	return ++theMicros;
}
int analogRead(uint8_t pin)
{
	int ret=0;
	static std::fstream  myInfile[255];
	if (!myInfile[pin].is_open())
	{
		char Filename[255];
		sprintf(Filename,"analogRead_%i.txt",(int)pin);
		myInfile[pin].open(Filename,  std::ios::in );
	}
	if (myInfile[pin].is_open())
	{
		char LineContent[30];
		myInfile[pin] >> LineContent;
		ret= atoi(LineContent);
	}
	if (myInfile[pin].eof())
	{
		myInfile[pin].close();
	}
	return ret;
}
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration ){

}
void noTone(uint8_t _pin){

}
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout){

}
