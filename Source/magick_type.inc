{
  Copyright 1999-2005 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  ImageMagick structure members.

  NOTE: This is a simplifyed version of magick/magick-type.h
}

const MaxTextExtent = 4096;

const
  MagickFalse = 0;
  MagickTrue = 1;

type
  MagickBooleanType = culong;

  PMagickBooleanType = ^MagickBooleanType;

//#include "magick/semaphore.h"

{
  The Quantum Depth was fixed at 16 to make the code simpler

  In the future there is the possibility to go to the c bindings
 and implement the variable QuantumDepth here
}
const
  QuantumDepth = 16;

{$define QuantumLeap}

const
  MagickEpsilon = 1.0E-10;
  MaxColormapSize = 65536;
  MaxMap = 65535;
  QuantumFormat = '%u';
  QuantumRange = 65535;

type
  MagickRealType = double;
  Quantum = Word;

{
  Type declarations.
}
type
  MagickStatusType = Word;
  MagickOffsetType = Int64;
  MagickSizeType = Int64;

type
 ChannelType = (
     UndefinedChannel = $0000,
      RedChannel = $0001,
      GrayChannel = $0001,
      CyanChannel = $0001,
      GreenChannel = $0002,
      MagentaChannel = $0002,
      BlueChannel = $0004,
      YellowChannel = $0004,
      BlackChannel = $0008,
      AlphaChannel = $0010,
      OpacityChannel = $0010,
      IndexChannel = $0020,             // Color Index Table? */
      ReadMaskChannel = $0040,          // Pixel is Not Readable? */
      WriteMaskChannel = $0080,         // Pixel is Write Protected? */
      MetaChannel = $0100,              // ???? */
      CompositeChannels = $001F,
      AllChannels = $7ffffff,
      {
        Special purpose channel types.
        FUTURE: are these needed any more - they are more like hacks
        SyncChannels for example is NOT a real channel but a 'flag'
        It really says -- "User has not defined channels"
        Though it does have extra meaning in the "-auto-level" operator
      }
      TrueAlphaChannel = $0100, // extract actual alpha channel from opacity */
      RGBChannels = $0200,      // set alpha from grayscale mask in RGB */
      GrayChannels = $0400,
      SyncChannels = $20000,    // channels modified as a single unit */
      DefaultChannels = AllChannels
      );

type
  PChannelType = ^ChannelType;

type
 ClassType = (
  UndefinedClass,
  DirectClass,
  PseudoClass
 );

  PClassType = ^ClassType;

type
 ColorspaceType = (
   UndefinedColorspace,
   CMYColorspace,           // negated linear RGB colorspace */
   CMYKColorspace,          // CMY with Black separation */
   GRAYColorspace,          // Single Channel greyscale (non-linear) image */
   HCLColorspace,
   HCLpColorspace,
   HSBColorspace,
   HSIColorspace,
   HSLColorspace,
   HSVColorspace,           // alias for HSB */
   HWBColorspace,
   LabColorspace,
   LCHColorspace,           // alias for LCHuv */
   LCHabColorspace,         // Cylindrical (Polar) Lab */
   LCHuvColorspace,         // Cylindrical (Polar) Luv */
   LogColorspace,
   LMSColorspace,
   LuvColorspace,
   OHTAColorspace,
   Rec601YCbCrColorspace,
   Rec709YCbCrColorspace,
   RGBColorspace,           // Linear RGB colorspace */
   scRGBColorspace,         // ??? */
   sRGBColorspace,          // Default: non-linear sRGB colorspace */
   TransparentColorspace,
   xyYColorspace,
   XYZColorspace,           // IEEE Color Reference colorspace */
   YCbCrColorspace,
   YCCColorspace,
   YDbDrColorspace,
   YIQColorspace,
   YPbPrColorspace,
   YUVColorspace,
   LinearGRAYColorspace,     // Single Channel greyscale (linear) image */
   JzazbzColorspace,
   DisplayP3Colorspace,
   Adobe98Colorspace,
   ProPhotoColorspace
  );

  PColorspaceType = ^ColorspaceType;

