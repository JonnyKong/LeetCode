//
//  223. Rectangle Area.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    
    int size = (H - F) * (G - E) + (D - B) * (C - A);
    
    if(E > C || B > H || A > G || F > D) return size;
    
    int overlap = (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
    return size - overlap;
    
}