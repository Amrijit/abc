#include <bits/stdc++.h>
#include"stackType.cpp"
using namespace std;

bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c)); //true when it's not a alphabet and letter
}


int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else
        return 0;
}

string infixToPostfix(string infix)
{
	infix = '(' + infix + ')' ;
	stackType <char> char_stack;
	string output;

	for (int i = 0; i <infix.size(); i++) {

        if (isdigit(infix[i])){
                int j=i;
                while(isdigit(infix[j])){
                        output =output + infix[j];
                        j++;
                    }
                    output=output+ " ";
                    i=j-1;
        }
        //output=output+" ";


		else if (infix[i] == '(')
			char_stack.push('(');


		else if (infix[i] == ')') {

			while (char_stack.Top() != '(' ){

                    char temp = char_stack.Top();
                    char_stack.pop();
                        if(char_stack.Top()=='(')
                            output=output+temp;
                        else if(char_stack.Top()=='+'||char_stack.Top()=='-'||char_stack.Top()=='*'|| char_stack.Top()=='/')
                            output=output+temp+" ";
                        else
                            char_stack.pop();
			}
		}

       else {

			if (isOperator(char_stack.Top())) {
				while (getPriority(infix[i]) <= getPriority(char_stack.Top())) {
					output =output+char_stack.Top()+" " ;
					char_stack.pop();
				}

				// Push current Operator on stack
				char_stack.push(infix[i]);
			}
		}
	}
	return output;

}

//evaluating postfix value


    int operation(int a,int b,char opr){

            switch(opr){

				case '+':return a+b;
                    break;
				case '-':return a-b;
                    break;
				case '*':return a*b;
                    break;
				case '/':return a/b;
                    break;
				default: return 0;
			}
		}


int calculatePostfix(string postfix) {

    stackType <int> st;
    int result;
    int jack,rose;

    for(int i=0; i<postfix.size() ; i++){

            if (postfix[i]!='+' || postfix[i]!='-' || postfix[i]!='*' || postfix[i]!='/'){

                st.push(postfix[i]);
            }

            else {
                    st.pop();

                    while(st.Top()!= NULL){

                        int a= st.Top();
                        st.pop();
                        int b = st.Top();
                                if(b!= NULL){

                                        jack= 10*b + a;
                                         st.pop();
                                }
                                else
                                    jack =a;

                    }

                    st.pop();
                    while(!st.isEmpty()){

                        int x=st.Top();
                        st.pop();
                        int y= st.Top();

                            if(y!=NULL){
                                    rose= y*10 + x;
                            }
                            else
                                rose =x;
                    }

                    //result= operation(rose,jack,postfix[i]);

            }
             result= operation(rose,jack,postfix[i]);
            st.push(result);
    }

    return st.Top();

}



int main()
{
	string s;
	cout<<"enter your string :"<<endl;
	cin>>s;

	string out=infixToPostfix(s);
	cout<<"postfix : ";
	cout<<out<<endl;

	int box = calculatePostfix(out);
	cout<<"calculation is : ";
	cout<<box<<endl;


}

