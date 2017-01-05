int binary_search(int A[], int key, int imin, int imax)
{
  // continue searching while [imin,imax] is not empty
  while (imax >= imin)
    {
      // calculate the midpoint for roughly equal partition
      int imid = midpoint(imin, imax);
 
      // determine which subarray to search
      if (A[imid] < key)
        // change min index to search upper subarray
        imin = imid + 1;
      else if (A[imid] > key)
        // change max index to search lower subarray
        imax = imid - 1;
      else
        // key found at index imid
        return imid;
    }
  // key not found
  return KEY_NOT_FOUND;
}
