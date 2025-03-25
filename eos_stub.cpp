#include <windows.h>
#include <stdint.h>

static int dummyInt = 1;
static void* dummyPtr = &dummyInt;

typedef struct {
    int dummy;
} EOS_Auth_Token;

extern "C" {

__declspec(dllexport) int EOS_Auth_Login(...) { return 0; }
__declspec(dllexport) int EOS_Connect_Login(...) { return 0; }

__declspec(dllexport) int EOS_Auth_CopyUserAuthToken(void* Handle, void* Options, EOS_Auth_Token** OutToken) {
    static EOS_Auth_Token fakeToken = { 1234 };
    *OutToken = &fakeToken;
    return 0;
}

__declspec(dllexport) int EOS_Auth_GetAuthToken(void* Handle, void* Options, EOS_Auth_Token** OutToken) {
    static EOS_Auth_Token fakeToken = { 5678 };
    *OutToken = &fakeToken;
    return 0;
}

__declspec(dllexport) void* EOS_Platform_Create(...) { return dummyPtr; }
__declspec(dllexport) void* EOS_Connect_GetLoggedInUserByIndex(...) { return dummyPtr; }

__declspec(dllexport) int EOS_Connect_CopyProductUserInfo(...) { return 0; }
__declspec(dllexport) int EOS_Connect_CopyProductUserExternalAccountByAccountType(...) { return 0; }
__declspec(dllexport) int EOS_Auth_Logout(...) { return 0; }
__declspec(dllexport) int EOS_Platform_Tick(...) { return 0; }

}
