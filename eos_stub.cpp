
#include <Windows.h>

extern "C" __declspec(dllexport) void* EOS_Platform_Create() {
    return (void*)1;
}

extern "C" __declspec(dllexport) int EOS_Auth_Login() {
    return 0;
}
