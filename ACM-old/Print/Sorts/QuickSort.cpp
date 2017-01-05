/**
 * Quicksort - rychle razeni (pivotem je prvni prvek), radi od nejvyssiho prvku
 * @param array pole k serazeni
 * @param left index prvniho prvku, na ktery muzeme sahnout (leva mez (vcetne))
 * @param right index prvniho prvku, na ktery nemuzeme sahnout (prava mez (bez))
 */
void quicksort(int array[], int left, int right){
    if(left < right){ 
        int boundary = left;
        for(int i = left + 1; i < right; i++){ 
            if(array[i] > array[left]){ 
                swap(array, i, ++boundary);
            }
        }
        swap(array, left, boundary);
        quicksort(array, left, boundary);
        quicksort(array, boundary + 1, right);
    }     
}

/**
 * Prohodi prvky v zadanem poli
 * @param array pole
 * @param left prvek 1
 * @param right prvek 2
 */
void swap(int array[], int left, int right){
    int tmp = array[right]; 
    array[right] = array[left];
    array[left] = tmp;         
}
