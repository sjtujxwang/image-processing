load mri
%imshow(D(:,:,7),map);
%montage(D,map);%在一个窗口显示
mov=immovie(D,map);%将多张图像转换为电影
colormap(map);%设定颜色表
movie(mov);%播放电影