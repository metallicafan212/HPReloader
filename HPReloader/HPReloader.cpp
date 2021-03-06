// HPReloader.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <mmsystem.h>
#include "resource.h"


int main()
{
	// Loop until we find that damn game or hit null again
	bool bLoop = true;

	HWND windowPTR = nullptr;

	// HP 2 loop
	while (bLoop)
	{

		// Try to find the default window
		//windowPTR = FindWindowW(windowPTR, L"Harry Potter and the Chamber of Secrets");//FindWindowExW(NULL, NULL, L"WLog", NULL);
		windowPTR = FindWindowEx(windowPTR, NULL, L"GameUnrealWLog", NULL);//NULL, L"Harry Potter and the Chamber of Secrets");

		// Check if we have it
		if (!windowPTR)
		{
			//std::cout << "Help, I've fallen and I can't get up!\n";
			// Get out of my loop!
			bLoop = false;
		}
		else
		{
			// Check this
			if (GetProp(windowPTR, TEXT("IsBrowser")))
			{
				//std::cout << "Found the game!\n";

				// Init the copy data struct
				COPYDATASTRUCT hpShit;

				// I think it needs the open message, this may be what fucks everyone up
				// So it looks like dwData doesn't matter
				hpShit.dwData = RegisterWindowMessage(TEXT("UnrealOpen"));
				hpShit.cbData = 3;//4 * sizeof(TCHAR*);
				hpShit.lpData = const_cast<char*>("map");//const_cast<char*>("-log");


				// Log the result
				DWORD result;

				// Send the message
				SendMessageTimeout(windowPTR, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&hpShit, SMTO_ABORTIFHUNG | SMTO_BLOCK, 30000, &result);

				// Play a sound and wait to show the program was used
				PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);

				//if (result == 0)
				//{
					// We have an error!
					//std::cout << "Last error is " << GetLastError() << "\n";
				//}

				//std::cout << "Result was " << result << "\n";
			}
			//else
				//std::cout << "Window is not browser?\n";
		}
	}

	// Now check for HP1
	bLoop = true;
	windowPTR = nullptr;
	while (bLoop)
	{
		windowPTR = FindWindowEx(windowPTR, NULL, L"HPUnrealWLog", NULL); 

		if (!windowPTR)
		{
			bLoop = false;
		}
		else
		{
			// Check this
			if (GetProp(windowPTR, TEXT("IsBrowser")))
			{
				//std::cout << "Found the game!\n";

				// Init the copy data struct
				COPYDATASTRUCT hpShit;

				// I think it needs the open message, this may be what fucks everyone up

				hpShit.dwData = RegisterWindowMessage(TEXT("HPUnrealOpen"));
				hpShit.cbData = 3;//4 * sizeof(TCHAR*);
				hpShit.lpData = const_cast<char*>("map");//const_cast<char*>("-log");


				// Log the result
				DWORD result;

				// Send the message
				SendMessageTimeout(windowPTR, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&hpShit, SMTO_ABORTIFHUNG | SMTO_BLOCK, 30000, &result);

				// Play a sound and wait to show the program was used
				PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);

				//if (result == 0)
				//{
					// We have an error!
					//std::cout << "Last error is " << GetLastError() << "\n";
				//}

				//std::cout << "Result was " << result << "\n";
			}
			//else
				//std::cout << "Window is not browser?\n";
		}
	}

    return 0;
}

