function [imagePoints, boardSize] = detectCheckerboardPoints8Bit(ImageData, CornerThreshold)

[imagePoints, boardSize] = detectCheckerboardPoints(ImageData,'MinCornerMetric', CornerThreshold);