type
 CompositeOperator = (
   UndefinedCompositeOp,
   AlphaCompositeOp,
   AtopCompositeOp,
   BlendCompositeOp,
   BlurCompositeOp,
   BumpmapCompositeOp,
   ChangeMaskCompositeOp,
   ClearCompositeOp,
   ColorBurnCompositeOp,
   ColorDodgeCompositeOp,
   ColorizeCompositeOp,
   CopyBlackCompositeOp,
   CopyBlueCompositeOp,
   CopyCompositeOp,
   CopyCyanCompositeOp,
   CopyGreenCompositeOp,
   CopyMagentaCompositeOp,
   CopyAlphaCompositeOp,
   CopyRedCompositeOp,
   CopyYellowCompositeOp,
   DarkenCompositeOp,
   DarkenIntensityCompositeOp,
   DifferenceCompositeOp,
   DisplaceCompositeOp,
   DissolveCompositeOp,
   DistortCompositeOp,
   DivideDstCompositeOp,
   DivideSrcCompositeOp,
   DstAtopCompositeOp,
   DstCompositeOp,
   DstInCompositeOp,
   DstOutCompositeOp,
   DstOverCompositeOp,
   ExclusionCompositeOp,
   HardLightCompositeOp,
   HardMixCompositeOp,
   HueCompositeOp,
   InCompositeOp,
   IntensityCompositeOp,
   LightenCompositeOp,
   LightenIntensityCompositeOp,
   LinearBurnCompositeOp,
   LinearDodgeCompositeOp,
   LinearLightCompositeOp,
   LuminizeCompositeOp,
   MathematicsCompositeOp,
   MinusDstCompositeOp,
   MinusSrcCompositeOp,
   ModulateCompositeOp,
   ModulusAddCompositeOp,
   ModulusSubtractCompositeOp,
   MultiplyCompositeOp,
   NoCompositeOp,
   OutCompositeOp,
   OverCompositeOp,
   OverlayCompositeOp,
   PegtopLightCompositeOp,
   PinLightCompositeOp,
   PlusCompositeOp,
   ReplaceCompositeOp,
   SaturateCompositeOp,
   ScreenCompositeOp,
   SoftLightCompositeOp,
   SrcAtopCompositeOp,
   SrcCompositeOp,
   SrcInCompositeOp,
   SrcOutCompositeOp,
   SrcOverCompositeOp,
   ThresholdCompositeOp,
   VividLightCompositeOp,
   XorCompositeOp,
   StereoCompositeOp,
   FreezeCompositeOp,
   InterpolateCompositeOp,
   NegateCompositeOp,
   ReflectCompositeOp,
   SoftBurnCompositeOp,
   SoftDodgeCompositeOp,
   StampCompositeOp,
   RMSECompositeOp
 );

  PCompositeOperator = ^CompositeOperator;

type
  // Verified with imagemagick 6.7.7-10
  CompressionType = (
   UndefinedCompression,
   B44ACompression,
   B44Compression,
   BZipCompression,
   DXT1Compression,
   DXT3Compression,
   DXT5Compression,
   FaxCompression,
   Group4Compression,
   JBIG1Compression,        // ISO/IEC std 11544 / ITU-T rec T.82 */
   JBIG2Compression,        // ISO/IEC std 14492 / ITU-T rec T.88 */
   JPEG2000Compression,     // ISO/IEC std 15444-1 */
   JPEGCompression,
   LosslessJPEGCompression,
   LZMACompression,         // Lempel-Ziv-Markov chain algorithm */
   LZWCompression,
   NoCompression,
   PizCompression,
   Pxr24Compression,
   RLECompression,
   ZipCompression,
   ZipSCompression,
   ZstdCompression,
   WebPCompression,
   DWAACompression,
   DWABCompression,
   BC7Compression
  );

  PCompressionType = ^CompressionType;
  
