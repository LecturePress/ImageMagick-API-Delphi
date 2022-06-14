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

  ImageMagick image methods.
}

{#define MaximumNumberOfImageMoments  8
#define MaximumNumberOfPerceptualColorspaces  6
#define MaximumNumberOfPerceptualHashes  7 }

const
  MaximumNumberOfImageMoments = 8;
  MaximumNumberOfPerceptualColorspaces = 6;
  MaximumNumberOfPerceptualHashes = 7;


type
  ChannelStatistics = record
    depth: culong;
    area,
    minima,
    maxima,
    sum,
    sum_squared,
    sum_cubed,
    sum_fourth_power,
    mean,
    variance,
    standard_deviation,
    kurtosis,
    skewness,
    entropy,
    median : double;
  end;
  
  PChannelStatistics = ^ChannelStatistics;
  
  ChannelMoments = record
    invariant[MaximumNumberOfImageMoments+1]: double;
    centroid,
    ellipse_axis: PointInfo;
    ellipse_angle,
    ellipse_eccentricity,
    ellipse_intensity: double;
  end;
  
  PChannelMoments = ^ChannelMoments;  
  
  ChannelPerceptualHash = record 
    srgb_hu_phash[MaximumNumberOfImageMoments+1],
    hclp_hu_phash[MaximumNumberOfImageMoments+1]: double; 
    number_colorspaces: culong; 
    colorspace[MaximumNumberOfPerceptualColorspaces+1]: ColorspaceType;
    phash[MaximumNumberOfPerceptualColorspaces+1][MaximumNumberOfImageMoments+1]: double;
    number_channels: culong;
  end; 
  
  PChannelPerceptualHash = ^ChannelPerceptualHash;
  
  MagickEvaluateOperator = (UndefinedEvaluateOperator,
                            AbsEvaluateOperator,
                            AddEvaluateOperator,
                            AddModulusEvaluateOperator,
                            AndEvaluateOperator,
                            CosineEvaluateOperator,
                            DivideEvaluateOperator,
                            ExponentialEvaluateOperator,
                            GaussianNoiseEvaluateOperator,
                            ImpulseNoiseEvaluateOperator,
                            LaplacianNoiseEvaluateOperator,
                            LeftShiftEvaluateOperator,
                            LogEvaluateOperator,
                            MaxEvaluateOperator,
                            MeanEvaluateOperator,
                            MedianEvaluateOperator,
                            MinEvaluateOperator,
                            MultiplicativeNoiseEvaluateOperator,
                            MultiplyEvaluateOperator,
                            OrEvaluateOperator,
                            PoissonNoiseEvaluateOperator,
                            PowEvaluateOperator,
                            RightShiftEvaluateOperator,
                            RootMeanSquareEvaluateOperator,
                            SetEvaluateOperator,
                            SineEvaluateOperator,
                            SubtractEvaluateOperator,
                            SumEvaluateOperator,
                            ThresholdBlackEvaluateOperator,
                            ThresholdEvaluateOperator,
                            ThresholdWhiteEvaluateOperator,
                            UniformNoiseEvaluateOperator,
                            XorEvaluateOperator,
                            InverseLogEvaluateOperator);  

  MagickFunction = (UndefinedFunction, 
                    ArcsinFunction,
                    ArctanFunction,
                    PolynomialFunction,
                    SinusoidFunction);

  StatisticType = (UndefinedStatistic,
                   GradientStatistic,
                   MaximumStatistic,
                   MeanStatistic,
                   MedianStatistic,
                   MinimumStatistic,
                   ModeStatistic,
                   NonpeakStatistic,
                   RootMeanSquareStatistic,
                   StandardDeviationStatistic,
                   ContrastStatistic);
                   
//extern MagickExport                   
GetImageStatistics: function(const image: PImage; exception: PExceptionInfo): PChannelStatistics; cdecl;
GetImageMoments: function(const image: PImage; exception: PExceptionInfo): PChannelMoments; cdecl;
GetImagePerceptualHash: function(const image: PImage; exception: PExceptionInfo): PChannelPerceptualHash; cdecl;
 
EvaluateImages: function(const image: PImage; const op: MagickEvaluateOperator; exception: PExceptionInfo): PImage; cdecl;
PolynomialImage: function(const image: PImage; const number_terms: culong; const terms: PDouble; exception: PExceptionInfo): PImage; cdecl;
StatisticImage: function(const image: PImage; const &type: StatisticType; const width: culong; const height: culong; exception: PExceptionInfo): PImage; cdecl;

EvaluateImage: function(image: PImage; const op: MagickEvaluateOperator; const value: Double; exception: PExceptionInfo): MagickBooleanType; cdecl;
FunctionImage: function(image: PImage; const &function: MagickFunction; const number_parameters: culong; const parameters: PDouble; exception: PExceptionInfo): MagickBooleanType; cdecl;
GetImageEntropy: function(const image: PImage; entropy: PDouble; exception: PExceptionInfo): MagickBooleanType; cdecl;
GetImageExtrema: function(const image: PImage; minima: pculong; maxima: pculong; exception: PExceptionInfo): MagickBooleanType; cdecl;
GetImageMean: function(const image: PImage; mean: PDouble; standard_deviation: PDouble; exception: PExceptionInfo): MagickBooleanType; cdecl;
GetImageMedian: function(const image: PImage; median: PDouble; exception: PExceptionInfo): MagickBooleanType; cdecl;
GetImageKurtosis: function(const image: PImage; kurtosis: PDouble; skewness: PDouble; exception: PExceptionInfo): MagickBooleanType; cdecl;
GetImageRange: function(const image: PImage; minima: PDouble; maxima: PDouble; exception: PExceptionInfo): MagickBooleanType; cdecl;                   
