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

// 实现类似PHP md5的函数
void CSocketDecription::md5_hash(char* input, char* output)
{
    unsigned char md5result[16]; // MD5的哈希值是16字节
   // MD5(0, 0, 0); // 使用OpenSSL的MD5函数

    MD5((unsigned char*)input, strlen(input), md5result); // 使用OpenSSL的MD5函数
    MD5ToString(md5result, output); // 将结果转换为16进制字符串
}

int CSocketDecription::main1()
{
    char input[] = "你好";
    char output[33] = { 0 }; // 存储32位哈希值加一个空字符
    char string[1000];

    md5_hash(input, output);
    sprintf(string, "MD5 Hash: %s\n", output);
    ::MessageBoxA(0, string, 0, 0);
    return 0;
}