type
 DisposeType = (
  UnrecognizedDispose = 0,
  UndefinedDispose = 0,
  NoneDispose = 1,
  BackgroundDispose = 2,
  PreviousDispose = 3
  );

type
  PDisposeType = ^DisposeType;
  
type
 EndianType = (
  UndefinedEndian,
  LSBEndian,
  MSBEndian
 );

  PEndianType = ^EndianType;

type
 ExceptionType = (
  UndefinedException,
  WarningException = 300,
  ResourceLimitWarning = 300,
  TypeWarning = 305,
  OptionWarning = 310,
  DelegateWarning = 315,
  MissingDelegateWarning = 320,
  CorruptImageWarning = 325,
  FileOpenWarning = 330,
  BlobWarning = 335,
  StreamWarning = 340,
  CacheWarning = 345,
  CoderWarning = 350,
  FilterWarning = 352,
  ModuleWarning = 355,
  DrawWarning = 360,
  ImageWarning = 365,
  WandWarning = 370,
  RandomWarning = 375,
  XServerWarning = 380,
  MonitorWarning = 385,
  RegistryWarning = 390,
  ConfigureWarning = 395,
  PolicyWarning = 399,
  ErrorException = 400,
  ResourceLimitError = 400,
  TypeError = 405,
  OptionError = 410,
  DelegateError = 415,
  MissingDelegateError = 420,
  CorruptImageError = 425,
  FileOpenError = 430,
  BlobError = 435,
  StreamError = 440,
  CacheError = 445,
  CoderError = 450,
  FilterError = 452,
  ModuleError = 455,
  DrawError = 460,
  ImageError = 465,
  WandError = 470,
  RandomError = 475,
  XServerError = 480,
  MonitorError = 485,
  RegistryError = 490,
  ConfigureError = 495,
  PolicyError = 499,
  FatalErrorException = 700,
  ResourceLimitFatalError = 700,
  TypeFatalError = 705,
  OptionFatalError = 710,
  DelegateFatalError = 715,
  MissingDelegateFatalError = 720,
  CorruptImageFatalError = 725,
  FileOpenFatalError = 730,
  BlobFatalError = 735,
  StreamFatalError = 740,
  CacheFatalError = 745,
  CoderFatalError = 750,
  FilterFatalError = 752,
  ModuleFatalError = 755,
  DrawFatalError = 760,
  ImageFatalError = 765,
  WandFatalError = 770,
  RandomFatalError = 775,
  XServerFatalError = 780,
  MonitorFatalError = 785,
  RegistryFatalError = 790,
  ConfigureFatalError = 795,
  PolicyFatalError = 799
  );
  
type
  PExceptionType = ^ExceptionType;

type
 FilterType = (
  UndefinedFilter,
  PointFilter,
  BoxFilter,
  TriangleFilter,
  HermiteFilter,
  HannFilter,
  HammingFilter,
  BlackmanFilter,
  GaussianFilter,
  QuadraticFilter,
  CubicFilter,
  CatromFilter,
  MitchellFilter,
  JincFilter,
  SincFilter,
  SincFastFilter,
  KaiserFilter,
  WelchFilter,
  ParzenFilter,
  BohmanFilter,
  BartlettFilter,
  LagrangeFilter,
  LanczosFilter,
  LanczosSharpFilter,
  Lanczos2Filter,
  Lanczos2SharpFilter,
  RobidouxFilter,
  RobidouxSharpFilter,
  CosineFilter,
  SplineFilter,
  LanczosRadiusFilter,
  CubicSplineFilter,
  SentinelFilter  // a count of all the filters, not a real filter */
 );

  PFilterType = ^FilterType;

type
 GravityType = (
  UndefinedGravity,
  ForgetGravity = 0,
  NorthWestGravity = 1,
  NorthGravity = 2,
  NorthEastGravity = 3,
  WestGravity = 4,
  CenterGravity = 5,
  EastGravity = 6,
  SouthWestGravity = 7,
  SouthGravity = 8,
  SouthEastGravity = 9
  );

type
  PGravityType = ^GravityType;

