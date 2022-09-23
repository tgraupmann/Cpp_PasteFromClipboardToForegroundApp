// PasteFromClipboardToForegroundApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void SendInputToForeground(HWND hwnd, char c)
{
    // This structure will be used to create the keyboard
    // input event.
    INPUT ip;

    if (c >= 'A' && c <= 'Z')
    {
        ip = { 0 };
        ip.type = INPUT_KEYBOARD;
        ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
        ip.ki.wVk = VK_SHIFT;
        SendInput(1, &ip, sizeof(INPUT));

        // Set up a generic keyboard event.
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0; // hardware scan code for key
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        // Press the char key
        ip.ki.wVk = c; // virtual-key code for the "a" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Release the key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));

        ip = { 0 };
        ip.type = INPUT_KEYBOARD;
        ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY;
        ip.ki.wVk = VK_SHIFT;
        SendInput(1, &ip, sizeof(INPUT));
    }

    else if (c >= 'a' && c <= 'z')
    {
        char sendChar = 'A' + c - 'a';

        // Set up a generic keyboard event.
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0; // hardware scan code for key
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        // Press the char key
        ip.ki.wVk = sendChar; // virtual-key code for the "a" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        // Release the key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));
    }

    else
    {
        char sendChar = 0;
        bool useShift = false;
        switch (c)
        {
            case ' ':
                sendChar = c;
                break;

            case '\t':
                sendChar = c;
                break;

            case 10:
                sendChar = c;
                break;

            case 13:
                sendChar = c;
                break;

            case '1':
                sendChar = '1';
                break;
            case '!':
                useShift = true;
                sendChar = '1';
                break;

            case '2':
                sendChar = '2';
                break;
            case '@':
                useShift = true;
                sendChar = '2';
                break;

            case '3':
                sendChar = '3';
                break;
            case '#':
                useShift = true;
                sendChar = '3';
                break;

            case '4':
                sendChar = '4';
                break;
            case '$':
                useShift = true;
                sendChar = '4';
                break;

            case '5':
                sendChar = '5';
                break;
            case '%':
                useShift = true;
                sendChar = '5';
                break;

            case '6':
                sendChar = '6';
                break;
            case '^':
                useShift = true;
                sendChar = '6';
                break;

            case '7':
                sendChar = '7';
                break;
            case '&':
                useShift = true;
                sendChar = '7';
                break;

            case '8':
                sendChar = '8';
                break;
            case '*':
                useShift = true;
                sendChar = '8';
                break;

            case '9':
                sendChar = '9';
                break;
            case '(':
                useShift = true;
                sendChar = '9';
                break;

            case '0':
                sendChar = '0';
                break;
            case ')':
                useShift = true;
                sendChar = '0';
                break;

            case ';':
                sendChar = VK_OEM_1;
                break;
            case ':':
                useShift = true;
                sendChar = VK_OEM_1;
                break;

            case '/':
                sendChar = VK_OEM_2;
                break;
            case '?':
                useShift = true;
                sendChar = VK_OEM_2;
                break;

            case '`':
                sendChar = VK_OEM_3;
                break;
            case '~':
                useShift = true;
                sendChar = VK_OEM_3;
                break;

            case '[':
                sendChar = VK_OEM_4;
                break;
            case '{':
                useShift = true;
                sendChar = VK_OEM_4;
                break;

            case '\\':
                sendChar = VK_OEM_5;
                break;
            case '|':
                useShift = true;
                sendChar = VK_OEM_5;
                break;

            case ']':
                sendChar = VK_OEM_6;
                break;
            case '}':
                useShift = true;
                sendChar = VK_OEM_6;
                break;

            case '\'':
                sendChar = VK_OEM_7;
                break;
            case '"':
                useShift = true;
                sendChar = VK_OEM_7;
                break;

            case '=':
                sendChar = VK_OEM_PLUS;
                break;
            case '+':
                useShift = true;
                sendChar = VK_OEM_PLUS;
                break;

            case '-':
                sendChar = VK_OEM_MINUS;
                break;
            case '_':
                useShift = true;
                sendChar = VK_OEM_MINUS;
                break;

            case ',':
                sendChar = VK_OEM_COMMA;
                break;
            case '<':
                useShift = true;
                sendChar = VK_OEM_COMMA;
                break;

            case '.':
                sendChar = VK_OEM_PERIOD;
                break;
            case '>':
                useShift = true;
                sendChar = VK_OEM_PERIOD;
                break;
        default:
            break;
        }
        if (sendChar != 0)
        {
            if (useShift)
            {
                ip = { 0 };
                ip.type = INPUT_KEYBOARD;
                ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
                ip.ki.wVk = VK_SHIFT;
                SendInput(1, &ip, sizeof(INPUT));
            }

            // Set up a generic keyboard event.
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = 0; // hardware scan code for key
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;

            // Press the char key
            ip.ki.wVk = sendChar; // virtual-key code for the "a" key
            ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));

            // Release the key
            ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
            SendInput(1, &ip, sizeof(INPUT));

            if (useShift)
            {
                ip = { 0 };
                ip.type = INPUT_KEYBOARD;
                ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY;
                ip.ki.wVk = VK_SHIFT;
                SendInput(1, &ip, sizeof(INPUT));
            }
        }
        else
        {
            cout << c << " => " << int(c) << endl;
        }
    }

    Sleep(1);
}

void PasteClipboard()
{
    HANDLE clip;
    if (OpenClipboard(NULL)) {
        clip = GetClipboardData(CF_TEXT);
        CloseClipboard();

        HWND hwnd = GetForegroundWindow();

        string text = (char*)clip;
        cout << "Send: " << text << endl;
        for (int i = 0; i < text.size(); ++i)
        {
            char c = text[i];

            SendInputToForeground(hwnd, c);
        }
    }    
}

int main()
{
    bool detectedTrigger = false;

    while (true)
    {
        // detect a key press
        bool isLeftShift = (GetKeyState(VK_LSHIFT) & 0x8000);
        bool isRightShift = (GetKeyState(VK_RSHIFT) & 0x8000);
        if (!detectedTrigger && isLeftShift && isRightShift)
        {
            cout << "Detect Trigger" << endl;
            detectedTrigger = true;
        }

        // detect key release
        if (detectedTrigger && !isLeftShift && !isRightShift)
        {
            detectedTrigger = false;
            cout << "Paste clipboard" << endl;
            PasteClipboard();
        }
        Sleep(1);
    }

    return TRUE;
}
