#include "SdlHardwareLayer.h"

#include "sdl.h"
#include "SdlLayerFactory.h"
#include "SdlLayerInstanceDelegator.h"

SdlHardwareLayer::SdlHardwareLayer() {
}

SdlHardwareLayer::~SdlHardwareLayer() {
}

void SdlHardwareLayer::initializeHardware() {
    const SDL_version * sdlVersion = SdlLayerFactory::getInstance()->SDL_Linked_Version();
    if (sdlVersion->minor < 2 && sdlVersion->major < 2) {
      throw 1;
    }
    else if (SdlLayerFactory::getInstance()->SDL_Init(SDL_INIT_VIDEO |
            SDL_INIT_AUDIO |
            SDL_INIT_NOPARACHUTE) < 0) {
              throw 2;
    }
    else {
        m_screen = SDL_SetVideoMode(m_x, m_y, m_bitDepth, SDL_DOUBLEBUF);
        if (0 != m_screen) {
            SDL_WM_SetCaption(m_title.c_str(), 0);
        }
    }
}

