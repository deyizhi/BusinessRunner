#ifndef _COMMONDEF_H_
#define _COMMONDEF_H_
#include <string.h>

/////////////////////////////////////////////////////////////
/// @brief 不同长度整数类型定义
typedef unsigned char		Byte;
typedef unsigned short		UInt16;
typedef short 				Int16;
typedef unsigned int 		UInt32;
typedef int	  				Int32;
typedef unsigned long long	UInt64;
typedef long long	 		Int64;
/////////////////////////////////////////////////////////////
/// @brief 常用的字符串和指针判断的函数定义
template<typename T>
inline bool IsNull(T*  p)
{
	return NULL == p;
}

inline bool IsStringEquel(const char* cstr1, const char* cstr2)
{
	if (!cstr1 || !cstr2)
	{
		return cstr1 == cstr2;
	}
	else
	{
		return 0 == strcmp(cstr1, cstr2);	
	}
}

inline bool IsStringEmpty(const char* cstr)
{
	if (NULL == cstr)
	{
		return true;
	}
	return  '\0' == cstr[0];
}

#endif // _COMMONDEF_H_
