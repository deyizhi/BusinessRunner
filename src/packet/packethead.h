#ifndef _PACKETHEAD_H_
#define _PACKETHEAD_H_
#include "commondef.h"
#pragma pack(push,1) 
struct PacketHead
{
	UInt16	uMark;
	UInt16	uLength;
	Byte	data[1];
};
#pragma pack(pop) 
#endif // _PACKETHEAD_H_
