#include "Arduino.h"
#include "HardwareSerial.h"

using namespace std;

HardwareSerial Serial("serial_in.txt","serial_out.txt");
HardwareSerial Serial1("serial1_in.txt","serial1_out.txt");
HardwareSerial Serial2("serial2_in.txt","serial2_out.txt");
HardwareSerial Serial3("serial3_in.txt","serial3_out.txt");
HardwareSerial::HardwareSerial(String inputfileName,String outputfileName)
{
	myInputfileName=inputfileName;
	myOutputfileName=outputfileName;
}


void HardwareSerial::begin(unsigned long, uint8_t)
{
	myOutfile.open(myOutputfileName.c_str(), ios::out | ios::trunc);
	myInfile.open(myInputfileName.c_str(),  ios::in );
	myOutfile<<"dit is de eerste lijn"<<endl;
}

void HardwareSerial::end()
{
	myOutfile.close();
	myInfile.close();
}

/* we read a char at the time to avoid reading all in one go.
 *
 */
int HardwareSerial::available(void)
{
	if(!myInfile.is_open())return 0;
	if (myInfile.eof()) return 0;
	return 1;
}

int HardwareSerial::peek(void)
{
	if(!myInfile.is_open())return 0;
	if (myInfile.eof()) return 0;
	return myInfile.peek();
}
int HardwareSerial::read(void)
{
	if(!myInfile.is_open())return 0;
	if (myInfile.eof()) return 0;
	char ret;
	myInfile.read(&ret,sizeof(ret));
	return ret;

}

int HardwareSerial::availableForWrite(void)
{
	return 1000;
}

void HardwareSerial::flush(void)
{
}

size_t HardwareSerial::write(uint8_t val)
{
	char mychar=val;
	myOutfile << mychar;
	myOutfile.flush();
	return 1;
}

size_t HardwareSerial::write(const uint8_t *buffer, size_t size)
{
	myOutfile.write((const char *)buffer,size);
	myOutfile.flush();
	return size;
}

