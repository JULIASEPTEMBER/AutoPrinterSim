#include "stdafx.h"
#include "CSocketDecription.h"
#include <stdio.h>
#include <string.h>
extern "C" {
#include <openssl/md5.h>
}
//#pragma comment(lib, "libeay32.lib")
int CSocketDecription::SendEncription(char* result, char* key, char* buf)
{
	
	return 1;
}

void CSocketDecription::MD5ToString(unsigned char* md5result, char* output) {
    int i;
    for (i = 0; i < 16; i++) {
        sprintf(&output[i * 2], "%02x", md5result[i]);
    }
}

// ʵ������PHP md5�ĺ���
void CSocketDecription::md5_hash(char* input, char* output)
{
    unsigned char md5result[16]; // MD5�Ĺ�ϣֵ��16�ֽ�
   // MD5(0, 0, 0); // ʹ��OpenSSL��MD5����

    MD5((unsigned char*)input, strlen(input), md5result); // ʹ��OpenSSL��MD5����
    MD5ToString(md5result, output); // �����ת��Ϊ16�����ַ���
}

int CSocketDecription::main1()
{
    char input[] = "���";
    char output[33] = { 0 }; // �洢32λ��ϣֵ��һ�����ַ�
    char string[1000];

    md5_hash(input, output);
    sprintf(string, "MD5 Hash: %s\n", output);
    ::MessageBoxA(0, string, 0, 0);
    return 0;
}