type ImageType = (
  UndefinedType,
  BilevelType,
  GrayscaleType,
  GrayscaleAlphaType,
  PaletteType,
  PaletteAlphaType,
  TrueColorType,
  TrueColorAlphaType,
  ColorSeparationType,
  ColorSeparationAlphaType,
  OptimizeType,
  PaletteBilevelAlphaType
 );

  PImageType = ^ImageType;

type
 InterlaceType = (
  UndefinedInterlace,
  NoInterlace,
  LineInterlace,
  PlaneInterlace,
  PartitionInterlace,
  GIFInterlace,
  JPEGInterlace,
  PNGInterlace
 );

  PInterlaceType = ^InterlaceType;

type
 OrientationType = (
  UndefinedOrientation,
  TopLeftOrientation,
  TopRightOrientation,
  BottomRightOrientation,
  BottomLeftOrientation,
  LeftTopOrientation,
  RightTopOrientation,
  RightBottomOrientation,
  LeftBottomOrientation
 );

  POrientationType = ^OrientationType;

type PreviewType = (
  UndefinedPreview,
  RotatePreview,
  ShearPreview,
  RollPreview,
  HuePreview,
  SaturationPreview,
  BrightnessPreview,
  GammaPreview,
  SpiffPreview,
  DullPreview,
  GrayscalePreview,
  QuantizePreview,
  DespecklePreview,
  ReduceNoisePreview,
  AddNoisePreview,
  SharpenPreview,
  BlurPreview,
  ThresholdPreview,
  EdgeDetectPreview,
  SpreadPreview,
  SolarizePreview,
  ShadePreview,
  RaisePreview,
  SegmentPreview,
  SwirlPreview,
  ImplodePreview,
  WavePreview,
  OilPaintPreview,
  CharcoalDrawingPreview,
  JPEGPreview
 );

  PPreviewType = ^PreviewType;

type RenderingIntent = (
  UndefinedIntent,
  SaturationIntent,
  PerceptualIntent,
  AbsoluteIntent,
  RelativeIntent
 );

  PRenderingIntent = ^RenderingIntent;

type ResolutionType = (
  UndefinedResolution,
  PixelsPerInchResolution,
  PixelsPerCentimeterResolution
 );

  PResolutionType = ^ResolutionType;

type TimerState = (
  UndefinedTimerState,
  StoppedTimerState,
  RunningTimerState
 );

  PTimerState = ^TimerState;

type
  AffineMatrix = record
    sx, rx, ry, sy, tx, ty: double;
  end;
  
  PAffineMatrix = ^AffineMatrix;

type
 IndexPacket = Quantum;

type
  PixelPacket = record
{$ifdef WORDS_BIGENDIAN}
   red, green, blue, alpha, black: Quantum;
{$else}
   blue, green, red, alpha, black: Quantum;
{$endif}
  end;
  
  PPixelPacket = ^PixelPacket;

type
  ColorPacket = record
   pixel: PixelPacket;
   index: IndexPacket;
   count: culong;
  end;
  
  PColorPacket = ^ColorPacket;

type
  ErrorInfo = record
   mean_error_per_pixel, normalized_mean_error, normalized_maximum_error: double;
  end;

type
  PrimaryInfo = record
   x, y, z: double;
  end;

type 
  ProfileInfo = record
  end;
  
  PProfileInfo = ^ProfileInfo;

type 
  RectangleInfo = record
   width, height: culong;
   x, y: culong;
  end;

type
  SegmentInfo = record
   x1, y1, x2, y2: double;
  end;

type
  Timer = record
   start, stop, total: double;
  end;
  
  PTimer = ^Timer;

type
  TimerInfo = record
   user, elapsed: Timer;
   state: TimerState;
   signature: culong;
  end;
  
  PTimerInfo = ^TimerInfo;

type
  ChromaticityInfo = record
   red_primary, green_primary, blue_primary, white_point: PrimaryInfo;
 end;

