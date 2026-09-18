#include "exploreNewMagClasterAndAddToOpenArr.cpp"
//=>get_HMagistral

float ThData::get_GMagistral(MagistralClaster *mcFather, MagistralClaster *son)
{
   return mcFather->up == son ||
                  mcFather->left == son ||
                  mcFather->right == son ||
                  mcFather->down == son
              ? 10
              : 14;
}