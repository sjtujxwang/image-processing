A=imread('coins.png');
%strel ����������̬ѧ�ṹԪ��
%translate��SE��[y x]����ԭ�нṹԪ��SE�Ͻ���x��y�����ƽ��
se=translate(strel(1), [120 90]);
%��̬ѧ����
B=imdilate(A,se);
[height,width,dim]=size(A);
%����ˮƽ�任����
%��ȡtform�ṹ
tform = affine2d([-1 0 0;0 1 0;width 0 1]);
%��ˮƽ�任imwarp
C=imwarp(A,tform,'nearest');
D=imresize(A,2,'nearest');
E=imrotate(A,30,'nearest','crop')
figure;
subplot(1,5,1),imshow(A);
title('ԭͼ��')
subplot(1,5,2),imshow(B);
title('ͼ��ƽ��')
subplot(1,5,3),imshow(C);
title('ͼ��Գ�')
subplot(1,5,4),imshow(D);
title('ͼ������')
subplot(1,5,5),imshow(E);
title('ͼ����ת')
figure;
imshow(A);
figure;
imshow(D);