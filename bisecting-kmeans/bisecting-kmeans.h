//
//  bisecting-kmeans.h
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/30/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#ifndef bisecting_kmeans_h
#define bisecting_kmeans_h

#include <stdio.h>
#include "dataset.h"
#include "debug.h"

void bisecting_kmeans(int dim, int elements, int totalCoordinates, int clusters, double *data, int *cluster_size, int *cluster_start, double *cluster_radius, double **cluster_centroid, int *cluster_assign);


#endif /* bisecting_kmeans_h */
