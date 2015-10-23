#include "load_image.h"
#include "haar_features.h"
#include <stdio.h>
#include <stdlib.h>

void compute_features(t_image *image, FILE *file)
{
  int findex = 0;
  unsigned long s1, s2, s3, s4;

  for(int i = 0; i < image->bw->h; i++)
  {
    for(int j = 0; j < image->bw->w; j++)
    {
      /* feature type a */
      for(int h = 1; i + h - 1 < image->bw->h; h++)
      {
        for(int w = 1; j + (2 * w) - 1 < image->bw->w; w++)
        {
          s1 = pixels_sum(image, i, j, w, h);
          s2 = pixels_sum(image, i, j + w, w, h);
          findex++;
          /* écrire (1, i, j, w, h):s1 - s2 */
        }
      }
      /* feature type b */
      for(int h = 1; i+h-1 < image->bw->h; h++)
      {
        for(int w = 1; j+(3*w)-1<image->bw->w; w++)
        {
          s1 = pixels_sum(image, i, j, w, h);
          s2 = pixels_sum(image, i, j+w, w, h);
          s3 = pixels_sum(image, i, j+w+w, w, h);
          findex++;
          /* écrire (2,i,j,w,h):S1 - S2 + S3 */
        }
      }
      /* feature type c */
      for(int h = 1; i+(2*h)-1 < image->bw->h; h++)
      {
        for(int w = 1; j+w-1<image->bw->w; w++)
        {
          s1 = pixels_sum(image, i, j, w, h);
          s2 = pixels_sum(image, i + h, j, w, h);
          findex++;
          /* écrire (3,i,j,w,h):S1 - S2 */
        }
      }
      /* feature type d */
      for(int h = 1; i+(3*h)-1 < image->bw->h; h++)
      {
        for(int w = 1; j+w-1<image->bw->w; w++)
        {
          s1 = pixels_sum(image, i, j, w, h);
          s2 = pixels_sum(image, i+h, j, w, h);
          s3 = pixels_sum(image, i+h+h, j, w, h);
          findex++;
          /* écrire (4,i,j,w,h):S1 - S2 + S3 */
        }
      }
      /* feature type e */
      for(int h = 1; i+(2*h)-1 < image->bw->h; h++)
      {
        for(int w = 1; j+(2*w)-1<image->bw->w; w++)
        {
          s1 = pixels_sum(image, i, j, w, h);
          s2 = pixels_sum(image, i+h, j, w, h);
          s3 = pixels_sum(image, i, j+w, w, h);
          s4 = pixels_sum(image, i+h,j+w,w,h);
          findex++;
          /* écrire (5,i,j,w,h):S1 - S2 - S3 + S4 */
        }
      }
    }
  }
}

unsigned long pixels_sum(t_image *image, unsigned x, unsigned y, unsigned width, unsigned height)
{
  unsigned long sum;

  sum = image->integral[y + height - 1][x + width - 1];
  if (y > 0 && x > 0)
    sum += image->integral[y - 1][x - 1];
  if (y > 0)
    sum -= image->integral[y - 1][x + width - 1];
  if (x > 0)
    sum -= image->integral[y + height - 1][x - 1];
  return sum;
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
