//
//  dataset.h
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/23/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#ifndef dataset_h
#define dataset_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Base Data Structure */
void generate_elements(int totalCoordinates, double* dataset);
double* get_element_at_index(int dim, int index,  double* dataset);
void set_element_at_index(int dim, int dataIndex, double* element, double* data);
void get_cluster_centroid_element(int dim, int cluster, double* dataElement, double** cluster_centroid);
void set_cluster_centroid(int dim, int cluster, double* data, double** cluster_centroid);

/* Calculate functions */
double distance(double* element1, double* element2, int dim);
void centroid(int dim, double* dataset, int numElements, double* cluster_centroid);

#endif /* dataset_h */
