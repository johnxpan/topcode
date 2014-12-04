// The power related questions is often asked in interview (akamai, google, etc)
// It is popular because it is quite extendable
int isPowerOfTwo (unsinged int x) {
   if (x==0) // special case 0
      return false;
   
   while(x%2 == 0) {
      x = x/2; // strip 2 from the number
   }  
   return x==1;  // number like 3,5,7  will not be 1 after stripping all 2
}
  
  
  
  
