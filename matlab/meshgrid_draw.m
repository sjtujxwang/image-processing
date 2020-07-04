%生成二维高斯函数并用meshgrid画出来
u=[-10:0.1:10];
v=[-10:0.1:10];
[U,V]=meshgrid(u,v);
%使用meshgrig将数组生成同阶网络
H=exp(-(U.^2+V.^2)./18);
mesh(u,v,H);