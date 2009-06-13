#include "TestDoubleSdlLayerInstanceDelegator.h"

TestDoubleSdlLayerInstanceDelegator::TestDoubleSdlLayerInstanceDelegator(){}

TestDoubleSdlLayerInstanceDelegator::~TestDoubleSdlLayerInstanceDelegator(){}

const SDL_version *TestDoubleSdlLayerInstanceDelegator::SDL_Linked_Version() {
  return 0;
}

int TestDoubleSdlLayerInstanceDelegator::SDL_Init(int bitMask) {
  return 0;
}

void *TestDoubleSdlLayerInstanceDelegator::SDL_SetVideoMode(int x, int y, int bitDepth, int mode) {
  return 0;
}

void TestDoubleSdlLayerInstanceDelegator::SDL_WM_SetCaption(const char *title, int someIntValue){}
