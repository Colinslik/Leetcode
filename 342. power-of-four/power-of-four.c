bool isPowerOfFour(int num) {
    double base = log(num);
    double divider = log(4);
    int coefficient;
    char temp[10];
    base /= divider;
    sprintf(temp,"%.9f",base);
    base = atof(temp);
    /*sprintf(temp,"%.7f",log(n));
    base = atof(temp);
    sprintf(temp,"%.7f",log(3));
    divider = atof(temp);
    base /= divider;*/
    coefficient = (int)base;
    //printf("base:%f divider:%f\n",base,divider);
    //printf("%.20f   %d\n",base,coefficient);
    return (base == coefficient)?1:0;
}
