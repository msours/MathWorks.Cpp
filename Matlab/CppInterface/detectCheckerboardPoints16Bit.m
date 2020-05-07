function [imagePoints, boardSize] = detectCheckerboardPoints16Bit(ImageData, CornerThreshold)

[imagePoints, boardSize] = detectCheckerboardPoints(ImageData,'MinCornerMetric', CornerThreshold);
