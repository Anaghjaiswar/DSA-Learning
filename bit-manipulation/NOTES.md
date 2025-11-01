<!-- decimal to binary -->

- convert 7 base to 10 to binary 

divide by 2 and keep dividing  -- ans: 111

similiarly if we need to convert 13 to binary it will 1101

<!-- binary to decimal -->

(1101) - > 13 

how ?
you start from right to left in binary numeber and indexing goes from 0 to last 

so it's like `(1 * 2^0) + (0 * 2^1) + (1 * 2^2) + (1 * 2^3) ==> 1 + 0 + 4 + 8 =  13` 

### can i write a function the takes a decimal number and give it's binary equivalent ?

i will be returning a string.

bash```

TC = log2(n)
SC = log2(n)

str ConvertToBinary(int n){
    str result = "";
    while(n ! = 1){

        if (n % 2 == 1) result += "1";
        else result += "0"
        n= n/2;   
    }
    // but you want it in reverse form
    reverse(result);
}

```


### a function which converts binary to decimal equivalents

bash```

int convertToDecimal(string x){
    int len = x.size();

    int result = 0;
    int PowerOfTwo = 1; // 2^0 == 1

    //reverse for loop
    for(i = len -1; i >= 0; i--){
        if(x[i] == 1) //beacuase multipying with zero doesn't make sense
        {
            num = num + PowerOfTwo;
        }
        powerOfTwo *= 2; // har for loop ke saath hame 2 ki power badhayenge kabhi bhi ham bade bade numbers like 2^5 , 2^ 10 pura calculate nahi karenge
    }
    return num;
}
```



<!-- part 2 -->
if i say x = 13 , the computer doesn't stores stores , it only understands 0 or 1 
so 13 is first converted to its binary equivalent
so does the computer itself store 1101 to the base 2?

no

int means 32 bits, so it like 00000000000000000000000000001101 this is stored 28 bits are zero and 4 bits are 1101

and when you do  ` print(x) ` it prints 13 , how ? --> reverse conversion happens

-> long long = 64 bits


1's complement
------------------------------

13 == 1101 (converted to binary)

now flip bits `1 -> 0; 0 -> 1`

so it becomes 0010.

2's complement
------------------------------

convert to 1's complemnet and then add 1 to it .

0010 + 1 => 0011 (this is the 2's complement)

## operators

- And ( & )

all true - > true
1 false -> false

eg = if you write x = 13 & 7 
in background what happend 13 is converted to binary 1101 and 7 is 111

 1101
+0111
=0101 (and operation result)

- OR ( | )

1 true - > true
all false -> false

x = 13 | 7

 1101
 0111
=1111 (or result)


- XOR ( ^ )

no. of 1's = odd --> 1
no. of 1's = even --> 0

x  13 ^ 7

 1101
  111
=1010 (XOR reult)

<!-- what if 0 and 0 , so there are zero 1's means zero ones means even so 0 that's how the rest of 28 or 29 bits are still zero-->

- RIGHT SHIFT ( >> )

if x = 13 >> 1

              mnip
13 represents 1101 in binary 

right shift means the pth psotion will go away and 0 next to it will take pth position
1 at the nth position will take ith position. 
1 at the mth position will take nth position.
and 0 from occupy mth position

so it becomes 0110 => 6

if x = 13 >> 2

13 == 1101

so x = 0011 (two times right shift) => 3

simple formula 
`x >> k = (x/2^k)`


- LEFT SHIFT ( << )

jsut oppostie of right shift , it shifts to left
``` 
if x = 13 << 1
     i
13 = 00000000000000000000000000001101
ith position 0 vanishes and appears at right
13 << 1 = 00000000000000000000000000011010 : 26
```


- NOT ( ~ )

funda --> flip bits --> check -ve --> take 2's complement if true  else stop

x = ~5

00000...00101
flip
11111...11010
it's negative convert to 2's complement == 1's complement + 1

1 00000...00101
             +1
1 00000...00110 = -6


ok now what if x = ~ (-6)

so computer will first store -6 using 1's com. + 1= 1 111111..11010

no flip it
0 000000..00101
since first bit is zero it is non negative so you stop 



a few important notes
------------------------

if x = 13 computer store 00....001101
but if x = -13 ,how does computer uses it 
so the 31st bit is reserved for sign 
+ve -> 0;
-ve -> 1;
so x = -13

and how to calculate?
write plain psoitiove numebr 00000....00001101
computer converts it into 2's complemt

so 1's complement is 11111......11110010
now add 1to this 
1111...1110011
i
the ith bit is 1 which will tell you it is a negative number 


Ques : what the largest numebr a int data type can store? 
last bit is reserved with sign 
if rest all fill with 1's so it's technically `2^30 + 2^29 + 2^28 + 2^27 + 2^26.....2^0 = 2^31 -1 Or INT_MAX` 
that was a geometric series 


and
What Happens with Sign Bit = 1
If the MSB is 1, the number is negative. In two's complement:

10000000000000000000000000000000 = -2^31

So the range of signed int is:

`-2^31 to 2^31−1`


