bool isUgly(int num) {
    if(num==0) return 0;
    for(;num%2==0;num/=2);
    for(;num%3==0;num/=3);
    for(;num%5==0;num/=5);
    return (num==1)?1:0;
}
