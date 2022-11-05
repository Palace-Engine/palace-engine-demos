#include <palace-engine/include/platform/entry_point.hpp>

#include <sstream>

int palaceMain(palace::ApplicationContext *context) {
    constexpr int WindowWidth = 256;
    constexpr int WindowHeight = 256;

    palace::WindowServer *windowServer = context->windowServer();
    windowServer->updateDisplayDevices();
    const size_t displayDeviceCount = windowServer->displayDevices().size();
    if (displayDeviceCount == 0) {
        return -1;
    }

    palace::DynamicArray<palace::Window *> windows;
    for (size_t i = 0; i < displayDeviceCount; ++i) {
        palace::DisplayDevice *displayDevice = windowServer->displayDevices()[i];

        std::stringstream ss;
        ss << "Window " << i << " | Palace Engine | Demo 01 | Window Spawning Demo";

        palace::Window::Parameters parameters;
        parameters.style = palace::Window::Style::Windowed;
        parameters.title = ss.str();
        parameters.size = { WindowWidth, WindowHeight };
        parameters.position = {
            displayDevice->origin().x() + displayDevice->logicalSize().w() / 2 - WindowWidth / 2,
            displayDevice->origin().y() + displayDevice->logicalSize().h() / 2 - WindowHeight / 2 };
        windows.append(windowServer->spawnWindow(parameters));
    }

    bool windowsRemaining = true;
    while (windowsRemaining) {
        windowsRemaining = false;
        for (size_t i = 0; i < windows.size(); ++i) {
            if (windows[i]->isOpen()) {
                windowsRemaining = true;
                break;
            }
        }

        windowServer->processMessages();
    }

    return 0;
}
