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

/* Base Data Structure */
void generateElements(int dim, double* dataset);
void setElementAtIndex(int dim, int index, double* dataset);
double* getElementAtIndex(int dim, int index,  double* dataset);

/* Calculate functions */
double distance(double* element1, double* element2, int dim);
double meanOfDimension(int dim, double* dataset);
double* centroid(int dim, double* dataset);


#endif /* dataset_h */
