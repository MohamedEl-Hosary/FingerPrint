/*
 * FINGER_PRINT_MODULE.h
 *
 *  Created on: 21 Jan 2019
 *      Author: HooS
 */

#ifndef FINGER_PRINT_MODULE_H_
#define FINGER_PRINT_MODULE_H_

#include <stdio.h>
#include "STD_Types_H.h"
#include "UART.h"
#include <avr/delay.h>




#define True 0x01;
#define False 0x00;

//Instructions Codes

//to collect finger image
#define FINGER_Print_CollectImg 0x01
//To generate character file from image
#define FINGER_Print_GenCharFile 0x02
//To Generate Template
#define FINGER_Print_GenTemplate 0x05
//To Store Template
#define FINGER_Print_StoreTemplate 0x06
//To Delete Template
#define FINGER_Print_DelTemplate 0x0c
//To Formate The Flash Memory
#define FINGER_Print_FormatFlash 0x0d
//To Search Finger Print
#define FINGER_Print_SearchFinger 0x04

//Confirmation Codes

#define Command_Complete  0x00
#define Command_ErrorRecPack  0x01
#define Command_NoFingerOnSensor  0x02
#define Command_FailToDetectFinger  0x03
#define Command_FailToGenCharFileOver  0x06
#define Command_FailToGenCharFileLackness  0x07
#define Command_FingerNotMatch  0x08
#define Command_FailToFindMatchingFinger 0x09
#define Command_FailToCombCharFile  0x0A
#define Command_ErrorWhenRecTemplate  0x0C
#define Command_FailToDelTemplate  0x10
#define Command_ErrorWrittingFlash  0x18


//Packet Format

#define Header_1 0xEF
#define Header_2 0x01
#define ModuleAddress_1 0xFF
#define ModuleAddress_2 0xFF
#define ModuleAddress_3 0xFF
#define ModuleAddress_4 0xFF
#define PackageIndentifier 0x01
//packet length
// Get image packet length
#define PacketLengh_GetImage_1 0x00
#define PacketLengh_GetImage_2 0x03
//to create character file from image   Img2Tz
#define PacketLengh_Img2Tz_1 0x00
#define PacketLengh_Img2Tz_2 0x04
//to generate template  RegModel
#define PacketLengh_CreatTemplet_1 0x00
#define PacketLengh_CreatTemplet_2 0x04
//to store template  Store
#define PacketLengh_Store_1 0x00
#define PacketLengh_Store_2 0x06
//to delete template
#define PacketLengh_Delet_1 0x00
#define PacketLengh_Delet_2 0x07
//to empty fingerPrint Library
#define PacketLengh_EmptyAll_1 0x00
#define PacketLengh_EmptyAll_2 0x03
//To carry out precise matching of two finger templates: Match
#define PacketLengh_Match_1 0x00
#define PacketLengh_Match_2 0x03





//Finger_Print Functions Prototypes

//Function to send the frame of getting image
void FingerPrint_CollectImage(void);
//Function To Generate Character File From Image
void FingerPrint_GenChar(u8 BufferID);
//Function To Generate Template
void FingerPrint_GenTemplate(void);
//Function To Store Template
void FingerPrint_Store(u8 BufferID, u16 PageID);
//Function To Delete Template
void FingerPrint_DelTemplate(u16 PageID, u16 N);
//Function To Search
void FingerPrint_Search(u8 BufferID, u16 StartPage, u16 PageNum);
//Function To Format The Flash Memory
void FingerPrint_Format(void);



//Acknowledge Package Function which return Ack "Confirmation Code"
//Type if true Ack Packet for all frames except search, IF False ACK Packet For Serach
u8 FingerPrint_AckPacket_All(void);
u8 FingerPrint_AckPacket_Search(void);


#endif /* FINGER_PRINT_MODULE_H_ */
