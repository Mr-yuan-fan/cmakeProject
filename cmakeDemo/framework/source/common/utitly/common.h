#ifndef __FRAMEWORK_COMMON_H__
#define __FRAMEWORK_COMMON_H__


#ifndef FRAMEWORK_COMMON_API
#ifdef FRAMEWORK_COMMON_API_FLAG
#define FRAMEWORK_COMMON_API __declspec(dllexport)
#else
#define FRAMEWORK_COMMON_API __declspec(dllimport)
#endif // !FRAMEWORK_COMMON_API_FLAG
#endif // !FRAMEWORK_COMMON_API

#define BEGINE_NAMESPACE( name ) namespace name{

#define END_NAMESPACE }


#endif
