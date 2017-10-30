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
void generateElements(int totalCoordinates, double* dataset);
double* getElementAtIndex(int dim, int index,  double* dataset);
double* generateRandomElement(double** boundary);
void getClusterCentroidElement(int dim, int cluster, double* dataElement, double** cluster_centroid);
void setClusterCentroid(int dim, int cluster, double* data, double** cluster_centroid);

/* Calculate functions */
double distance(double* element1, double* element2, int dim);
double meanOfDimension(int dim, double* dataset);
double* centroid(int dim, double* dataset);

#endif /* dataset_h */
