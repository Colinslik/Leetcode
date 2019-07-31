class Solution {
public:
    string intToRoman(int num) {
        string rome;
        while (num >= 1000) {
            num -= 1000;
            rome += "M";
        }
        if (num >= 900) {
            num -= 900;
            rome += "CM";
        }
        while (num >= 500) {
            num -= 500;
            rome += "D";
        }
        if (num >= 400) {
            num -= 400;
            rome += "CD";
        }
        while (num >= 100) {
            num -= 100;
            rome += "C";
        }
        if (num >= 90) {
            num -= 90;
            rome += "XC";
        }
        while (num >= 50) {
            num -= 50;
            rome += "L";
        }
        if (num >= 40) {
            num -= 40;
            rome += "XL";
        }
        while (num >= 10) {
            num -= 10;
            rome += "X";
        }
        if (num >= 9) {
            num -= 9;
            rome += "IX";
        }
        while (num >= 5) {
            num -= 5;
            rome += "V";
        }
        if (num >= 4) {
            num -= 4;
            rome += "IV";
        }
        while (num > 0) {
            num --;
            rome += "I";
        }
        return rome;
    }
};
