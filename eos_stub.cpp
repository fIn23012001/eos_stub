#include <windows.h>
#include <stdint.h>
#include <stdio.h>

static int dummyInt = 1;
static void* dummyPtr = &dummyInt;

#define LOG_CALL(func) log_call(#func)

void log_call(const char* func) {
    FILE* f = fopen("eos_stub_log.txt", "a");
    if (f) {
        fprintf(f, "Called: %s\n", func);
        fclose(f);
    }
}

typedef struct {
    int dummy;
} EOS_Auth_Token;

extern "C" {

__declspec(dllexport) int EOS_Auth_Login(...) { LOG_CALL(EOS_Auth_Login); return 0; }
__declspec(dllexport) int EOS_Connect_Login(...) { LOG_CALL(EOS_Connect_Login); return 0; }

__declspec(dllexport) int EOS_Auth_CopyUserAuthToken(void* Handle, void* Options, EOS_Auth_Token** OutToken) {
    LOG_CALL(EOS_Auth_CopyUserAuthToken);
    static EOS_Auth_Token fakeToken = { 1234 };
    *OutToken = &fakeToken;
    return 0;
}

__declspec(dllexport) int EOS_Auth_GetAuthToken(void* Handle, void* Options, EOS_Auth_Token** OutToken) {
    LOG_CALL(EOS_Auth_GetAuthToken);
    static EOS_Auth_Token fakeToken = { 5678 };
    *OutToken = &fakeToken;
    return 0;
}

__declspec(dllexport) void* EOS_Platform_Create(...) { LOG_CALL(EOS_Platform_Create); return dummyPtr; }
__declspec(dllexport) void* EOS_Connect_GetLoggedInUserByIndex(...) { LOG_CALL(EOS_Connect_GetLoggedInUserByIndex); return dummyPtr; }

__declspec(dllexport) int EOS_Connect_CopyProductUserInfo(...) { LOG_CALL(EOS_Connect_CopyProductUserInfo); return 0; }
__declspec(dllexport) int EOS_Connect_CopyProductUserExternalAccountByAccountType(...) { LOG_CALL(EOS_Connect_CopyProductUserExternalAccountByAccountType); return 0; }
__declspec(dllexport) int EOS_Connect_CopyIdToken(...) { LOG_CALL(EOS_Connect_CopyIdToken); return 0; }
__declspec(dllexport) int EOS_Connect_VerifyIdToken(...) { LOG_CALL(EOS_Connect_VerifyIdToken); return 0; }
__declspec(dllexport) int EOS_Auth_Logout(...) { LOG_CALL(EOS_Auth_Logout); return 0; }
__declspec(dllexport) int EOS_Platform_Tick(...) { LOG_CALL(EOS_Platform_Tick); return 0; }

__declspec(dllexport) int EOS_UserInfo_CopyUserInfo(...) { LOG_CALL(EOS_UserInfo_CopyUserInfo); return 0; }
__declspec(dllexport) int EOS_Ecom_CopyEntitlementByIndex(...) { LOG_CALL(EOS_Ecom_CopyEntitlementByIndex); return 0; }
__declspec(dllexport) int EOS_Ecom_GetEntitlementsCount(...) { LOG_CALL(EOS_Ecom_GetEntitlementsCount); return 0; }

}
