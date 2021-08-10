class Solution {
public:
    string addStrings(string num1, string num2) 
    {
   
    /* approach: 
      => if numbers are 1000 and 500
          we add it by  1000
                         500 (+)
         answer will be 1500
      => if we reverse the numbers and left align the second number 
                    0001
                    005
        answer is   0051
      => now if we reverse this answer we get actual output = 1500
     
      01. we are going to use above approach and do reversing the two strings
      02. find maximum length of given two strings
      03. run loop until that size 
      04. if one string size ended we dont need to consider it for addition
      05. two important things to handle: 
        i) Quotient of sum => need to inserted in output string
        ii) carry got from sum => need to be added with next sum and added to outputs string
     06. reverse the output string
   */
                      
        int n = max(num1.size(),num2.size());
        int carry = 0;
        string output ="";
        int s1 = num1.size();
        int s2 = num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i =0;i<n;i++)
        {
          int sum =0;
            if(i<s1)
                 sum+= num1[i]-48;
            if(i<s2)
                sum+= num2[i]-48;
            sum+= carry;
            output += to_string(sum%10);
            carry = sum/10;
        }
        if(carry!=0)
            output += to_string(carry);
           reverse(output.begin(),output.end());
        return output;
    }
};
