#include <windows.h>
#include <wincred.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>
int main()
{
    std::string serviceName="", key="";
    wprintf(L"enter service name : ");
    std::cin >> serviceName;
    wprintf(L"enter key value : ");
    std::cin >> key;
    std::string queryString = serviceName + "/" + key;
    std::wstring queryWString = std::wstring(queryString.begin(),queryString.end());
    LPCWSTR realQuery = queryWString.c_str();
    PCREDENTIALW pcred;
    BOOL flag = CredReadW(realQuery, CRED_TYPE_GENERIC, 0, &pcred);

    if (!flag) {
        wprintf(L"Oooops there is no credential like that, give me another correct key plz\n");
        exit(1);     
    }

    wprintf(L"requested password by key ID ('%s')='%S' \n", pcred->UserName, (char*)pcred->CredentialBlob);
    CredFree(pcred);
}