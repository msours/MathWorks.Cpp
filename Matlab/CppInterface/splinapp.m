function output = splinapp(x,y,w,xx)
%SPLINAPP  Data approximation(!) by natural cubic splines.
%          Given data vectors X and Y, weight vector W, and a new 
%          abscissa vector XI, the function
%
%	   YI = SPLINAPP(X,Y,W,XI) uses cubic spline approximation to
%                                  find a vector YI corresponding to XI.
%
%          PP = SPLINAPP(X,Y,W)    returns the pp-form of the cubic spline
%                                  instead, for later use with  ppval, etc.
%
%          The greater the weight of a knot, the smaller its residual.

%          R. Marbach Jan.31,1990
%          this file is essentially a copy of:
%               Carl de Boor 7-2-86
%       	Copyright (c) 1985-1987 by the MathWorks, Inc.
%	        Revised 11-24-87 JNL
%          Especially, the same PP-format is used to provide compatibility
%          with M-files PPVAL, UNMKPP and MKPP.

% Generate the cubic spline approximant in pp form, depending on
% the number of data points. (using the natural cubic spline condition).
%
% The algorithm has been taken from: 
%    Helmut SpÑth, Algorithmen fÅr elementare Ausgleichsmodelle,
%    Oldenbourg, MÅnchen 1973
% and has been verified with numerical data given there!

n=length(x); [x,ind]=sort(x); x=x(:);
y=y(ind);y=y(:);
w=w(ind);w=w(:);   
output=[];
if n<2,
   fprintf('There should be at least two data points!\n')
elseif all(diff(x))==0,
   fprintf('The data abscissae should be distinct!\n')
elseif n~=length(y),
   fprintf('Abscissa and ordinate vector should be of the same length!\n')
elseif n~=length(w),
   fprintf('Weigth vector should be of the same length as data vectors!\n')
else   

   if (n==2), % the interpolant is a straight line (no approximation)
      pp=mkpp(x',[diff(y)./diff(x) y(1)]);
   elseif (n==3), % the interpolant is a parabola (no approximation)
      y(2:3)=diff(y)./diff(x);
      y(3)=(y(3)-y(2))/(x(3)-x(1));
      y(2)=y(2)-y(3)*(x(2)-x(1));
      pp = mkpp([x(1),x(3)],y([3 2 1])');
   else 
      % set up the linear system for solving for the 2'cd deriv. der2 at xi.
      Dy=[diff(y);0];
        Dym1=[0;Dy(1:n-1)];
      Dx=[diff(x);0];
        Dxm1=[0;Dx(1:n-1)];
      IDx=[diff(x).\1;0]; 
        IDxm2=[0;0;IDx(1:n-2)];
        IDxm1=[0;  IDx(1:n-1)];
        IDxp1=[IDx(2:n);0];
      Iw=w.\1;
      Iwm1=[0;Iw(1:n-1)];
      Iwp1=[Iw(2:n);0];

      % Hauptdiagonale
      hlp=2*(Dxm1+Dx) +6*Iwm1.*IDxm1.*IDxm1 + 6*Iw.*(IDxm1+IDx).*(IDxm1+IDx) ...
          +6*Iwp1.*IDx.*IDx;
      M=diag(hlp(2:n-1));
      % obere erste Nebendiagonale
      hlp=Dx -6*Iw.*IDx.*(IDxm1+IDx) -6*Iwp1.*IDx.*(IDx+IDxp1);
      M=M + diag(hlp(2:n-2),1);
      % obere zweite Nebendiagonale
      hlp=6*Iwp1.*IDx.*IDxp1;
      M=M + diag(hlp(2:n-3),2);
      % untere erste Nebendiagonale
      hlp=Dxm1 -6*Iwm1.*IDxm1.*(IDxm2+IDxm1) -6*Iw.*IDxm1.*(IDxm1+IDx);
      M=M + diag(hlp(3:n-1),-1);
      % untere zweite Nebendiagonale
      hlp=6*Iwm1.*IDxm2.*IDxm1;
      M=M + diag(hlp(4:n-1),-2);

      % Solving for the 2'cd derivatives of the spline ('der2') at xi.
      hlp=6*(Dy.*IDx - Dym1.*IDxm1);
      der2=M\hlp(2:n-1);
      der2=[0;der2;0]; % natural spline

      % Solving for spline function values ('der0') at xi.
      der2m1=[0;der2(1:n-1)];
      der2p1=[der2(2:n);0];
      der0= y - Iw.* ( IDxm1.*der2m1 - (IDxm1+IDx).*der2 + IDx.*der2p1 );

      % Solving for the spline coefficients
      Dder0=[diff(der0);0];
      a=(6\1)*IDx.*(der2p1-der2);               a=a(1:n-1);
      b=0.5*der2;                               b=b(1:n-1);
      c=Dder0.*IDx - (6\1)*Dx.*(der2p1+2*der2); c=c(1:n-1);
      d=der0;                                   d=d(1:n-1);
      coefs=[a,b,c,d];
      pp=mkpp(x',coefs);
   end
   if nargin==3,
      output=pp;
   else
      output=ppval(pp,xx);
   end
end
