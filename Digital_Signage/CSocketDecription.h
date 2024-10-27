#pragma once
class CSocketDecription
{
public:
	int SendEncription(char* result, char* key, char* buf);
	void MD5ToString(unsigned char* md5result, char* output);
	void md5_hash(char* input, char* output);
	int main1();
};
