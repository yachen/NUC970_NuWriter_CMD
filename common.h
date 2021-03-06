
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>  /* sleep/usleep*/
/* change if your libusb.h is located elswhere */
#include <libusb-1.0/libusb.h>
#include "Serial.h"


/* for upgrade */
#define USBD_FLASH_SDRAM		0x0
#define USBD_FLASH_NAND			0x3
#define USBD_FLASH_NAND_RAW		0x4
#define USBD_FLASH_MMC			0x5
#define USBD_FLASH_MMC_RAW		0x6
#define USBD_FLASH_SPI			0x7
#define USBD_FLASH_SPI_RAW		0x8
#define USBD_MTP			0x9
#define USBD_INFO			0xA
#define USBD_BURN_TYPE 			0x80


#define USB_VENDOR_ID		0x0416	/* USB vendor ID used by the device */
#define USB_PRODUCT_ID		0x5963	/* USB product ID used by the device */

#define USB_ENDPOINT_IN		(LIBUSB_ENDPOINT_IN  | 1)	/* endpoint address */
#define USB_ENDPOINT_OUT	(LIBUSB_ENDPOINT_OUT | 2)	/* endpoint address */
#define USB_TIMEOUT		(10000)	/* Connection timeout (in ms) */



#define DDRADDRESS	16
#define BUF_SIZE 	4096

#define SDRAM_M	0
#define NAND_M	1
#define EMMC_M	2
#define SPI_M	3


#define RUN_ON_XUSB 0x08FF0001

#if 0
#define MSG_DEBUG	printf
#else
#define MSG_DEBUG(...)
#endif


#define MAX_DEV 8

/* load_file.c */
extern char* load_ddr(char *FilePath,int *len);
extern char * load_xusb(char *FilePath,int *len);


/* NuclibUsb.c */
extern int NUC_OpenUsb(void);
extern void NUC_CloseUsb(void);
extern int NUC_SetType(int id,int type);
extern int NUC_ReadPipe(int id,unsigned char *buf,int len);
extern int NUC_WritePipe(int id,unsigned char *buf,int len);
extern int get_device_num_with_vid_pid(libusb_context *ctx,unsigned int vendor_id,unsigned int product_id);

/* device.c */
extern int XUSBtoDevice(unsigned char *buf,unsigned int len);
extern int DDRtoDevice(unsigned char *buf,unsigned int len);
int InfoFromDevice(void);

/* parse.c */
extern int ParseFlashType(void);
extern int init_xusb(void);

/* UXmodem.c */
extern int UXmodem_SDRAM(void);
extern int UXmodem_NAND(void);
extern int UXmodem_SPI(void);
extern int UXmodem_EMMC(void);

/* crc32.c */
unsigned int CalculateCRC32(unsigned char * buf,unsigned int len);

/* gloabel */
extern char DDR_fileName[128];
extern char write_file[256];
extern char read_file[256];
extern char Data_Path[256];
extern int mode;
extern int type;
extern unsigned int exe_addr;
extern unsigned int dram_run;
extern unsigned int erase_read_len;
extern int erase_tag;
extern int read_tag;
extern int write_tag;
extern int verify_tag;
extern int dtb_tag;
extern unsigned int dtb_addr;

extern struct _INFO_T m_info;

extern libusb_context *ctx;
extern libusb_device_handle *handle;

extern unsigned int csg_usb_index;
extern libusb_device *dev_arr[MAX_DEV];
extern unsigned int dev_count;

#endif
