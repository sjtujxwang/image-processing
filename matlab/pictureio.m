load mri
%imshow(D(:,:,7),map);
%montage(D,map);%��һ��������ʾ
mov=immovie(D,map);%������ͼ��ת��Ϊ��Ӱ
colormap(map);%�趨��ɫ��
movie(mov);%���ŵ�Ӱ