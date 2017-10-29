//
//  dataset.c
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/23/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#include "dataset.h"


// Generates 'random' data for the dataset
void generateElements(int totalDatapoints, double* dataset) {
    srand(1);
    
    for(int i = 0; i < totalDatapoints; i++)
    {
        dataset[i] = (double)(rand() % 100);
    }
}


