class SdlLayerInstanceDelegator;

class SdlLayerFactory
{
public:
  static SdlLayerInstanceDelegator *getInstance();
  static SdlLayerInstanceDelegator *replaceInstance(SdlLayerInstanceDelegator *replacement);

private:
  static SdlLayerInstanceDelegator *instance;

  SdlLayerFactory();
  ~SdlLayerFactory();
};

