struct SDL_version;

class SdlLayerInstanceDelegator {
public:
  virtual ~SdlLayerInstanceDelegator(void) = 0;

  virtual const SDL_version *SDL_Linked_Version() = 0;
  virtual int SDL_Init(int bitMask) = 0;
  virtual void *SDL_SetVideoMode(int x, int y, int bitDepth, int mode) = 0;
  virtual void SDL_WM_SetCaption(const char *title, int someIntValue) = 0;

protected:
  SdlLayerInstanceDelegator();

private:
  SdlLayerInstanceDelegator(const SdlLayerInstanceDelegator &rhs);
  SdlLayerInstanceDelegator &operator = (const SdlLayerInstanceDelegator &);
};

