#ifndef _RCSwitch_h
#define _RCSwitch_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#else
    #include <wiringPi.h>
    #include <stdint.h>
    #define NULL 0
    #define CHANGE 1
#ifdef __cplusplus
extern "C"{
#endif
typedef uint8_t boolean;
typedef uint8_t byte;

#if !defined(NULL)
#endif
#ifdef __cplusplus
}
#endif
#endif


// Number of maximum High/Low changes per packet.
// We can handle up to (unsigned long) => 32 bit * 2 H/L changes per bit + 2 for sync
#define RCSWITCH_MAX_CHANGES 67


class RCSwitch {

  public:
    RCSwitch();
    
    void switchOn(int nGroupNumber, int nSwitchNumber);
    void switchOff(int nGroupNumber, int nSwitchNumber);
    void switchOn(char* sGroup, int nSwitchNumber);
    void switchOff(char* sGroup, int nSwitchNumber);
    void switchOn(char sFamily, int nGroup, int nDevice);
    void switchOff(char sFamily, int nGroup, int nDevice);
    void switchOn(char* sGroup, char* sDevice);
    void switchOff(char* sGroup, char* sDevice);

    void sendTriState(char* Code);
    void send(unsigned long Code, unsigned int length);
    void send(char* Code);
    
    void enableReceive(int interrupt);
    void enableReceive();
    void disableReceive();
    bool available();
	void resetAvailable();
	
    unsigned long getReceivedValue();
    unsigned int getReceivedBitlength();
    unsigned int getReceivedDelay();
	unsigned int getReceivedProtocol();
    unsigned int* getReceivedRawdata();
  
    void enableTransmit(int nTransmitterPin);
    void disableTransmit();
    void setPulseLength(int nPulseLength);
    void setRepeatTransmit(int nRepeatTransmit);
    void setReceiveTolerance(int nPercent);
	void setProtocol(int nProtocol);
	void setProtocol(int nProtocol, int nPulseLength);
  
  private:
    char* getCodeWordB(int nGroupNumber, int nSwitchNumber, boolean bStatus);
    char* getCodeWordA(char* sGroup, int nSwitchNumber, boolean bStatus);
    char* getCodeWordA(char* sGroup, char* sDevice, boolean bStatus);
    char* getCodeWordC(char sFamily, int nGroup, int nDevice, boolean bStatus);
    void sendT0();
    void sendT1();
    void sendTF();
    void send0();
    void send1();
    void sendSync();
    void transmit(int nHighPulses, int nLowPulses);

    static char* dec2binWzerofill(unsigned long dec, unsigned int length);
    
    static void handleInterrupt();
	static bool receiveProtocol1(unsigned int changeCount);
	static bool receiveProtocol2(unsigned int changeCount);
    int nReceiverInterrupt;
    int nTransmitterPin;
    int nPulseLength;
    int nRepeatTransmit;
	char nProtocol;

	static int nReceiveTolerance;
    static unsigned long nReceivedValue;
    static unsigned int nReceivedBitlength;
	static unsigned int nReceivedDelay;
	static unsigned int nReceivedProtocol;
    static unsigned int timings[RCSWITCH_MAX_CHANGES];

    
};

#endif
