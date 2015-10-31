#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "load_image.h"
#include "haar_features.h"

void compute_features(t_image *image)
{
  int findex = 0;
  unsigned long s1, s2, s3, s4;
  image->haar_results = fopen(strcat("haar_results", file_name(image->path)), "w");

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
          fprintf("%lu ", s1 - s2);
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
          fprintf("%lu ", s1 - s2 + s3);
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
          fprintf("%lu ", s1 - s2);
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
          fprintf("%lu ", s1 - s2 + s3);
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
          fprintf("%lu ", s1 - s2 - s3 + s4);
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

double feature_scaling(unsigned int width, char *featuretype, int i, int j, int w, int h, t_image *image)
{
  // mettre les div par 2 et 3 du ceil.. pas d'arrondi ?? à verifier
  double featureval = 0;
  unsigned long s1;
  unsigned long s2;
  unsigned long s3;
  unsigned long s4;
  if(strcmp(featuretype, "typea") == 0)
  {
    long a = (2 * w * h);
    i = ceil(i * width / 24);
    j = ceil(j * width / 24);
    h = ceil(h * width / 24);
    w = max_integer(ceil((1 + (2 * w * width)) / 24) / 2, width - j + 1, 1, 2);
    s1 = pixels_sum(image, i, j, w, h);
    s2 = pixels_sum(image, i, j + w, w, h);
    featureval = ((s1 - s2) * a) / (2 * w * h);
    return featureval;
  }
  if(strcmp(featuretype, "typeb") == 0)
  {
    long a = (3 * w * h);
    i = ceil(i * width / 24);
    j = ceil(j * width / 24);
    h = ceil(h * width / 24);
    w = max_integer(ceil((1 + (3 * w * width)) / 24) / 3,width - j + 1, 1, 3);
    s1 = pixels_sum(image, i, j, w, h);
    s2 = pixels_sum(image, i, j+w, w, h);
    s3 = pixels_sum(image, i, j+w+w, w, h);
    featureval = ((s1 - s2 + s3) * a) / (3 * w * h);
    return featureval;
  }
  if(strcmp(featuretype, "typec") == 0)
  {
    long a = (2 * w * h);
    i = ceil(i * width / 24);
    j = ceil(j * width / 24);
    w = ceil(w * width / 24);
    h = max_integer(ceil((1 + (2 * h * width)) / 24) / 2, width - i + 1, 1, 2);
    s1 = pixels_sum(image, i, j, w, h);
    s2 = pixels_sum(image, i + h, j, w, h);
    featureval = ((s1 - s2) * a) / (2 * w * h);
  }
  if(strcmp(featuretype, "typed") == 0)
  {
    long a = (3 * w * h);
    i = ceil(i * width / 24);
    j = ceil(j * width / 24);
    w = ceil(w * width / 24);
    h = max_integer(ceil((1 + (3 * h * width)) / 24) / 3, width - i + 1, 1, 3);
    s1 = pixels_sum(image, i, j, w, h);
    s2 = pixels_sum(image, i+h, j, w, h);
    s3 = pixels_sum(image, i+h+h, j, w, h);
    featureval = ((s1 - s2 + s3) * a) / (3 * w * h);
  }
  if(strcmp(featuretype, "typee") == 0)
  {
    long a = (4 * w * h);
    i = ceil(i * width / 24);
    j = ceil(j * width / 24);
    w = max_integer(ceil((1 + (2 * w * h)) / 24) / 2, width - j + 1, 1, 2);
    h = max_integer(ceil((1 + (2 * h * width)) / 24) / 2, width - i + 1, 1, 2);
    s1 = pixels_sum(image, i, j, w, h);
    s2 = pixels_sum(image, i+h, j, w, h);
    s3 = pixels_sum(image, i, j+w, w, h);
    s4 = pixels_sum(image, i+h,j+w,w,h);
    featureval = ((s1 - s2 - s3 + s4) * a) / 4 * h * w;
  }
  return featureval;
}

int max_integer(double a, double b, int scale1, int scale2)
{
  int k = 0;
  while(((scale1 * k) <= a && (scale2 * k) <= b))
  {
    k++;
  }
  if(k >= 0) k--;
  return k;
}

