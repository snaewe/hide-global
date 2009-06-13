#include "SdlLayerFactory.h"

SdlLayerInstanceDelegator *SdlLayerFactory::instance = 0;

SdlLayerFactory::SdlLayerFactory(){}

SdlLayerFactory::~SdlLayerFactory(){}

SdlLayerInstanceDelegator *SdlLayerFactory::getInstance() {
  return instance;
}

SdlLayerInstanceDelegator *SdlLayerFactory::replaceInstance(SdlLayerInstanceDelegator *replacement) {
  SdlLayerInstanceDelegator *original = instance;
  instance = replacement;
  return original;
}

