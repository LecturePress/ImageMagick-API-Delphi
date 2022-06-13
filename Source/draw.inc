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

  ImageMagick drawing methods.
}

//#include "magick/type.h"

type
 AlignType = (
  UndefinedAlign,
  LeftAlign,
  CenterAlign,
  RightAlign
 );

type
 ClipPathUnits = (
  UndefinedPathUnits,
  UserSpace,
  UserSpaceOnUse,
  ObjectBoundingBox
 );

type
 DecorationType = (
  UndefinedDecoration,
  NoDecoration,
  UnderlineDecoration,
  OverlineDecoration,
  LineThroughDecoration
 );

type
 DirectionType = (
  UndefinedDirection,
  RightToLeftDirection,
  LeftToRightDirection
);

type
 FillRule = (
  UndefinedRule,
//#undef EvenOddRule
  EvenOddRule,
  NonZeroRule
 );

type
 GradientType = (
  UndefinedGradient,
  LinearGradient,
  RadialGradient
 );

type
 LineCap = (
  UndefinedCap,
  ButtCap,
  RoundCap,
  SquareCap
 );

type
 LineJoin = (
  UndefinedJoin,
  MiterJoin,
  RoundJoin,
  BevelJoin
 );

type
 PaintMethod = (
  UndefinedMethod,
  PointMethod,
  ReplaceMethod,
  FloodfillMethod,
  FillToBorderMethod,
  ResetMethod
 );

type
 PrimitiveType = (
  UndefinedPrimitive,
  AlphaPrimitive,
  ArcPrimitive,
  BezierPrimitive,
  CirclePrimitive,
  ColorPrimitive,
  EllipsePrimitive,
  ImagePrimitive,
  LinePrimitive,
  PathPrimitive,
  PointPrimitive,
  PolygonPrimitive,
  PolylinePrimitive,
  RectanglePrimitive,
  RoundRectanglePrimitive,
  TextPrimitive
 );

type
 ReferenceType = (
  UndefinedReference,
  GradientReference
 );

type
 SpreadMethod = (
  UndefinedSpread,
  PadSpread,
  ReflectSpead,
  RepeatSpread
 );

type
 ComplianceType = (
  UndefinedCompliance,
  NoCompliance = $0000,
  CSSCompliance = $0001,
  SVGCompliance = $0001,
  X11Compliance = $0002,
  XPMCompliance = $0004,
  MVGCompliance = $0008,
  AllCompliance = $7fffffff
 );

 type
  StopInfo = record
    color: PixelInfo;
    offfset: double;
  end;
  PStopInfo = ^StopInfo;

type
  GradientInfo = record
    type_: GradientType;
    bounding_box: RectangleInfo;
    gradient_vector: SegmentInfo;
    stops: PStopInfo;
    number_stops: culong;
    spread: SpreadMethod;
    debug: MagickBooleanType;
    center, radii: PointInfo;
    radius, angle: double;
    signature: culong;
  end;


type
  PElementReference = ^ElementReference;
  ElementReference = record
    id: PAnsiChar;
    type_: ReferenceType;
    gradient: GradientInfo;
    previous, next: PElementReference;
    signature: culong;
  end;

type
  DrawInfo = record
    primitive, geometry: PAnsiChar;

    viewbox: RectangleInfo;

    affine: AffineMatrix;

//    gravity: GravityType;

    fill, stroke, undercolor, border_color: PixelInfo;

    fill_pattern, stroke_pattern: PImage;

    stroke_width: double;

    gradient: GradientInfo;

    stroke_antialias, text_antialias: MagickBooleanType;

    fill_rule: FillRule;

    linecap_: LineCap;

    linejoin_: LineJoin;

    miterlimit: culong;

    dash_offset: double;

    decorate: DecorationType;

    compose: CompositeOperator;

    text, font, metrics, family: PAnsiChar;

    face: culong;

    style: StyleType;

    stretch: StretchType;

    weight: culong;

    encoding: PAnsiChar;

    pointsize: double;

    density: PAnsiChar;

    align: AlignType;

    gravity: GravityType;

    server_name: PAnsiChar;

    dash_pattern: Pdouble;

    clip_mask: PAnsiChar;

    bounds: SegmentInfo;

    clip_units: ClipPathUnits;

    alpha: Quantum;

    render: MagickBooleanType;

    element_reference: ElementReference;

    kerning, interword_spacing, interline_spacing: double;

    direction: DirectionType;

    debug: MagickBooleanType;

    signature: culong;

    fill_alpha, stroke_alpha: double;

    clip_path: MagickBooleanType;

    clipping_mask: PImage;

    compliance: ComplianceType;

    composite_mask: PImage;

    id: PAnsiChar;

  end;

  PDrawInfo = ^DrawInfo;

  PPDrawInfo = ^PDrawInfo;


type
  PrimitiveInfo = record
    point: PointInfo;

    coordinates: culong;

    primitive: PrimitiveType;

    method: PaintMethod;

    text: PAnsiChar;

    closed_subpath: MagickBooleanType;
  end;

type
  TypeMetric = record
    pixels_per_em: PointInfo;

    ascent,
    descent,
    width,
    height,
    max_advance,
    underline_position,
    underline_thickness: double;

    bounds: SegmentInfo;

    origin: PointInfo;
  end;

{extern MagickExport DrawInfo
  *CloneDrawInfo(const ImageInfo *,const DrawInfo *),
  *DestroyDrawInfo(DrawInfo *);

extern MagickExport MagickBooleanType
  DrawAffineImage(Image *,const Image *,const AffineMatrix *),
  DrawClipPath(Image *,const DrawInfo *,const char *),
  DrawImage(Image *,const DrawInfo *),
  DrawPatternPath(Image *,const DrawInfo *,const char *,Image **),
  DrawPrimitive(Image *,const DrawInfo *,const PrimitiveInfo *);

extern MagickExport void
  GetAffineMatrix(AffineMatrix *),
  GetDrawInfo(const ImageInfo *,DrawInfo *);}


