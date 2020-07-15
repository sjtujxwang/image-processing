A=imread('coins.png');
%strel 用来创建形态学结构元素
%translate（SE，[y x]）在原有结构元素SE上进行x和y方向的平移
se=translate(strel(1), [120 90]);
%形态学膨胀
B=imdilate(A,se);
[height,width,dim]=size(A);
%定义水平变换矩阵
%获取tform结构
tform = affine2d([-1 0 0;0 1 0;width 0 1]);
%求水平变换imwarp
C=imwarp(A,tform,'nearest');
D=imresize(A,2,'nearest');
E=imrotate(A,30,'nearest','crop')
figure;
subplot(1,5,1),imshow(A);
title('原图像')
subplot(1,5,2),imshow(B);
title('图像平移')
subplot(1,5,3),imshow(C);
title('图像对称')
subplot(1,5,4),imshow(D);
title('图像缩放')
subplot(1,5,5),imshow(E);
title('图像旋转')
figure;
imshow(A);
figure;
imshow(D);