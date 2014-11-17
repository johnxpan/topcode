//quick sort for java
static void sort(Object[] v, int left, int right, Cmp cmp)
{
   int i, last;
   if(left>right) // nothing to do
      return;
      
    swap(v, left, rand(left, right)); // move pivot elem
    last = left;
    for(i=left+1; i<=right; i++) // partition
       if(cmp.cmp(v[i], v[left]) < 0) 
          swap(v, ++last, i);
    swap(v, left, last);
    sort(v, left, last -1, cmp)
    sort(v, last+1, right, cmp);
}

static void swap(Object[] v, int i, int j) {
  Object temp = v[i];
  v[i]=v[j];
  v[j]=temp;
}

Static int rand(int left, int right) {
  return left+Math.abs(rgen.nextInt())%(right - left);
}
