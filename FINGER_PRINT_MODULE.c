#include "FINGER_PRINT_MODULE.h"
#include <stdio.h>

u8 PageID_High;
u8 PageID_Low;
u16 CheckSum;
u8 CheckSum_High;
u8 CheckSum_Low;
u8 ConfirmationAck;
u16 UserID;

void FingerPrint_CollectImage(void)
{
	CheckSum_High=0x00;
	CheckSum_Low=0x05;

	vUART_Transmit(Header_1);
	vUART_Transmit(Header_2);
	vUART_Transmit(ModuleAddress_1);
	vUART_Transmit(ModuleAddress_2);
	vUART_Transmit(ModuleAddress_3);
	vUART_Transmit(ModuleAddress_4);
	vUART_Transmit(PackageIndentifier);
	vUART_Transmit(PacketLengh_GetImage_1);
	vUART_Transmit(PacketLengh_GetImage_2);
	vUART_Transmit(FINGER_Print_CollectImg);
	vUART_Transmit(CheckSum_High);
	vUART_Transmit(CheckSum_Low);
	_delay_ms(500);
}

void FingerPrint_GenChar(u8 BufferID)
{
	CheckSum=PackageIndentifier+PacketLengh_Img2Tz_1+PacketLengh_Img2Tz_2+FINGER_Print_GenCharFile+BufferID;
	CheckSum_High= CheckSum >> 8;
	CheckSum_Low= (u8) CheckSum;

	vUART_Transmit(Header_1);
	vUART_Transmit(Header_2);
	vUART_Transmit(ModuleAddress_1);
	vUART_Transmit(ModuleAddress_2);
	vUART_Transmit(ModuleAddress_3);
	vUART_Transmit(ModuleAddress_4);
	vUART_Transmit(PackageIndentifier);
	vUART_Transmit(PacketLengh_Img2Tz_1);
	vUART_Transmit(PacketLengh_Img2Tz_2);
	vUART_Transmit(FINGER_Print_GenCharFile);
	vUART_Transmit(BufferID);
	vUART_Transmit(CheckSum_High);
	vUART_Transmit(CheckSum_Low);
	_delay_ms(300);
}

void FingerPrint_GenTemplate(void)
{
	CheckSum_High=0x00;
	CheckSum_Low=0x09;

	vUART_Transmit(Header_1);
	vUART_Transmit(Header_2);
	vUART_Transmit(ModuleAddress_1);
	vUART_Transmit(ModuleAddress_2);
	vUART_Transmit(ModuleAddress_3);
	vUART_Transmit(ModuleAddress_4);
	vUART_Transmit(PackageIndentifier);
	vUART_Transmit(PacketLengh_CreatTemplet_1);
	vUART_Transmit(PacketLengh_CreatTemplet_2);
	vUART_Transmit(FINGER_Print_GenTemplate);
	vUART_Transmit(CheckSum_High);
	vUART_Transmit(CheckSum_Low);
}


void FingerPrint_DelTemplate(u16 PageID, u16 N)
{
	//We Shifted Page ID To High and Low Bytes
	//We Shifted The High byte to variable High_PageID by 8 bits
	//We Casted The PageID to store it in The Low Byte (Low_PageID)
	PageID_High = PageID>>8;
	PageID_Low  = (u8) PageID;
	CheckSum=PackageIndentifier+PacketLengh_Delet_1+PacketLengh_Delet_2+FINGER_Print_DelTemplate+PageID_High+PageID_Low+0x00+0x01;
	CheckSum_High= CheckSum >> 8;
	CheckSum_Low= (u8) CheckSum;


	vUART_Transmit(Header_1);
	vUART_Transmit(Header_2);
	vUART_Transmit(ModuleAddress_1);
	vUART_Transmit(ModuleAddress_2);
	vUART_Transmit(ModuleAddress_3);
	vUART_Transmit(ModuleAddress_4);
	vUART_Transmit(PackageIndentifier);
	vUART_Transmit(PacketLengh_Delet_1);
	vUART_Transmit(PacketLengh_Delet_2);
	vUART_Transmit(FINGER_Print_DelTemplate);
	vUART_Transmit(PageID_High);
	vUART_Transmit(PageID_Low);
	vUART_Transmit(0x00);
	vUART_Transmit(0x01);
	vUART_Transmit(CheckSum_High);
	vUART_Transmit(CheckSum_Low);
	_delay_ms(300);
}
void FingerPrint_Store(u8 BufferID, u16 PageID)
{
	PageID_High =PageID>>8;
	PageID_Low = (u8)PageID;
	CheckSum=PackageIndentifier+PacketLengh_Store_1+PacketLengh_Store_2+FINGER_Print_StoreTemplate
	+BufferID+PageID_High+PageID_Low;
	CheckSum_High=CheckSum>>8;
	CheckSum_Low=(u8)CheckSum;


	vUART_Transmit(Header_1);
	vUART_Transmit(Header_2);
	vUART_Transmit(ModuleAddress_1);
	vUART_Transmit(ModuleAddress_2);
	vUART_Transmit(ModuleAddress_3);
	vUART_Transmit(ModuleAddress_4);
	vUART_Transmit(PackageIndentifier);
	vUART_Transmit(PacketLengh_Store_1);
	vUART_Transmit(PacketLengh_Store_2);
	vUART_Transmit(FINGER_Print_StoreTemplate);
	vUART_Transmit(BufferID);
	vUART_Transmit(PageID_High);
	vUART_Transmit(PageID_Low);
	vUART_Transmit(CheckSum_High);
	vUART_Transmit(CheckSum_Low);
}

void FingerPrint_Format(void)
{
	CheckSum_High=0x00;
	CheckSum_Low=0x11;

	vUART_Transmit(Header_1);
	vUART_Transmit(Header_2);
	vUART_Transmit(ModuleAddress_1);
	vUART_Transmit(ModuleAddress_2);
	vUART_Transmit(ModuleAddress_3);
	vUART_Transmit(ModuleAddress_4);
	vUART_Transmit(PackageIndentifier);
	vUART_Transmit(PacketLengh_EmptyAll_1);
	vUART_Transmit(PacketLengh_EmptyAll_2);
	vUART_Transmit(FINGER_Print_FormatFlash);
	vUART_Transmit(0x00);
	vUART_Transmit(0x11);
}


u8 FingerPrint_AckPacket_All(void)
{
	u8 i;
	for(i=0;i<=11;i++)
	{
		if(i==9)
		{
			ConfirmationAck=ucUART_recieve();
    	}
		ucUART_recieve();
	}
	return ConfirmationAck;
}
u8 FingerPrint_AckPacket_Search_Search(void)
{
	u8 i;
	for(i=0;i<=15;i++)
	{
		if(i==9)
		{
			ConfirmationAck=ucUART_recieve();
    	}
		else if(i==10)
		{
			PageID_High=ucUART_recieve();
		}
		else if (i==11)
		{
			PageID_Low =ucUART_recieve();
		}
		else
		{
			ucUART_recieve();
		}
	}
	UserID=PageID_High;
	UserID=(UserID << 8)|| PageID_Low;

	return ConfirmationAck;
}




