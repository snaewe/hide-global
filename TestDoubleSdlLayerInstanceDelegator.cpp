#include "SdlLayerInstanceDelegator.h"

class TestDoubleSdlLayerInstanceDelegator: public SdlLayerInstanceDelegator {
public:
  TestDoubleSdlLayerInstanceDelegator();
  virtual ~TestDoubleSdlLayerInstanceDelegator();

  const SDL_version *SDL_Linked_Version();
  int SDL_Init(int bitMask);
  void *SDL_SetVideoMode(int x, int y, int bitDepth, int mode);
  void SDL_WM_SetCaption(const char *title, int someIntValue);
};
