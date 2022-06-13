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

  ImageMagick Cache View Methods.
}


type
 VirtualPixelMethod = (
  UndefinedVirtualPixelMethod,
  BackgroundVirtualPixelMethod,
  DitherVirtualPixelMethod,
  EdgeVirtualPixelMethod,
  MirrorVirtualPixelMethod,
  RandomVirtualPixelMethod,
  TileVirtualPixelMethod,
  TransparentVirtualPixelMethod,
  MaskVirtualPixelMethod,
  BlackVirtualPixelMethod,
  GrayVirtualPixelMethod,
  WhiteVirtualPixelMethod,
  HorizontalTileVirtualPixelMethod,
  VerticalTileVirtualPixelMethod,
  HorizontalTileEdgeVirtualPixelMethod,
  VerticalTileEdgeVirtualPixelMethod,
  CheckerTileVirtualPixelMethod
  );

type
  PNexusInfo = ^NexusInfo;
  PPNexusInfo = ^PNexusInfo;

  NexusInfo = record
    mapped: MagickBooleanType;
    region: RectangleInfo;
    length: MagickSizeType;
    cache, pixels: ^Quantum;
    authentic_pixel_cache: MagickBooleanType;
    metacontent: Pointer;
    signature: culong;
    virtual_nexus: PNexusInfo;
  end;


type
  CacheView = record
    image: PImage;

    virtual_pixel_method: VirtualPixelMethod;

    number_threads: culong;

    nexus_info: PPNexusInfo;

    debug: MagickBooleanType;

    signature: culong;
  end;
  
  PCacheView = ^CacheView;

{extern MagickExport const PixelPacket
  *AcquireCacheView(const ViewInfo *,const long,const long,const unsigned long,
    const unsigned long,ExceptionInfo *);

extern MagickExport IndexPacket
  *GetCacheViewIndexes(const ViewInfo *);

extern MagickExport MagickBooleanType
  SyncCacheView(ViewInfo *);

extern MagickExport PixelPacket
  *GetCacheViewPixels(const ViewInfo *),
  *GetCacheView(ViewInfo *,const long,const long,const unsigned long,
    const unsigned long),
  *SetCacheView(ViewInfo *,const long,const long,const unsigned long,
    const unsigned long);

extern MagickExport ViewInfo
  *OpenCacheView(Image *);

extern MagickExport void
  CloseCacheView(ViewInfo *);}

