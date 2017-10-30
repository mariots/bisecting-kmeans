//
//  dataset.c
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/23/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#include "dataset.h"

// Generates 'random' data for the dataset
void generateElements(int totalCoordinates, double* dataset) {
    srand(1);
    
    for(int i = 0; i < totalCoordinates; i++)
    {
        dataset[i] = (double)(rand() % 100);
    }
}

// Returns element at specified index
double* getElementAtIndex(int dim, int elementIndex, double* data) {
    return &data[dim*elementIndex]; // [dim * elementIndex]: will give the starting index of the element requested
}
