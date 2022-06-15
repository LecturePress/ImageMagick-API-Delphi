/*
  Copyright @ 2000 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.  You may
  obtain a copy of the License at
  
    https://imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  MagickCore artifact methods.
*/

//extern MagickExport 
RemoveImageArtifact: function(image: PImage; const artifact: PAnsiChar): PAnsiChar; cdecl;

GetNextImageArtifact(const image: PImage): PAnsiChar; cdecl;
GetImageArtifact(const image: PImage; const artifact: PAnsiChar): PAnsiChar; cdecl;

CloneImageArtifacts: function(image: PImage; const clone_image: PImage): MagickBooleanType; cdecl;
DefineImageArtifact: function(image: PImage; const artifact: PAnsiChar): MagickBooleanType; cdecl;
DeleteImageArtifact: function(image: PImage; const artifact: PAnsiChar): MagickBooleanType; cdecl;
SetImageArtifact: function(image: PImage; const artifact: PAnsiChar; const value: PAnsiChar): MagickBooleanType; cdecl;

DestroyImageArtifacts: procedure(image: PImage); cdecl;
ResetImageArtifactIterator: procedure(const image: PImage); cdecl;

