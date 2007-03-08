#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0xAF,0x2D,0x6D,0x09,0x3D,0xFE,0x41,0x34,0x51,0xFF,0xCB,0x76,
		0xF7,0x45,0x00,0x85,0x76,0xED,0xF8,0xD9,0x2C,0xD8,0x08,0x4C,
		0x0E,0xA9,0xA4,0x90,0x12,0x80,0x85,0x0D,0x18,0xF7,0xAF,0xB6,
		0xC6,0xDE,0xC4,0x65,0x51,0x9A,0x9F,0x17,0xA2,0x11,0x0D,0x0E,
		0x57,0xE0,0xC3,0x2C,0x15,0x87,0x7D,0x9B,0x1F,0x07,0x14,0x9D,
		0xE2,0x54,0x03,0x53,
		};
	static unsigned char dh512_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}
