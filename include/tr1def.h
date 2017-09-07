#ifndef _TR1DEF_H_
#define _TR1DEF_H_
#if defined(_WIN32) || defined(_WIN64) || __cplusplus >= 201103L
#		include <memory> 
#		include <functional>
#else
#		include <tr1/memory> 
#		include <tr1/functional>
#endif 

#if __cplusplus < 201103L
	namespace stdtr1 = std::tr1;		
#else
	namespace stdtr1 = std;
#endif 

#endif // _TR1DEF_H_
