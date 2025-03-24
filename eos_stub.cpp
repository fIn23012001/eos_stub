#include <windows.h>

extern "C" {

// Заглушка платформы
__declspec(dllexport) void* EOS_Platform_Create(...) {
    return (void*)1;
}

__declspec(dllexport) void EOS_Platform_Release(...) {
}

// Заглушка авторизации
__declspec(dllexport) int EOS_Auth_Login(...) {
    return 0; // EOS_Success
}

__declspec(dllexport) int EOS_Connect_Login(...) {
    return 0; // EOS_Success
}

__declspec(dllexport) void EOS_Auth_Token_Release(...) {}
__declspec(dllexport) void EOS_Auth_IdToken_Release(...) {}
__declspec(dllexport) void EOS_Connect_IdToken_Release(...) {}

__declspec(dllexport) int EOS_Auth_GetLoginStatus(...) {
    return 1; // LoggedIn
}

__declspec(dllexport) int EOS_Connect_GetLoginStatus(...) {
    return 1; // LoggedIn
}

// Прочие возможные вызовы
__declspec(dllexport) int EOS_Auth_CopyUserAuthToken(...) {
    return 0;
}

__declspec(dllexport) int EOS_Auth_CopyIdToken(...) {
    return 0;
}

__declspec(dllexport) int EOS_Connect_CopyIdToken(...) {
    return 0;
}

__declspec(dllexport) int EOS_Auth_GetLoggedInAccountsCount(...) {
    return 1;
}

__declspec(dllexport) void* EOS_Connect_GetLoggedInUserByIndex(...) {
    return (void*)1;
}

}
