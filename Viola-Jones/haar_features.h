#ifndef HAAR_FEATURES_H_
# define HAAR_FEATURES_H_

typedef struct s_haar t_haar;
typedef struct s_feature t_feature;

void compute_features(t_image *image, FILE *file);
long som1(size_t i, size_t j, size_t w, size_t h, t_image *image);
void init_haar(t_haar *haar);
void init_feature(t_feature *ft);

struct s_haar
{
    t_feature *typea;
    t_feature *typeb;
    t_feature *typec;
    t_feature *typed;
    t_feature *typee;
};

struct s_feature
{
    long result;
};

#endif /* !HAAR_FEATURES_H_ */
