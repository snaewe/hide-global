#include "RealSdlLayerInstanceDelegator.h"
#include "sdl.h"

RealSdlLayerInstanceDelegator::RealSdlLayerInstanceDelegator(){}

RealSdlLayerInstanceDelegator::~RealSdlLayerInstanceDelegator(){}

const SDL_version *RealSdlLayerInstanceDelegator::SDL_Linked_Version() {
  return ::SDL_Linked_Version();
}

int RealSdlLayerInstanceDelegator::SDL_Init(int bitMask) {
  return ::SDL_Init(bitMask);
}

void *RealSdlLayerInstanceDelegator::SDL_SetVideoMode(int x, int y, int bitDepth, int mode) {
  return ::SDL_SetVideoMode(x, y, bitDepth, mode);
}

void RealSdlLayerInstanceDelegator::SDL_WM_SetCaption(const char *title, int someIntValue) {
  ::SDL_WM_SetCaption(title, someIntValue);
}
