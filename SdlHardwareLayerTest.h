#include <CppUTest/TestHarness.h>

#include "sdl.h"
#include "SdlLayerFactory.h"
#include "SdlHardwareLayer.h"
#include "TestDoubleSdlLayerInstanceDelegator.h"

TEST_GROUP(SdlHardwareLayerTest) {
  virtual void setup() {
    original = SdlLayerFactory::getInstance();
    layer = new SdlHardwareLayer;
  }

  virtual void teardown() {
    if(SdlLayerFactory::getInstance() != original)
      delete SdlLayerFactory::getInstance();

    SdlLayerFactory::replaceInstance(original);
    delete layer;
  }

  SdlLayerInstanceDelegator *original;
  SdlHardwareLayer *layer;
};

struct MajorMinorSdlhardwareLayer : public TestDoubleSdlLayerInstanceDelegator {
  struct SDL_version v;

  MajorMinorSdlhardwareLayer() {
    v.major = 0;
    v.minor = 0;
  }

  const SDL_version *SDL_Linked_Version() {
    return &v;
  }
};

TEST(SdlHardwareLayerTest, ItGeneratsErrorWithLowMajorMinorVersionNumber) {
  SdlLayerFactory::replaceInstance(new MajorMinorSdlhardwareLayer);
  try {
    layer->initializeHardware();
    FAIL("Should have thrown int value");
  } catch (int value) {
    LONGS_EQUAL(1, value);
  }
}

struct InitFailingSdlHardwareLayer : public MajorMinorSdlhardwareLayer {
  InitFailingSdlHardwareLayer () {
    v.major = 3;
    v.minor = 3;
  }

  int SDL_Init(int bitMask) {
    return -1;
  }
};

TEST(SdlHardwareLayerTest, ItGeneratesErrorWhenInitReturnsLessThan0) {
  SdlLayerFactory::replaceInstance(new InitFailingSdlHardwareLayer);
  try {
    layer->initializeHardware();
    FAIL("Should have thrown int value");
  } catch (int value) {
    LONGS_EQUAL(2, value);
  }
}

