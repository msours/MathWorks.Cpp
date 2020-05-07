function ResizedImage = imresize8bit(Image, NewHeight, NewWidth, Method)

ResizedImage = uint8(zeros(double(NewHeight), double(NewWidth)));

% Implementing this way is required since C Coder does not seem to support 'elseif'
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