type
  ExceptionInfo = record
   severity: ExceptionType;
   error_number: Shortint;
   //severity: culong;
   //error_number: culong;
   reason, description: PAnsiChar;
	 exceptions: Pointer;
	 relinquish: MagickBooleanType;
   semaphore: Pointer; //PSemaphoreInfo;
   signature: culong;
  end;

  PExceptionInfo = ^ExceptionInfo;

//typedef struct _Ascii85Info _Ascii85Info_;

//typedef struct _BlobInfo _BlobInfo_;
type
  PointInfo = record
    x, y: double;
  end;

  PPointInfo = ^PointInfo;

const MaxPixelChannels = 32;

type
  PixelChannel = (
  UndefinedPixelChannel = 0,
  RedPixelChannel = 0,
  CyanPixelChannel = 0,
  GrayPixelChannel = 0,
  LPixelChannel = 0,
  LabelPixelChannel = 0,
  YPixelChannel = 0,
  aPixelChannel = 1,
  GreenPixelChannel = 1,
  MagentaPixelChannel = 1,
  CbPixelChannel = 1,
  bPixelChannel = 2,
  BluePixelChannel = 2,
  YellowPixelChannel = 2,
  CrPixelChannel = 2,
  BlackPixelChannel = 3,
  AlphaPixelChannel = 4,
  IndexPixelChannel = 5,
  ReadMaskPixelChannel = 6,
  WriteMaskPixelChannel = 7,
  MetaPixelChannel = 8,
  CompositeMaskPixelChannel = 9,
  IntensityPixelChannel = MaxPixelChannels,  // ???? */
  CompositePixelChannel = MaxPixelChannels,  // ???? */
  SyncPixelChannel = MaxPixelChannels+1      // not a real channel */
  );

type
  PixelTrait = (
    UndefinedPixelTrait = $000000,
    CopyPixelTrait = $000001,
    UpdatePixelTrait = $000002,
    BlendPixelTrait = $000004
  );

type
  PixelChannelMap = record
    channel: PixelChannel;
    traits: PixelTrait;
    offset: cint;

  end;
  PPixelChannelMap = ^PixelChannelMap;

type
  PixelIntensityMethod = (
    UndefinedPixelIntensityMethod = 0,
    AveragePixelIntensityMethod,
    BrightnessPixelIntensityMethod,
    LightnessPixelIntensityMethod,
    MSPixelIntensityMethod,
    Rec601LumaPixelIntensityMethod,
    Rec601LuminancePixelIntensityMethod,
    Rec709LumaPixelIntensityMethod,
    Rec709LuminancePixelIntensityMethod,
    RMSPixelIntensityMethod
    );

type
  PixelInterpolateMethod = (
    UndefinedInterpolatePixel,
    AverageInterpolatePixel,    // Average 4 nearest neighbours */
    Average9InterpolatePixel,   // Average 9 nearest neighbours */
    Average16InterpolatePixel,  // Average 16 nearest neighbours */
    BackgroundInterpolatePixel, // Just return background color */
    BilinearInterpolatePixel,   // Triangular filter interpolation */
    BlendInterpolatePixel,      // blend of nearest 1, 2 or 4 pixels */
    CatromInterpolatePixel,     // Catmull-Rom interpolation */
    IntegerInterpolatePixel,    // Integer (floor) interpolation */
    MeshInterpolatePixel,       // Triangular Mesh interpolation */
    NearestInterpolatePixel,    // Nearest Neighbour Only */
    SplineInterpolatePixel      // Cubic Spline (blurred) interpolation */
  );


type
  MagickProgressMonitor = function (const str: PAnsiChar; const para: MagickOffsetType;
   const sizetype: MagickSizeType; param: Pointer): PMagickBooleanType;

type
  PixelInfo = record
    storage_class: ClassType;
    colorspace: ColorspaceType;
    alpha_trait: PixelTrait;
    fuzz: double;
    depth: culong;
    count: MagickSizeType;
    red, green, blue, black, alpha, index: MagickRealType;
end;

