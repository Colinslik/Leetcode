int min(int array[],int array_size)
{
    int i=1,minVal = array[0];
    for(;i<array_size;i++)
    {
      if(array[i]<minVal) minVal = array[i];
    }
    return minVal;
}

void update(int _ugly_list[],int _primes[],int _primes_copy[],int _prime_count[],int _primesize,int _minVal)
{
    int i=0;
    for(;i<_primesize;i++)
    {
        if(_minVal == _primes_copy[i])
        {
            _primes_copy[i] = _primes[i] * _ugly_list[++_prime_count[i]];
        }
    }
}

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int ugly_list[n];
    int primes_copy[primesSize];
    int prime_count[primesSize];
    memset(ugly_list,0,sizeof(int)*n);
    memset(prime_count,0,sizeof(int)*n);
    int minVal=0,count=1;
    ugly_list[0]=1;
    
    int i=0;
    for(;i<primesSize;i++)
    {
      primes_copy[i] = primes[i];
    }
    
    for(;count<n;count++)
    {
        minVal = min(primes_copy, primesSize);
        ugly_list[count] = minVal;
        update(ugly_list,primes,primes_copy,prime_count,primesSize,minVal);
    }
    return ugly_list[n-1];
}
