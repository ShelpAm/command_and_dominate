#ifndef SMALL_UTILITY_MACRO_MACRO_H_
#define SMALL_UTILITY_MACRO_MACRO_H_

#if defined __linux__
# define SMALL_UTILITY_LINUX
#elif defined _WIN32 // __linux__
# define SMALL_UTILITY_WINDOWS
#else
# error no_corresponding_platform
#endif // _WIN32

#endif  // SMALL_UTILITY_MACRO_MACRO_H_


#if defined SMALL_UTILITY_LINUX
# define SMALL_UTILITY_FUNCTION_NAME    __PRETTY_FUNCTION__
#elif defined SMALL_UTILITY_WINDOWS
# define SMALL_UTILITY_FUNCTION_NAME    __FUNCSIG__
#endif

#define SMALL_UTILITY_LINE              __LINE__
#define SMALL_UTILITY_FILE_NAME         __FILE__
