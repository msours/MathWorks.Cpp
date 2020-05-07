function imageComponents = ConnectedComponents16Bit(BinaryData, ImageData, StrelSize)

CC =  bwconncomp(BinaryData);

if(StrelSize > 0)
    
    % In the event that a convolution with a sobel kernel is used to highlight features with edges,
    % the middle of the feature will have a gap, which is fixed by strel
    
    if(StrelSize > 19)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 20)));
    end
    if(StrelSize == 19)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 19)));
    end
    if(StrelSize == 18)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 18)));
    end
    if(StrelSize == 17)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 17)));
    end
    if(StrelSize == 16)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 16)));
    end
    if(StrelSize == 15)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 15)));
    end
    if(StrelSize == 14)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 14)));
    end
    if(StrelSize == 13)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 13)));
    end
    if(StrelSize == 12)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 12)));
    end
    if(StrelSize == 11)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 11)));
    end
    if(StrelSize == 10)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 10)));
    end
    if(StrelSize == 9)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 9)));
    end
    if(StrelSize == 8)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 8)));
    end
    if(StrelSize == 7)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 7)));
    end
    if(StrelSize == 6)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 6)));
    end
    if(StrelSize == 5)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 5)));
    end
    if(StrelSize == 4)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 4)));
    end
    if(StrelSize == 3)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 3)));
    end
    if(StrelSize == 2)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 2)));
    end
    if(StrelSize == 1)
        CC =  bwconncomp(imclose(BinaryData, strel('disk', 1)));
    end
end

imageComponents = regionprops(CC, ImageData, 'WeightedCentroid', 'BoundingBox', 'Area', 'EquivDiameter');
