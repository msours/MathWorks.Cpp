function ResizedImage = imresize16bit(Image, NewHeight, NewWidth, Method)

ResizedImage = uint16(zeros(double(NewHeight), double(NewWidth)));

MethodChosen = false;
if(Method == 0)
    ResizedImage = imresize(Image, double([NewHeight, NewWidth]), 'bilinear');
    MethodChosen = true;
end
if(Method == 1)
    ResizedImage = imresize(Image, double([NewHeight, NewWidth]), 'bicubic');
    MethodChosen = true;
end
if(~MethodChosen)
    ResizedImage = imresize(Image, double([NewHeight, NewWidth]));
end
