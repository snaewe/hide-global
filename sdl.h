extern "C" {
  const int SDL_INIT_VIDEO = 1;
  const int SDL_INIT_AUDIO = 2;
  const int SDL_INIT_NOPARACHUTE = 4;
  const int SDL_DOUBLEBUF = 8;

  struct SDL_version {
    int major;
    int minor;
  };

  const SDL_version *SDL_Linked_Version();
  int SDL_Init(int bitMask);
  void *SDL_SetVideoMode(int x, int y, int bitDepth, int mode);
  void SDL_WM_SetCaption(const char *title, int someIntValue);
}
