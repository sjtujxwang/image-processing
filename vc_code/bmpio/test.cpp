#include "/home/wjx/CImg/CImg.h"
#include <string>
using namespace std;
using namespace cimg_library;
int main()
{
   CImg<unsigned char> SrcImg;
   SrcImg.load_bmp("1.bmp");
   SrcImg.display("scene");
   return 0;
}