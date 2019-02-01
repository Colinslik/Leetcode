class Solution {
public:
    int getSum(int a, int b) {
         while(b){
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
/*        temp_a = a;
        temp_b = b;
        for(bits=0; temp_a!=0 || temp_b != 0 || carry != 0; bits++)
        {
cout << "temp_a: " <<temp_a << "  temp_b: " <<temp_b <<endl;
            bit_a = (a >> bits) & bitmask;
            bit_b = (b >> bits) & bitmask;
            bitnumber = bit_a ^ bit_b;
cout <<endl<< "bit_a: " <<bit_a << "  bit_b: " <<bit_b << "  bitnumber: " <<bitnumber << "  carry: " <<carry <<endl;
            if(temp_a==0 && temp_b == 0 && carry == 0) sum = sum | (bitnumber ^ carry);
            else sum = (sum << 1) | (bitnumber ^ carry);
cout <<endl << "sum: " <<sum << "  (bitnumber ^ carry): " <<(bitnumber ^ carry)  <<endl;
            if( (carry && bit_a) || (carry && bit_b) || (bit_a && bit_b) ) carry = 1;
            else carry = 0;
cout <<endl<< "AFTER" << "  carry: " <<carry <<endl;
            temp_a = (a >> bits);
            temp_b = (b >> bits);
cout <<endl << "AFTER  "<< "temp_a: " <<temp_a << "  temp_b: " <<temp_b <<"  bits: " <<bits<<endl<<endl<<endl<<endl;
        }
cout <<endl<<"  bits: " <<bits <<endl;
        for(int i=0;i < bits; i++)
        {
            inv_sum = (inv_sum << 1) | ((sum >> i) & bitmask);
        }
        return inv_sum;
    }
private:
    unsigned temp_a,temp_b;
    int bitmask = 0x1;
    int bit_a;
    int bit_b;
    int bitnumber = 0;
    int sum = 0;
    int inv_sum = 0;
    int carry = 0;
    int bits;*/
};
