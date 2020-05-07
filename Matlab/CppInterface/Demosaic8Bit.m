function Image = Demosaic8Bit(BayerPatternImage, ColorConversionCode)

% ColorConversionCode : ['rggb', 'bggr', 'grbg', 'gbrg'] = [0, 1, 2, 3]

[Height, Width] = size(BayerPatternImage);
Image = uint8(zeros(Height, Width, 3));

% Implementing this way is required since C Coder does not seem to support 'elseif'
if(ColorConversionCode == 0)
    Image = demosaic(BayerPatternImage, 'rggb');
end
if(ColorConversionCode == 1)
    Image = demosaic(BayerPatternImage, 'bggr');
end
if(ColorConversionCode == 2)
    Image = demosaic(BayerPatternImage, 'grbg');
end
if(ColorConversionCode == 3)
    Image = demosaic(BayerPatternImage, 'gbrg');
end
