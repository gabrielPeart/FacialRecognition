#include "load_image.h"
#include "haar_features.h"
#include <stdio.h>
#include <stdlib.h>

void compute_features(t_image *image, FILE *file)
{
  int findex = 0;
  long s1;
  long s2;
  long s3;
  long s4;
  for(size_t i = 0; i < image->bw->h; i++)
  {
    for(size_t j = 0; j < image->bw->w; j++)
    {
      /* feature type a */
      for(size_t h = 1; i + h - 1 < image->bw->h; h++)
      {
        for(size_t w = 1; j + (2 * w) - 1 < image->bw->w; w++)
        {
          s1 = som1(i, j, w, h, image);
          s2 = som1(i, j+w, w, h, image);
          findex++;
          /* écrire (1, i, j, w, h):s1 - s2 */
        }
      }
      /* feature type b */
      for(size_t h = 1; i+h-1 < image->bw->h; h++)
      {
        for(size_t w = 1; j+(3*w)-1<image->bw->w; w++)
        {
          s1 = som1(i, j, w, h, image);
          s2 = som1(i, j+w, w, h, image);
          s3 = som1(i, j+w+w, w, h, image);
          findex++;
          /* écrire (2,i,j,w,h):S1 - S2 + S3 */
        }
      }
      /* feature type c */
      for(size_t h = 1; i+(2*h)-1 < image->bw->h; h++)
      {
        for(size_t w = 1; j+w-1<image->bw->w; w++)
        {
          s1 = som1(i, j, w, h, image);
          s2 = som1(i+h, j, w, h, image);
          findex++;
          /* écrire (3,i,j,w,h):S1 - S2 */
        }
      }
      /* feature type d */
      for(size_t h = 1; i+(3*h)-1 < image->bw->h; h++)
      {
        for(size_t w = 1; j+w-1<image->bw->w; w++)
        {
          s1 = som1(i, j, w, h, image);
          s2 = som1(i+h, j, w, h, image);
          s3 = som1(i+h+h, j, w, h, image);
          findex++;
          /* écrire (4,i,j,w,h):S1 - S2 + S3 */
        }
      }
      /* feature type e */
      for(size_t h = 1; i+(2*h)-1 < image->bw->h; h++)
      {
        for(size_t w = 1; j+(2*w)-1<image->bw->w; w++)
        {
          s1 = som1(i, j, w, h, image);
          s2 = som1(i+h, j, w, h, image);
          s3 = som1(i, j+w, w, h, image);
          s4 = som1(i+h,j+w,w,h,image);
          findex++;
          /* écrire (5,i,j,w,h):S1 - S2 - S3 + S4 */
        }
      }
    }
  }
  
}

long som1(size_t i, size_t j, size_t w, size_t h, t_image *image)
{
  long a;
  long b;
  long c;
  long d;
  long s1;
  if(i-1 > 0 && j-1>0)
  {
    a = image->integral[i-1][j-1];
    b = image->integral[i-1][j+w-1];
    c = image->integral[i+h-1][j-1];
    d = image->integral[i+h-1][j+w-1];
    s1 = a + d - b - c;
  }
  else if(i-1 > 0)
  {
    a = 0;
    b = image->integral[i-1][j];
    c = 0;
    d = image->integral[i+h-1][j+w-1];
    s1 = d - b;
  }
  else if(j-1 > 0)
  {
    c = image->integral[i+h-1][j-1];
    d = image->integral[i+h-1][j+w-1];
    s1 = d - c;
  }
  else
  {
    s1 = image->integral[i+h-1][j+w-1];
  }
  return s1;
}
void init_haar(t_haar *haar)
{
  init_feature(haar->typea);
  init_feature(haar->typeb);
  init_feature(haar->typec);
  init_feature(haar->typed);
  init_feature(haar->typee);
}

void init_feature(t_feature *ft)
{
  ft->result = 0;
}
