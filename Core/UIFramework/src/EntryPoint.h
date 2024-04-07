#pragma once

extern UI::Application* UI::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace UI
{

int Main(int argc, char** argv)
{
    while (g_ApplicationRunning)
    {
        UI::Application* app = UI::CreateApplication(argc, argv);
        app->run();
        delete app;
    }

    return 0;
}

}

#ifdef DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return Walnut::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
    return UI::Main(argc, argv);
}

#endif // WL_DIST