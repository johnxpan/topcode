/********************************************************/
/* This is the code from K&R that does not belong to any*/
/* specific groups, it is general practice              */
/********************************************************/

// Calculate power of m**n
int power(int base, int n) {
   int result = 1;
   int i= 0;

   for(i=0; i<n; i++) {
      result *= base;
   }
   return result;
}

//check if a number x is the power of N
// if x%N == 0, keep extract N from x: x=x/N
// if the residue ==1, it is true, otherwise false
int isPowerOf3(int x) {  //2, 3, 4 is the same
   if(x==0) // x ==0 will cause infinite loop
      return 0; // false
   if(x%3 == 0) {
      x = x/3;
   }
   return x==1; 
}
// o(log3(N))
int isPowerOf3v2(int x) {
   if(x==0) 
     return 0;
   if(x%9 == 0) {
      x=x/9;
   }
   return (x==1 || x==3);//6 won't work
}
// O(log9(N)
//space for speed
// assume 32bit machine, it will 3**19 ~ 2**32
// for 32 bit machine, there are less than 32 of 3 power
int ap3[19]= { 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
int fastPower3(int n) {
   int i;
   for(i=0; i< 19; i++){
      if(n==ap3[i]) {
         return 1;
      }
   }
   return 0;
}




// calculate string length
int strlen(char s[]) {
   int i=0;
   while(s[i]!= '\0') {
      i++;
   }
   return i;
}

// return 1 if t occurs at the end of s, otherwise return 0
void strend(char *s, char *t) {
   char *bs =s;
   char *bt =t;

   for(; *s; s++) // end of string s;
        ;
   for(; *t; t++) // end of string t;
        ;
   for(; *s==*t; s--, t--) {
       if(t==bt || s==bt)
           break; // at the beginning of a str 
   if(*s==*t && t==bt && *s!='\0)
        return 1;
   else
        return 0;
}
//turn an char to lower case
int lower (int c) {
   if(c >= 'A' && c <='Z') {
      return c + 'a' -'A';
   }
}

int lower2 (int c) {
   return c>='A' && c<='Z' ? c+'a'-'A' : c;
}

// various string copy 
//assume to[] is big enough
void copy(char to[], char from[]) {
  int i=0;
  while((to[i]=from[i])!='\0') {
     i++ ;
  }
}

// delete all c from s
void squeeze (char s[], int c) {
   int i, j;

   for(i=j=0; s[i] !='\0'; i++) {
       if(s[i]!=c) {
          s[j++]=s[i];
       }
   }
   s[j] = '\0';
}
// delete each char in s1 which is also in s2
void squeeze(char s1[]; char s2[]) {
{
   int i,j,k;

   for(i=k=0; s[i]!='\0'; i++) {
      for(j=0; s2[j]!='\0' && s2[j] !=s1[i]; j++)
         ;
      if(s2[j] =='\0')
         s1[k++] - s1[i]; // keep the unfound char only
   }
   s1[k] = '\0';
}

// return the first location in s1 where any char from s2 occurs
int any(char s1[], char s2[]) {
   int i, j;
   for(i=0; s1[i]!='\0'; i++) {
      for(j=0;s2[j] != '\0'; j++)
          if(s1[i] == s2[j])
               return i;
   }
   return -1;
}

// array vs integer conversion
int atoi(char s[]) {
   int result=0;
   int i;

   // c>='0' && c<='9' same as isdigit(c) 
   for(i=0; s[i]>'0' && s[i]<'9'; i++){
       result = result *10 + s[i]-'0';
   }
   return result;
}

//convert n to chars in s
// use reverse()
void itoa(int n, char s[]) {
   int i;

   for(i=0; n!=0; i++) {
      s[i]=n%10+'0';
      n=n/10;
   }
   s[++i]='\0';
   reverse(s);
}

// recursive itoa
void itoa2(int n, char s[]) {
   //need to keep the value between function call
   static int i;

   if(n/10)  // keep calling till reach the foremost digit 
      itoa2(n/10, s);
   else {
      i=0; // base case
      if(n<0)
         s[i++]= '-';
   }
   s[i++] = abs(n)%10+'0';
   // each level add a '\0', but next level overwrite it, except the last
   s[i] = '\0';
}


// return length of string s
int strlen(char *s) {
  int n=0;

  for(n =0; *s!='\0'; s++) {
       n++;
  return n;
}

int strlen2(char *s) {
   char *p=s;

   while(*p != '\0')
      p++;

   return p-s;
}
//copy t to s
// last '\0' is failure
void strcpy(char *s, char *t) {
    while (*s++ = *t++)
       ;
}
// return < 0 if s< t, 0 if s==t, > 0 if s>t
// if t is smaller than s, t will reach \0 before s, so it will exit
int strcmp(char *s, char *t) {
  while(*s++ == *t++)
      if(*s=='\0')
        return 0;
  return *s - *t;
}

// concat string t to the end of s, s must be big enough
void strcat(char s[], char t[]) {
   int i=0;
   int j=0;
   while (s[i]!='\0') {
      i++;
   }

   while(t[j]!='\0') {
      s[i++]=t[j++];
   }
   s[i] ='\0';
}

void strcat2(char *s, char *t) {
    while(*s) // do not use while(*s++), it will pass the \0 char
       s++;
    while(*s++ = *t++)
       ;
}

//library functions of strncpy, strncat, and strncmp
// copy n char from t to s, if t is shorter then s
// fill the reset with '\0'
void strncpy( char *s, char *t, int n) {
  while(*t && n-->0)
    *s++ = *t++;

  while( n-- > 0)
     *s++='\0';  // fill the rest of s with empty \0
}

void strncmp( char *s, char *t, int n) {
  for(; *s==*t; s++, t++) {
     if(*s=='\0' || --n <=0)
        return 0;
  }
  return *s-*t;
}

void strncat(char *s, char *t, int n) {
   strncpy(s+strlen, t, n);
}

//return the rightmost occurance  of t in s, return -1 if there is none
int strindex(char s[], char t[]) {
   int i,j, k, pos;
   pos=-1;

   for(i=0; s[i] != '\0'; i++) {
      for(j=i, k=0; t[k]!='\0' && s[j] == t[k]; j++, k++)
         ;
      if(k>0; && t[k] == '\0')
         pos = i;
   }
   return pos;
}

int strindex2( char s[], char t[]) {
   int i, j, k;
   for(i = strlen(s) -strlen(t); i>=0; i--) {
      for(j=i; k=0; t[k]!='\0' && s[j] == t[k]; j++, k++)
          ;
      if(k>0 && t[k]=='\0')
          return i;
   }
   return -1;
}

#define YES 1
#define NO 0
// convert hex digital string like 0xa45d to a integer
// in array, 0x is the first two char!!!
int htoi(char s[]) {
   int i, n;
   int hexdigit, index;

   i=0;
   if(s[i]=='0') { // skip optional 0x or 0X
      i++;
      if(s[i] == 'x' || s[i] == 'X')
         i++;
   }

   n=0;
   for (; index==YES; ++i) {
      if(s[i] >= '0' && s[i] <='9')
        hexdigit= s[i]-'0';
      else if (s[i] >='a' && s[i]<='f')
        hexdigit= s[i]-'a'+10;
      else if (s[i] >='A' && s[i]<='F')
        hexdigit=s[i] - 'A'+10;
      else
        index = NO; /* not a valid hex digit */
      if(index==Yes)
        n=16*n+ hexdigit;
   }
   return n;
}




// git n bits from position p
unsigned getbits(unsigned x, int p, int n) {
   return (x>>(p+1-n) & ~(~0<<n);
}

//set n bits of x at position p with bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y) {
   return x & ~(~(~0<<n) <<(p+1-n)) |
          (y & ~(~0<<n)) <<(p+1-n);
}
// invert the n bits of x that begin at position p */
unsigned invert(unsigned x, int p, int n) {
   return  x^(~(~0<<n)<<(p+1-n));
}

//compute the word length of the machine
int wordlength (void) {
  int i;
  unsigned v = (unsigned)~0;
  for(i=1; (v = v>>1) > 0; i++)
    ;
  return i;
}



int bitCount (unsigned x) {
  int b=0;
  for (b=0; x!=0; x>>1) {
    if(x&01)
       b++;
  }
  return b;
}

//smart way 
int bitCount2(unsigned x) {
  int b =0;

  for(b=0; x!=0; x&=(x-1))
    b++;
  }
  return b;
}

// memory map
// fastest but consume a lot of memory
// assume 16 bit integer
int b[1024*64] = {0,1,1,2 ....};
int bitCount3(unsigned x) {
  return b[x];
}

//reverse string in place
void reverse (char s[]) {
   int i=j=0;

   while(s[j] != '\0') {
      j++;
   }
   j--; // back off one element

   while (i < j) {
      char temp =s[i];
      s[i]=s[j];
      s[j]=temp;
      i++, j--;
   }
}

void reverse2( char s[]) {
   int i=0;
   int j= strlen(s) -1;

   for(i=0, j=strlen(s)-1; i<j; i++, j--) {
       char temp = s[i];
       s[i] = s[j];
       s[j] = temp;
   }
}

// recursive version of reverse
// to call it, use reverse(s, 0, strlen(s))
void reverser (char s[], int i, int len) {
  int j;
  // we keep the len unchanged, but update j
  j = len-(i+1);
  if(i< j) {
    char c= s[i];
    s[i]=s[j];
    s[j]=c;
    reverser(s, ++i, len);
}

// define a macro to swap two argument of type t
#define swap(t, x, y) { t temp; temp=x; x=y; y=temp; }

/* Returns true if the machine is little-endian, false if the machine is big-endian */
bool endianness(){
    int   testNum;
    char *ptr;
    testNum = 1;
    ptr = (char *) &testNum;
    return (*ptr); /* Returns the byte at the lowest address */
}
 
//You can also use the Union to decide the big/little endian Returns true if the machine is little-endian, false if the machine is big-endian*/
bool endianness(){
    union {
        int theInteger;
        char singleByte;
    } endianTest;
 
    endianTest.theInteger = 1;
    return endianTest.singleByte;
}





