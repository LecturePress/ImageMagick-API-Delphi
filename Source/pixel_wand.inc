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

  ImageMagick pixel wand API.
}


{
  Declaration from pixel-wand.c
}
type
  PixelWand = record
    id: culong;

    name: array[1..MaxTextExtent] of char;

    exception: ExceptionInfo;

    pixel: PixelInfo;

    count: culong;

    debug: MagickBooleanType;

    signature: culong;
  end;

  PPixelWand = ^PixelWand;
  
  PPPixelWand = ^PPixelWand;
  
  PQuantum = ^Quantum; 
  
var
PixelGetException: function(const wand: PPixelWand; severity: PExceptionType): PAnsiChar; cdecl;
PixelGetColorAsString: function(const wand: PPixelWand): PAnsiChar; cdecl;
PixelGetColorAsNormalizedString: function(const wand: PPixelWand): PAnsiChar; cdecl;

PixelGetAlpha: function(const wand: PPixelWand): Double; cdecl;
PixelGetBlack: function(const wand: PPixelWand): Double; cdecl;
PixelGetBlue: function(const wand: PPixelWand): Double; cdecl;
PixelGetCyan: function(const wand: PPixelWand): Double; cdecl;
PixelGetFuzz: function(const wand: PPixelWand): Double; cdecl;
PixelGetGreen: function(const wand: PPixelWand): Double; cdecl;
PixelGetMagenta: function(const wand: PPixelWand): Double; cdecl;
//PixelGetOpacity: function(const wand: PPixelWand): Double; cdecl; //Function name => PixelGetAlpha
PixelGetRed: function(const wand: PPixelWand): Double; cdecl;
PixelGetYellow: function(const wand: PPixelWand): Double; cdecl;

PixelGetExceptionType: function(const wand: PPixelWand): ExceptionType; cdecl;

PixelGetIndex: function(const wand: PPixelWand): Quantum; cdecl;

IsPixelWand: function(const wand: PPixelWand): MagickBooleanType; cdecl;
IsPixelWandSimilar: function(p: PPixelWand; q: PPixelWand; const fuzz: double): MagickBooleanType; cdecl;
PixelClearException: function(wand: PPixelWand): MagickBooleanType; cdecl;
PixelSetColor: function(wand: PPixelWand; const color: PAnsiChar): MagickBooleanType; cdecl;

PixelGetPixel: function(const wand: PPixelWand): PixelInfo; cdecl;

ClonePixelWand: function(const wand: PPixelWand): PPixelWand; cdecl;
ClonePixelWands: function(const wand: PPPixelWand; const number_wands: culong): PPPixelWand; cdecl;
DestroyPixelWand: function(wand: PPixelWand): PPixelWand; cdecl;
DestroyPixelWands: function(wand: PPPixelWand; const number_wands: culong): PPPixelWand; cdecl;
NewPixelWand: function: PPixelWand; cdecl;
NewPixelWands: function(const number_wands: culong): PPPixelWand; cdecl;

PixelGetAlphaQuantum: function(const wand: PPixelWand): Quantum; cdecl;
PixelGetBlackQuantum: function(const wand: PPixelWand): Quantum; cdecl;
PixelGetBlueQuantum: function(const wand: PPixelWand): Quantum; cdecl;
PixelGetCyanQuantum: function(const wand: PPixelWand): Quantum; cdecl;
PixelGetGreenQuantum: function(const wand: PPixelWand): Quantum; cdecl;
PixelGetMagentaQuantum: function(const wand: PPixelWand): Quantum; cdecl;
//PixelGetOpacityQuantum: function(const wand: PPixelWand): Quantum; cdecl; //Function name => PixelGetAlphaQuantum
PixelGetRedQuantum: function(const wand: PPixelWand): Quantum; cdecl;
PixelGetYellowQuantum: function(const wand: PPixelWand): Quantum; cdecl;

PixelGetColorCount: function(const wand: PPixelWand): culong; cdecl;

ClearPixelWand: procedure(wand: PPixelWand); cdecl;
PixelGetHSL: procedure(wand: PPixelWand; const hue: PDouble; const saturation: PDouble; const lightness: PDouble); cdecl;
PixelGetMagickColor: procedure(const wand: PPixelWand; color: PPixelInfo); cdecl;
PixelGetQuantumPacket: procedure(const wand: PPixelWand; packet: PPixelInfo); cdecl;
PixelGetQuantumPixel: procedure(const image: PImage; const wand: PPixelWand; pixel: PQuantum); cdecl;
PixelSetAlpha: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetAlphaQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetBlack: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetBlackQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetBlue: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetBlueQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetColorFromWand: procedure(wand: PPixelWand; const color: PPixelWand); cdecl;
PixelSetColorCount: procedure(wand: PPixelWand; const count: culong); cdecl;
PixelSetCyan: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetCyanQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetFuzz: procedure(wand: PPixelWand; const fuzz: Double); cdecl;
PixelSetGreen: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetGreenQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetHSL: procedure(wand: PPixelWand; const hue: Double; const saturation: Double; const lightness: Double); cdecl;
PixelSetIndex: procedure(wand: PPixelWand; const index: IndexPacket); cdecl;
PixelSetMagenta: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetMagentaQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetPixelColor: procedure(wand: PPixelWand; const color: PPixelInfo); cdecl;
//PixelSetOpacity: procedure(wand: PPixelWand; const opacity: Double); cdecl;   => Alpha
//PixelSetOpacityQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;  => Alpha
PixelSetPixelColor: procedure(wand: PPixelWand; const color: PPixelInfo); cdecl; 
PixelSetQuantumPixel: procedure(const image: PImage; const pixel: PQuantum; wand: PPixelWand); cdecl;
PixelSetRed: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetRedQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;
PixelSetYellow: procedure(wand: PPixelWand; const opacity: Double); cdecl;
PixelSetYellowQuantum: procedure(wand: PPixelWand; const opacity: Quantum); cdecl;

// Considered a private method in newer versions (after 6.2)
//PixelGetMagickColor: procedure(const wand: PPixelWand; packet: PMagickPixelPacket); cdecl;


