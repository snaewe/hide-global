#include <string>

class SdlHardwareLayer {
public:
  SdlHardwareLayer();
  virtual ~SdlHardwareLayer();
  void initializeHardware();

private:
  int m_x;
  int m_y;
  int m_bitDepth;
  std::string m_title;
  void *m_screen;
};

