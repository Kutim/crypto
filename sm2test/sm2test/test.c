#include <stdio.h>
#include "sm2.h"
#include "sm3.h"

int main()
{
	unsigned char plain[10] = {01,23,45,67,89,98,76,54,32,10};
	unsigned long plainlen = 10;
	unsigned char prikey[32] = {66,59,51,79,109,21,26,85,31,126,0,74,56,78,42,92,120,27,17,115,14,124,122,68,63,104,51,3,47,60,107,53};
	//unsigned char pubkey[64] = {-61, 92, 48, -52, -74, -11, 108, 115, -98, -90, -76, -43, 111, -94, 122, 102, -25, 76, 62, 2, -79, 107, -128, 51, -55, -24, 92, 92, 64, -82, 41, -19, -87, 73, 73, -34, -36, 7, 6, -27, 111, 32, -126, -99, -55, 104, -13, 51, -14, 104, 112, 105, -2, -33, 72, -28, 12, -20, 68, 39, 2, -96, 23, 69};
	unsigned char pubkey[64] = { 0 };
	unsigned long keylen = 64;
	unsigned char encdata[107];
	unsigned long encdatalen = 107;
	unsigned int  ulPriLen = 32;
	unsigned char buf[32] = {0};
	int ret;
	int i = 0;
	printf("prikey:\n");
	for(; i < 32; i++)
	{
		printf("%02x", prikey[i]);
	}
	printf("\n\n");

	BYTE_Point_mul(prikey,pubkey);
	printf("pubkey:\n");
	for(i = 0; i < keylen; i++)
	{
		printf("%02x", pubkey[i]);
	}
	printf("\n\n");


	ret = GM_SM2Encrypt(encdata, &encdatalen, plain, plainlen, pubkey, keylen);
	printf("cipher:\n");
	for(i = 0; i < encdatalen; i++)
	{
		printf("%02x", encdata[i]);
	}
	printf("\n\n");
	printf("ret:%d\n", ret);

	sm3(pubkey,64,buf);
	printf("sm3:\n");
	for (i = 0; i < 32; i++)
	{
		printf("%02x", buf[i]);
	}
	printf("\n\n");
	getchar();
	return ret;
}