type
  PImageInfo = ^ImageInfo;
  PImage = ^Image;

  Image = record
   storage_class: ClassType;
   colorspace: ColorspaceType;
   compression: CompressionType;
   quality: culong;
   orientation: OrientationType;
   taint: MagickBooleanType;
   columns, rows, depth, colors: culong;
   colormap: PPixelPacket;
   alpha_coloer, background_color, border_color, transparent_color: PixelPacket;
   gamma: double;
   chromaticity: ChromaticityInfo;
   rendering_intent: RenderingIntent;
   profiles: Pointer;
   units: ResolutionType;
   montage, directory, geometry: PAnsiChar;
   offset: cint;
   //x_resolution, y_resolution: double;
   resolution: PointInfo;
   page, extract_info: RectangleInfo;  // deprecated
   fuzz: double;
   filter: FilterType;
   intensity: PixelIntensityMethod;
   interlace: InterlaceType;
   endian: EndianType;
   gravity: GravityType;
   compose: CompositeOperator;
   dispose: DisposeType;
   scene, delay, duration: culong;
   ticks_per_second: cint;
   iterations, total_colors: culong;
   start_loop: cint;
   interpolate: PixelInterpolateMethod;
   black_point_compensation: MagickBooleanType;
   tile_offset: RectangleInfo;
   type_: ImageType;
   dither: MagickBooleanType;
   extent: MagickSizeType;
   ping: MagickBooleanType;
   read_mask, write_mask: MagickBooleanType;
   alpha_trait: PixelTrait;
   number_channels, number_meta_channels, metacontent_extent: culong;
   channel_mask: ChannelType;
   channel_map: PPixelChannelMap;
   cache: Pointer;
   error: ErrorInfo;
   timer: TimerInfo;
   progress_monitor: MagickProgressMonitor;
   client_data: Pointer;
   ascii85: Pointer; //_Ascii85Info_
   generic_profile: PProfileInfo;
   properties, artifacts: Pointer;
   filename, magick_filename, magick: array[1..MaxTextExtent] of char;
   magick_columns, magick_rows: culong;
   blob: Pointer; // _BlobInfo_
   timestamp: culong; // ???
   debug: MagickBooleanType;
   reference_count: Longint;
   semaphore: Pointer; //PSemaphoreInfo;
   image_info: PImageInfo;
   list, previous, next: PImage;
   signature: culong;
   matte_color: PixelInfo;
   composite_mask: MagickBooleanType;
   mask_trait: PixelTrait;
   channels: ChannelType;
  end;

 ImageInfo = record
   compression: CompressionType;
   orientation: OrientationType;
   temporary, adjoin, affirm, antialias: MagickBooleanType;
   size, extract, page, scenes: PAnsiChar;
   scene, number_scenes, depth: culong;
   interlace: InterlaceType;
   endian: EndianType;
   units: ResolutionType;
   quality: culong;
   sampling_factor, server_name, font, texture, density: PAnsiChar;
   pointsize, fuzz: double;
   alpha_color, background_color, border_color, transparent_color: PixelInfo;
   dither, monochrome: MagickBooleanType;
//   colors: culong;
   colorspace: ColorspaceType;
   compose: CompositeOperator;
   type_: ImageType ;
//   preview_type: PreviewType;
//   group: Longint;
   ping, verbose: MagickBooleanType;
//   view, authenticate: PAnsiChar;
   channel: ChannelType;
//   attributes: PImage;
   options: Pointer;
   profile: Pointer;
   synchronize: MagickBooleanType;
   progress_monitor: MagickProgressMonitor;
   client_data, cache: Pointer;
   stream: culong; //StreamHandler;
   file_: Pointer; // *file
   blob: Pointer;
   length: cint;
   magick, unique, filename: array[1..MaxTextExtent] of char;
   debug: MagickBooleanType;
   signature: culong;
   custom_stream: Pointer; // *CustomStreamInfo
   matte_color: PixelInfo;
 end;


//type
//  size_t = PStreamHandler(procedure (const image: PImage;
//   const param: Pointer; const) );



